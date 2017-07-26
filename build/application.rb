# Copyright (c) 2010-2017 the corto developers
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

USE_PACKAGE = [] if not defined? USE_PACKAGE
LIBPATH = [] if not defined? LIBPATH
INCLUDE = [] if not defined? INCLUDE
PP_ATTR = [] if not defined? PP_ATTR

INSTALL = "bin/cortobin" if not defined? INSTALL
ARTEFACT_PREFIX = "" if not defined? ARTEFACT_PREFIX
ARTEFACT_EXT = "" if not defined? ARTEFACT_EXT
PP_ATTR << "app=true"
APP = true

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
