cmake_minimum_required(VERSION 3.26)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(src)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

target_link_libraries(FlappyBird sfml-system sfml-window sfml-graphics sfml-audio)
file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})