require "#{ENV['CORTO_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

INCLUDE ||= []

TARGETPATH ||= "components"
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/components"

require "#{ENV['CORTO_BUILD']}/library"
