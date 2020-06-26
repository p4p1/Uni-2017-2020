# Babel
65;5601;1c
## How to install:

To install be insured that the build/ project does not exist and run the
build.sh script on your linux distribution.
```
build.sh
```
You can also do the following command:
```
sudo pip3 install -U conan && mkdir build && cd build && conan intall .. \
--build=missing && cmake .. && make && ./bin/babel
```