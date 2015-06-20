
if not ENV['CORTEX_HOME'] then
    raise "CORTEX_HOME not defined (did you forget to 'source configure'?)"
end

Dir.chdir(File.dirname(Rake.application.rakefile))

if not defined? COMPONENTS then
    raise "COMPONENTS not specified\n"
end

require "#{ENV['CORTEX_HOME']}/build/subrake"
