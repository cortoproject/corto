require "#{ENV['CORTO_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETPATH ||= "components"

INCLUDE ||= []
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/components"

GENERATED_SOURCES ||= []
GENERATED_SOURCES <<
    ".corto/#{TARGET}__load.c"

file ".corto/#{TARGET}__load.c" => [".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    sh "corto pp --name #{TARGET} -g c_project --attr component=true"
end

task :prebuild => ".corto/#{TARGET}__load.c"

require "#{ENV['CORTO_BUILD']}/library"
