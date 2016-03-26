require "#{ENV['CORTO_BUILD']}/common"
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
if not ENV['target'] then
    ENV['target'] = "debug"
end

# --- DATA PROCESSING

# Utility that replaces buildsystem tokens with actual values
def corto_replace(str)
    str = str.gsub("$(CORTO_OS)", CORTO_OS)
    str = str.gsub("$(CORTO_MACHINE)", CORTO_MACHINE)
    str = str.gsub("$(CORTO_PLATFORM)", CORTO_PLATFORM)
    str = str.gsub("$(CORTO_TARGET)", TARGETDIR)
    projectPath = ""
    if defined? PACKAGEDIR then
        projectPath = PACKAGEDIR
    end
    str = str.gsub("$(CORTO_ETC)", ENV['CORTO_TARGET'] + "/etc/corto/#{CORTO_VERSION}/" + projectPath)
    str = str.gsub("$(CORTO_INCLUDE)", ENV['CORTO_TARGET'] + "/include/corto/#{CORTO_VERSION}/" + projectPath)
    str = str.gsub("$(CORTO_LIB)", ENV['CORTO_TARGET'] + "/include/corto/#{CORTO_VERSION}/" + projectPath)
end

# Private variables
TARGETDIR ||= ENV['CORTO_TARGET'] + "/lib"
GENERATED_SOURCES ||= []
GENERATED_HEADERS ||= []
USE_PACKAGE_LOADED ||=[]

# Add lib path for builds that don't install to global environment
if ENV['CORTO_TARGET'] != "/usr/local" then
    LIBPATH << "#{ENV['CORTO_TARGET']}/lib"
end

# Add default include paths
INCLUDE <<
    "src" <<
    "#{ENV['CORTO_TARGET']}/include/corto/#{CORTO_VERSION}" <<
    "/usr/local/include/corto/#{CORTO_VERSION}"

# Default CFLAGS
CFLAGS << "-std=c99" << "-Wstrict-prototypes" << "-pedantic" << "-fPIC" << "-D_XOPEN_SOURCE=600"
CFLAGS.unshift("-Wall")

# Default CXXFLAGS
CXXFLAGS << "-Wall" << "-std=c++11" << "-fPIC" << "-Wno-write-strings"

# Set default compiler
if LANGUAGE == "c" then
    COMPILER = CC
elsif LANGUAGE == "c++" then
    COMPILER = CXX
else
    abort "\033[1;31m[ language #{LANGUAGE} unsupported ]\033[0;49m"
end

# Set NDEBUG macro in release builds to disable tracing & checking
# Also enable optimizations
if ENV['target'] == "release" then
  CFLAGS << "-DNDEBUG" << "-O3"
  CXXFLAGS << "-DNDEBUG" << "-O3"
end

# Enable debug info, coverage and disable optimizations in debug
if ENV['target'] == "debug" then
  CFLAGS << "-g" << "-O0"
  CXXFLAGS << "-g" << "-O0"
  if COVERAGE == true then
    CFLAGS << "-fprofile-arcs" << "-ftest-coverage"
    CXXFLAGS << "-fprofile-arcs" << "-ftest-coverage"
    LFLAGS << "-fprofile-arcs" << "-ftest-coverage"
  end
end

# Crawl src directory to get list of source files
SOURCES = Rake::FileList["src/**/*.{c,cc,cpp,cxx}"]
OBJECTS = SOURCES.ext(".o")
              .pathmap(".corto/%{^src/,obj/#{CORTO_PLATFORM}/}p") +
            Rake::FileList[GENERATED_SOURCES]
              .ext(".o")
              .pathmap(".corto/obj/#{CORTO_PLATFORM}/%f")

# Load packages from file
if File.exists? ".corto/packages.txt" then
    f = File.open(".corto/packages.txt")
    f.each_line {|l|
        p = l[0...-1]
        USE_PACKAGE_LOADED.push p
        USE_PACKAGE.push p
    }
end

# Setup default clean & clobber rules
CLEAN.include(".corto/obj/#{CORTO_PLATFORM}")
CLEAN.include("doc")
CLEAN.include("*.gcov")
CLOBBER.include(".corto/obj")
CLOBBER.include(TARGETDIR + "/" + ARTEFACT)
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(GENERATED_HEADERS)

# If packages.txt is empty, clobber it
if USE_PACKAGE_LOADED.length == 0 then
    CLOBBER.include(".corto/packages.txt")
end


# --- BUILD RULES

# Task that collects all artefacts from the build and store them in a 'pack'
# folder, where they can be tarred for redistribution.
task :collect do
    verbose(VERBOSE)
    artefact = "#{TARGETDIR}/#{ARTEFACT}"
    target = ENV['HOME'] + "/.corto/pack" + artefact["#{ENV['CORTO_TARGET']}".length..artefact.length]
    targetDir = target.split("/")[0...-1].join("/")
    sh "mkdir -p #{targetDir}"
    sh "cp #{artefact} #{target}"

    if File.exists? "#{TARGETDIR}/build.sh" then
        sh "cp #{TARGETDIR}/build.sh #{targetDir}/build.sh"
    end
end

# Rule to automatically create packages.txt
file ".corto/packages.txt" do
    verbose(VERBOSE)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

task :binary => "#{TARGETDIR}/#{ARTEFACT}" do
    UNINSTALL << TARGETDIR
end

# Build artefact
file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(VERBOSE)
    sh "mkdir -p #{TARGETDIR}"

    # Create list of files that are going to be linked with. Abstract away from the
    # difference between dll, so and dylib. When a dylib is encountered, perform  a
    # bit of magic to ensure that the executable can find the shared object.
    LINKED = LINK.map do |l|
        l = corto_replace(l)
        prefix = ""
        if File.dirname(l) != "." then
          prefix = File.dirname(l) + "/"
        end
        lib = prefix + "lib" + File.basename(l) + ".so"
        if (not File.exists? lib) and (CORTO_OS == "Darwin") then
            lib = prefix + "lib" + File.basename(l) + ".dylib"
            if (not File.exists? lib) then
                abort "\033[1;31m[ #{l} not found ]\033[0;49m"
            end
        end
        lib
    end

    OBJECTS.concat(LINKED)
    objects  = "#{OBJECTS.to_a.uniq.join(' ')}"
    libpath = "#{LIBPATH.map {|i| "-L" + corto_replace(i)}.join(" ")} "
    libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
    lflags = "#{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"

    use_link =
      USE_LIBRARY.map {|i|
        "#{ENV['CORTO_HOME']}/lib/corto/#{CORTO_VERSION}/libraries/lib" + i + ".so"
      }.join(" ")

    # Check if there were any new files created during code generation
    Rake::FileList["src/*.c"].each do |file|
        obj = file.ext(".o").pathmap(".corto/obj/#{CORTO_PLATFORM}/%f")
        if not OBJECTS.include? obj
            build_source(file, obj, true)
            objects += " " + obj
        end
    end

    cc_command = "#{COMPILER} #{objects} #{use_link} #{libpath} #{libmapping} #{lflags}"
    begin
      sh cc_command
    rescue
      STDERR.puts "\033[1;31mcommand failed: #{cc_command}\033[0;49m"
      abort
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

    # If target is release, strip binary
    if ENV['target'] == "release" then
      sh "strip -Sx #{TARGETDIR}/#{ARTEFACT}"
    end

    if ENV['silent'] != "true" then
        sh "echo '#{C_BOLD}[ #{C_NORMAL}#{C_TARGET}#{ARTEFACT}#{C_NORMAL}#{C_BOLD} ]#{C_NORMAL}'"
    end
end

# These tasks allow projects to define actions that should happen before and
# after the build.
task :prebuild do
  verbose(VERBOSE)
  # Load dependency build instructions before anything else
  USE_PACKAGE.each {|p|
      location = `corto locate #{p} --path`[0...-1]
      buildscript = location + "/build.rb"
      if File.exists? buildscript then
          require "#{buildscript}"
      end
  }
end

task :postbuild

# The default rule that kicks of the build process
task :default => [:prebuild, :binary, :postbuild]

# For make junkies
task :all => :default

# Run test for project
task :test do
  verbose(VERBOSE)
  file = ""
  if File.exists? "test/rakefile" then
    sh "rake -f test/rakefile silent=true"
    if File.exists? "test/.corto/libtest.so" then
      Dir.chdir("test")
      file = ".corto/libtest.so"
    end
  elsif File.exists? ".corto/libtest.so" then
    file = ".corto/libtest.so"
  end

  if file != "" then
    begin
      sh "corto #{file} #{ENV['testcase']}"
    rescue
      abort
    end
  end
end

# Keep track of overal coverage statistics for project
covered = 0
total = 0
coverage_report = []

# Run gcov for project
task :gcov => SOURCES.ext(".gcov") do
  coverage_report.sort_by {|item| item['uncovered']}.reverse!.each {|item|
      if (item['uncovered'] != 0) then
        if (item['pct'] < 0.7) then
          print "#{item['source']}: #{C_FAIL}#{"%.2f" % (item['pct']*100)}%#{C_NORMAL} (#{item['uncovered']} uncovered)\n"
        elsif (item['pct'] >= 0.8) then
          print "#{item['source']}: #{C_OK}#{"%.2f" % (item['pct']*100)}%#{C_NORMAL} (#{item['uncovered']} uncovered)\n"
        else
          print "#{item['source']}: #{"%.2f" % (item['pct']*100)}% (#{item['uncovered']} uncovered)\n"
        end
      end
  }
  if (total != 0) then
    pct = covered / total
    if (pct < 0.7) then
      print ("#{C_BOLD}[ #{C_NORMAL}#{C_TARGET}#{ARTEFACT}#{C_NORMAL}#{C_FAIL} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n")
    elsif (pct >= 0.8) then
      print ("#{C_BOLD}[ #{C_NORMAL}#{C_TARGET}#{ARTEFACT}#{C_NORMAL}#{C_OK} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n")
    else
      print ("#{C_BOLD}[ #{C_NORMAL}#{C_TARGET}#{ARTEFACT}#{C_NORMAL}#{C_BOLD} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n")
    end
  end
end

# Rules for generated files
rule '_api.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '_meta.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '_wrapper.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end
rule '_load.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task.source, task.name, false)
end

# Generic rule for translating source files into object files
rule '.o' => ->(t) {
  file = nil
  base = File.join(File.dirname(t), File.basename(t, '.*'))
  SOURCES.each do |e|
    if e.pathmap("%{^src/,.corto/obj/#{CORTO_PLATFORM}/}X") == base then
      file = e
      break;
    end
  end
  if file == nil then
    file = t.pathmap("src/%f").ext(".c")
  end
  file
} do |task|
  sh "rm -f #{task.name.ext(".gcda")}"
  sh "rm -f #{task.name.ext(".gcno")}"
  build_source(task.source, task.name, true)
end

# Rule for creating a gcov file
rule '.gcov' => ->(t){t.ext(".c")} do |task|
  if File.basename(task.name)[0] != "_" then
    gcov_dir = File.dirname(task.source.pathmap(".corto/%{^src/,obj/#{CORTO_PLATFORM}/}p"))
    begin
      coverage = `gcov --object-directory #{gcov_dir} #{task.source}`
      data = coverage.split("\n")[1]
      pct = data.match(/(\w+)\.(\w+)\%/)[0][0...-1].to_f / 100
      lines = data.split(" ")[3].to_i
      covered += (pct) * lines
      total += lines

      if (pct < 0.7) then
        #print "#{task.source}:#{C_FAIL} #{"%.2f" % (pct*100)}%#{C_NORMAL}#{C_BOLD}#{C_NORMAL} of #{lines}\n"
      elsif (pct > 0.8) then
        #print "#{task.source}:#{C_OK} #{"%.2f" % (pct*100)}%#{C_NORMAL}#{C_BOLD}#{C_NORMAL} of #{lines}\n"
      else
        #print "#{task.source}:#{C_NORMAL} #{"%.2f" % (pct*100)}%#{C_NORMAL}#{C_BOLD}#{C_NORMAL} of #{lines}\n"
      end
      coverage_report << {'pct' => pct, 'uncovered' => (lines - lines * pct).round, 'source' => task.source}
    rescue
    end
  end
end

# --- UTILITIES

# Utility for building a sourcefile
def build_source(source, target, echo)
    verbose(VERBOSE)
    flags = ""
    cc = ""

    if LANGUAGE == "c" then
        flags = CFLAGS
        cc = CC
    else
        flags = CXXFLAGS
        cc = CXX
    end

    path = File.dirname(target)
    if not File.exists? path then
        sh "mkdir -p #{path}"
    end

    if echo
        if ENV['silent'] != "true" then
            sh "echo '#{source}'"
        end
    end

    cc_command = "#{COMPILER} -c #{flags.join(" ")} #{DEFINE.map {|d| "-D" + d}.join(" ")} #{INCLUDE.map {|i| "-I" + corto_replace(i)}.join(" ")} #{source} -o #{target}"
    begin
      sh cc_command
    rescue
      STDERR.puts "\033[1;31mcommand failed: #{cc_command}\033[0;49m"
      abort
    end
end
