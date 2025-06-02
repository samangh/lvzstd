# -*- mode: shell-script -*-

DIR=build-x86_64

cmake -S . -B ${DIR} -DBUILD_SHARED_LIBS=OFF -DCMAKE_BUILD_TYPE=Release -DIPO=ON
cmake --build ${DIR} --config Release
cp ${DIR}/lib/liblvzstd.so ../libs/liblvzstd-x86_64.so

