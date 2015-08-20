if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = "app"
TARGETDIR = "./.cortex"
CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".cortex/#{TARGET}__load.c"

CORTEX_LIB << "cortex"
LIBPATH << "#{ENV['CORTEX_HOME']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/cx/include"

file ".cortex/#{TARGET}__load.c" do
    verbose(false)
    sh "mkdir -p .cortex"
    sh "cortex pp --name #{TARGET} -g c_project"
end

task :prebuild => ".cortex/#{TARGET}__load.c" do

end

require "#{ENV['CORTEX_HOME']}/build/artefact"
