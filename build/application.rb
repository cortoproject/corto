


if not defined? TARGET then
    if defined? PACKAGE then
        TARGET = PACKAGE
    else
        raise "library: TARGET not specified\n"
    end
end

ARTEFACT = TARGET.split("/").last
USE_PACKAGE ||= []
LIBPATH ||= []
PP_ATTR = ["app=true"]
NAME = TARGET
INCLUDE ||= []

if not defined? PACKAGE then
    PACKAGE = TARGET
end

INSTALL = "bin/cortobin"
INCLUDE << "include"
ARTEFACT_PREFIX = ""
ARTEFACT_EXT = ""

task :symlink do
  cmd "ln -fs #{TARGETDIR}/#{ARTEFACT} ./#{ARTEFACT}"
end

if ENV['CORTO_TARGET'] != '/usr/local' then
  task :postbuild => [:symlink]
end

require "#{ENV['CORTO_BUILD']}/package"
