#!/bin/bash
if [ -d "./build" ]; then
	rm -rf ./build
fi
mkdir build && cd build && conan install .. --build=missing && cmake .. -G "Unix Makefiles" && cmake --build .
cp -r ./../res/ ./bin/
