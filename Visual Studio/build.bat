@ECHO off
set test="cpul"

IF "%1"=="vstest" (
	ECHO branched
	set test="vstest"
	)

if %test%=="vstest" (
	ECHO VS Test Build
	msbuild.exe Lyre.sln /p:Platform=x64;Configuration=Debug;TestPlatform=vstest /m
	msbuild.exe LyreTest.vcxproj /p:Platform=x64;Configuration=Debug;TestPlatform=vstest /target:messages /m
	vstest.console.exe .\Outputs\x64_debug\LyreTest.dll /Platform:x64 /Framework:framework45 /Enablecodecoverage /InIsolation
	)

if %test%=="cpul" (
	ECHO CppUnitLite Build
	msbuild.exe Lyre.sln /p:Platform=x64;Configuration=Debug;TestPlatform=cpul /m
	msbuild.exe LyreTest.vcxproj /p:Platform=x64;Configuration=Debug;TestPlatform=cpul /target:messages /m
	.\Outputs\x64_debug\LyreTest.exe
	)