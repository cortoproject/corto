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

INCLUDE ||= []
LIB ||= []
CORTO_LIB ||= []
LIBPATH ||= []
CFLAGS ||= []
LFLAGS ||= []
TARGETDIR ||= ENV['CORTO_TARGET'] + "/lib"
GENERATED_SOURCES ||= []
GENERATED_HEADERS ||= []
USE_PACKAGE ||= []
USE_COMPONENT ||= []
USE_LIBRARY ||= []
INCLUDE << "include"

CFLAGS << "-g" << "-Wstrict-prototypes" << "-std=c99" << "-pedantic" << "-fPIC" << "-D_XOPEN_SOURCE=600"
CFLAGS.unshift("-Wall")

SOURCES = (Rake::FileList["src/*.c"] + GENERATED_SOURCES)
OBJECTS = SOURCES.ext(".o").pathmap(TARGETDIR + "/obj/%f")

CLEAN.include(TARGETDIR + "/obj")
CLOBBER.include(TARGETDIR + "/" + ARTEFACT)
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(GENERATED_HEADERS)

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

task :binary => "#{TARGETDIR}/#{ARTEFACT}"

file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(false)
    sh "mkdir -p #{TARGETDIR}"
    objects  = "#{OBJECTS.to_a.uniq.join(' ')}"
    cflags = "#{CFLAGS.join(" ")}"
    corto_lib = "#{CORTO_LIB.map {|i| ENV['CORTO_HOME'] + "/lib/lib" + i + ".so"}.join(" ")}"
    libpath = "#{LIBPATH.map {|i| "-L" + i}.join(" ")} "
    libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
    lflags = "#{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"
    use_link =
        USE_PACKAGE.map do |i|
            dirs = i.split("::")
            "#{ENV['CORTO_HOME']}/lib/corto/#{VERSION}/packages/" + i.gsub("::", "/") + "/lib" + dirs[dirs.length-1] + ".so"
        end.join(" ") +
        USE_COMPONENT.map {|i| "#{ENV['CORTO_HOME']}/lib/corto/#{VERSION}/components/lib" + i + ".so"}.join(" ") +
        USE_LIBRARY.map {|i| "#{ENV['CORTO_HOME']}/lib/corto/#{VERSION}/libraries/lib" + i + ".so"}.join(" ")
    cc_command = "cc #{objects} #{cflags} #{corto_lib} #{libpath} #{libmapping} #{use_link} #{lflags}"
    sh cc_command
    if ENV['silent'] != "true" then
        sh "echo '\033[1;49m[ \033[1;34m#{ARTEFACT}\033[0;49m\033[1;49m ]\033[0;49m'"
    end
end

task :prebuild
task :postbuild

rule '__api.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__meta.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__wrapper.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__load.o' => ->(t){t.pathmap(".corto/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '.o' => ->(t){t.pathmap("src/%f").ext(".c")} do |task|
    build_source(task, true)
end

task :default => [:prebuild, :binary, :postbuild]

def build_source(task, echo)
    verbose(false)
    if not File.exists? "#{TARGETDIR}/obj" then
        sh "mkdir -p #{TARGETDIR}/obj"
    end
    if echo
        if ENV['silent'] != "true" then
            sh "echo '#{task.source}'" 
        end
    end
    use_include = USE_PACKAGE.map{|i| "-I #{ENV['CORTO_HOME']}/include/corto/#{VERSION}/packages/" + i.gsub("::", "/")}.join(" ")
    sh "cc -c #{CFLAGS.join(" ")} #{use_include} #{INCLUDE.map {|i| "-I" + i}.join(" ")} #{task.source} -o #{task.name}"
end


