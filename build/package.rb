require "#{ENV['CORTO_BUILD']}/common"

PACKAGE_FWSLASH = PACKAGE.gsub("::", "/")

LIB_PUBLIC ||= [] + LIB
LIBPATH_PUBLIC ||= [] + LIBPATH
LINK_PUBLIC ||= ["."] + LINK
GENERATED_SOURCES ||= []
TARGET ||= PACKAGE_FWSLASH.split("/").last
DEFINE << "BUILDING_" + PACKAGE_FWSLASH.gsub("/", "_").upcase
PREFIX ||= TARGET
NAME ||= PACKAGE_FWSLASH.split("/").last
ARTEFACT ||= "lib#{TARGET}.so"

# Preprocessor variables
PP_ATTR ||= []
if not defined? PP_OBJECTS then
  PP_SCOPES ||= [PACKAGE]
else
  PP_SCOPES ||= []
end
PP_OBJECTS ||= []

# Include corto package only when not building the core
if TARGET != "corto" and not defined? NOCORTO then USE_PACKAGE << "corto" end

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
  TARGETDIR ||= "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
end

# Define a convenience macro in the package that points to the installed ETC directory
DEFINE << PACKAGE_FWSLASH.gsub("/", "_").upcase + "_ETC='\"#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}\"'"

# Rule for creating packages.txt
file ".corto/packages.txt" do
  verbose(VERBOSE)
  sh "mkdir -p .corto"
  sh "touch .corto/packages.txt"
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
    GENERATED_SOURCES <<
      ".corto/_api.#{EXT}" <<
      ".corto/_wrapper.#{EXT}" <<
      ".corto/_meta.#{EXT}" <<
      ".corto/_load.#{EXT}"

    GENERATED_HEADERS ||= [] <<
      "include/_api.h" <<
      "include/_meta.h" <<
      "include/_type.h" <<
      "include/_interface.h"

    file "include/_type.h" => [GENFILE, ".corto/packages.txt"] do
      verbose(VERBOSE)
      preload = PP_PRELOAD.join(" ")
      sh "mkdir -p .corto"
      sh "touch .corto/_wrapper.#{EXT}"

      localStr = ""
      docStr = ""

      if LOCAL then
        localStr = "--attr local=true"
      else
        begin
          sh "corto locate corto/gen/doc/doc --silent"
          # docStr = "-g doc/doc"
        rescue
        end
      end

      command = "corto pp #{preload} #{GENFILE} --name #{PACKAGE} " +
                "#{PP_SCOPES.map{|s| "--scope " + s}.join(" ")} " +
                "#{PP_OBJECTS.map{|o| "--object " + o}.join(" ")} " +
                "#{PP_ATTR.map{|a| "--attr " + a}.join(" ")} " +
                "--prefix #{PREFIX} #{localStr} #{docStr} --lang #{LANGUAGE}"

      begin
        sh command
      rescue
        STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
        if File.exists? "include/_type.h" then
          sh "rm include/_type.h"
        end
        abort()
      end
    end
    task :prebuild => ["include/_type.h"]
  else
    GENERATED_SOURCES <<
        ".corto/_load.#{EXT}"

    file ".corto/_load.#{EXT}" => [".corto/packages.txt"] do
      verbose(VERBOSE)
      preload = PP_PRELOAD.join(" ")
      sh "mkdir -p .corto"

      localStr = ""

      if LOCAL then
        localStr = "--attr local=true"
      end
      if LANGUAGE == "c4cpp" then
        langStr = "--attr c4cpp=true"
      end

      command =
        "corto pp #{preload} #{localStr} --name #{PACKAGE} " +
        "--attr h=include --attr c=src #{PP_ATTR.map{|a| "--attr " + a}.join(" ")} -g c/project #{langStr}"

      begin
        sh command
      rescue
        STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
        if File.exists? "include/#{NAME}.h" then
          sh "rm include/#{NAME}.h"
        end
        abort()
      end
    end
    task :prebuild => [".corto/_load.#{EXT}"]
  end
end

# Document framework integration
task :doc do
  verbose(VERBOSE)
  if `which corto` != "" then
    begin
      sh "corto locate corto/md --silent"
      if File.exists? "#{NAME}.md" then
        if not LOCAL and not NOCORTO then
          command = "corto pp #{NAME}.md --scope #{PACKAGE_FWSLASH} -g doc/html"
        else
          command = "corto pp #{NAME}.md -g doc/html"
        end
        begin
          sh command
        rescue
          STDERR.puts "\033[1;31mcommand failed: #{command}\033[0;49m"
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
      dir = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
      sh "mkdir -p #{dir}"
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
    dir = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{PACKAGEDIR}"
    sh "mkdir -p #{dir}"
    File.open("#{dir}/uninstall.txt", "w") do |file|
      UNINSTALL.each do |f|
        file.write("#{f}\n")
      end
    end
  end
end

task :uninstall do
  verbose(VERBOSE)
  if not LOCAL then
    dir = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{PACKAGEDIR}"
    if File.exists?("#{dir}/uninstall.txt") then
      File.open("#{dir}/uninstall.txt") do |file|
        file.each_line do |l|
          # That will not happen to me
          if l.strip.length > "/usr/local\n".length then
            file = l[0...-1]
            if File.directory? file then
              if not Dir.glob("#{file}/*").length then
                sh "rm -rf #{l[0...-1]}"
              end
            else
              sh "rm -f #{l[0...-1]}"
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
  if File.directory? source then
    target = File.dirname(target) + "/"
  end
  if SOFTLINKS then
    sh "ln -fs #{source} #{target}"
  else
    begin
      sh "cp -r #{source} #{target}"
    rescue
      STDERR.puts "\033[1;31mwarning: failed to copy file #{source}, retrying\033[0;49m"
      sh "rm -rf #{target}"
      sh "cp -r #{source} #{target}"
    end
  end
  UNINSTALL << target
end

task :install do
  verbose(VERBOSE)

  if not LOCAL then
    libpath = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    if not File.exists? libpath then
      sh "mkdir -p #{libpath}"
    end
    if File.exists?("include") then
      installFiles = Dir.glob("include/*")

      if installFiles.length != 0 then
        includePath = "#{CORTO_TARGET}/include/corto/#{CORTO_VERSION}/#{TARGETPATH}"

        sh "mkdir -p #{includePath}"

        # Keep track of installed include files
        installFiles.each do |f|
          file = Dir.getwd + "/" + f
          if File.basename(f).start_with?("Linux", "Darwin") then
            if File.basename(f) == CORTO_PLATFORM then
              Dir.glob(file + "/*").each do |pf|
                installFile(pf, includePath + "/" + File.basename(pf))
              end
            end
          else
            newFile = f.pathmap("#{includePath}/%{^include/,}p")
            installFile(file, newFile)
          end
        end

        # Write package prefix to include path
        sh "rm -f #{includePath}/.prefix"
        sh "echo \"#{PREFIX}\" >> #{includePath}/.prefix"
      end
    end
    if File.exists?("etc") then
      etc = "#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
      sh "rm -rf #{etc}"
      sh "mkdir -p #{etc}"

      if File.exists? "etc/everywhere" then
        sh "cp -r etc/everywhere/. #{etc}/"
        if CORTO_OS == "Darwin" then
          access = `stat -f '%A' etc/everywhere`.strip
        else
          access = `stat -c '%a' etc/everywhere`.strip
        end
        sh "chmod #{access} #{etc}"
      end
      platformStr = "etc/" + CORTO_PLATFORM
      if File.exists? platformStr then
        sh "cp -r " + platformStr + "/. #{etc}"
      end
      UNINSTALL << etc
    end
    if File.exists?("lib") then
      if File.exists? "lib/everywhere" then
        sh "cp -r lib/everywhere/. #{libpath}/"
        if CORTO_OS == "Darwin" then
          access = `stat -f '%A' lib/everywhere`.strip
        else
          access = `stat -c '%a' lib/everywhere`.strip
        end
        sh "chmod #{access} #{libpath}"
      end
      platformStr = "lib/" + CORTO_PLATFORM
      if File.exists? platformStr then
        sh "cp -r " + platformStr + "/. #{libpath}"
      end
      UNINSTALL << libpath
    end
    if File.exists?("install") then
      platformStr = "install/" + CORTO_PLATFORM
      if File.exists? platformStr then
        install = "#{CORTO_TARGET}"
        if File.exists? "#{platformStr}/lib" then
          sh "cp -r #{platformStr}/lib/. #{install}/lib"
        end
        if File.exists? "#{platformStr}/bin" then
          sh "cp -r #{platformStr}/bin/. #{install}/bin"
        end
        if File.exists? "#{platformStr}/include" then
          sh "cp -r #{platformStr}/include/. #{install}/include"
        end
        if File.exists? "#{platformStr}/etc" then
          sh "cp -r #{platformStr}/etc/. #{install}/etc"
        end

        # Add installed files to FILES variable
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
      sh "echo \"`pwd`\" >> source.txt"
      if File.exists? "#{libpath}/source.txt" then
        if not FileUtils.compare_file("source.txt", "#{libpath}/source.txt") then
          STDERR.puts "\033[1;31mwarning: potential package name clash (did you move the '#{PACKAGE}' project?)\033[0;49m"
        end
      end
      sh "mv source.txt #{libpath}/source.txt"
    end
    if not LOCAL and File.exists? ".corto/packages.txt" then
      sh "cp .corto/packages.txt #{libpath}"
    end
    if not LOCAL and File.exists? ".corto/version.txt" then
      sh "cp .corto/version.txt #{libpath}"
    end
  end
end

# Collect files in preparation for creating a tar
task :collect do
  verbose(VERBOSE)
  buildScript = "#{CORTO_TARGET}/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}/build.rb"
  if not File.exists?(buildScript) then
    STDERR.puts "\033[1;31m build.rb not found ]\033[0;49m"
    abort
  end
  libPath = "#{ENV['HOME']}/.corto/pack/lib/corto/#{CORTO_VERSION}/#{TARGETPATH}"
  sh "mkdir -p #{libPath}"
  sh "cp -r #{buildScript} #{libPath}"
  if File.exists?("include") then
    includePath = "#{ENV['HOME']}/.corto/pack/include/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    sh "mkdir -p #{includePath}"
    sh "cp -r include/. #{includePath}/"
  end
  if File.exists?("etc") then
    etc = "#{ENV['HOME']}/.corto/pack/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    targetEtc = "#{CORTO_TARGET}/etc/corto/#{CORTO_VERSION}/#{TARGETPATH}"
    sh "mkdir -p #{etc}"
    sh "cp -r #{targetEtc}/. #{etc}/"
  end
end

# Prebuild tasks
task :prebuild => [:uninstall, :install]

# Postbuild tasks
task :postbuild => [:doc, :buildscript, :uninstaller]

require "#{CORTO_BUILD}/artefact"
require "#{CORTO_BUILD}/subrake"
