cmake_minimum_required(VERSION 3.16)
project(divided_worms VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Expose headers in include/
include_directories(${CMAKE_SOURCE_DIR}/include)

# Recursively collect all .cpp files in src/
file(GLOB_RECURSE SRC_FILES
        "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

# Add executable
add_executable(${PROJECT_NAME} ${SRC_FILES} main.cpp)

# If you have config headers to install or generate:
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/config
>>>>>>> 12bae4e (cmake changes)
)
