require 'rake/clean'
require "#{ENV['CORTEX_HOME']}/build/version"
require "#{ENV['CORTEX_HOME']}/build/libmapping"

Dir.chdir(File.dirname(Rake.application.rakefile))

if not ENV['CORTEX_HOME'] then
    raise "CORTEX_HOME not defined (did you forget to 'source configure'?)"
end
if not defined? ARTEFACT then
    raise "artefact: ARTEFACT not specified\n"
end

INCLUDE ||= []
LIB ||= []
CORTEX_LIB ||= []
LIBPATH ||= []
CFLAGS ||= []
LFLAGS ||= []
TARGETDIR ||= ENV['CORTEX_TARGET'] + "/lib"
GENERATED_SOURCES ||= []
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

task :binary => "#{TARGETDIR}/#{ARTEFACT}"

file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(false)
    sh "mkdir -p #{TARGETDIR}"
    objects  = "#{OBJECTS.to_a.uniq.join(' ')}"
    cflags = "#{CFLAGS.join(" ")}"
    cortex_lib = "#{CORTEX_LIB.map {|i| ENV['CORTEX_TARGET'] + "/lib/lib" + i + ".so"}.join(" ")}"
    libpath = "#{LIBPATH.map {|i| "-L" + i}.join(" ")} "
    libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
    lflags = "#{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"
    use_link =
        USE_PACKAGE.map do |i|
            dirs = i.split("::")
            "#{ENV['CORTEX_TARGET']}/lib/cortex/#{VERSION}/packages/" + i.gsub("::", "/") + "/lib" + dirs[dirs.length-1] + ".so"
        end.join(" ") +
        USE_COMPONENT.map {|i| "#{ENV['CORTEX_TARGET']}/lib/cortex/#{VERSION}/components/lib" + i + ".so"}.join(" ") +
        USE_LIBRARY.map {|i| "#{ENV['CORTEX_TARGET']}/lib/cortex/#{VERSION}/libraries/lib" + i + ".so"}.join(" ")
    cc_command = "cc #{objects} #{cflags} #{cortex_lib} #{libpath} #{libmapping} #{use_link} #{lflags}"
    sh cc_command
    if ENV['silent'] != "true" then
        sh "echo '\033[1;49m[ \033[1;34m#{ARTEFACT}\033[0;49m\033[1;49m ]\033[0;49m'"
    end
end

task :prebuild
task :postbuild

rule '__api.o' => ->(t){t.pathmap(".cortex/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__meta.o' => ->(t){t.pathmap(".cortex/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__wrapper.o' => ->(t){t.pathmap(".cortex/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '__load.o' => ->(t){t.pathmap(".cortex/%f").ext(".c")} do |task|
    build_source(task, false)
end
rule '.o' => ->(t){t.pathmap("src/%f").ext(".c")} do |task|
    build_source(task, true)
end

task :default => [:prebuild, :binary, :postbuild]

def build_source(task, echo)
    verbose(false)
    sh "mkdir -p #{TARGETDIR}/obj"
    if echo
        if ENV['silent'] != "true" then
            sh "echo '#{task.source}'" 
        end
    end
    use_include = USE_PACKAGE.map{|i| "-I" + "#{ENV['CORTEX_TARGET']}/include/cortex/#{VERSION}/packages/" + i.gsub("::", "/")}.join(" ")
    sh "cc -c #{CFLAGS.join(" ")} #{use_include} #{INCLUDE.map {|i| "-I" + i}.join(" ")} #{task.source} -o #{task.name}"
end


