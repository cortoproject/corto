
USE_PACKAGE = [] if not defined? USE_PACKAGE
LIBPATH = [] if not defined? LIBPATH
INCLUDE = [] if not defined? INCLUDE
PP_ATTR = [] if not defined? PP_ATTR

INSTALL = "bin/cortobin"
ARTEFACT_PREFIX = "" if not defined? ARTEFACT_PREFIX
ARTEFACT_EXT = "" if not defined? ARTEFACT_EXT
PP_ATTR << "app=true"

if not defined? PACKAGE then
    if defined? TARGET then
        PACKAGE = TARGET
    else
        raise "library: PACKAGE not specified\n"
    end
end

ARTEFACT = PACKAGE.split("/").last

task :symlink do
  cmd "ln -fs #{TARGETDIR}/#{ARTEFACT} ./#{ARTEFACT}"
end

if ENV['CORTO_TARGET'] != '/usr/local' then
  task :postbuild => [:symlink]
end

require "#{ENV['CORTO_BUILD']}/package"
