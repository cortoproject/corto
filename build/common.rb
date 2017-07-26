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

CWD = Dir.pwd

def msg(text)
  print "[ #{C_DEFAULT}#{text}#{C_NORMAL} ]\n"
end

def err(text)
  print "[ #{C_FAIL}error #{C_NORMAL}#{text} ]\n"
end

def warn(text)
  print "[ #{C_WARNING}warning #{C_NORMAL}#{text} ]\n"
end


def cmd(command)
  begin
    sh command
  rescue
    err command
    raise
  end
end

def getArtefactName(prefix, name, ext)
  if ext and ext != "" then
    "#{TARGETDIR}/#{prefix}#{name}.#{ext}"
  else
    "#{TARGETDIR}/#{prefix}#{name}"
  end
end

# Set Corto version variable
if ENV['CORTO_VERSION'] then
  CORTO_VERSION = ENV['CORTO_VERSION']
else
  CORTO_VERSION = `corto --minor`.strip
end

# Set platform variables
CORTO_OS = `uname -s`.strip if
CORTO_MACHINE = `uname -m`.strip
CORTO_PLATFORM = CORTO_OS + "-" + CORTO_MACHINE

# Set verbosity
if not defined? VERBOSE then
  if ENV['verbose'] == "true" then
    VERBOSE = true
    ENV['CORTO_VERBOSITY'] = "TRACE"
  elsif not ENV['CORTO_VERBOSITY'] or ENV['CORTO_VERBOSITY'] == "" or ENV['CORTO_VERBOSITY'] == "OK" then
    VERBOSE = false
  else
    VERBOSE = true
  end
end

# Enable debugging of buildsystem (use valgrind on corto commands)
if not defined? DEBUGCMD then
  if ENV['debug'] == "true" then
    DEBUGCMD = "valgrind --track-origins=yes --num-callers=50 "
  else
    DEBUGCMD = ""
  end
end

# Set coverage
if not defined? COVERAGE then
  if ENV['coverage'] == "true" then
    COVERAGE = true
  else
    COVERAGE = false
  end
end

# Set softlinks
if not defined? SOFTLINKS then
  if ENV['softlinks'] == "false" then
    SOFTLINKS = false
  else
    SOFTLINKS = true
  end
end

# Set multithreading
if not defined? MULTITHREAD then
  if ENV['multithread'] == "false" then
    MULTITHREAD = false
  else
    MULTITHREAD = true
  end
end

# Set dryrun
if not defined? DRYRUN then
  if ENV['dryrun'] == "true" then
    DRYRUN = true
  else
    DRYRUN = false
  end
end

# Set config
if not defined? CONFIG then
  if not ENV['config'] or ENV['config'] == "" then
    CONFIG = "debug"
  else
    CONFIG = ENV['config']
  end
end

# Set colors
C_DEFAULT = "\033[0;36m"
C_BOLD = "\033[0;49m\033[1;49m"
C_NORMAL = "\033[0;49m"
C_FAIL = "\033[0;31m"
C_OK = "\033[0;32m"
C_WARNING = "\033[0;33m"
C_HIGHLIGHT = "\033[0;32m\033[1;49m"

# Initialize public variables
INCLUDE = [] if not defined? INCLUDE
LIB = [] if not defined? LIB
LIBPATH = [] if not defined? LIBPATH
LINK = [] if not defined? LINK
CFLAGS = ["-pedantic", "-Wstrict-prototypes"] if not defined? CFLAGS
CXXFLAGS = [] if not defined? CXXFLAGS
LFLAGS = [] if not defined? LFLAGS
LOCAL = false if not defined? LOCAL
USE_PACKAGE = [] if not defined? USE_PACKAGE
DEFINE = [] if not defined? DEFINE
PP_PRELOAD = [] if not defined? PP_PRELOAD
LANGUAGE = "c" if not defined? LANGUAGE
ALWAYS_REBUILD = [] if not defined? ALWAYS_REBUILD
NOAPI = false if not defined? NOAPI
NOCORTO = false if not defined? NOCORTO
TOOL = false if not defined? TOOL
UNINSTALL = []

# Set environment variables in local constants
CORTO_TARGET = ENV['CORTO_TARGET']
CORTO_BUILD = ENV['CORTO_BUILD']
CORTO_HOME = ENV['CORTO_HOME']

# Set compiler
if not defined? CC then
  CC = if ENV['CC'].nil? or ENV['CC'].empty?
    "cc"
  else
    ENV['CC']
  end
end
if not defined? CXX then
  CXX = if ENV['CXX'].nil? or ENV['CXX'].empty?
    "g++"
  else
    ENV['CXX']
  end
end

# Set default extension
EXT = if LANGUAGE == "c" then
  "c"
else
  "cpp"
end

# Set root path
CORTO_BUILDROOT = if ENV['CORTO_BUILDROOT'].nil? or ENV['CORTO_BUILDROOT'].empty?

  # First time rake is called
  if ENV['silent'] != "true" then
    if ENV['show_header'] != "false" then
      print "#{C_BOLD}[ #{C_HIGHLIGHT}corto #{C_BOLD}buildsystem v#{CORTO_VERSION}#{C_NORMAL} ]\n"
    end
    if ENV['binaries'] != "false" then
      msg "install to #{C_BOLD}#{CORTO_TARGET}"
      if ENV['redistr'] != "false" then
        msg "redistr to #{C_BOLD}#{CORTO_TARGET}/redistr/corto/#{CORTO_VERSION}"
      end      
    end

    tool = `which corto`
    if $?.exitstatus == 0 then
      # print "  #{`corto --version`}"
      # print "  tool:    #{tool}\n"
    end
    msg "start from #{C_BOLD}#{Dir.pwd}"
    msg "config #{C_BOLD}#{CONFIG}"
  end

  ENV['CORTO_BUILDROOT'] = Dir.pwd
  Dir.pwd
else
  ENV['CORTO_BUILDROOT']
end

include_ld_path =  "#{ENV['CORTO_TARGET']}/lib"
include_ld_path += ":#{ENV['CORTO_TARGET']}/redistr/corto/#{CORTO_VERSION}/lib"
include_ld_path += ":/usr/local/redistr/corto/#{CORTO_VERSION}/lib"
ENV["LD_LIBRARY_PATH"] = "#{include_ld_path}:#{ENV["LD_LIBRARY_PATH"]}"

# Utility that replaces buildsystem tokens with actual values
def corto_replace(str)
    str = str.gsub("$(CORTO_OS)", CORTO_OS)
    str = str.gsub("$(CORTO_MACHINE)", CORTO_MACHINE)
    str = str.gsub("$(CORTO_PLATFORM)", CORTO_PLATFORM)
    str = str.gsub("$(CORTO_TARGET)", TARGETDIR)
    str = str.gsub("$(CORTO_VERSION)", CORTO_VERSION)
    projectPath = ""
    if defined? PACKAGEDIR then
        projectPath = PACKAGEDIR
    end
    str = str.gsub("$(CORTO_ETC)", ENV['CORTO_TARGET'] + "/etc/corto/#{CORTO_VERSION}/" + projectPath)
    str = str.gsub("$(CORTO_INCLUDE)", ENV['CORTO_TARGET'] + "/include/corto/#{CORTO_VERSION}/" + projectPath)
    str = str.gsub("$(CORTO_LIB)", ENV['CORTO_TARGET'] + "/lib/corto/#{CORTO_VERSION}/" + projectPath)
end

def corto_section(package, section)
    s = ENV["CORTO_TARGET"] + "/#{section}/corto/#{CORTO_VERSION}/#{package}"
    corto_replace(s)
end
