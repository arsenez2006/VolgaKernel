cmake_minimum_required(VERSION 3.20)
include(cmake/toolchain.cmake)
project(VolgaKernel)

include(cmake/options.cmake)

add_subdirectory(libk)
add_subdirectory(kernel)

add_custom_target(${PROJECT_NAME} ALL
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:kernel> ${OUTPUT}/kernel.pe
    DEPENDS ${KERNEL_DEPS}
)
