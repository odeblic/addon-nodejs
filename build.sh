#!/bin/sh

export LD_LIBRARY_PATH=$PWD/native/cpp/target

cd native
cmake . && make -j
cd -

cd nodejs
node-gyp configure build
cd -

nodejs test.js

