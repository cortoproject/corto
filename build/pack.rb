require "#{ENV['CORTO_BUILD']}/common"

task :pack do
    Version = ENV["CORTO_VERSION"]
    Temporary = "#{ENV['HOME']}/.corto#{Version}-pack-temp"
    Prefix = "#{ENV['HOME']}/.corto"
    # bin
    sh "rm -rf #{Temporary}"
    sh "mkdir -p #{Temporary}/bin"
    sh "cp #{Prefix}/bin/corto #{Temporary}/bin/corto"
    sh "cp #{Prefix}/lib/libcorto.so #{Temporary}/bin/libcorto.so"
    # lib
    sh "mkdir #{Temporary}/lib"
    sh "cp -R #{Prefix}/lib/corto/#{Version}/ #{Temporary}/lib"
    sh "find #{Temporary}/lib -name obj -type d -exec rm -rf \"{}\" \\+"
    # include
    sh "mkdir #{Temporary}/include"
    # repeat as above
end
