
if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

ARTEFACT = TARGET.split("/").last
USE_PACKAGE ||= []
LIBPATH ||= []
PP_ATTR = ["app=true"]
NAME = TARGET
INCLUDE ||= []
PACKAGE = TARGET
INSTALL = "bin/cortobin"
INCLUDE << "include"

task :symlink do
  cmd "ln -fs #{TARGETDIR}/#{ARTEFACT} ./#{ARTEFACT}"
end

if ENV['CORTO_TARGET'] != '/usr/local' then
  task :postbuild => [:symlink]
end

require "#{ENV['CORTO_BUILD']}/package"
