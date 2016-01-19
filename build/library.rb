require "#{ENV['CORTO_BUILD']}/version"
require 'rake/clean'

if not defined? VERBOSE then
    if ENV['verbose'] == "true" then
        VERBOSE ||= true
    else
        VERBOSE ||= false
    end
end

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

if not defined? LOCAL then
    LOCAL = false
end

LFLAGS ||= []
USE_PACKAGE ||= []
LIBPATH ||= []
INCLUDE ||= ["include"]

ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"

if LOCAL == true then
    if not defined? TARGETPATH then
        TARGETPATH ||= "./.corto"
        TARGETDIR ||= TARGETPATH
    end
else
    TARGETPATH ||= "libraries"
end
TARGETDIR ||= "#{ENV['CORTO_TARGET']}/lib/corto/" + VERSION + "/" + TARGETPATH

# Special case for when building the core
if TARGET != "corto" and not defined? NOCORTO then
    USE_PACKAGE << "corto"
end

INCLUDE <<
    "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}" <<
    "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/libraries"

task :prebuild do
    verbose(VERBOSE)
    if File.exists?("include") and Dir.glob("include/**/*").length != 0 then
        includePath = "#{ENV['CORTO_TARGET']}/include/corto/#{VERSION}/#{TARGETPATH}"

        # Clear subdirectories of include in target include directory
        Dir.glob("include/**/*/").each do |file|
            sh "rm -rf #{includePath}/#{file.pathmap("%{^include/,}p")}"
        end

        # Clear header files in root include
        sh "rm -f #{includePath}/*.h #{includePath}/.prefix"

        # Copy new header files
        sh "mkdir -p #{includePath}"
        sh "cp -r include/. #{includePath}/"
    end
    if File.exists?("etc") then
        etc = "#{ENV['CORTO_TARGET']}/etc/corto/#{VERSION}/#{TARGETPATH}"
        sh "rm -rf #{etc}"
        sh "mkdir -p #{etc}"
        if File.exists? "etc/everywhere" then
            sh "cp -r etc/everywhere/. #{etc}/"
        end
        platformStr = "etc/" + `uname -s`[0...-1] + "-" + `uname -p`[0...-1]
        if File.exists? platformStr then
            sh "cp -r " + platformStr + "/. #{etc}"
        end
    end
    if ENV['CORTO_TARGET'] != "/usr/local" then
        sh "echo \"`pwd`\" >> source.txt"
        libpath = "#{ENV['CORTO_TARGET']}/lib/corto/#{VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{libpath}"
        sh "mv source.txt #{libpath}/source.txt"
    end
    if File.exists? ".corto/packages.txt" then
        sh "mkdir -p #{libpath}/.corto"
        sh "cp .corto/packages.txt #{libpath}/.corto"
    end
    if File.exists? ".corto/components.txt" then
        sh "mkdir -p #{libpath}/.corto"
        sh "cp .corto/components.txt #{libpath}/.corto"
    end
end

task :collect do
    verbose(VERBOSE)
    if File.exists?("include") then
        includePath = "#{ENV['HOME']}/.corto/pack/include/corto/#{VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{includePath}"
        sh "cp -r include/. #{includePath}/"
    end
    if File.exists?("etc") then
        etc = "#{ENV['HOME']}/.corto/pack/etc/corto/#{VERSION}/#{TARGETPATH}"
        targetEtc = "#{ENV['CORTO_TARGET']}/etc/corto/#{VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{etc}"
        sh "cp -r #{targetEtc}/. #{etc}/"
    end
end

require "#{ENV['CORTO_BUILD']}/artefact"
