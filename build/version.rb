
if ENV['CORTEX_VERSION'] then
	VERSION ||= ENV['CORTEX_VERSION']
else
	VERSION ||= `cortex -v`
end
