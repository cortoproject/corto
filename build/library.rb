require "#{ENV['CORTO_BUILD']}/version"
require 'rake/clean'

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

if not defined? LOCAL then
	LOCAL = false
end

LFLAGS ||= []
CORTO_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

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

CORTO_LIB << "corto"

INCLUDE << 
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}" << 
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/packages/corto/lang" << 
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/libraries"

task :prebuild do
	verbose(false)
	if File.exists?("include") then
		includePath = "#{ENV['CORTO_TARGET']}/include/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end
	if File.exists?("etc") then
		etc = "#{ENV['CORTO_TARGET']}/etc/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{etc}"
	    sh "cp etc/* #{etc}/"
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
	verbose(false)
	if File.exists?("include") then
		includePath = ENV['HOME'] + "/.corto/pack/include/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end	
	if File.exists?("etc") then
		etc = ENV['HOME'] + "/.corto/pack/etc/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{etc}"
	    sh "cp etc/* #{etc}/"
	end	
end

require "#{ENV['CORTO_BUILD']}/artefact"
