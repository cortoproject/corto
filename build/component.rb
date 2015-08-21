
if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

CORTEX_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

CORTEX_LIB << "cortex"
LIBPATH << "#{ENV['CORTEX_HOME']}/bin"
INCLUDE << "#{ENV['CORTEX_HOME']}/core/include"
TARGETDIR ||= "#{ENV['CORTEX_HOME']}/components/bin"

require "#{ENV['CORTEX_HOME']}/build/library"
