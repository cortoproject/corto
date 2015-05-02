module Os
  def self.windows?
    (/cygwin|mswin|mingw|bccwin|wince|emx/ =~ RUBY_PLATFORM) != nil
  end

  def self.mac?
   (/darwin/ =~ RUBY_PLATFORM) != nil
  end

  def self.unix?
    !self.windows?
  end

  def self.linux?
    self.unix? and not self.mac?
  end

  def self.name
    if self.linux? then "Linux"
    elsif self.windows? then "Windows"
    elsif self.mac? then "Mac"
    end
  end
end

module LibMapping

    @@libmap = {
        'Linux' =>   {'dl'=>'dl', 'm'=>'m', 'rt'=>'rt'},
        'Mac' =>     {'dl'=>'dl', 'm'=>'m'},
        'Windows' => {}
    }

    def self.mapLibs(libs)
        libs.select do |i|
            @@libmap[Os.name][i]
        end.map do |i|
            @@libmap[Os.name][i]
        end
    end
end
