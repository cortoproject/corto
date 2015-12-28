require "#{ENV['CORTO_BUILD']}/version"
require "rake/clean"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = "app"
TARGETDIR = "./.corto"
USE_PACKAGE ||= []
LIBPATH ||= []
INCLUDE ||= []

GENERATED_SOURCES ||= []

GENERATED_SOURCES << ".corto/_load.c"

USE_PACKAGE << "corto"
INCLUDE <<
    "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}" <<
    "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/packages/corto/lang" <<
    "include"


CLOBBER.include ".corto/#{TARGET}.h"

file ".corto/_load.c" => [".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    sh "corto pp --name #{TARGET} --attr local=true --attr h=include -g c_project"
end

task :prebuild => ".corto/_load.c"

require "#{ENV['CORTO_BUILD']}/artefact"
