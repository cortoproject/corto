require "#{ENV['CORTEX_BUILD']}/version"
require 'rake/clean'

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

LFLAGS ||= []
CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"
TARGETPATH ||= "libraries"
TARGETDIR = "#{ENV['CORTEX_TARGET']}/lib/cortex/" + VERSION + "/" + TARGETPATH

CORTEX_LIB << "cortex"

INCLUDE << 
	"#{ENV['CORTEX_HOME']}/include/cortex/#{VERSION}" << 
	"#{ENV['CORTEX_HOME']}/include/cortex/#{VERSION}/libraries"

CLEAN.include(TARGETPATH + "/obj")
CLOBBER.include(TARGETPATH)

task :prebuild do
	verbose(false)
	if File.exists?("include") then
		includePath = "#{ENV['CORTEX_TARGET']}/include/cortex/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end
end

task :collect do
	verbose(false)
	if File.exists?("include") then
		includePath = ENV['HOME'] + "/.cortex/pack/include/cortex/#{VERSION}/#{TARGETPATH}"
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end	
end

require "#{ENV['CORTEX_BUILD']}/artefact"
