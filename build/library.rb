require "#{ENV['CORTO_BUILD']}/version"
require 'rake/clean'

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

LFLAGS ||= []
CORTO_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"
TARGETPATH ||= "libraries"
TARGETDIR = "#{ENV['CORTO_TARGET']}/lib/corto/" + VERSION + "/" + TARGETPATH

CORTO_LIB << "corto"

INCLUDE << 
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}" << 
	"#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/libraries"

CLEAN.include(TARGETPATH + "/obj")
CLOBBER.include(TARGETPATH)

task :prebuild do
	verbose(false)
	if File.exists?("include") then
		includePath = "#{ENV['CORTO_TARGET']}/include/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end
end

task :collect do
	verbose(false)
	if File.exists?("include") then
		includePath = ENV['HOME'] + "/.corto/pack/include/corto/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end	
end

require "#{ENV['CORTO_BUILD']}/artefact"
