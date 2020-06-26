cmake_minimum_required(VERSION 2.8.12)
project(Babel)
add_definitions("-fPIC")
SET(CMAKE_CXX_FLAGS_DEBUG "-g3")
find_package(Boost REQUIRED system)
find_package(Threads)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

include_directories(include)
include_directories(include/server)
include_directories(include/client)
include_directories(include/audio)

conan_basic_setup()

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Qt5Widgets CONFIG REQUIRED)
find_package(Qt5Network CONFIG REQUIRED)

include_directories(${CMAKE_INCLUDE_PATH})

add_executable(babel_client
  src/client/main.cpp
  src/client/sockettest.cpp
  src/client/Udp.cpp
  include/client/sockettest.hpp
  include/client/Udp.hpp
  src/audio/Play.cpp
  src/audio/Record.cpp
  #src/audio/audio.cpp
  #src/audio/Opus.cpp
)

add_executable(babel_audio
  #src/audio/main.cpp
  #src/audio/audio.cpp
  #src/audio/Opus.cpp
  #src/audio/main.cpp
  src/audio/test_audio.cpp
  src/audio/Play.cpp
  src/audio/Record.cpp
  include/client/Udp.hpp
  src/client/Udp.cpp
)

add_executable(babel_server
  src/server/Session.cpp
  src/server/Server.cpp
  src/server/main.cpp
  src/server/Room.cpp
)

target_link_libraries(babel_client
  ${Boost_LIBRAIRIES}
  ${CMAKE_THREAD_LIBS_INIT}
  pthread
)

target_link_libraries(babel_server
  ${Boost_LIBRAIRIES}
  pthread
  boost_system
)

target_link_libraries(babel_client ${CONAN_LIBS}
  Qt5::Widgets
  Qt5::Network
  Qt5::Core
  Qt5::Gui
)
target_link_libraries(babel_server ${CONAN_LIBS}
  Qt5::Widgets
)

target_link_libraries(babel_audio ${CONAN_LIBS}
  Qt5::Widgets
  Qt5::Network
  Qt5::Core
  Qt5::Gui
)
