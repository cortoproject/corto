require "#{ENV['CORTO_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETDIR = "#{ENV['CORTO_TARGET']}/bin"
ARTEFACT = "#{TARGET}"
CORTO_LIB ||= []
LIBPATH ||= []
INCLUDE ||= []

CORTO_LIB << "corto"
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}"

require "#{ENV['CORTO_BUILD']}/artefact"
