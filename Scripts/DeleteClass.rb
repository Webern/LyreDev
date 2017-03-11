require 'FIleUtils'

class_name = ARGV[0]
if class_name == nil
	class_name = "RubyGenerated"
end

path_src = "../Sourcecode"
path_lyre = "#{path_src}/Lyre"
path_priv = "#{path_lyre}/Private"
path_test = "#{path_src}/LyreTest/Tests"
path_sln = "../Visual Studio/Lyre.sln"
path_lyre_vcxproj = "../Visual Studio/Lyre.vcxproj"
path_test_vcxproj = "../Visual Studio/LyreTest.vcxproj"
path_xcode_lyre = "../XCode/Lyre/Lyre.xcodeproj/project.pbxproj"

name_interface_h = "I#{class_name}.h"
name_ifactory_h = "I#{class_name}Factory.h"
name_ifactory_cpp = "I#{class_name}Factory.cpp"
name_class_h = "#{class_name}.h"
name_class_cpp = "#{class_name}.cpp"
name_factory_h = "#{class_name}Factory.h"
name_factory_cpp = "#{class_name}Factory.cpp"

File.delete("#{path_lyre}/#{name_interface_h}")
File.delete("#{path_lyre}/#{name_ifactory_h}")
File.delete("#{path_lyre}/#{name_ifactory_cpp}")
File.delete("#{path_priv}/#{name_class_h}")
File.delete("#{path_priv}/#{name_class_cpp}")
File.delete("#{path_priv}/#{name_factory_h}")
File.delete("#{path_priv}/#{name_factory_cpp}")