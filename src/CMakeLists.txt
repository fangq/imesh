#################################################################
#  CMake configure file for Monte Carlo eXtreme (MCX)
#  Qianqian Fang <q.fang at neu.edu>
#  2018/08/26
#################################################################

cmake_minimum_required(VERSION 3.3)

project(mcx)

execute_process(COMMAND CMD /c grep -o -E "\'\\s[0-9]\.[0-9]+\'" /usr/include/CGAL/version.h OUTPUT_VARIABLE CGALVER)

if(CGALVER GREATER_EQUAL 5.0)
   set(CGALLIB '')
   set(CGALIMG '')
else()
   set(CGALLIB 'CGAL')
   set(CGALIMG 'CGAL_ImageIO')
endif()

find_package(ZLIB REQUIRED)

add_subdirectory(zmat)

# C Options
set(CMAKE_C_FLAGS "-g -Wall -fPIC")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../lib)

# Add include directories
include_directories(cjson ubj zmat zmat/easylzma)

# Add link directories
link_directories(zmat)

# Create mcx library
add_library(bjd STATIC
    cjson/cJSON.c
    cjson/cJSON.h
    ubj/ubj.h
    ubj/ubjw.c
    )

# Add all project units
add_executable(
    imesh
    imesh.cpp
    )

# Link options
target_link_libraries(
    imesh
    bjd
    zmat
    ${CGALLIB}
    ${CGALIMG}
    gmp
    mpfr
    ZLIB::ZLIB
    )
