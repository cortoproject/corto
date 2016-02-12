require "#{ENV['CORTO_BUILD']}/common"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETDIR = "#{ENV['CORTO_TARGET']}/bin"
ARTEFACT = "#{TARGET}"

USE_PACKAGE << "corto"

require "#{ENV['CORTO_BUILD']}/artefact"
