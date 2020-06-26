#!/bin/bash
#sudo pip3 uninstall conan
sudo pip uninstall conan
sudo pip3 install -U conan
mkdir build && cd build && conan install .. --build=missing && cmake ..
make -C build/
./build/bin/babel
