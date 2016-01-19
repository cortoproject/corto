require "#{ENV['CORTO_BUILD']}/version"

if not defined? VERBOSE then
    if ENV['verbose'] == "true" then
        VERBOSE ||= true
    else
        VERBOSE ||= false
    end
end

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

if not defined? NOCORTO then
    GENERATED_SOURCES ||= [".corto/_load.c"]
    GENERATED_HEADERS ||= ["include/_interface.h"]

    file ".corto/_load.c" => [".corto/packages.txt", ".corto/components.txt"] do
        verbose(VERBOSE)
        if generate then
            sh "mkdir -p .corto"
            command = "corto pp --name #{TARGET} -g c_project --attr h=include --attr component=true"
            begin
                sh command
            rescue
                puts "\033[1;31mcommand failed: #{command}\033[0;49m"
                abort()
            end
        end
    end
    task :prebuild => ".corto/_load.c"
end

require "#{ENV['CORTO_BUILD']}/library"
