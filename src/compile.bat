@rem -*- mode: bat -*-
@echo off

set X86_DIR=build-x86
set X64_DIR=build-x86_64

cmake -S . -B %X86_DIR% ^
  -DBUILD_SHARED_LIBS=OFF -DUSE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release -A Win32

cmake -S . -B %X64_DIR% ^
  -DBUILD_SHARED_LIBS=OFF -DUSE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release

cmake --build %X86_DIR% --config Release
cmake --build %X64_DIR% --config Release

copy %X64_DIR%\lib\Release\lvzstd.dll ..\libs\lvzstd-x86_64.dll
copy %X86_DIR%\lib\Release\lvzstd.dll ..\libs\lvzstd-x86.dll

