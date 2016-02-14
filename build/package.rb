require "#{ENV['CORTO_BUILD']}/common"

PACKAGE_FWSLASH = PACKAGE.gsub("::", "/")

INCLUDE_PUBLIC ||= [] + INCLUDE
LIB_PUBLIC ||= [] + LIB
LINK_PUBLIC ||= ["."] + LINK
GENERATED_SOURCES ||= []
TARGET = PACKAGE_FWSLASH.split("/").last
DEFINE << "BUILDING_" + PACKAGE_FWSLASH.gsub("/", "_").upcase
PREFIX ||= TARGET
NAME ||= PACKAGE_FWSLASH.split("/").last
ARTEFACT = "lib#{TARGET}.so"
LFLAGS << "--shared"

# Include corto package only when not building the core
if TARGET != "corto" and not defined? NOCORTO then USE_PACKAGE << "corto" end

# Set working directory to where the rakefile is
CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

# Support for local packages (packages that are not installed to environment)
if LOCAL == true then
    TARGETPATH = "./.corto"
    TARGETDIR = TARGETPATH
    INCLUDE << "include"
else
    PACKAGEDIR = PACKAGE_FWSLASH
    TARGETPATH = PACKAGEDIR
    TARGETDIR = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
end

# If this is not a corto package, expose all symbols by default
if not defined? NOCORTO then
    CFLAGS << "-fvisibility=hidden"
end

# Rule for creating packages.txt
file ".corto/packages.txt" do
    verbose(VERBOSE)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

# Code generation
if not defined? NOCORTO then
    DEFFILES = Rake::FileList["#{NAME}.{cx,idl,xml}"]

    if DEFFILES.length != 0 then
        GENFILE = DEFFILES[0]
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
            elsif (`corto locate corto/gen/doc/doc` != "corto: package 'corto/gen/doc/doc' not found\n") then
                docStr = "-g doc/doc"
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
    else
        file "include/#{NAME}.h" => [".corto/packages.txt"] do
            verbose(VERBOSE)
            preload = PP_PRELOAD.join(" ")
            sh "mkdir -p .corto"

            localStr = ""

            if LOCAL then
                localStr = "--attr local=true"
            end

            command =
                "corto pp #{preload} #{localStr} --name #{NAME} " +
                "--attr h=include --attr c=src -g c/project"

            begin
              sh command
            rescue
              STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
              if File.exists? "include/#{NAME}.h" then
                  sh "rm include/#{NAME}.h"
              end
              abort()
            end
        end
        task :prebuild => ["include/#{NAME}.h"]
    end


end

# Document framework integration
task :doc do
    verbose(VERBOSE)
    if `which corto` != "" then
        if `corto locate corto::md` != "corto: package 'corto::md' not found\n" then
            if File.exists? "#{NAME}.md" and not LOCAL then
                command = "corto pp #{NAME}.md --scope #{PACKAGE_FWSLASH} -g doc/html"
                begin
                    sh command
                rescue
                    STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
                    abort
                end
            end
        end
    end
end

# Generate a script with build instructions for this package
task :buildscript do
    verbose(VERBOSE)
    if not LOCAL then
        if INCLUDE_PUBLIC.length or LIB_PUBLIC.length or LINK_PUBLIC.length then
            dir = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{PACKAGEDIR}"
            CLOBBER.include("#{dir}/build.rb")
            FILES << "#{dir}/build.rb"
            sh "mkdir -p #{dir}"
            File.open("#{dir}/build.rb", "w") {|file|
                if INCLUDE_PUBLIC.length != 0 then
                    file.write "INCLUDE"
                    INCLUDE_PUBLIC.each {|i|
                        file.write " << \"#{corto_replace(i)}\""
                    }
                    file.write "\n"
                end

                if LIB_PUBLIC.length != 0 then
                    file.write "LIB"
                    LIB_PUBLIC.each {|i|
                        file.write " << \"#{corto_replace(i)}\""
                    }
                    file.write "\n"
                end

                if LINK_PUBLIC.length != 0 then
                    file.write "LINK"
                    LINK_PUBLIC.each {|i|
                        if i != "." then
                            file.write " << \"#{corto_replace(i)}\""
                        else
                            file.write " << \"#{TARGETDIR}/#{TARGET}\""
                        end
                    }
                    file.write "\n"
                end
            }
        end
    end
end

# dep.rb contains CLOBBER rules for generated header files
if File.exists? "./.corto/dep.rb"
    require "./.corto/dep.rb"
end

# Crawl project directory for files that need to be installed with binary
task :prebuild do
    verbose(VERBOSE)
    if File.exists?("include") and Dir.glob("include/**/*").length != 0 then
        includePath = "#{CORTO_TARGET}/include/corto/#{CORTO_VERSION}/#{TARGETPATH}"

        sh "rm -rf #{includePath}"

        # Copy new header files
        sh "mkdir -p #{includePath}"
        sh "cp -r include/. #{includePath}/"
    end
    if File.exists?("etc") then
        etc = "#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
        sh "rm -rf #{etc}"
        sh "mkdir -p #{etc}"
        if File.exists? "etc/everywhere" then
            sh "cp -r etc/everywhere/. #{etc}/"
        end
        platformStr = "etc/" + CORTO_PLATFORM
        if File.exists? platformStr then
            sh "cp -r " + platformStr + "/. #{etc}"
        end
    end
    if File.exists?("install") then
        platformStr = "install/" + CORTO_PLATFORM
        if File.exists? platformStr then
            install = "#{CORTO_TARGET}"
            sh "cp -r " + platformStr + "/. #{install}"
        end
    end
    if ENV['CORTO_TARGET'] != "/usr/local" then
        # Using this file, corto can auto-rebuild the package when changes in
        # package files are made while a running application is using it.
        sh "echo \"`pwd`\" >> source.txt"
        libpath = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{libpath}"
        sh "mv source.txt #{libpath}/source.txt"
    end
    if File.exists? ".corto/packages.txt" then
        sh "mkdir -p #{libpath}/.corto"
        sh "cp .corto/packages.txt #{libpath}/.corto"
    end
end

# Collect files in preparation for creating a tar
task :collect do
    verbose(VERBOSE)
    if File.exists?("include") then
        includePath = "#{ENV['HOME']}/.corto/pack/include/corto/#{CORTO_VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{includePath}"
        sh "cp -r include/. #{includePath}/"
    end
    if File.exists?("etc") then
        etc = "#{ENV['HOME']}/.corto/pack/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
        targetEtc = "#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
        sh "mkdir -p #{etc}"
        sh "cp -r #{targetEtc}/. #{etc}/"
    end
end

# Generate markdown file & buildscript after build
task :postbuild => [:doc, :buildscript]

require "#{CORTO_BUILD}/artefact"
require "#{CORTO_BUILD}/subrake"
