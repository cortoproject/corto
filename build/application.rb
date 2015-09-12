require "#{ENV['CORTO_BUILD']}/version"
require "rake/clean"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = "app"
TARGETDIR = "./.corto"
CORTO_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".corto/#{TARGET}__load.c"

CORTO_LIB << "corto"
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}" <<
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/packages/corto/lang"

CLOBBER.include ".corto/#{TARGET}.h"

file ".corto/#{TARGET}__load.c" => [".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    sh "corto pp --name #{TARGET} -g c_project"
end

task :prebuild => ".corto/#{TARGET}__load.c"

require "#{ENV['CORTO_BUILD']}/artefact"
