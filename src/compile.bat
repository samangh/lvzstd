@rem -*- mode: bat -*-
@echo off

cmake -S . -B build-x86 ^
  -DBUILD_SHARED_LIBS=OFF -DUSE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release -A Win32

cmake -S . -B build-x86_64 ^
  -DBUILD_SHARED_LIBS=OFF -DUSE_STATIC_RUNTIME=ON -DCMAKE_BUILD_TYPE=Release

cmake --build build-x86    --config Release
cmake --build build-x86_64 --config Release
