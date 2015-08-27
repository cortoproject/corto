if not defined? TARGET then
    raise "library: TARGET not specified\n"
end

TARGETPATH = "generators"

require "#{ENV['CORTO_BUILD']}/library"
