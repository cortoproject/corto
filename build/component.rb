
if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

LIBPATH ||= []
INCLUDE ||= []

TARGETPATH ||= "#{ENV['CORTEX_TARGET']}/components"
INCLUDE << "#{ENV['CORTEX_TARGET']}/components/include"

require "#{ENV['CORTEX_HOME']}/build/library"
