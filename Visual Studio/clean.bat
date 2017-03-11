msbuild.exe Lyre.sln /p:Platform=x64;Configuration=Debug /t:clean
if exist ".\Outputs\" rd /q /s ".\Outputs\"
if exist ".\Intermediates\" rd /q /s ".\Intermediates\"
if exist ".\TestResults\" rd /q /s ".\TestResults\"