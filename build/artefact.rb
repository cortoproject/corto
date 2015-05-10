require 'rake/clean'
require 'set'
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
TARGETDIR ||= ENV['CORTEX_HOME'] + "/bin"
GENERATED_SOURCES ||= []

CLEAN.include("obj/*.o")
CLEAN.include("obj")
CLOBBER.include("#{TARGETDIR}/#{ARTEFACT}")

INCLUDE << "include"

CFLAGS << "-g" << "-Wall" << "-Wextra" << "-Wno-gnu-label-as-value" << "-Wno-unknown-pragmas" <<
           "-Wstrict-prototypes" << "-pedantic" << "-std=c99" << "-fPIC" << "-D_XOPEN_SOURCE=600"

SOURCES = (Rake::FileList["src/*.c"] + GENERATED_SOURCES)
OBJECTS = SOURCES.ext(".o").pathmap("obj/%f")
INCLUDE_LIST = INCLUDE.map {|i| "-I" + i}.join(" ")

task :binary => "#{TARGETDIR}/#{ARTEFACT}"

file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(false)
    sh "mkdir -p #{TARGETDIR}"
    sh "cc #{OBJECTS.to_a.uniq.join(' ')} #{CFLAGS.join(" ")} #{CORTEX_LIB.map {|i| ENV['CORTEX_HOME'] + "/bin/lib" + i + ".so"}.join(" ")} #{LIBPATH.map {|i| "-L" + i}.join(" ")} #{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")} #{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"
    sh "echo '\033[1;30m[ \033[1;34m#{ARTEFACT}\033[1;30m ]\033[0;49m'"
end

task :prebuild
task :postbuild

rule '.o' => ->(t){t.pathmap("src/%f").ext(".c")} do |task|
    verbose(false)
    sh "mkdir -p obj"
    sh "echo '#{task.source}'"
    sh "cc -c #{CFLAGS.join(" ")} #{INCLUDE.map {|i| "-I" + i}.join(" ")} #{task.source} -o #{task.name}"
end

task :default => [:prebuild, :binary, :postbuild]
