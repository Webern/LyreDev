msbuild.exe Lyre.sln /p:Platform=x64;Configuration=Debug /m
REM vstest.console.exe .\Outputs\x64_debug\LyreTest.dll /Platform:x64 /Framework:framework45 /Enablecodecoverage /InIsolation
.\Outputs\x64_debug\LyreTest.exe