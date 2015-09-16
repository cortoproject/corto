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

generate = true
if defined? GENERATED_SOURCES then
    # Don't generate project file if GENERATED_SOURCES is set, which implies that
    # a subclass of component already is taking responsibility for code generation
    # This could've been handled by the rake rules, which could see that, based on
    # timestamps of the __load.c and packages.txt files regeneration is not needed.
    # However, since file timestamps are only accurate up to a second, and tasks
    # are run much faster in sequence (fortunately) the build system is not always
    # capable to correctly derive the rules.
    generate = false
end

GENERATED_SOURCES ||= []
GENERATED_SOURCES <<
    ".corto/#{TARGET}__load.c"

file ".corto/#{TARGET}__load.c" => [".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
    if generate then
        sh "mkdir -p .corto"
        sh "corto pp --name #{TARGET} -g c_project --attr component=true"
    end
end

task :prebuild => ".corto/#{TARGET}__load.c"

require "#{ENV['CORTO_BUILD']}/library"
