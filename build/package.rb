require 'rake/clean'

PACKAGEDIR = "packages/" + PACKAGE.gsub("::", "/")
TARGETPATH = PACKAGEDIR
TARGET = PACKAGE.split("::").last

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".corto/#{TARGET}__api.c" <<
    ".corto/#{TARGET}__wrapper.c" <<
    ".corto/#{TARGET}__meta.c" <<
    ".corto/#{TARGET}__load.c"

PREFIX ||= TARGET

require "#{ENV['CORTO_BUILD']}/component"

GENFILE = Rake::FileList["#{TARGET}.*"][0]

CLOBBER.include("include/#{TARGET}__api.h")
CLOBBER.include("include/#{TARGET}__meta.h")
CLOBBER.include("include/#{TARGET}__type.h")
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(TARGETDIR)

file "include/#{TARGET}__type.h" => GENFILE do
    verbose(false)
    sh "mkdir -p .corto"
    sh "touch .corto/#{TARGET}__wrapper.c"
    sh "corto pp #{GENFILE} --scope #{PACKAGE} --prefix #{PREFIX} --lang c"
end

task :prebuild => "include/#{TARGET}__type.h" do
    require "./.corto/dep.rb"
end

task :clobber do
    if File.exists?(".corto/dep.rb")
        sh "rake clobber -f .corto/dep.rb" 
    end
end

require "#{ENV['CORTO_BUILD']}/subrake"
