require 'rake/clean'
require "#{ENV['CORTO_BUILD']}/version"
require "#{ENV['CORTO_BUILD']}/libmapping"

CHDIR_SET ||= false

if !CHDIR_SET then
    Dir.chdir(File.dirname(Rake.application.rakefile))
end

if not ENV['CORTO_BUILD'] then
    raise "CORTO_BUILD not defined (did you forget to 'source configure'?)"
end
if not defined? ARTEFACT then
    raise "artefact: ARTEFACT not specified\n"
end


# --- DATA PROCESSING

# Utility that replaces buildsystem tokens with actual values
def corto_replace(str)
    str = str.gsub("$(CORTO_OS)", `uname -s`[0...-1])
    str = str.gsub("$(CORTO_PLATFORM)", `uname -p`[0...-1])
    str = str.gsub("$(CORTO_TARGET)", TARGETDIR)
    etcPath = ENV['CORTO_TARGET'] + "/corto/#{VERSION}"
    etcPath = TARGETDIR[etcPath.length..-1]
    str = str.gsub("$(CORTO_ETC)", ENV['CORTO_TARGET'] + "/etc/corto" + etcPath)
end

# Public variables
INCLUDE ||= []
LIB ||= []
LIBPATH ||= []
LINK ||= []
CFLAGS ||= []
LFLAGS ||= []
USE_PACKAGE ||= []
USE_COMPONENT ||= []
USE_LIBRARY ||= []
DEFINE ||= []
CC ||= if ENV['CC'].nil? or ENV['CC'].empty?
  "cc"
else
  ENV['CC']
end

# Private variables
TARGETDIR ||= ENV['CORTO_TARGET'] + "/lib"
GENERATED_SOURCES ||= []
GENERATED_HEADERS ||= []
USE_PACKAGE_LOADED ||=[]
USE_COMPONENT_LOADED ||=[]

# Add default include paths
INCLUDE <<
    "src" <<
    "include" <<
    "#{ENV['CORTO_TARGET']}/include/corto/#{VERSION}/packages" <<
    "/usr/local/include/corto/#{VERSION}/packages"

# Default CFLAGS
CFLAGS << "-g" << "-Wstrict-prototypes" << "-std=c99" << "-pedantic" << "-fPIC" << "-D_XOPEN_SOURCE=600"
CFLAGS.unshift("-Wall")

# Obtain list of source and object files
SOURCES = Rake::FileList["src/*.c"] + GENERATED_SOURCES
OBJECTS = SOURCES.ext(".o").pathmap(".corto/obj/%f")

# Load components from file
if File.exists? ".corto/components.txt" then
    f = File.open(".corto/components.txt")
    f.each_line {|line|
        USE_COMPONENT_LOADED.push line[0...-1]
        USE_COMPONENT.push line[0...-1]
    }
end

# Load packages from file
if File.exists? ".corto/packages.txt" then
    f = File.open(".corto/packages.txt")
    f.each_line {|line|
        USE_PACKAGE_LOADED.push line[0...-1]
        USE_PACKAGE.push line[0...-1]
    }
end

# Setup default clean & clobber rules
CLEAN.include(".corto/obj")
CLEAN.include("doc")
CLOBBER.include(TARGETDIR + "/" + ARTEFACT)
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(GENERATED_HEADERS)

# If components.txt is empty, clobber it
if USE_COMPONENT_LOADED.length == 0 then
    CLOBBER.include(".corto/components.txt")
end

# If packages.txt is empty, clobber it
if USE_PACKAGE_LOADED.length == 0 then
    CLOBBER.include(".corto/packages.txt")
end


# --- BUILD RULES

# Task that collects all artefacts from the build and store them in a 'pack'
# folder, where they can be tarred for redistribution.
task :collect do
    verbose(false)
    artefact = "#{TARGETDIR}/#{ARTEFACT}"
    target = ENV['HOME'] + "/.corto/pack" + artefact["#{ENV['CORTO_TARGET']}".length..artefact.length]
    sh "mkdir -p " + target.split("/")[0...-1].join("/")

    if `uname` == "Darwin\n" then
        sh "cp -r #{artefact} #{target}"
    else
        sh "cp -rL #{artefact} #{target}"
    end
end

# Rule to automatically create components.txt
file ".corto/components.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/components.txt"
end

# Rule to automatically create packages.txt
file ".corto/packages.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

task :binary => "#{TARGETDIR}/#{ARTEFACT}"

# Build artefact
file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(false)
    sh "mkdir -p #{TARGETDIR}"

    # Create list of files that are going to be linked with. Abstract away from the
    # difference between dll, so and dylib. When a dylib is encountered, perform  a
    # bit of magic to ensure that the executable can find the shared object.
    LINKED = LINK.map do |l|
        l = corto_replace(l)
        lib = File.dirname(l) + "/lib" + File.basename(l) + ".so"
        if (not File.exists? lib) and (`uname` == "Darwin\n") then
            lib = File.dirname(l) + "/lib" + File.basename(l) + ".dylib"
            if (not File.exists? lib) then
                abort "\033[1;31m[ #{l} not found ]\033[0;49m"
            end
        end
        lib
    end

    OBJECTS.concat(LINKED)
    objects  = "#{OBJECTS.to_a.uniq.join(' ')}"
    cflags = "#{CFLAGS.join(" ")}"
    libpath = "#{LIBPATH.map {|i| "-L" + corto_replace(i)}.join(" ")} "
    libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
    lflags = "#{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"
    use_link =
        USE_PACKAGE.map do |i|
            result = `corto locate #{i} --lib`[0...-1]
            if $?.exitstatus != 0 then
                p result
                abort "\033[1;31m[ build failed ]\033[0;49m"
            end
            result
        end.join(" ") + " " +
        USE_COMPONENT.map {|i| "#{ENV['CORTO_HOME']}/lib/corto/#{VERSION}/components/lib" + i + ".so"}.join(" ") + " " +
        USE_LIBRARY.map {|i| "#{ENV['CORTO_HOME']}/lib/corto/#{VERSION}/libraries/lib" + i + ".so"}.join(" ")

    # Check if there were any new files created during code generation
    Rake::FileList["src/*.c"].each do |file|
        if not SOURCES.include? file
            obj = file.ext(".o").pathmap(".corto/obj/%f")
            build_source(file, obj, true)
            objects += " " + obj
        end
    end

    cc_command = "#{CC} #{objects} #{cflags} #{libpath} #{libmapping} #{use_link} #{lflags}"
    begin
      sh cc_command
    rescue
      puts "\033[1;31mcommand failed: #{cc_command}\033[0;49m"
      abort()
    end

    # If required, alter paths to dylib files
    LINKED.each do |lib|
        if File.extname(lib) == ".dylib" then
            # Obtain name of library, check if its different from target path. If
            # names don't match, setup a task to alter the name in the executable
            # path.
            libname = `otool -L #{lib}`.split("\n")[1].split[0]
            if libname != lib then
                sh "install_name_tool -change #{libname} #{lib} #{TARGETDIR}/#{ARTEFACT}"
            end
        end
    end

    if ENV['silent'] != "true" then
        sh "echo '\033[1;49m[ \033[1;34m#{ARTEFACT}\033[0;49m\033[1;49m ]\033[0;49m'"
    end
end

# These tasks allow projects to define actions that should happen before and
# after the build.
task :prebuild
task :postbuild

# The default rule that kicks of the build process
task :default => [:prebuild, :binary, :postbuild]

# For make junkies
task :all => :default

# Run test for project
task :test do
    verbose(false)
    begin
      sh "corto test"
    rescue
      abort
    end
end

# Rules for generated files
rule '__api.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '__meta.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '__wrapper.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '__load.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end

# Generic rule for translating source files into object files
rule '.o' => ->(t) {t.pathmap("src/%f").ext(".c")} do |task|
    build_source(task.source, task.name, true)
end

# --- UTILITIES

# Utility for building a sourcefile
def build_source(source, target, echo)
    verbose(false)
    if not File.exists? ".corto/obj" then
        sh "mkdir -p .corto/obj"
    end
    if echo
        if ENV['silent'] != "true" then
            sh "echo '#{source}'"
        end
    end
    cc_command = "#{CC} -c #{CFLAGS.join(" ")} #{DEFINE.map {|d| "-D" + d}.join(" ")} #{INCLUDE.map {|i| "-I" + i}.join(" ")} #{source} -o #{target}"
    begin
      sh cc_command
    rescue
      puts "\033[1;31mcommand failed: #{cc_command}\033[0;49m"
      abort()
    end
end
