if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETDIR = "#{ENV['CORTEX_TARGET']}/bin"
ARTEFACT = "#{TARGET}"
CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

CORTEX_LIB << "cortex"
INCLUDE << "#{ENV['CORTEX_TARGET']}/include/cortex"

require "#{ENV['CORTEX_HOME']}/build/artefact"
