require "#{ENV['CORTO_BUILD']}/common"
require "#{ENV['CORTO_BUILD']}/libmapping"
require 'rake/clean'
require 'pathname'

CHDIR_SET = false if not defined? CHDIR_SET
if !CHDIR_SET then
  Dir.chdir(File.dirname(Rake.application.rakefile))
end

if not ENV['CORTO_BUILD'] then
  raise "CORTO_BUILD not defined (did you forget to 'source configure'?)"
end
if not defined? ARTEFACT then
  raise "artefact: ARTEFACT not specified\n"
end

# Private variables
TARGETDIR = ENV['CORTO_TARGET'] + "/lib" if not defined? TARGETDIR
GENERATED_SOURCES = [] if not defined? GENERATED_SOURCES
GENERATED_HEADERS = [] if not defined? GENERATED_HEADERS
USE_PACKAGE_LOADED = [] if not defined? USE_PACKAGE_LOADED

# Variable that indicates whether dependencies for redistributable librares are
# resolved
$redis_dependencies_resolved = true

ARTEFACT_NAME = getArtefactName(ARTEFACT_PREFIX, ARTEFACT, ARTEFACT_EXT)

# Add lib path for builds that don't install to global environment
if ENV['CORTO_TARGET'] != "/usr/local" then
  LIBPATH << "#{ENV['CORTO_TARGET']}/lib"
end

# Add default include paths
INCLUDE <<
  "src" <<
  "." <<
  "#{ENV['CORTO_TARGET']}/include/corto/#{CORTO_VERSION}" <<
  "#{ENV['CORTO_HOME']}/include/corto/#{CORTO_VERSION}" <<
  "/usr/local/include/corto/#{CORTO_VERSION}"

# Default CFLAGS
CFLAGS << "-std=c99" << "-fPIC" << "-D_XOPEN_SOURCE=600"
CFLAGS.unshift("-Wall")

# Default CXXFLAGS
CXXFLAGS << "-Wall" << "-std=c++0x" << "-fPIC" << "-Wno-write-strings"

# Set default compiler
if LANGUAGE == "c" then
  COMPILER = CC
elsif LANGUAGE == "c4cpp" then
  COMPILER = CXX
elsif LANGUAGE == "cpp" then
  COMPILER = CXX
elsif LANGUAGE == "c++" then
  COMPILER = CXX
else
  abort "\033[1;31m[ language #{LANGUAGE} unsupported ]\033[0;49m"
end

# Set NDEBUG macro in release builds to disable tracing & checking
# Also enable optimizations
if CONFIG == "release" then
  CFLAGS << "-DNDEBUG" << "-O3"
  CXXFLAGS << "-DNDEBUG" << "-O3"
end

# Enable debug info, coverage and disable optimizations in debug
if CONFIG == "debug" then
  CFLAGS << "-g" << "-O0"
  CXXFLAGS << "-g" << "-O0"

  if COVERAGE == true then
    CFLAGS << "-fprofile-arcs" << "-ftest-coverage"
    CXXFLAGS << "-fprofile-arcs" << "-ftest-coverage"
    LFLAGS << "-fprofile-arcs" << "-ftest-coverage"
  end
end

# Crawl src directory to get list of source files
SOURCES = Rake::FileList["src/**/*.{c,cpp}"] - ALWAYS_REBUILD
OBJECTS = SOURCES.
          ext(".o").
          pathmap(".corto/%{^src/,obj/#{CORTO_PLATFORM}/}p") +
        Rake::FileList[GENERATED_SOURCES].
          ext(".o").
          pathmap(".corto/obj/#{CORTO_PLATFORM}/%f")

# Load packages from file
if File.exists? ".corto/packages.txt" then
  verbose(false)
  f = File.open(".corto/packages.txt")
  f.each_line do |l|
    p = l.strip
    USE_PACKAGE_LOADED.push p
    USE_PACKAGE.push p
  end
end

# Setup default clean & clobber rules
CLEAN.include(".corto/obj/#{CORTO_PLATFORM}")
CLEAN.include("doc")
if NOCORTO == false
  CLEAN.include("c")
end
CLEAN.include("*.gcov")
CLOBBER.include(".corto/obj")
CLOBBER.include(".corto/*.c")
if ARTEFACT_EXT and not ARTEFACT_EXT == "" then
  CLOBBER.include("./#{ARTEFACT_PREFIX}#{ARTEFACT}.#{ARTEFACT_EXT}")
  CLOBBER.include(TARGETDIR + "/" + "#{ARTEFACT_PREFIX}#{ARTEFACT}.#{ARTEFACT_EXT}")
else
  CLOBBER.include("./#{ARTEFACT_PREFIX}#{ARTEFACT}")
  CLOBBER.include(TARGETDIR + "/" + "#{ARTEFACT_PREFIX}#{ARTEFACT}")
end
CLOBBER.include(TARGETDIR + "/" + "#{ARTEFACT_PREFIX}#{ARTEFACT}.a")
CLOBBER.include(GENERATED_SOURCES)
CLOBBER.include(GENERATED_HEADERS)

if TARGET != "corto" then
  CLOBBER.include("include/_load.h")
  CLOBBER.include("include/_interface.h")
  CLOBBER.include("include/_project.h")
  CLOBBER.include("include/_api.h")
end

if File.exists? "project.json"
  CLOBBER.include("rakefile")
end

# If packages.txt is empty, clobber it
if USE_PACKAGE_LOADED.length == 0 then
  CLOBBER.include(".corto/packages.txt")
end

# --- BUILD RULES

# Task that collects all artefacts from the build and store them in a 'pack'
# folder, where they can be tarred for redistribution.
task :collect do
  verbose(VERBOSE)
  artefact = "#{TARGETDIR}/#{ARTEFACT}"
  target = ENV['HOME'] + "/.corto/pack" + artefact["#{ENV['CORTO_TARGET']}".length..artefact.length]
  targetDir = target.split("/")[0...-1].join("/")
  cmd "mkdir -p #{targetDir}"
  cmd "cp #{artefact} #{target}"

  if File.exists? "#{TARGETDIR}/build.cmd" then
    cmd "cp #{TARGETDIR}/build.cmd #{targetDir}/build.cmd"
  end
end

# Rule to automatically create packages.txt
file ".corto/packages.txt" do
  verbose(VERBOSE)
  cmd "mkdir -p .corto"
  cmd "touch .corto/packages.txt"
end

task :binary => ARTEFACT_NAME do
  UNINSTALL << TARGETDIR
end

def relative_path(from, to)
  from = Pathname.new from
  to = Pathname.new to
  begin
    to.relative_path_from from
  rescue
    to
  end
end

def package_from_path(directory, repo)
  package = nil
  env = ENV['CORTO_TARGET'] + repo + ENV['CORTO_VERSION']
  if directory[0..env.length - 1] == env then
    package = relative_path(env, directory)
  else
    env = "/usr/local" + repo + ENV['CORTO_VERSION']
    if directory[0..env.length - 1] == env then
      package = relative_path(env, directory)
    end
  end
  return package
end

def get_library_name(hardcodedPaths, link, directory, basename, prefix, ext)
  if directory != "." then
    directory = directory + "/"
  end
  if ext != "" then
    ext = "." + ext
  end

  if not hardcodedPaths then
    artefact = ""
    package = package_from_path(directory, "/lib/corto/")
    if not package then
      package = package_from_path(directory, "/bin/cortobin/")
      if package then
        artefact = "bin"
      end
    else
      artefact = "lib"
    end
    if package then
      basename = package.to_s.gsub("/", "_")
    end
    if link then
      directory = "-l"
      prefix = ""
      ext = ""
    else
      directory = ENV['CORTO_TARGET'] + "/redistr/corto/" + ENV['CORTO_VERSION'] + "/" + artefact + "/"
      sh "mkdir -p #{directory}"
    end
  end
  directory + prefix + basename + ext
end

def get_artefact_name(hardcodedPaths)
  result = get_library_name(hardcodedPaths, FALSE, TARGETDIR, ARTEFACT, ARTEFACT_PREFIX, ARTEFACT_EXT)
end

# Build artefact
def build_target(hardcodedPaths)
  verbose(VERBOSE)

  artefact = get_artefact_name(hardcodedPaths)

  if not File.exists? TARGETDIR then
    cmd "mkdir -p #{TARGETDIR}"
  end

  # Create list of files that are going to be linked with. Abstract away from the
  # difference between dll, so and dylib. When a dylib is encountered, perform  a
  # bit of magic to ensure that the executable can find the shared object.
  linked = LINK.map do |l|
    l = corto_replace(l)
    lib = get_library_name(hardcodedPaths, TRUE, File.dirname(l), File.basename(l), "lib", "so")
    if hardcodedPaths and (not File.exists? lib) and (CORTO_OS == "Darwin") then
      lib = get_library_name(hardcodedPaths, TRUE, File.dirname(l), File.basename(l), "lib", "dylib")
      if (not File.exists? lib) then
        abort "\033[1;31mcorto:\033[0;49m #{l} not found"
      end
    end
    lib
  end

  # If not using hardcoded paths, copy libraries that project specified in LINK
  # to redistributable directory
  if not hardcodedPaths and defined? LINK_NO_DEPS then
    LINK_NO_DEPS.each do |l|
      l = corto_replace(l)
      so = File.dirname(l) + "/lib" + File.basename(l) + ".so"
      targetDir = ENV['CORTO_TARGET'] + "/redistr/corto/" + ENV['CORTO_VERSION'] + "/lib"
      targetSo = targetDir + "/lib" + File.basename(l) + ".so"
      if File.exists? so and not File.exists? targetSo then
        sh "cp #{so} #{targetDir}"
      else
        so = File.dirname(l) + "/lib" + File.basename(l) + ".dylib"
        if File.exists? so then
          sh "cp #{so} #{targetDir}"
        end
      end
    end
  end

  objects = OBJECTS.clone

  # Build ALWAYS_REBUILD
  ALWAYS_REBUILD.each do |file|
    obj = file.ext(".o").pathmap(".corto/obj/#{CORTO_PLATFORM}/%f")
    if hardcodedPaths then
      build_source(file, obj, true, "-DCORTO_OBJECT_NAME='\"#{artefact}\"'")
    else
      if ARTEFACT_EXT and ARTEFACT_EXT != "" then
        build_source(file, obj, true, "-DCORTO_REDIS -DCORTO_OBJECT_NAME='\"#{ARTEFACT_PREFIX}#{ARTEFACT}.#{ARTEFACT_EXT}\"'")
      else
        build_source(file, obj, true, "-DCORTO_REDIS -DCORTO_OBJECT_NAME='\"#{ARTEFACT_PREFIX}#{ARTEFACT}\"'")
      end
    end
    objects << obj
  end

  objects  = "#{objects.to_a.uniq.join(' ')}"
  linked_objects = linked.join(' ')

  libpath = "#{LIBPATH.map {|i| "-L" + corto_replace(i)}.join(" ")} "
  libmapping = "#{(LibMapping.mapLibs(LIB)).map {|i| "-l" + i}.join(" ")}"
  lflags = "#{LFLAGS.join(" ")}"

  if not hardcodedPaths then
    libpath = libpath + " -L#{CORTO_TARGET}/redistr/corto/#{CORTO_VERSION}/lib"
  end

  linkShared = ""
  if ARTEFACT_EXT == "so" then
    linkShared = "--shared"
  end

  # Put lflags after objects so that linker knows about unresolved symbols
  # before processing libraries
  cc_command = "#{COMPILER} #{objects} #{libpath} #{linked_objects} #{lflags} #{libmapping} #{linkShared} -o #{artefact}"
  begin
    cmd cc_command
  rescue
    STDERR.puts "\033[1;31mcorto:\033[0;49m command failed: #{cc_command}"
    abort
  end

  # If required, alter paths to dylib files
  linked.each do |lib|
    if File.extname(lib) == ".dylib" then
      # Obtain name of library, check if its different from target path. If
      # names don't match, setup a task to alter the name in the executable
      # path.
      libname = `otool -L #{lib}`.split("\n")[1].split[0]
      if libname != lib then
        cmd "install_name_tool -change #{libname} #{lib} #{artefact}"
      end
    end
  end

  # If target is release, strip binary
  if CONFIG == "release" then
    cmd "strip -Sx #{artefact}"
  end
end

def build()
  verbose(VERBOSE)

  # Check if there were any new files created during code generation
  files = Rake::FileList["src/*.{c,cpp}"] - ALWAYS_REBUILD
  files.each do |file|
    obj = file.ext(".o").pathmap(".corto/obj/#{CORTO_PLATFORM}/%f")
    if not OBJECTS.include? obj
      build_source(file, obj, true, "")
      OBJECTS << obj
    end
  end

  if not ENV['binaries'] == "false" then
    if not LOCAL then
      if not ENV['redistr'] == "false" then
        if $redis_dependencies_resolved then
          build_target(false)
          if ENV['silent'] != "true" then
            msg "  rds #{C_BOLD}#{relative_path(ENV['CORTO_TARGET'], get_artefact_name(FALSE))}"
          end
        else
          msg "  rds #{C_WARNING}missing dependencies, skipping"
        end
      end
    end
    build_target(true)
    if ENV['silent'] != "true" then
      artefact = "???"
      if ARTEFACT_EXT == "so" then
        artefact = "pkg"
      else
        artefact = "app"
      end
      msg "  #{artefact} #{C_BOLD}#{relative_path(ENV['CORTO_TARGET'], get_artefact_name(TRUE))}"
    end
  end
  if ENV['silent'] != "true" then
    print "\n"
  end
end

if MULTITHREAD == true then
  multitask ARTEFACT_NAME => OBJECTS do
    build()
  end
else
  task ARTEFACT_NAME => OBJECTS do
    build()
  end
end

def loadPackageConfigs()
  USE_PACKAGE.each do |p|
    location = `corto locate #{p} --path`.strip
    if not $?.to_i == 0 then
      if ENV['binaries'] == "true" then
        STDERR.puts "[\033[0;31m error\033[0;49m missing dependency: #{p} ]"
        sh "corto locate #{p} --verbose --error_only"
        abort
      else
        # If not building binaries, all we need is a build.rb
        location = "#{ENV['CORTO_TARGET']}/lib/corto/#{CORTO_VERSION}/#{p}"
        if not File.exists? location then
        STDERR.puts "[\033[0;31m error\033[0;49m missing dependency: #{p} ]"
          abort
        end
      end
    else
      redis_msg = ""

      # Check if redistributable library can be found for dependency
      if ENV['redistr'] != "false" then
        redistr = `corto locate #{p} --lib-redistr`.strip
        if not $?.to_i == 0 then
          # Disable redistributable build when there are unresolved dependencies
          redis_msg = "#{C_WARNING} (no redistr)#{C_NORMAL}"
          $redis_dependencies_resolved = false
        end
      end
      if ENV['silent'] != "true" then
        msg "  use #{C_NORMAL}#{location}#{redis_msg}"
      end
    end

    if LANGUAGE == "c4cpp" then
      lang_buildscript = "#{location}/c/build.rb"
    else
      lang_buildscript = "#{location}/#{LANGUAGE}/build.rb"
    end
    if not NOCORTO and defined? LANGUAGE and LANGUAGE != "none" then
      if File.exists? lang_buildscript then
        require "#{lang_buildscript}"
      end
    end

    buildscript = location + "/build.rb"
    if File.exists? buildscript then
        require "#{buildscript}"
    end
  end
end

task :prebuild => GENERATED_SOURCES do
  verbose(VERBOSE)
  if ENV['silent'] != "true" then
      pkg = relative_path(CORTO_BUILDROOT, Dir.pwd).to_s
      if pkg == "." then
        msg "build"
      else
        msg "build #{C_NORMAL}#{pkg}"
      end
  end

  # Load dependency build instructions before anything else
  loadPackageConfigs()

  # Don't overwhelm the compiler with potentially duplicate include paths that can
  # be introduced when the same package is included multiple times, by multiple
  # dependencies.
  INCLUDE.uniq!
end

task :postbuild

# The default rule that kicks of the build process
task :default => [:prebuild, :binary, :postbuild]

task :clean do
  verbose(VERBOSE)

  if ENV['silent'] != "true" then
    pkg = relative_path(CORTO_BUILDROOT, Dir.pwd).to_s
    if pkg == "." then
      msg "clean"
    else
      msg "clean #{C_NORMAL}#{pkg}"
    end
  end
end

# For make junkies
task :all => :default

# Build and run tests for project
task :test do
  verbose(VERBOSE)
  TEST = true

  # Build test
  if File.exists? "test/rakefile" then
    begin
      buildCmd = "none"
      if ENV['clean'] == "true" then
        buildCmd = "clobber"
      elsif ENV['rebuild'] == "true" then
        buildCmd = "clobber default"
      elsif ENV['build'] == "true" then
        buildCmd = ""
      end
      if buildCmd != "none" then
        cmd "rake #{buildCmd} -f test/rakefile silent=true"
      end
    rescue
      STDERR.puts "\033[1;31mcorto:\033[0;49m failed to build test"
      abort
    end
    if ENV["build"] != "true" and ENV["rebuild"] != "true" and ENV["clean"] != "true" then
      begin
        cmd "rake runtest -f #{Dir.pwd}/test/rakefile testcase=#{ENV['testcase']}"
      rescue
        abort
      end
    end
  end
end

# Current project is a test project, run test
task :runtest do
  verbose(VERBOSE)
  TEST = true
  cmd "rake"
  begin
    cmd "corto #{get_artefact_name(TRUE)} #{ENV['testcase']}"
  rescue
    abort
  end
end


# Keep track of overal coverage statistics for project
covered = 0
total = 0
coverage_report = []

# Run gcov for project
task :gcov => SOURCES.ext(".gcov") do
  coverage_report.sort_by { |item| item['uncovered'] }.reverse!.each do |item|
    if (item['uncovered'] != 0) then
      if (item['pct'] < 0.7) then
        print "#{item['source']}: #{C_FAIL}#{"%.2f" % (item['pct']*100)}%#{C_NORMAL} (#{item['uncovered']} uncovered)\n"
      elsif (item['pct'] >= 0.8) then
        print "#{item['source']}: #{C_OK}#{"%.2f" % (item['pct']*100)}%#{C_NORMAL} (#{item['uncovered']} uncovered)\n"
      else
        print "#{item['source']}: #{"%.2f" % (item['pct']*100)}% (#{item['uncovered']} uncovered)\n"
      end
    end
  end
  if (total != 0) then
    pct = covered / total
    if (pct < 0.7) then
      print "#{C_BOLD}[ #{C_NORMAL}#{C_NORMAL}#{ARTEFACT}#{C_NORMAL}#{C_FAIL} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n"
    elsif (pct >= 0.8) then
      print "#{C_BOLD}[ #{C_NORMAL}#{C_NORMAL}#{ARTEFACT}#{C_NORMAL}#{C_OK} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n"
    else
      print "#{C_BOLD}[ #{C_NORMAL}#{C_NORMAL}#{ARTEFACT}#{C_NORMAL}#{C_BOLD} #{"%.2f" % ((covered / total) * 100)}% #{C_NORMAL}#{C_BOLD}]#{C_NORMAL}\n"
    end
  end
  print "\n"
end

def g_src(obj)
  obj.pathmap(".corto/%f").ext(".#{EXT}")
end

# Rules for generated files
# rule (/^\.corto.*\/_[a-zA-Z]+\.o$/) do |task|
#     print "Build #{task.name}\n"
#     build_source(g_src(task.name), task.name, false, "")
# end

# Generic rule for translating source files into object files
rule '.o' => lambda {|t|
  file = nil
  base = File.join(File.dirname(t), File.basename(t, '.*'))
  SOURCES.each do |e|
    if e.pathmap("%{^src/,.corto/obj/#{CORTO_PLATFORM}/}X") == base then
      file = e
      break;
    end
  end

  # If file wasn't found and starts with _ it is generated and is from .corto
  if file == nil then
    if File.basename(t)[0, 1] == "_" then
      file = t.pathmap(".corto/%f").ext(".#{EXT}")
    end
  end

  # If file wasn't found in SOURCES, it may be a generated file in src
  if file == nil then
    file = t.pathmap("src/%f").ext(".#{EXT}")
    if not File.exists? file then
      file = t.pathmap("src/%f").ext(".c")
    end
  end
  file
} do |task|
  if COVERAGE then
    cmd "rm -f #{task.name.ext(".gcda")}"
    cmd "rm -f #{task.name.ext(".gcno")}"
  end
  build_source(task.source, task.name, true, "")
end

# Rule for creating a gcov file
rule '.gcov' => lambda{|t| t.ext(".#{EXT}")} do |task|
  if File.basename(task.name)[0] != "_" then
    gcov_dir = File.dirname(task.source.pathmap(".corto/%{^src/,obj/#{CORTO_PLATFORM}/}p"))
    begin
      coverage = `gcov --object-directory #{gcov_dir} #{task.source}`
      data = coverage.split("\n")[1]
      pct = data.match(/(\w+)\.(\w+)\%/)[0][0...-1].to_f / 100
      lines = data.split(" ")[3].to_i
      covered += (pct) * lines
      total += lines
      coverage_report << {'pct' => pct, 'uncovered' => (lines - lines * pct).round, 'source' => task.source}
    rescue
    end
  end
end

# --- UTILITIES

# Utility function for building a sourcefile
def build_source(source, target, echo, custom)
  verbose(VERBOSE)
  flags = ""
  cc = ""
  own_include = ""

  if LANGUAGE == "c" then
    flags = CFLAGS
    cc = CC
  else
    flags = CXXFLAGS
    cc = CXX
  end

  path = File.dirname(target)
  if not File.exists? path then
    cmd "mkdir -p #{path}"
  end

  if echo
    if ENV['silent'] != "true" and DRYRUN != true then
      msg "  src #{C_NORMAL}#{source}"
    end
  end

  if defined? ADD_OWN_INCLUDE and ADD_OWN_INCLUDE == true then
    own_include = "-Iinclude"
  end

  cc_command = "#{COMPILER} -c #{flags.join(" ")} #{custom} #{DEFINE.map {|d| "-D" + d}.join(" ")} #{own_include} #{INCLUDE.map {|i| "-I" + corto_replace(i)}.join(" ")} #{source} -o #{target}"
  begin
    cmd cc_command
  rescue
    STDERR.puts "\033[1;31mcorto:\033[0;49mcorto: command failed: #{cc_command}"
    abort
  end
end
