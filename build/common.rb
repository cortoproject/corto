require 'rake/clean'

# Set Corto version variable
if ENV['CORTO_VERSION'] then
  CORTO_VERSION ||= ENV['CORTO_VERSION']
else
  CORTO_VERSION ||= `corto --minor`[0...-1]
end

# Set platform variables
CORTO_OS ||= `uname -s`[0...-1]
CORTO_MACHINE ||= `uname -m`[0...-1]
CORTO_PLATFORM ||= CORTO_OS + "-" + CORTO_MACHINE

# Set verbosity
if not defined? VERBOSE then
  if ENV['verbose'] == "true" then
    VERBOSE ||= true
  else
    VERBOSE ||= false
  end
end

# Set covergae
if not defined? COVERAGE then
  if ENV['coverage'] == "false" then
    COVERAGE ||= false
  else
    COVERAGE ||= true
  end
end

# Set colors
if ENV['target'] == "release" then
  C_BOLD = "\033[1;36m"
  C_NAME = "\033[1;49m"
  C_NORMAL = "\033[0;49m"
  C_TARGET = "\033[1;49m"
else
  C_BOLD = "\033[1;49m"
  C_NAME = "\033[1;35m"
  C_NORMAL = "\033[0;49m"
  C_TARGET = "\033[1;34m"
end
C_FAIL = "\033[1;31m"
C_OK = "\033[1;32m"
C_WARNING = "\033[1;33m"

# Initialize public variables
INCLUDE ||= []
LIB ||= []
LIBPATH ||= []
LINK ||= []
CFLAGS ||= []
CXXFLAGS ||= []
LFLAGS ||= []
USE_PACKAGE ||= []
USE_COMPONENT ||= []
USE_LIBRARY ||= []
DEFINE ||= []
PP_PRELOAD ||= []
LANGUAGE ||= "c"

# Variable that tracks files created by the buildsystem for uninstaller
UNINSTALL ||= []

# Set environment variables in local constants
CORTO_TARGET = ENV['CORTO_TARGET']
CORTO_BUILD = ENV['CORTO_BUILD']
CORTO_HOME = ENV['CORTO_HOME']

# Initialize LOCAL
LOCAL ||= false

# Set compiler
CC ||= if ENV['CC'].nil? or ENV['CC'].empty?
  "cc"
else
  ENV['CC']
end
CXX ||= if ENV['CXX'].nil? or ENV['CXX'].empty?
  "g++"
else
  ENV['CXX']
end

# Set default extension
EXT = if LANGUAGE == "c" then
  "c"
else
  "cpp"
end
