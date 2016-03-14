########################################################################
# Build stuff
########################################################################

cmake_minimum_required(VERSION 2.8.7)
project(learnsoapy C CXX)

macro(use_c99)
    if (CMAKE_VERSION VERSION_LESS "3.1")
        if (CMAKE_C_COMPILER_ID STREQUAL "GNU")
            set (CMAKE_C_FLAGS "--std=gnu99 ${CMAKE_C_FLAGS}")
        endif ()
    else ()
        set (CMAKE_C_STANDARD 99)
    endif ()
endmacro(use_c99)
use_c99()

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#find_package(LibSDRplay)
#find_package(SoapySDR "0.4.0" NO_MODULE REQUIRED)
find_package(SoapySDR "0.4.0" REQUIRED)
include_directories(${SOAPY_SDR_INCLUDE_DIR})
SET(OTHER_LIBRARIES ${SOAPY_SDR_LIBRARY} ${OTHER_LIBRARIES})
ADD_DEFINITIONS(
    -DUSE_SOAPY_SDR=1
)

add_executable(soppy soppy.c)
add_executable(soppy++ soppy++.cpp)
set_source_files_properties(soppy.c PROPERTIES LANGUAGE CXX)
target_link_libraries(soppy ${OTHER_LIBRARIES})
target_link_libraries(soppy++ ${OTHER_LIBRARIES})
