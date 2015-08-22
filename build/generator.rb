if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETPATH = "#{ENV['CORTEX_TARGET']}/generators"

require "#{ENV['CORTEX_HOME']}/build/library"
