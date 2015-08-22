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
TARGETPATH ||= "#{ENV['CORTEX_TARGET']}/libraries"
TARGETDIR = TARGETPATH + "/lib"

CORTEX_LIB << "cortex"

LIBPATH << "#{ENV['CORTEX_TARGET']}/bin"
INCLUDE << 
	"#{ENV['CORTEX_HOME']}/core/include" << 
	"#{ENV['CORTEX_TARGET']}/libraries/include"

CLEAN.include(TARGETPATH + "/obj")
CLOBBER.include(TARGETPATH)

task :prebuild do
	verbose(false)
	if File.exists?("include") then
		sh "mkdir -p #{TARGETPATH}"
	    sh "cp -R include #{TARGETPATH}/"
	end
end

require "#{ENV['CORTEX_HOME']}/build/artefact"
