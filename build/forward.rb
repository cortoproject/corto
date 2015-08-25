
if not ENV['CORTEX_BUILD'] then
    raise "CORTEX_BUILD not defined (did you forget to 'source configure'?)"
end

Dir.chdir(File.dirname(Rake.application.rakefile))

if not defined? COMPONENTS then
    raise "COMPONENTS not specified\n"
end

require "#{ENV['CORTEX_BUILD']}/subrake"
