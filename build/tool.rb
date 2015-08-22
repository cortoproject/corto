if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = "#{TARGET}"
CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

CORTEX_LIB << "cortex"
LIBPATH << "#{ENV['CORTEX_TARGET']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/core/include"

require "#{ENV['CORTEX_HOME']}/build/artefact"
