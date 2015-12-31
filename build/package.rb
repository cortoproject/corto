require 'rake/clean'

LOCAL ||= false
INCLUDE ||= []

if LOCAL == true then
    TARGETPATH = "./.corto"
    TARGETDIR = TARGETPATH
    INCLUDE << "include"
else
    PACKAGEDIR = "packages/" + PACKAGE.gsub("::", "/")
    TARGETPATH = PACKAGEDIR
end

TARGET = PACKAGE.split("::").last

PP_PRELOAD ||= []
GENERATED_SOURCES ||= []
DEFINE ||= []
CFLAGS ||= []

DEFINE << "BUILDING_" + PACKAGE.gsub("::", "_").upcase
CFLAGS << "-fvisibility=hidden"

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

PREFIX ||= TARGET
NAME ||= PACKAGE.split("::").last

CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

GENFILE = Rake::FileList["#{NAME}.{cx,idl,xml}"][0]

file ".corto/packages.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/packages.txt"
end

file ".corto/components.txt" do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/components.txt"
end

file "include/_type.h" => [GENFILE, ".corto/packages.txt", ".corto/components.txt"] do
    verbose(false)
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
      puts "\033[1;31mcommand failed: #{command}\033[0;49m"
      sh "rm include/_type.h"
      abort()
    end
end

task :doc do
    verbose(false)
    if `corto locate corto::md` != "corto: package 'corto::md' not found\n" then
        if File.exists? "#{NAME}.md" and not LOCAL then
            command = "corto pp #{NAME}.md --scope #{PACKAGE} -g html"
            begin
                sh command
            rescue
                puts "\033[1;31mcommand failed: #{command}\033[0;49m"
                abort()
            end
        end
    end
end

task :default => ["include/_type.h"]

task :postbuild => [:doc]

if File.exists? "./.corto/dep.rb"
    require "./.corto/dep.rb"
end

require "#{ENV['CORTO_BUILD']}/component"
require "#{ENV['CORTO_BUILD']}/subrake"
