cmake_minimum_required(VERSION 3.15.0)

project(lvzstd
  VERSION "0.0.1"
  DESCRIPTION "lvzstd"
  LANGUAGES C CXX)

set(NAMESPACE sg)

##
## CMake module paths
##

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/external/libsg_cmake/cmake")

##
## Build options
##

include(DefaultPreamble)

##
## Packages
##

CPMAddPackage(NAME zstd
  GITHUB_REPOSITORY facebook/zstd
  VERSION 1.5.7
  GIT_SHALLOW
  SOURCE_SUBDIR build/cmake
  OPTIONS
  "BUILD_TESTING OFF"
  "ZSTD_LEGACY_SUPPORT OFF"
  "ZSTD_BUILD_PROGRAMS OFF"
  "ZSTD_BUILD_SHARED OFF"
  "ZSTD_BUILD_STATIC ON")

##
## Targets/Sources
##

add_subdirectory(lib)
add_subdirectory(print_errors)

# include(CTest)
# if(BUILD_TESTING)
#   add_subdirectory(test)
# endif()


##
## Postamble
##
include(DefaultPostamble)
