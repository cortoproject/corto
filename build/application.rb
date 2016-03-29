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

GENERATED_SOURCES << ".corto/_load.#{EXT}"
GENERATED_HEADERS << "include/_interface.h"

USE_PACKAGE << "corto"
INCLUDE <<
    "#{ENV['CORTO_HOME']}/include/corto/#{CORTO_VERSION}" <<
    "#{ENV['CORTO_HOME']}/include/corto/#{CORTO_VERSION}/packages/corto/lang" <<
    "include"

CLOBBER.include ".corto/#{TARGET}.h"

file ".corto/_load.#{EXT}" => [".corto/packages.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    c4cppStr = ""
    if LANGUAGE == "c4cpp" then
        c4cppStr = "--attr c4cpp=true"
    end
    command = "corto pp --name #{TARGET} --attr local=true --attr h=include --attr app=true #{c4cppStr} -g c/project"
    begin
        sh command
    rescue
        STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
        abort()
    end
end

task :prebuild => ".corto/_load.#{EXT}"

require "#{ENV['CORTO_BUILD']}/artefact"
