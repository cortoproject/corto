require "#{ENV['CORTO_BUILD']}/common"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = "app"
TARGETDIR = "./.corto"
USE_PACKAGE ||= []
LIBPATH ||= []
INCLUDE << "include"

GENERATED_SOURCES ||= []
GENERATED_HEADERS ||= []

GENERATED_SOURCES << ".corto/_load.c"
GENERATED_HEADERS << "include/_interface.h"

USE_PACKAGE << "corto"
INCLUDE <<
    "#{ENV['CORTO_HOME']}/include/corto/#{CORTO_VERSION}" <<
    "#{ENV['CORTO_HOME']}/include/corto/#{CORTO_VERSION}/packages/corto/lang" <<
    "include"

CLOBBER.include ".corto/#{TARGET}.h"

file ".corto/_load.c" => [".corto/packages.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    command = "corto pp --name #{TARGET} --attr local=true --attr h=include --attr app=true -g c/project"
    begin
        sh command
    rescue
        STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
        abort()
    end
end

task :prebuild => ".corto/_load.c"

require "#{ENV['CORTO_BUILD']}/artefact"
