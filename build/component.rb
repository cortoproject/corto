require "#{ENV['CORTO_BUILD']}/version"

if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

if not defined? LOCAL then
	LOCAL = false
end

if LOCAL == true then
	if not defined? TARGETPATH then
	    TARGETPATH ||= "./.corto"
	    TARGETDIR ||= TARGETPATH
	end
else
    TARGETPATH ||= "components"
end

INCLUDE ||= []
INCLUDE << "#{ENV['CORTO_HOME']}/include/corto/#{VERSION}/components"

GENERATED_SOURCES ||= []
GENERATED_SOURCES <<
    ".corto/#{TARGET}__load.c"

file ".corto/#{TARGET}__load.c" => [".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    sh "mkdir -p .corto"
    sh "corto pp --name #{TARGET} -g c_project --attr component=true"
end

task :prebuild => ".corto/#{TARGET}__load.c"

require "#{ENV['CORTO_BUILD']}/library"
