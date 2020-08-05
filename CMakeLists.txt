cmake_minimum_required(VERSION 3.10)

project(ziplib)

if(CMAKE_CXX_COMPILER_ID MATCHES Clang AND CMAKE_C_COMPILER_ID MATCHES Clang)
    set(CMAKE_C_FLAGS "-fPIC -Wno-enum-conversion -O3")
    set(CMAKE_CXX_FLAGS "-fPIC -std=c++11 -O3")
endif()
if(CMAKE_CXX_COMPILER_ID MATCHES MSVC AND CMAKE_C_COMPILER_ID MATCHES MSVC)
    set(CMAKE_C_FLAGS "")
    set(CMAKE_CXX_FLAGS "/EHsc")
endif()

file(GLOB SOURCES
  "Source/ZipLib/*.cpp"
  "Source/ZipLib/detail/*.cpp"
  "Source/ZipLib/extlibs/zlib/*.c"
  "Source/ZipLib/extlibs/bzip2/*.c"
)

if(WIN32)
    file(GLOB LZMA_SOURCES "Source/ZipLib/extlibs/lzma/*.c")
else()
    file(GLOB LZMA_SOURCES "Source/ZipLib/extlibs/lzma/unix/*.c")
endif()

list(APPEND SOURCES ${LZMA_SOURCES})

add_library(ziplib STATIC ${SOURCES})
target_include_directories(ziplib PUBLIC ${PROJECT_SOURCE_DIR}/Source/ZipLib)

install(TARGETS ziplib
        LIBRARY DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/Source/ZipLib
        DESTINATION include
        FILES_MATCHING PATTERN "*.h")

