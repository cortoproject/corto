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
