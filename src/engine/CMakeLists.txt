add_library(libEngine engine.cpp)

#TODO sfml lib im ganzen projekt aktivieren
set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(libEngine sfml-system sfml-window sfml-graphics)

target_include_directories(libEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})