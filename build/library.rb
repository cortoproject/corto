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
TARGETDIR = "#{ENV['CORTEX_TARGET']}/lib/cortex/" + TARGETPATH

CORTEX_LIB << "cortex"

INCLUDE << 
	"#{ENV['CORTEX_TARGET']}/include/cortex" << 
	"#{ENV['CORTEX_TARGET']}/include/cortex/libraries"

CLEAN.include(TARGETPATH + "/obj")
CLOBBER.include(TARGETPATH)

task :prebuild do
	verbose(false)
	if File.exists?("include") then
		includePath = "#{ENV['CORTEX_TARGET']}/include/cortex/" + TARGETPATH
		sh "mkdir -p #{includePath}"
	    sh "cp include/* #{includePath}/"
	end
end

require "#{ENV['CORTEX_HOME']}/build/artefact"
