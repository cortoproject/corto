COMPONENTS = [] if not defined? COMPONENTS

if not defined? VERBOSE then
    if ENV['verbose'] == "true" then
        VERBOSE ||= true
    else
        VERBOSE ||= false
    end
end

task :all => :default

task :default do
    if ENV['target'] == "release" then
      c_bold = "\033[1;36m"
      c_name = "\033[1;49m"
      c_normal = "\033[0;49m"
    else
      c_bold = "\033[1;49m"
      c_name = "\033[1;35m"
      c_normal = "\033[0;49m"
    end
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        if ENV['silent'] != "true" then
            sh "echo '#{c_bold}[ >> building #{c_normal}#{c_name}#{e}#{c_normal}#{c_bold} ]#{c_normal}'"
        end
        sh "rake -f #{e}/rakefile"
        if ENV['silent'] != "true" then
            sh "echo '#{c_bold}[ << leaving #{c_normal}#{c_name}#{e}#{c_normal}#{c_bold} ]#{c_normal}'"
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
        verbose(VERBOSE)
        sh "rake clean -f #{e}/rakefile"
        if File.exists? "#{e}/test/rakefile" then
            sh "rake clean -f #{e}/test/rakefile"
        end
    end
end

task :clobber do
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        sh "rake clobber -f #{e}/rakefile"
        if File.exists? "#{e}/test/rakefile" then
            sh "rake clobber -f #{e}/test/rakefile"
        end
    end
end

task :test do
    error = 0
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        begin
          sh "rake test -f #{e}/rakefile"
        rescue
          error = 1
        end
    end
    if error != 0 then
      abort()
    end
end
