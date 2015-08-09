require 'rake/clean'

PACKAGEDIR = "#{ENV['CORTEX_HOME']}/packages/" + PACKAGE.gsub("::", "/")
TARGETDIR =  PACKAGEDIR + "/bin"
TARGET = PACKAGE.split("::").last

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    ".cortex/#{TARGET}__api.c" <<
    ".cortex/#{TARGET}__wrapper.c" <<
    ".cortex/#{TARGET}__meta.c" <<
    ".cortex/#{TARGET}__load.c" 

PREFIX ||= TARGET

require "#{ENV['CORTEX_HOME']}/build/component"

GENFILE = Rake::FileList["#{TARGET}.*"][0]

CLEAN.include(GENERATED_SOURCES)
CLOBBER.include("include/#{TARGET}__api.h")
CLOBBER.include("include/#{TARGET}__meta.h")
CLOBBER.include("include/#{TARGET}__type.h")
CLOBBER.include("bin")

file "include/#{TARGET}__type.h" => GENFILE do
    verbose(false)
    sh "mkdir -p .cortex"
    sh "touch .cortex/#{TARGET}__wrapper.c"
    sh "cxgen #{TARGET} --prefix #{PREFIX} --lang c"
    if not File.identical?(PACKAGEDIR, Dir.pwd) then
        sh "mkdir -p #{PACKAGEDIR}"
        sh "cp -R include #{PACKAGEDIR}/include"
    end
end

task :prebuild => "include/#{TARGET}__type.h" do
    require "./.cortex/dep"
end

task :clobber do
    if File.exists?(".cortex/dep.rb")
        sh "rake clobber -f .cortex/dep.rb" 
    end
end

require "#{ENV['CORTEX_HOME']}/build/subrake"
