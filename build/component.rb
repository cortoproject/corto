require "#{ENV['CORTEX_HOME']}/build/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

INCLUDE ||= []

TARGETPATH ||= "components"
INCLUDE << "#{ENV['CORTEX_TARGET']}/include/cortex/#{VERSION}/components"

require "#{ENV['CORTEX_HOME']}/build/library"
