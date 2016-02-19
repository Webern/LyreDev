require 'FIleUtils'
require 'SecureRandom'

class_name = ARGV[0]
if class_name == nil
	class_name = "Bishop"
end

path_src = "../Sourcecode"
path_lyre = "#{path_src}/Lyre"
path_priv = "#{path_lyre}/Private"
path_test = "#{path_src}/LyreTest/Tests"
path_sln = "../Visual Studio/Lyre.sln"
path_lyre_vcxproj = "../Visual Studio/Lyre.vcxproj"
path_test_vcxproj = "../Visual Studio/LyreTest.vcxproj"
path_xcode_lyre = "../XCode/Lyre/Lyre.xcodeproj/project.pbxproj"
path_todo = "../XCode/ToDo.md"

name_interface_h = "I#{class_name}.h"
name_ifactory_h = "I#{class_name}Factory.h"
name_ifactory_cpp = "I#{class_name}Factory.cpp"
name_class_h = "#{class_name}.h"
name_class_cpp = "#{class_name}.cpp"
name_factory_h = "#{class_name}Factory.h"
name_factory_cpp = "#{class_name}Factory.cpp"
name_test_cpp = "Test#{class_name}.cpp"

interface_h = File.open("#{path_lyre}/#{name_interface_h}", "w")
ifactory_h = File.open("#{path_lyre}/#{name_ifactory_h}", "w")
ifactory_cpp = File.open("#{path_lyre}/#{name_ifactory_cpp}", "w")
class_h = File.open("#{path_priv}/#{name_class_h}", "w")
class_cpp = File.open("#{path_priv}/#{name_class_cpp}", "w")
factory_h = File.open("#{path_priv}/#{name_factory_h}", "w")
factory_cpp = File.open("#{path_priv}/#{name_factory_cpp}", "w")
test_cpp = File.open("#{path_test}/#{name_test_cpp}", "w")

# place notes in todo file
todo = File.open(path_todo, 'a')
todo << "\n"
todo << "add to Xcode #{name_interface_h}\n"
todo << "add to Xcode #{name_ifactory_h}\n"
todo << "add to Xcode #{name_ifactory_cpp}\n"
todo << "add to Xcode #{name_class_h}\n"
todo << "add to Xcode #{name_class_cpp}\n"
todo << "add to Xcode #{name_factory_h}\n"
todo << "add to Xcode #{name_factory_cpp}\n"
todo << "implement #{name_class_h}\n"
todo << "implement #{name_class_cpp}\n"
todo << "implement #{name_interface_h}\n"
todo << "implement #{name_factory_h}\n"
todo << "implement #{name_factory_cpp}\n"
todo << "implement #{name_ifactory_h}\n"
todo << "implement #{name_ifactory_cpp}\n"
todo.close

##### TODO Stub the files #####

interface_h.close
ifactory_h.close
ifactory_cpp.close
class_h.close
class_cpp.close
factory_h.close
factory_cpp.close
test_cpp.close

###### Add Files to Visual Studio #####

vcxproj_contents = File.read(path_lyre_vcxproj)

# h files
replaceable = "<ClInclude Include=\"..\\Sourcecode\\Lyre\\IAlter.h\" />"
replacement = replaceable.dup
replacement << "\n    <ClInclude Include=\"..\\Sourcecode\\Lyre\\#{name_interface_h}\" />"
replacement << "\n    <ClInclude Include=\"..\\Sourcecode\\Lyre\\#{name_ifactory_h}\" />"
replacement << "\n    <ClInclude Include=\"..\\Sourcecode\\Lyre\\Private\\#{name_class_h}\" />"
replacement << "\n    <ClInclude Include=\"..\\Sourcecode\\Lyre\\Private\\#{name_factory_h}\" />"
vcxproj_contents.sub!(replaceable, replacement)

# cpp files
replaceable = "<ClCompile Include=\"..\\Sourcecode\\Lyre\\IAlter.cpp\" />"
replacement = replaceable.dup
replacement << "\n    <ClCompile Include=\"..\\Sourcecode\\Lyre\\#{name_ifactory_cpp}\" />"
replacement << "\n    <ClCompile Include=\"..\\Sourcecode\\Lyre\\Private\\#{name_class_cpp}\" />"
replacement << "\n    <ClCompile Include=\"..\\Sourcecode\\Lyre\\Private\\#{name_factory_cpp}\" />"
vcxproj_contents.sub!(replaceable, replacement)

puts vcxproj_contents

vcxproj_file = File.open(path_lyre_vcxproj, 'w')
vcxproj_file << vcxproj_contents
vcxproj_file.close

__END__
<ClCompile Include="..\Sourcecode\Lyre\IAlter.cpp" />


replacement << "\n    <ClCompile Include=\"..\\Sourcecode\\LyreTest\\Tests\\#{name_test_cpp}\" />"
