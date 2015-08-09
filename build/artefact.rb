require 'rake/clean'
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
USE ||= []

CLEAN.include(".obj/*.o")
CLEAN.include(".obj")
CLOBBER.include("#{TARGETDIR}/#{ARTEFACT}")

INCLUDE << "include"

CFLAGS << "-g" << "-Wall" << "-Wextra" << "-Wno-gnu-label-as-value" << "-Wno-unknown-pragmas" <<
           "-Wstrict-prototypes" << "-pedantic" << "-std=c99" << "-fPIC" << "-D_XOPEN_SOURCE=600"

SOURCES = (Rake::FileList["src/*.c"] + GENERATED_SOURCES)
OBJECTS = SOURCES.ext(".o").pathmap(".obj/%f")
USE_INCLUDE = USE.map{|i| "-I" + "#{ENV['CORTEX_HOME']}/packages/" + i.gsub("::", "/") + "/include"}.join(" ")

task :binary => "#{TARGETDIR}/#{ARTEFACT}"

file "#{TARGETDIR}/#{ARTEFACT}" => OBJECTS do
    verbose(false)
    sh "mkdir -p #{TARGETDIR}"
    objects  = "#{OBJECTS.to_a.uniq.join(' ')}"
    cflags = "#{CFLAGS.join(" ")}"
    cortex_lib = "#{CORTEX_LIB.map {|i| ENV['CORTEX_HOME'] + "/bin/lib" + i + ".so"}.join(" ")}"
    libpath = "#{LIBPATH.map {|i| "-L" + i}.join(" ")}"
    libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
    libuse = USE.map do |i|
        dirs = i.split("::")
        "#{ENV['CORTEX_HOME']}/packages/" + dirs[0..dirs.length-2].join("/") + "/bin/lib" + dirs[dirs.length-1] + ".so"
    end.join(" ")
    lflags = "#{LFLAGS.join(" ")} -o #{TARGETDIR}/#{ARTEFACT}"
    cc_command = "cc #{objects} #{cflags} #{cortex_lib} #{libpath} #{libmapping} #{libuse} #{lflags}"
    sh cc_command
    sh "echo '\033[1;49m[ \033[1;34m#{ARTEFACT}\033[0;49m\033[1;49m ]\033[0;49m'"
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
    sh "mkdir -p .obj"
    if echo 
        sh "echo '#{task.source}'" 
    end
    sh "cc -c #{CFLAGS.join(" ")} #{USE_INCLUDE} #{INCLUDE.map {|i| "-I" + i}.join(" ")} #{task.source} -o #{task.name}"
end


