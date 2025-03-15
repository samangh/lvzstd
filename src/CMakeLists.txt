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

##
## Targets/Sources
##

add_subdirectory(lib)

# include(CTest)
# if(BUILD_TESTING)
#   add_subdirectory(test)
# endif()


##
## Postamble
##
include(DefaultPostamble)
