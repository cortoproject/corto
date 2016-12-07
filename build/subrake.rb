require "#{ENV['CORTO_BUILD']}/common"

COMPONENTS = [] if not defined? COMPONENTS

task :all => :default

task :default do
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        sh "rake -f #{e}/rakefile"
    end
end

task :collect do
    COMPONENTS.each do |e|
        verbose(false)
        sh "rake collect -f #{Dir.pwd}/#{e}/rakefile"
    end
end

task :clean do
  COMPONENTS.each do |e|
      verbose(VERBOSE)
      sh "rake clean -f #{e}/rakefile"
      if File.exists? "#{e}/test/rakefile" then
          sh "rake clean -f #{Dir.pwd}/#{e}/test/rakefile"
      end
  end
end

task :clobber do
  COMPONENTS.each do |e|
      verbose(VERBOSE)
      sh "rake clobber -f #{e}/rakefile"
      if File.exists? "#{e}/test/rakefile" then
          sh "rake clobber -f #{Dir.pwd}/#{e}/test/rakefile"
      end
  end
end

task :test do
  if not defined? TEST
    verbose(VERBOSE)
    error = 0
    COMPONENTS.each do |e|
      if File.exists? "#{e}" then
        begin
          sh "rake test -f #{Dir.pwd}/#{e}/rakefile"
        rescue
          error = 1
        end
      end
    end
    if File.exists? "test" then
      begin
        sh "rake runtest -f #{Dir.pwd}/test/rakefile"
      rescue
        error = 1
      end
    end
    if error != 0 then
      abort
    end
  end
end

task :runtest do
  if not defined? TEST
    verbose(VERBOSE)
    error = 0
    COMPONENTS.each do |e|
      if File.exists? "#{e}" then
        begin
          sh "rake runtest -f #{Dir.pwd}/#{e}/rakefile"
        rescue
          error = 1
        end
      end
    end
    if error != 0 then
      abort
    end
  end
end

task :gcov do
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        if ENV['silent'] != "true" then
            sh "echo '#{C_BOLD}[ >> entering #{C_NORMAL}#{C_NAME}#{e}#{C_NORMAL}#{C_BOLD} ]#{C_NORMAL}'"
        end
        sh "rake gcov -f #{Dir.pwd}/#{e}/rakefile"
        if ENV['silent'] != "true" then
            sh "echo '#{C_BOLD}[ << leaving #{C_NORMAL}#{C_NAME}#{e}#{C_NORMAL}#{C_BOLD} ]#{C_NORMAL}'"
        end
    end
end
