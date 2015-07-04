

GENERATED_SOURCES ||= []

GENERATED_SOURCES <<
    "src/y.tab.c" <<
    "src/lex.yy.c"

file "src/lex.yy.c" => ["src/#{LEX}", "src/y.tab.c"] do |task|
    sh "flex -o #{task.name} src/#{LEX}"
end

file "src/y.tab.c" => "src/#{YACC}" do |task|
    sh "yacc -d -v -o #{task.name} src/#{YACC}"
end
