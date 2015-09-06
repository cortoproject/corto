COMPONENTS = [] if not defined? COMPONENTS

task :all => :default

task :default do
    COMPONENTS.each do |e|
        verbose(false)
        if ENV['silent'] != "true" then
            sh "echo '\033[1;49m[ >> building \033[1;35m#{e}\033[0;49m\033[1;49m ]\033[0;49m'"
        end
        sh "rake -f #{e}/rakefile"
        if ENV['silent'] != "true" then
            sh "echo '\033[1;49m[ << leaving \033[1;35m#{e}\033[0;49m\033[1;49m ]\033[0;49m'"
        end
    end
end

task :collect do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake collect -f #{e}/rakefile"
    end
end


task :clean do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake clean -f #{e}/rakefile"
        if File.exists? "#{e}/test/rakefile" then
            sh "rake clean -f #{e}/test/rakefile"
        end
    end
end

task :clobber do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake clobber -f #{e}/rakefile"
        if File.exists? "#{e}/test/rakefile" then
            sh "rake clobber -f #{e}/test/rakefile"
        end
    end
end

task :test do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake test -f #{e}/rakefile"
    end
end
