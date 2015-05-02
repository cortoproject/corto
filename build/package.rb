require 'rake/clean'

GENERATED_SOURCES = [] <<
    "src/#{TARGET}__api.c" <<
    "src/#{TARGET}__wrapper.c" <<
    "src/#{TARGET}__meta.c" <<
    "src/#{TARGET}__load.c"

TARGETDIR = "./bin"

require "#{ENV['CORTEX_HOME']}/build/component"

GENFILE = Rake::FileList["#{TARGET}.*"][0]

CLEAN.include(GENERATED_SOURCES)
CLEAN.include("include/#{TARGET}__api.h")
CLEAN.include("include/#{TARGET}__meta.h")
CLEAN.include("include/#{TARGET}__type.h")
CLOBBER.include("bin")

file "include/#{TARGET}__type.h" => GENFILE do
    verbose(true)
    sh "cxgen #{TARGET} --lang c"
end

task :generate => "include/#{TARGET}__type.h" do
    require "./dep"
end

task :clobber do
    if File.exists?("dep.rb")
        sh "rake clobber -f dep.rb" 
    end
end
