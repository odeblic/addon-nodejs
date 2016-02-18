#!/bin/sh

rm -rf nodejs/build

rm -rf native/Makefile
rm -rf native/CMakeCache.txt
rm -rf native/CMakeFiles
rm -rf native/cmake_install.cmake
rm -rf native/cpp/target

find . -name "*~" -delete

