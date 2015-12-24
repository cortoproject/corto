require "#{ENV['CORTO_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETDIR = "#{ENV['CORTO_TARGET']}/bin"
ARTEFACT = "#{TARGET}"
USE_LIBRARY ||= []
LIBPATH ||= []
INCLUDE ||= ["include"]

USE_LIBRARY << "corto"
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/packages/corto/lang"


require "#{ENV['CORTO_BUILD']}/artefact"
