cmake_minimum_required(VERSION 3.20)
set(CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/cmake)
include(cmake/toolchain.cmake)
project(VolgaKernel)

include(cmake/options.cmake)

add_subdirectory(libk)
add_subdirectory(kernel)

add_custom_target(${PROJECT_NAME} ALL
    DEPENDS ${KERNEL_DEPS}
)
