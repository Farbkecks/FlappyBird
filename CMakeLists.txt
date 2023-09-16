cmake_minimum_required(VERSION 3.26)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 17)

add_executable(FlappyBird src/main.cpp src/engine.cpp
        src/bird.cpp
        headers/bird.h
        headers/helperFuntions.h
        src/pipe.cpp
        headers/pipe.h
        src/pipe.cpp
        headers/constants.h
        src/helperFunktions.cpp
        src/scene.cpp
        headers/scene.h
        src/scene.cpp
        headers/scene.h
        src/runningscene.cpp
        headers/runningscene.h
        src/breakscene.cpp
        headers/breakscene.h
)

# Copy dlls to build
if (WIN32)
    message(Windows)
    #Warning check if correct Path
    include_directories(headers c:/SFML/include)

    #Warning check if correct Path
    set(SFML_ROOT c:/SFML)
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
    find_package(SFML REQUIRED system window graphics)
    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(FlappyBird ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif ()

    file(COPY assets DESTINATION ${CMAKE_BINARY_DIR})

    file(GLOB BINARY_DEP_DLLS "${SFML_INCLUDE_DIR}/../bin/*.dll")
    file(COPY ${BINARY_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
    #Warning check if correct Path
    file(GLOB MINGW_DEP_DLLS "C:/mingw64_13.1.0/bin/*.dll")
    file(COPY ${MINGW_DEP_DLLS} DESTINATION ${CMAKE_BINARY_DIR})
endif ()
if (APPLE)
    message(Apple)
    #Warning check if correct Path
    include_directories(headers /opt/homebrew/Cellar/sfml/2.6.0/include)

    #Warning check if correct Path
    set(SFML_ROOT /opt/homebrew/Cellar/sfml)
    set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
    find_package(SFML REQUIRED system window graphics)
    if (SFML_FOUND)
        include_directories(${SFML_INCLUDE_DIR})
        target_link_libraries(FlappyBird ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
    endif ()
endif ()
