cmake_minimum_required(VERSION 2.8.12)

project(rtype)
add_definitions("-fPIC")
set(CMAKE_CXX_FLAGS_DEBUG "-g3")
find_package(Threads)

include (${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

include_directories(include)
include_directories(include/server)
include_directories(include/client)
include_directories(include/Exception)

conan_basic_setup()

add_executable(r-type_client
	src/protocol.cpp
	src/client/main.cpp
	src/client/Client.cpp
	src/client/Menu.cpp
	src/client/Network.cpp
	src/client/SFML.cpp
)

add_executable(r-type_server
	src/protocol.cpp
	src/server/main.cpp
	src/server/server.cpp
	src/server/Engine.cpp
)

target_link_libraries(r-type_server
	pthread ${CONAN_LIBS}
)

target_link_libraries(r-type_client ${CONAN_LIBS})
