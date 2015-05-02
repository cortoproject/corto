
if not ENV['CORTEX_HOME'] then
    raise "CORTEX_HOME not defined (did you forget to 'source configure'?)"
end

Dir.chdir(File.dirname(Rake.application.rakefile))

if not defined? COMPONENTS then
    raise "COMPONENTS not specified\n"
end

task :default do
    COMPONENTS.each do |e|
        verbose(false)
        sh "echo '\033[1;30m[ >> building \033[1;35m#{e}\033[1;30m ]\033[0;49m'"
        sh "rake -f #{e}/rakefile"
        sh "echo '\033[1;30m[ << leaving \033[1;35m#{e}\033[1;30m ]\033[0;49m'"
    end
end

task :clean do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake clean -f #{e}/rakefile"
    end
end

task :clobber do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake clobber -f #{e}/rakefile"
    end
end
