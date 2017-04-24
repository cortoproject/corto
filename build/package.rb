require "#{ENV['CORTO_BUILD']}/common"
require 'rake/clean'

PACKAGE_FWSLASH = PACKAGE.gsub("::", "/")

# Public variables
LIB_PUBLIC = [] + LIB if not defined? LIB_PUBLIC
LIBPATH_PUBLIC = [] + LIBPATH if not defined? LIBPATH_PUBLIC
LINK_PUBLIC = ["."] + LINK if not defined? LINK_PUBLIC
# keep track of the original LINK array as the buildsystem will append LINK with
# dependencies
TARGET = PACKAGE_FWSLASH.split("/").last if not defined? TARGET
NAME = PACKAGE_FWSLASH.split("/").last if not defined? NAME
ARTEFACT = TARGET if not defined? ARTEFACT
ARTEFACT_PREFIX = "lib" if not defined? ARTEFACT_PREFIX
ARTEFACT_EXT = "so" if not defined? ARTEFACT_EXT
INSTALL = "lib/corto" if not defined? INSTALL
NOCORTO = false if not defined? NOCORTO
DEFINE << "BUILDING_" + PACKAGE_FWSLASH.gsub("/", "_").upcase
COMPONENTS = [] if not defined? COMPONENTS

# Private variables
GENERATED_SOURCES = [] if not defined? GENERATED_SOURCES
GENERATED_HEADERS = [] if not defined? GENERATED_HEADERS
LINK_NO_DEPS = LINK.clone

# Preprocessor variables
PP_ATTR = [] if not defined? PP_ATTR

if not defined? PP_SCOPES then
  PP_SCOPES = [PACKAGE] if not defined? PP_SCOPES
end

if defined? PP_OBJECTS then
  if not PP_ATTR.include?("app=true") then
    STDERR.puts "\033[1;31mcorto: cannot use PP_OBJECTS for packages\033[0;49m"
    abort();
  end
else
  PP_OBJECTS = []
end

if not defined? PREFIX then
  if LANGUAGE == "cpp" or LANGUAGE == "c++" then
    PREFIX = "."
  elsif defined? PP_SCOPES then
    PREFIX = PP_SCOPES[0].split("/").last
  end
end

# Include corto package only when not building the core
if TARGET != "corto" and NOCORTO == false then
  USE_PACKAGE << "corto"
  if LANGUAGE == "cpp" or LANGUAGE == "c++" then
    USE_PACKAGE << "corto/cpp"
  elsif LANGUAGE == "c" or LANGUAGE == "c4cpp" then
    if not NOAPI then
      USE_PACKAGE << "corto/c"
    end
  end
end

# Set working directory to where the rakefile is
CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

# Support for local packages (packages that are not installed to environment)
if LOCAL == true then
  TARGETPATH = "./.corto"
  TARGETDIR = TARGETPATH if not defined? TARGETDIR
else
  PACKAGEDIR = PACKAGE_FWSLASH
  TARGETPATH = PACKAGEDIR
  TARGETDIR = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}" if not defined? TARGETDIR
end

if LOCAL == true then
  if not defined? ADD_OWN_INCLUDE then
    ADD_OWN_INCLUDE = true
  end
end

# Define a convenience macro in the package that points to the installed ETC directory
if not LOCAL then
  DEFINE << PACKAGE_FWSLASH.gsub("/", "_").upcase + "_ETC='\"#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}\"'"
else
  DEFINE << PACKAGE_FWSLASH.gsub("/", "_").upcase + "_ETC='\"" + Dir.getwd + "/etc\"'"
end

# Rule for creating packages.txt
file ".corto/packages.txt" do
  verbose(VERBOSE)
  cmd "mkdir -p .corto"
  cmd "touch .corto/packages.txt"
end

# Code generation
if NOCORTO == false then
  verbose(VERBOSE)

  definitionFiles = Rake::FileList["#{PP_SCOPES[0].split("/").last}.{cx,idl,xml}"]
  if definitionFiles.length == 0 then
    definitionFiles = Rake::FileList["#{NAME}.{cx,idl,xml}"]
  end
  
  DEFFILES = definitionFiles

  if DEFFILES.length != 0 then
    # If this is a corto package, let Corto manage which symbols should be
    # external
    CFLAGS << "-fvisibility=hidden"

    GENFILE = DEFFILES[0]

    if LANGUAGE == "c" or LANGUAGE == "c4cpp" then
      GENERATED_SOURCES <<
        ".corto/_wrapper.#{EXT}" <<
        ".corto/_project.#{EXT}" <<
        ".corto/_load.#{EXT}"

      GENERATED_HEADERS <<
        "include/_load.h" <<
        "include/_type.h" <<
        "include/_project.h"
    else
      GENERATED_SOURCES <<
        ".corto/_api.#{EXT}" <<
        ".corto/_project.#{EXT}" <<
        ".corto/_load.#{EXT}"

      GENERATED_HEADERS <<
        "include/_load.h" <<
        "include/_type.h"
    end

    file "include/_type.h" => [GENFILE, ".corto/packages.txt"] do
      verbose(VERBOSE)
      preload = PP_PRELOAD.join(" ")
      cmd "mkdir -p .corto"
      cmd "touch .corto/_wrapper.#{EXT}"

      localStr = " "
      docStr = " "

      if LOCAL then
        localStr = "--attr local=true "
      end

      if defined? PREFIX then
        prefixStr = "--prefix #{PREFIX} "
      end

      packages_filtered = USE_PACKAGE.select do |elem|
        elem != PACKAGE + "/c"
      end

      command = "#{DEBUGCMD}corto pp #{preload} #{GENFILE} --name #{PACKAGE} " +
                "#{PP_SCOPES.map{|s| "--scope " + s}.join(" ")} " +
                "#{PP_OBJECTS.map{|o| "--object " + o}.join(" ")} " +
                "--import #{packages_filtered.join(",")} " +
                "#{PP_ATTR.map{|a| "--attr " + a}.join(" ")} " +
                "#{prefixStr}#{localStr}#{docStr}--lang #{LANGUAGE}"

      if ENV['silent'] != "true" then
        msg "preprocess #{C_NORMAL}#{GENFILE}"
      end
      begin
        cmd command
      rescue
        if File.exists? "include/_type.h" then
          cmd "rm include/_type.h"
        end
        exit(-1)
      end
    end
    task :default => ["include/_type.h"]
  else
    GENERATED_SOURCES <<
      ".corto/_project.#{EXT}"

    file ".corto/_project.#{EXT}" => [".corto/packages.txt"] do
      verbose(VERBOSE)
      preload = PP_PRELOAD.join(" ")
      cmd "mkdir -p .corto"

      localStr = ""

      if LOCAL then
        localStr = "--attr local=true"
      end
      if LANGUAGE == "c4cpp" then
        langStr = "--attr c4cpp=true --attr cpp=src --attr hpp=include"
      elsif LANGUAGE == "cpp" or LANGUAGE == "c++" then
        langStr = "--attr c4cpp=true --attr lang=cpp --attr hpp=include --attr cpp=src"
      end

      if not defined? ADD_OWN_INCLUDE then
        ADD_OWN_INCLUDE = true
      end

      command =
        "#{DEBUGCMD}corto pp #{preload} #{localStr} --name #{PACKAGE} " +
        "--attr h=include --attr c=src #{PP_ATTR.map{|a| "--attr " + a}.join(" ")} " +
        "--import #{USE_PACKAGE.join(",")} " +
        " -g c/interface -g c/project #{langStr}"

      if ENV['silent'] != "true" then
        msg "preprocess"
      end
      begin
        cmd command
      rescue
        if File.exists? "include/#{NAME}.h" then
          cmd "rm include/#{NAME}.h"
        end
        exit(-1)
      end
    end
    task :prebuild => [".corto/_project.#{EXT}"]
  end
else
  if not defined? ADD_OWN_INCLUDE then
    ADD_OWN_INCLUDE = true
  end
end

# Generate a script with build instructions for this package
task :buildscript do
  verbose(VERBOSE)
  if not LOCAL then
    INCLUDE_PUBLIC = [] + INCLUDE if not defined? INCLUDE_PUBLIC
    if INCLUDE_PUBLIC.length or LIB_PUBLIC.length or LINK_PUBLIC.length then
      dir = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}"
      cmd "mkdir -p #{dir}"
      File.open("#{dir}/build.rb", "w") do |file|
        if INCLUDE_PUBLIC.length != 0 then
          file.write "INCLUDE"
          INCLUDE_PUBLIC.each do |i|
            file.write " << \"#{corto_replace(i)}\""
          end
          file.write "\n"
        end

        if LIBPATH_PUBLIC.length != 0 then
          file.write "LIBPATH"
          LIBPATH_PUBLIC.each do |i|
            file.write " << \"#{corto_replace(i)}\""
          end
          file.write "\n"
        end

        if LIB_PUBLIC.length != 0 then
          file.write "LIB"
          LIB_PUBLIC.each do |i|
            file.write " << \"#{corto_replace(i)}\""
          end
          file.write "\n"
        end

        if LINK_PUBLIC.length != 0 then
          file.write "LINK"
          LINK_PUBLIC.each do |i|
            if i != "." then
              file.write " << \"#{corto_replace(i)}\""
            else
              file.write " << \"#{TARGETDIR}/#{TARGET}\""
            end
          end
          file.write "\n"
        end
      end
    end
  end
end

task :uninstaller do
  if not LOCAL then
    dir = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{PACKAGEDIR}"
    cmd "mkdir -p #{dir}"
    File.open("#{dir}/uninstall.txt", "w") do |file|
      UNINSTALL.each do |f|
        file.write("#{f}\n")
      end
    end
  end
end

def uninstallDir(dir)
  artefact = getArtefactName(ARTEFACT_PREFIX, ARTEFACT_NAME, ARTEFACT_EXT)

  if File.exists?("#{dir}/uninstall.txt") then
    File.open("#{dir}/uninstall.txt") do |file|
      file.each_line do |l|
        # That will not happen to me
        if l.strip.length > "/usr/local\n".length then
          file = l[0...-1]
          if File.directory? file then
            if not Dir.glob("#{file}/*").length then
              cmd "rm -rf #{file}"
            end
          else
            if file != artefact then
              cmd "rm -f #{file}"
            end
          end
        end
      end
    end
  else
    # Remove files from directory, keep directories
    files = Dir.glob("#{dir}/*")
    files.each do |f|
      if not File.directory? f and f != artefact then
        cmd "rm -f #{f}"
      end
    end
  end
end

task :uninstall_files do
  verbose(VERBOSE)
  if not LOCAL then
    dir = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{PACKAGEDIR}"
    uninstallDir(dir)

    # Also make sure that there are no packages with the same name but different case
    dirLc = dir.downcase
    if dirLc != dir then
      uninstallDir(dirLc)
    end
  end
end

# Crawl project directory for files that need to be installed with binary
def installFile(source, target)
  if File.directory? source and target[-1, 1] != "/" then
    target = File.dirname(target) + "/"
  end
  if SOFTLINKS then
    begin
      cmd "ln -fs #{source} #{target}"
    rescue
      if File.exists?(target) then
        cmd "rm -rf #{target}#{File.basename(source)}"
      end
      cmd "ln -fs #{source} #{target}"
    end
  else
    begin
      cmd "cp -r #{source} #{target}"
    rescue
      STDERR.puts "#{C_WARNING}warning: failed to copy file #{source}, retrying#{C_NORMAL}"
      if File.exists?(target) then
        cmd "rm -rf #{target}"
      end
      cmd "cp -r #{source} #{target}"
      STDERR.puts " => OK"
    end
  end
  UNINSTALL << target
end

def installDir(dir)
  if File.exists?(dir) then
    installFiles = Dir.glob("#{dir}/*")

    if installFiles.length != 0 then
      dstPath = "#{CORTO_TARGET}/#{dir}/corto/#{CORTO_VERSION}/#{TARGETPATH}"
      if not File.exists? dstPath then
        cmd "mkdir -p #{dstPath}"
      end

      if ENV['silent'] != "true" then
        msg "copy #{C_NORMAL}#{dir} to #{dstPath}"
      end

      # Keep track of installed include files
      installFiles.each do |f|
        file = Dir.getwd + "/" + f
        if File.basename(f).start_with?("Linux", "Darwin") then
          if File.basename(f) == CORTO_PLATFORM then
            Dir.glob(file + "/*").each do |pf|
              installFile(pf, dstPath + "/" + File.basename(pf))
            end
          end
        elsif File.basename(f) == "everywhere" then
          Dir.glob(file + "/*").each do |pf|
            installFile(pf, dstPath + "/" + File.basename(pf))
          end
        else
          newFile = f.pathmap("#{dstPath}/%{^#{dir}/,}p")
          installFile(file, newFile)
        end
      end

      # Write package prefix to include path
      cmd "rm -f #{dstPath}/.prefix"
      if defined? PREFIX then
        cmd "echo \"#{PREFIX}\" >> #{dstPath}/.prefix"
      end
    end
  end
end

task :build_binding do
  # If a package for C language binding was generated, install its headers
  # so the current package can be compiled
  if not NOCORTO and File.exists? "c" then
    sh "rake -f c/rakefile"
  end
end

task :install_files do
  verbose(VERBOSE)

  if not LOCAL then
    libpath = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}"
    if not File.exists? libpath then
        begin
          cmd "mkdir -p #{libpath}"
        rescue
          exit(-1)
        end
    end

    if not PP_ATTR.include?("app=true") then
      installDir("include")
    end
    installDir("etc")
    installDir("lib")

    if File.exists?("install") then
      platformStr = "install/" + CORTO_PLATFORM
      if File.exists? platformStr then
        install = "#{CORTO_TARGET}"
        if File.exists? "#{platformStr}/lib" then
          msg "copy #{C_NORMAL}#{platformStr}/lib to #{install}/lib"
          cmd "cp -r #{platformStr}/lib/. #{install}/lib"
        end
        if File.exists? "#{platformStr}/bin" then
          msg "copy #{C_NORMAL}#{platformStr}/bin to #{install}/bin"
          cmd "cp -r #{platformStr}/bin/. #{install}/bin"
        end
        if File.exists? "#{platformStr}/include" then
          msg "copy #{C_NORMAL}#{platformStr}/include to #{install}/include"
          cmd "cp -r #{platformStr}/include/. #{install}/include"
        end
        if File.exists? "#{platformStr}/etc" then
          msg "copy #{C_NORMAL}#{platformStr}/etc to #{install}/etc"
          cmd "cp -r #{platformStr}/etc/. #{install}/etc"
        end

        # Add installed files to UNINSTALL variable
        Dir.glob("#{platformStr}/lib/**/*").each do |file|
          UNINSTALL << file.pathmap("#{CORTO_TARGET}/%{^#{platformStr}/,}p")
        end
        Dir.glob("#{platformStr}/bin/**/*").each do |file|
          UNINSTALL << file.pathmap("#{CORTO_TARGET}/%{^#{platformStr}/,}p")
        end
        Dir.glob("#{platformStr}/include/**/*").each do |file|
          UNINSTALL << file.pathmap("#{CORTO_TARGET}/%{^#{platformStr}/,}p")
        end
        Dir.glob("#{platformStr}/etc/**/*").each do |file|
          UNINSTALL << file.pathmap("#{CORTO_TARGET}/%{^#{platformStr}/,}p")
        end
      end
    end
    if not LOCAL and ENV['CORTO_TARGET'] != "/usr/local" then
      # Using this file, corto can auto-rebuild the package when changes in
      # package files are made while a running application is using it.
      cmd "echo \"`pwd`\" >> source.txt"
      if DRYRUN != true then
        if File.exists? "#{libpath}/source.txt" then
          if not FileUtils.compare_file("source.txt", "#{libpath}/source.txt") then
            STDERR.puts "\033[0;33mwarning: potential package name clash (did you move the '#{PACKAGE}' project?)\033[0;49m"
          end
        end
        cmd "mv source.txt #{libpath}/source.txt"
      end
    end
    if not LOCAL then
      if File.exists? "project.json" then
        cmd "cp project.json #{libpath}"
      else
        if File.exists? ".corto/packages.txt" then
          cmd "cp .corto/packages.txt #{libpath}"
        end
        if File.exists? ".corto/version.txt" then
          cmd "cp .corto/version.txt #{libpath}"
        end
      end
    end
  end
end

# Collect files in preparation for creating a tar
task :collect do
  verbose(VERBOSE)
  buildScript = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}/build.rb"
  if not File.exists?(buildScript) then
    STDERR.puts "\033[1;31m build.rb not found ]\033[0;49m"
    abort
  end
  libPath = "#{ENV['HOME']}/.corto/pack/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}"
  cmd "mkdir -p #{libPath}"
  cmd "cp -r #{buildScript} #{libPath}"
  if File.exists?("include") then
    includePath = "#{ENV['HOME']}/.corto/pack/include/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    cmd "mkdir -p #{includePath}"
    cmd "cp -r include/. #{includePath}/"
  end
  if File.exists?("etc") then
    etc = "#{ENV['HOME']}/.corto/pack/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    targetEtc = "#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    cmd "mkdir -p #{etc}"
    cmd "cp -r #{targetEtc}/. #{etc}/"
  end
end

# Prebuild tasks
task :prebuild => [:uninstall_files, :install_files, :build_binding]

# Postbuild tasks
task :postbuild => [:buildscript, :uninstaller]

require "#{CORTO_BUILD}/artefact"
require "#{CORTO_BUILD}/subrake"
