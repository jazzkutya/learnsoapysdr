########################################################################
# Build stuff
########################################################################
cmake_minimum_required(VERSION 2.8.7)
project(learnsoapy C)

# list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR})
#find_package(LibSDRplay)
#find_package(SoapySDR "0.4.0" NO_MODULE REQUIRED)
find_package(SoapySDR "0.4.0" NO_MODULE REQUIRED)
include_directories(${SOAPY_SDR_INCLUDE_DIR})
SET(OTHER_LIBRARIES ${SOAPY_SDR_LIBRARY} ${OTHER_LIBRARIES})
ADD_DEFINITIONS(
    -DUSE_SOAPY_SDR=1
)

add_executable(soppy soppy.c)
target_link_libraries(soppy ${OTHER_LIBRARIES})
