require "#{ENV['CORTO_BUILD']}/common"
require 'rake/clean'

PACKAGE_FWSLASH = PACKAGE.gsub("::", "/")

LIB_PUBLIC ||= [] + LIB
LIBPATH_PUBLIC ||= [] + LIBPATH
LINK_PUBLIC ||= ["."] + LINK
# keep track of the original LINK array as the buildsystem will append LINK with
# dependencies
LINK_NO_DEPS = LINK
GENERATED_SOURCES ||= []
TARGET ||= PACKAGE_FWSLASH.split("/").last
DEFINE << "BUILDING_" + PACKAGE_FWSLASH.gsub("/", "_").upcase
NAME ||= PACKAGE_FWSLASH.split("/").last
ARTEFACT ||= TARGET
ARTEFACT_PREFIX ||= "lib"
ARTEFACT_EXT ||= "so"
INSTALL ||= "lib/corto"

# Preprocessor variables
PP_ATTR ||= []
if not defined? PP_OBJECTS then
  PP_SCOPES ||= [PACKAGE]
else
  if not PP_ATTR.include?("app=true") then
    STDERR.puts "\033[1;31mcorto: cannot use PP_OBJECTS for packages\033[0;49m"
    abort();
  end
  PP_SCOPES ||= []
end
PP_OBJECTS ||= []

if LANGUAGE != "cpp" and LANGUAGE != "c++" then
  PREFIX ||= TARGET
else
  PREFIX = "."
end

# Include corto package only when not building the core
if TARGET != "corto" and not defined? NOCORTO then
  USE_PACKAGE << "corto"
  if LANGUAGE == "cpp" or LANGUAGE == "c++" then
    USE_PACKAGE << "corto/cpp"
  end
end

# Set working directory to where the rakefile is
CHDIR_SET = true
Dir.chdir(File.dirname(Rake.application.rakefile))

# Support for local packages (packages that are not installed to environment)
if LOCAL == true then
  TARGETPATH = "./.corto"
  TARGETDIR ||= TARGETPATH
  INCLUDE << "include"
else
  PACKAGEDIR = PACKAGE_FWSLASH
  TARGETPATH = PACKAGEDIR
  TARGETDIR ||= "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}"
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
if not defined? NOCORTO then
  verbose(VERBOSE)
  DEFFILES = Rake::FileList["#{NAME}.{cx,idl,xml}"]

  if DEFFILES.length != 0 then
    # If this is a corto package, let Corto manage which symbols should be
    # external
    CFLAGS << "-fvisibility=hidden"

    GENFILE = DEFFILES[0]

    if LANGUAGE == "c" or LANGUAGE == "c4cpp" then
      GENERATED_SOURCES <<
        ".corto/_api.#{EXT}" <<
        ".corto/_wrapper.#{EXT}" <<
        ".corto/_project.#{EXT}" <<
        ".corto/_load.#{EXT}"

      GENERATED_HEADERS ||= [] <<
        "include/_api.h" <<
        "include/_load.h" <<
        "include/_type.h" <<
        "include/_project.h"
    else
      GENERATED_SOURCES <<
        ".corto/_api.#{EXT}" <<
        ".corto/_project.#{EXT}" <<
        ".corto/_load.#{EXT}"

      GENERATED_HEADERS ||= [] <<
        "include/_load.h" <<
        "include/_type.h"
    end

    file "include/_type.h" => [GENFILE, "rakefile", ".corto/packages.txt"] do
      verbose(VERBOSE)
      preload = PP_PRELOAD.join(" ")
      cmd "mkdir -p .corto"
      cmd "touch .corto/_wrapper.#{EXT}"

      localStr = ""
      docStr = ""

      if LOCAL then
        localStr = "--attr local=true"
      else
        begin
          cmd "corto locate corto/gen/doc/doc --silent"
          # docStr = "-g doc/doc"
        rescue
        end
      end

      if defined? PREFIX then
        prefixStr = "--prefix #{PREFIX}"
      end

      command = "corto pp #{preload} #{GENFILE} --name #{PACKAGE} " +
                "#{PP_SCOPES.map{|s| "--scope " + s}.join(" ")} " +
                "#{PP_OBJECTS.map{|o| "--object " + o}.join(" ")} " +
                "#{PP_ATTR.map{|a| "--attr " + a}.join(" ")} " +
                "#{prefixStr} #{localStr} #{docStr} --lang #{LANGUAGE}"

      if ENV['silent'] != "true" then
        msg "preprocess #{C_NORMAL}#{GENFILE}"
      end
      begin
        cmd command
      rescue
        STDERR.puts "\033[1;31mcorto: command failed: #{command}\033[0;49m"
        if File.exists? "include/_type.h" then
          cmd "rm include/_type.h"
        end
        abort()
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
        langStr = "--attr c4cpp=true"
      elsif LANGUAGE == "cpp" or LANGUAGE == "c++" then
        langStr = "--attr c4cpp=true --attr lang=cpp --attr hpp=include --attr cpp=src"
      end

      command =
        "corto pp #{preload} #{localStr} --name #{PACKAGE} " +
        "--attr h=include --attr c=src #{PP_ATTR.map{|a| "--attr " + a}.join(" ")}" +
        " -g c/project #{langStr}"

      if ENV['silent'] != "true" then
        msg "preprocess"
      end
      begin
        cmd command
      rescue
        STDERR.puts "\033[1;31mcorto: command failed: #{command}\033[0;49m"
        if File.exists? "include/#{NAME}.h" then
          cmd "rm include/#{NAME}.h"
        end
        abort()
      end
    end
    task :prebuild => [".corto/_project.#{EXT}"]
  end
end

# Document framework integration
task :doc do
  verbose(VERBOSE)
  if `which corto` != "" then
    begin
      cmd "corto locate corto/md --silent"
      if File.exists? "#{NAME}.md" then
        if not LOCAL and not NOCORTO then
          command = "corto pp #{NAME}.md --scope #{PACKAGE_FWSLASH} -g doc/html"
        else
          command = "corto pp #{NAME}.md -g doc/html"
        end
        begin
          cmd command
        rescue
          STDERR.puts "\033[1;31mcorto: command failed: #{command}\033[0;49m"
          abort
        end
      end
    rescue
    end
  end
end

# Generate a script with build instructions for this package
task :buildscript do
  verbose(VERBOSE)
  if not LOCAL then
    INCLUDE_PUBLIC ||= [] + INCLUDE
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

task :uninstall_files do
  verbose(VERBOSE)
  if not LOCAL then
    dir = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{PACKAGEDIR}"
    if File.exists?("#{dir}/uninstall.txt") then
      File.open("#{dir}/uninstall.txt") do |file|
        file.each_line do |l|
          # That will not happen to me
          if l.strip.length > "/usr/local\n".length then
            file = l[0...-1]
            if File.directory? file then
              if not Dir.glob("#{file}/*").length then
                cmd "rm -rf #{l[0...-1]}"
              end
            else
              cmd "rm -f #{l[0...-1]}"
            end
          end
        end
      end
    end
  end
end

# dep.rb contains CLOBBER rules for generated header files
if File.exists? "./.corto/dep.rb"
  require "./.corto/dep.rb"
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
      STDERR.puts "\033[0;33mwarning: failed to create link #{target}#{File.basename(source)}, retrying\033[0;49m"
      if File.exists?(target) then
        cmd "rm -rf #{target}#{File.basename(source)}"
      end
      cmd "ln -fs #{source} #{target}"
      STDERR.puts " => OK"
    end
  else
    begin
      cmd "cp -r #{source} #{target}"
    rescue
      STDERR.puts "\033[0;33mwarning: failed to copy file #{source}, retrying\033[0;49m"
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

task :install_files do
  verbose(VERBOSE)

  if not LOCAL then
    libpath = "#{CORTO_TARGET}/#{INSTALL}/#{CORTO_VERSION}/#{TARGETPATH}"
    if not File.exists? libpath then
      cmd "mkdir -p #{libpath}"
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
          cmd "cp -r #{platformStr}/lib/. #{install}/lib"
        end
        if File.exists? "#{platformStr}/bin" then
          cmd "cp -r #{platformStr}/bin/. #{install}/bin"
        end
        if File.exists? "#{platformStr}/include" then
          cmd "cp -r #{platformStr}/include/. #{install}/include"
        end
        if File.exists? "#{platformStr}/etc" then
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
    if not LOCAL and File.exists? ".corto/packages.txt" then
      cmd "cp .corto/packages.txt #{libpath}"
    end
    if not LOCAL and File.exists? ".corto/version.txt" then
      cmd "cp .corto/version.txt #{libpath}"
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
task :prebuild => [:uninstall_files, :install_files]

# Postbuild tasks
task :postbuild => [:doc, :buildscript, :uninstaller]

require "#{CORTO_BUILD}/artefact"
require "#{CORTO_BUILD}/subrake"
