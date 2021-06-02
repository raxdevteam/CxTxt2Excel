cmake_minimum_required(VERSION 3.5)

#project(CxTxt2Excel LANGUAGES CXX)

project( CxTxt2Excel
         # Note: the following fields are optional
         DESCRIPTION "Any text to excel, pdf, json, sql or xml generator"
         VERSION     1.0
         LANGUAGES    CXX
       )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}"  "-std=c++17 -g -Wall -Wextra -pendantic -O0" )

FILE(GLOB_RECURSE INC_FILES "include/*.h")
FILE(GLOB_RECURSE SRC_FILES "src/*.cpp")
include_directories("include")

#message(" [INFO]  System Name  - CMAKE_SYSTEM_NAME     = ${CMAKE_SYSTEM_NAME}")
#message(" [INFO]  Build type   - CMAKE_BUILD_TYPE      = ${CMAKE_BUILD_TYPE}")
#message(" [INFO]  Compiler ID  - CMAKE_CXX_COMPILER_ID = ${CMAKE_CXX_COMPILER_ID}")
#message(" [INFO]  Install path - CMAKE_INSTALL_PREFIX  = ${CMAKE_INSTALL_PREFIX} ")
#if(CMAKE_SIZEOF_VOID_P EQUAL 8)
#   message(" [INFO] Target = 64 bits build.")
#else()
#   message(" [INFO] Target = 32 bits build.")
#endif()

#message(" [INFO] CMake binary dir = ${CMAKE_BINARY_DIR}")
#message(" [INFO] CMakeLists.txt is in the directory ${CMAKE_CURRENT_LIST_DIR}")

include_directories(/usr/include)
include_directories(/usr/local/include/xlsxwriter)

link_directories(/usr/lib)
link_directories(/usr/local/lib)
link_directories(/usr/lib/x86_64-linux-gnu)
link_directories(/usr/lib/gcc/x86_64-linux-gnu/9)

add_executable(CxTxt2Excel ${INC_FILES} ${SRC_FILES})

target_link_libraries(CxTxt2Excel z)
target_link_libraries(CxTxt2Excel stdc++fs)
target_link_libraries(CxTxt2Excel xlsxwriter)
