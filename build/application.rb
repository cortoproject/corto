
if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = TARGET.split("/").last
USE_PACKAGE ||= []
LIBPATH ||= []
LOCAL = true
PP_ATTR = ["app=true"]
NAME = TARGET
INCLUDE ||= []
PACKAGE = TARGET

INCLUDE << "include"

require "#{ENV['CORTO_BUILD']}/package"
