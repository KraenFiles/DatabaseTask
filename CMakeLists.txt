cmake_minimum_required(VERSION 3.11)
project (CitiesDb VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_SOURCE_DIR}/ui_files)

if (CMAKE_BUILD_TYPE STREQUAL "Release")
  message("Release mode")
  set(RELEASE 1)
elseif(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message("Debug mode")
  set(RELEASE 0)
elseif(CMAKE_BUILD_TYPE STREQUAL "Test")
  message("Test mode")
  set(RELEASE 0)
  set(TEST_MODE 1)
else()
  message("Default mode")
  set(RELEASE 0)
endif()

file(GLOB_RECURSE SOURCES RELATIVE ${CMAKE_SOURCE_DIR}
  "include/**.h"
  "include/**.hpp"
  "src/**.cpp"
  "src/**.c"
  "ui_files/**.ui"
)

find_package(Qt5 COMPONENTS Widgets Sql REQUIRED)

add_executable(CitiesDb ${SOURCES})
target_link_libraries(CitiesDb Qt5::Widgets Qt5::Sql)

include(FetchContent)

if(RELEASE EQUAL 1)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O2 -Wextra -Wpedantic -Wall")
  add_definitions(-DRELEASE)
else()
  add_definitions(-DDEBUG)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -Wextra -Wpedantic -Wall")
  if(TEST_MODE EQUAL 1)
  endif()
endif()
      
include_directories(include)
include_directories(ui_files)
set(SOURCE_DIR src)
set(BUILD_DIR build)
set_target_properties(CitiesDb PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
