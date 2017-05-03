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
