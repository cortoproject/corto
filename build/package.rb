require 'rake/clean'

PACKAGEDIR = "packages/" + PACKAGE.gsub("::", "/")
TARGETPATH = PACKAGEDIR
TARGET = PACKAGE.split("::").last

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".cortex/#{TARGET}__api.c" <<
    ".cortex/#{TARGET}__wrapper.c" <<
    ".cortex/#{TARGET}__meta.c" <<
    ".cortex/#{TARGET}__load.c"

PREFIX ||= TARGET

require "#{ENV['CORTEX_BUILD']}/component"

GENFILE = Rake::FileList["#{TARGET}.*"][0]

CLOBBER.include("include/#{TARGET}__api.h")
CLOBBER.include("include/#{TARGET}__meta.h")
CLOBBER.include("include/#{TARGET}__type.h")
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(TARGETDIR)

file "include/#{TARGET}__type.h" => GENFILE do
    verbose(false)
    sh "mkdir -p .cortex"
    sh "touch .cortex/#{TARGET}__wrapper.c"
    sh "cortex pp #{GENFILE} --scope #{PACKAGE} --prefix #{PREFIX} --lang c"
end

task :prebuild => "include/#{TARGET}__type.h" do
    require "./.cortex/dep"
end

task :clobber do
    if File.exists?(".cortex/dep.rb")
        sh "rake clobber -f .cortex/dep.rb" 
    end
end

require "#{ENV['CORTEX_BUILD']}/subrake"
