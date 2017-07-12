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
require 'rake/clean'

ANTLR3_BINARY  = "antlr-3.4-complete-no-antlrv2.jar"
ANTLR3_ETC = "#{ENV["CORTO_TARGET"]}/etc/corto/#{ENV["CORTO_VERSION"]}/antlr3"
ANTLR3_JAR = "#{ANTLR3_ETC}/#{ANTLR3_BINARY}"
ENV["CLASSPATH"] = "#{ANTLR3_JAR}:#{ENV['CLASSPATH']}"

GENERATED_SOURCES = [] if not defined? GENERATED_SOURCES
GENERATED_SOURCES << "src/#{ANTLR3}Parser.c"

INCLUDE << "#{ENV['CORTO_TARGET']}/include/corto/#{CORTO_VERSION}/antlr3"
LIB << "antlr3c"

file "src/#{ANTLR3}Parser.c" => "src/#{ANTLR3}.g" do |task|
  msg "preprocess #{C_NORMAL}src/#{ANTLR3}.g"
  sh "java org.antlr.Tool src/#{ANTLR3}.g"
end

CLEAN.include("src/#{ANTLR3}Parser.c")
CLEAN.include("src/#{ANTLR3}Parser.h")
CLEAN.include("src/#{ANTLR3}Lexer.c")
CLEAN.include("src/#{ANTLR3}Lexer.h")
