# Copyright (c) 2010-2017 the corto developers
#
# Permission is hereby granted, free of charge, to any person obtaining a copy
# of this software and associated documentation files (the "Software"), to deal
# in the Software without restriction, including without limitation the rights
# to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
# copies of the Software, and to permit persons to whom the Software is
# furnished to do so, subject to the following conditions:
#
# The above copyright notice and this permission notice shall be included in
# all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
# AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
# OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
# THE SOFTWARE.

require "#{ENV['CORTO_BUILD']}/common"

COMPONENTS = [] if not defined? COMPONENTS
COMPONENTS_DONE = []

def forward(dir, task)
  if not COMPONENTS_DONE.include? dir then
    if File.exists? "#{dir}/project.json" then
      begin
        sh "corto rakefile #{dir}"
      rescue
        warn "failed to generate rakefile for '#{dir}'"
      end
    end
    if File.exists? "#{dir}/rakefile" then
      begin
        sh "rake #{task} -f #{dir}/rakefile"
      rescue
        exit(-1)
      end
      COMPONENTS_DONE << dir
    end
  end
end

task :all => :default

task :default do
  verbose(VERBOSE)
  COMPONENTS.each do |e|
    forward(e, "default")
  end
  COMPONENTS_DONE.clear
end

task :collect do
  verbose(VERBOSE)
  COMPONENTS.each do |e|
    forward(e, "collect")
  end
  COMPONENTS_DONE.clear
end

task :clean do
  # Prevent cleaning twice
  if not ARGV.include? "clobber" then
    verbose(VERBOSE)
    COMPONENTS.reverse_each do |e|
      forward(e, "clean")
    end
    forward("test", "clean")
  end
end

task :clobber do
  verbose(VERBOSE)
  COMPONENTS.reverse_each do |e|
    forward(e, "clobber")
  end
  forward("test", "clobber")
  COMPONENTS_DONE.clear
end

task :test do
  if not defined? TEST
    verbose(VERBOSE)
    error = 0
    COMPONENTS.each do |e|
      if File.exists? "#{e}" then
        begin
          forward("#{Dir.pwd}/#{e}", "test")
        rescue
          error = 1
        end
      end
    end
    if File.exists? "test" then
      begin
        forward("#{Dir.pwd}/test", "runtest")
      rescue
        error = 1
      end
    end
    if error != 0 then
      exit(-1)
    end
  end
  COMPONENTS_DONE.clear
end

task :runtest do
  if not defined? TEST
    verbose(VERBOSE)
    error = 0
    COMPONENTS.each do |e|
      if File.exists? e then
        begin
          forward("#{Dir.pwd}/#{e}", "runtest")
        rescue
          error = 1
        end
      end
    end
    if error != 0 then
      exit(-1)
    end
  end
  COMPONENTS_DONE.clear
end

task :gcov do
    COMPONENTS.each do |e|
        verbose(VERBOSE)
        sh "rake gcov -f #{Dir.pwd}/#{e}/rakefile"
    end
    COMPONENTS_DONE.clear
end
