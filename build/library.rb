if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

LFLAGS ||= []
CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"
TARGETDIR ||= "#{ENV['CORTEX_HOME']}/libraries/bin"

CORTEX_LIB << "cortex"
LIBPATH << "#{ENV['CORTEX_HOME']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/core/include"

require "#{ENV['CORTEX_HOME']}/build/artefact"
