
if not ENV['CORTEX_HOME'] then
    raise "CORTEX_HOME not defined (did you forget to 'source configure'?)"
end

Dir.chdir(File.dirname(Rake.application.rakefile))

require "#{ENV['CORTEX_HOME']}/build/subrake"
