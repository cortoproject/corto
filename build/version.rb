
if ENV['CORTO_VERSION'] then
	VERSION ||= ENV['CORTO_VERSION']
else
	VERSION ||= `corto --minor`[0...-1]
end
