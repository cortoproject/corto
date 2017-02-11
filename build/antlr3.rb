require "#{ENV['CORTO_BUILD']}/common"

ANTLR3_BINARY  = "antlr-3.4-complete-no-antlrv2.jar"
ANTLR3_ETC = "#{ENV["CORTO_TARGET"]}/etc/corto/#{ENV["CORTO_VERSION"]}/antlr3"
ANTLR3_JAR = "#{ANTLR3_ETC}/#{ANTLR3_BINARY}"
ENV["CLASSPATH"] = "#{ANTLR3_JAR}:#{ENV['CLASSPATH']}"

GENERATED_SOURCES = [] if not defined? GENERATED_SOURCES
GENERATED_SOURCES << "src/#{ANTLR3}Parser.c"

file "src/#{ANTLR3}Parser.c" => "src/#{ANTLR3}.g" do |task|
  msg "preprocess #{C_NORMAL}src/#{ANTLR3}.g"
  sh "java org.antlr.Tool src/#{ANTLR3}.g"
end
