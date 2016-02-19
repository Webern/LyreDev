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

name_interface_h = "I#{class_name}.h"
name_ifactory_h = "I#{class_name}Factory.h"
name_ifactory_cpp = "I#{class_name}Factory.cpp"
name_class_h = "#{class_name}.h"
name_class_cpp = "#{class_name}.cpp"
name_factory_h = "#{class_name}Factory.h"
name_factory_cpp = "#{class_name}Factory.cpp"

File.open("#{path_lyre}/#{name_interface_h}", "w")
File.open("#{path_lyre}/#{name_ifactory_h}", "w")
File.open("#{path_lyre}/#{name_ifactory_cpp}", "w")
File.open("#{path_priv}/#{name_class_h}", "w")
File.open("#{path_priv}/#{name_class_cpp}", "w")
File.open("#{path_priv}/#{name_factory_h}", "w")
File.open("#{path_priv}/#{name_factory_cpp}", "w")

file = File.open(path_xcode_lyre)
xcode_proj = file.read
xcode_proj.gsub(/\r\n?/,"\n")


hex_interface_h = SecureRandom.hex(12).upcase
hex_ifactory_h = SecureRandom.hex(12).upcase
hex_ifactory_cpp = SecureRandom.hex(12).upcase
hex_class_h = SecureRandom.hex(12).upcase
hex_class_cpp = SecureRandom.hex(12).upcase
hex_factory_h =  SecureRandom.hex(12).upcase
hex_factory_cpp = SecureRandom.hex(12).upcase

# cpp only
xcode_proj.sub!( "/* End PBXBuildFile section */", "\t\t#{SecureRandom.hex(12).upcase} /* #{name_ifactory_cpp} in Sources */ = {isa = PBXBuildFile; fileRef = #{hex_ifactory_cpp} /* #{name_ifactory_cpp} */; };\n/* End PBXBuildFile section */")

# both cpp and h
xcode_proj.sub!( "/* End PBXFileReference section */", "\t\t#{hex_ifactory_h} /* #{name_ifactory_h} */ = {isa = PBXFileReference; fileEncoding = 4; lastKnownFileType = sourcecode.c.h; name = #{name_ifactory_h}; path = ../../Sourcecode/Lyre/#{name_ifactory_h}; sourceTree = \"<group>\"; };\n\t\t#{hex_ifactory_cpp} /* #{name_ifactory_cpp} */ = {isa = PBXFileReference; fileEncoding = 4; lastKnownFileType = sourcecode.cpp.cpp; name = #{name_ifactory_cpp}; path = ../../Sourcecode/Lyre/#{name_ifactory_cpp}; sourceTree = \"<group>\"; };\n/* End PBXFileReference section */")

# both cpp and h
replacethis = "\t\t\t);\n\t\t\tname = Sourcecode;\n\t\t\tsourceTree = \"<group>\";\n\t\t};\n/* End PBXGroup section */"
xcode_proj.sub!(replacethis, "\t\t\t\t#{hex_ifactory_h} /* #{name_ifactory_h} */,\n\t\t\t\t#{hex_ifactory_cpp} /* #{name_ifactory_cpp} */\n#{replacethis}")

# cpp only
replacethis = "\t\t\t);\n\t\t\trunOnlyForDeploymentPostprocessing = 0;\n\t\t};\n/* End PBXSourcesBuildPhase section */"
xcode_proj.sub!(replacethis, "\t\t\t\t#{hex_ifactory_cpp} /* #{name_ifactory_cpp} in Sources */\n#{replacethis}")

output = File.open("#{path_xcode_lyre}.new", "w")
output << xcode_proj
output.close
__END__

				29E4D2231C06C7400038E6FC /* TupletDefFatory.h */,
				29109DE81BE559F2001FF3E6 /* TypeDefs.h */,
			);
			name = Sourcecode;
			sourceTree = "<group>";
		};
/* End PBXGroup section */