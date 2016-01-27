
if not ENV['CORTO_BUILD'] then
    raise "CORTO_BUILD not defined (did you forget to 'source configure'?)"
end

if not defined? VERBOSE then
    if ENV['verbose'] == "true" then
        VERBOSE ||= true
    else
        VERBOSE ||= false
    end
end

Dir.chdir(File.dirname(Rake.application.rakefile))

if not defined? COMPONENTS then
    raise "COMPONENTS not specified\n"
end

require "#{ENV['CORTO_BUILD']}/subrake"
