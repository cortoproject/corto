require "#{ENV['CORTO_BUILD']}/common"

PACKAGE_FWSLASH = PACKAGE.gsub("::", "/")

if LOCAL == true then
    TARGETPATH = "./.corto"
    TARGETDIR = TARGETPATH
    INCLUDE << "include"
else
    PACKAGEDIR = "packages/" + PACKAGE_FWSLASH
    TARGETPATH = PACKAGEDIR
end

TARGET = PACKAGE_FWSLASH.split("/").last

GENERATED_SOURCES ||= []

INCLUDE_PUBLIC ||= [] + INCLUDE
LIB_PUBLIC ||= ["."] + LIB
LIBPATH_PUBLIC ||= [] + LIBPATH

DEFINE << "BUILDING_" + PACKAGE_FWSLASH.gsub("/", "_").upcase

# If this is not a corto package, expose all symbols by default
if not defined? NOCORTO then
    CFLAGS << "-fvisibility=hidden"
end

PREFIX ||= TARGET
NAME ||= PACKAGE_FWSLASH.split("/").last

CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

GENFILE = Rake::FileList["#{NAME}.{cx,idl,xml}"][0]

file ".corto/packages.txt" do
    verbose(VERBOSE)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

if not defined? NOCORTO then
    GENERATED_SOURCES <<
        ".corto/_api.c" <<
        ".corto/_wrapper.c" <<
        ".corto/_meta.c" <<
        ".corto/_load.c"

    GENERATED_HEADERS ||= [] <<
        "include/_api.h" <<
        "include/_meta.h" <<
        "include/_type.h" <<
        "include/_interface.h"

    file "include/_type.h" => [GENFILE, ".corto/packages.txt"] do
        verbose(VERBOSE)
        preload = PP_PRELOAD.join(" ")
        sh "mkdir -p .corto"
        sh "touch .corto/_wrapper.c"

        localStr = ""
        docStr = ""

        if LOCAL then
            localStr = "--attr local=true"
        elsif (`corto locate doc --generator` != "corto: generator 'doc' not found\n") then
            docStr = "-g doc"
        end

        command = "corto pp #{preload} #{GENFILE} --scope #{PACKAGE} " +
                  "--prefix #{PREFIX} #{localStr} #{docStr} --lang c"

        begin
          sh command
        rescue
          STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
          if File.exists? "include/_type.h" then
              sh "rm include/_type.h"
          end
          abort()
        end
    end

    task :prebuild => ["include/_type.h"]
end

task :doc do
    verbose(VERBOSE)
    if `corto locate corto::md` != "corto: package 'corto::md' not found\n" then
        if File.exists? "#{NAME}.md" and not LOCAL then
            command = "corto pp #{NAME}.md --scope #{PACKAGE_FWSLASH} -g html"
            begin
                sh command
            rescue
                STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
                abort()
            end
        end
    end
end

task :postbuild => [:doc]

if File.exists? "./.corto/dep.rb"
    require "./.corto/dep.rb"
end

require "#{ENV['CORTO_BUILD']}/library"
require "#{ENV['CORTO_BUILD']}/subrake"
