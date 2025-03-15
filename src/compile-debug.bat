cmake -S . -B build-x86-debug -DBUILD_SHARED_LIBS=OFF -DUSE_STATIC_RUNTIME=ON -DCMAKE_TOOLCHAIN_FILE=C:/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=x64-windows-static -DCMAKE_BUILD_TYPE=Debug -A Win32

cmake --build build-x86-debug --config Debug
