
USE_PACKAGE ||= []
LIBPATH ||= []
PP_ATTR = ["app=true"]
INCLUDE ||= []

if not defined? PACKAGE then
    if defined? TARGET then
        PACKAGE = TARGET
    else
        raise "library: PACKAGE not specified\n"
    end
end

INSTALL = "bin/cortobin"
ARTEFACT_PREFIX = ""
ARTEFACT_EXT = ""
ARTEFACT = PACKAGE.split("/").last

task :symlink do
  cmd "ln -fs #{TARGETDIR}/#{ARTEFACT} ./#{ARTEFACT}"
end

if ENV['CORTO_TARGET'] != '/usr/local' then
  task :postbuild => [:symlink]
end

require "#{ENV['CORTO_BUILD']}/package"
