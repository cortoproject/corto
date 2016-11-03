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
        'Linux' =>   {'dl'=>'dl', 'm'=>'m', 'rt'=>'rt', 'xml2' => 'xml2'},
        'Mac' =>     {'dl'=>'dl', 'm'=>'m', 'xml2' => 'xml2', 'rt'=>nil},
        'Windows' => {}
    }

    def self.mapLibs(libs)
      libs.map do |i|
        if @@libmap[Os.name].has_key?(i) then @@libmap[Os.name][i]
        else i
        end
      end.compact
    end
end
