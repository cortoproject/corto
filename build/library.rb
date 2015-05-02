if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

LFLAGS ||= []

ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"

require "#{ENV['CORTEX_HOME']}/build/artefact"