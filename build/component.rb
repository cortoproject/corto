require "#{ENV['CORTEX_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

INCLUDE ||= []

TARGETPATH ||= "components"
INCLUDE << "#{ENV['CORTEX_HOME']}/include/cortex/#{VERSION}/components"

require "#{ENV['CORTEX_BUILD']}/library"
