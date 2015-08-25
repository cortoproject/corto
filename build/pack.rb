
require 'rake/clean'


task :pack do
    Version = ENV["CORTEX_VERSION"]
    Temporary = "#{ENV['HOME']}/.cortex#{Version}-pack-temp"
    Prefix = "#{ENV['HOME']}/.cortex"
    # bin
    sh "rm -rf #{Temporary}"
    sh "mkdir -p #{Temporary}/bin"
    sh "cp #{Prefix}/bin/cortex #{Temporary}/bin/cortex"
    sh "cp #{Prefix}/lib/libcortex.so #{Temporary}/bin/libcortex.so"
    # lib
    sh "mkdir #{Temporary}/lib"
    sh "cp -R #{Prefix}/lib/cortex/#{Version}/ #{Temporary}/lib"
    sh "find #{Temporary}/lib -name obj -type d -exec rm -rf \"{}\" \\+"
    # include
    sh "mkdir #{Temporary}/include"
    # repeat as above
end
