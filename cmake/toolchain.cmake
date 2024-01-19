set(CMAKE_SYSTEM_NAME Generic)

find_program(CMAKE_C_COMPILER "clang" REQUIRED)
find_program(CMAKE_CXX_COMPILER "clang++" REQUIRED)

set(CMAKE_C_COMPILER_WORKS TRUE)
set(CMAKE_CXX_COMPILER_WORKS TRUE)

set(CMAKE_C_FLAGS "-target x86_64-pc-win32" CACHE STRING "" FORCE)
set(CMAKE_CXX_FLAGS "${CMAKE_C_FLAGS}" CACHE STRING "" FORCE)

list(APPEND LINK_FLAGS
    "/machine:x64"
    "/subsystem:native"
    "/base:0x100000"
    "/dynamicbase"
)
string(REPLACE ";" "," LINK_FLAGS "${LINK_FLAGS}")

set(CMAKE_EXE_LINKER_FLAGS "-fuse-ld=lld -nostdlib -Wl,${LINK_FLAGS}" CACHE STRING "" FORCE)
