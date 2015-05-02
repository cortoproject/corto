if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

INCLUDE ||= []
CORTEX_LIB ||= []
CFLAGS ||= []
LIBPATH ||= []

TARGETDIR = "#{ENV['CORTEX_HOME']}/generator/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/dev/include"
CORTEX_LIB << "cortex" << "cortexdev"
LIBPATH << "#{ENV['CORTEX_HOME']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/cx/include"
CFLAGS << "--shared"
ARTEFACT = TARGET

require "#{ENV['CORTEX_HOME']}/build/artefact"