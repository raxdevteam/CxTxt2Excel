cmake_minimum_required(VERSION 3.5)

project( CxTxt2Excel
         # Note: the following fields are optional
         DESCRIPTION "Any text to excel convertor"
         VERSION     1.0
         LANGUAGES   CXX
       )

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}"  "-std=c++17 -g -Wall -Wextra -pendantic -O0" )

FILE(GLOB_RECURSE INC_FILES "include/*.h")
FILE(GLOB_RECURSE SRC_FILES "src/*.cpp")
include_directories("include")


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
