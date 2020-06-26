cmake_minimum_required(VERSION 3.0)
 
project(asio_async)
add_definitions("-fPIC")
find_package(Boost REQUIRED system)
find_package(Threads)

include_directories(${CMAKE_INCLUDE_DIR})

include_directories(include)

add_executable(client
    client.cpp
)
 
add_executable(server
    server.cpp
)

target_link_libraries(client
    ${Boost_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT}
    pthread
)
 
target_link_libraries(server
  ${Boost_LIBRARIES}
  pthread
)
