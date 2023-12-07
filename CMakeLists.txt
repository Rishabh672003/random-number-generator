cmake_minimum_required(VERSION 3.9.1)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# add executable
project(random)

# this downloads CPM.cmake that we use for installing dependancies
file(
  DOWNLOAD
  https://github.com/cpm-cmake/CPM.cmake/releases/download/v0.38.3/CPM.cmake
  ${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake
  EXPECTED_HASH SHA256=cc155ce02e7945e7b8967ddfaff0b050e958a723ef7aad3766d368940cb15494
)
# this includes the file
include(${CMAKE_CURRENT_BINARY_DIR}/cmake/CPM.cmake)
# this is the way to add/install new stuff
CPMAddPackage("gh:fmtlib/fmt#10.1.1")
CPMAddPackage("gh:eliaskosunen/scnlib#v1.1.3")

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Debug")
endif()

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  # Debug-specific options and flags
  add_compile_definitions(DEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
else()
  # Release-specific options and flags
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3")
endif()

file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
add_executable(random ${MY_SOURCES})
target_link_libraries(random fmt)
