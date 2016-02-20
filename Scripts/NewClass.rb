require 'FIleUtils'

class_name = ARGV[0]
if class_name == nil
	class_name = "Bones"
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

prototype = File.read("IXXXX.h")
prototype.sub!("XXXX", class_name)
interface_h << prototype
interface_h.close

prototype = File.read("IXXXXFactory.h")
prototype.sub!("XXXX", class_name)
ifactory_h << prototype
ifactory_h.close

prototype = File.read("IXXXXFactory.cpp")
prototype.sub!("XXXX", class_name)
ifactory_cpp << prototype
ifactory_cpp.close

prototype = File.read("XXXX.h")
prototype.sub!("XXXX", class_name)
class_h << prototype
class_h.close

prototype = File.read("XXXX.cpp")
prototype.sub!("XXXX", class_name)
class_cpp << prototype
class_cpp.close

prototype = File.read("XXXXFactory.h")
prototype.sub!("XXXX", class_name)
factory_h << prototype
factory_h.close

prototype = File.read("XXXXFactory.cpp")
prototype.sub!("XXXX", class_name)
factory_cpp << prototype
factory_cpp.close

prototype = File.read("TestXXXX.cpp")
prototype.sub!("XXXX", class_name)
test_cpp << prototype
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

vcxproj_file = File.open(path_lyre_vcxproj, 'w')
vcxproj_file << vcxproj_contents
vcxproj_file.close

vcxproj_contents = File.read(path_test_vcxproj)
replaceable = "<ClCompile Include=\"..\\Sourcecode\\LyreTest\\Tests\\TestAlter.cpp\" />"
replacement = replaceable.dup
replacement << "\n    <ClCompile Include=\"..\\Sourcecode\\LyreTest\\Tests\\#{name_test_cpp}\" />"
vcxproj_contents.sub!(replaceable, replacement)

vcxproj_file = File.open(path_test_vcxproj, 'w')
vcxproj_file << vcxproj_contents
vcxproj_file.close






