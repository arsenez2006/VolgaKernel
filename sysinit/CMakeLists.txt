cmake_minimum_required(VERSION 3.20)
project(sysinit)

# SysInit sources
file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.hpp")

# Output symbols map
set(SYM_MAP "${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

# Link Options
list(APPEND LINK_OPTIONS
    "/map:${SYM_MAP}"
    "/noentry"
)
string(REPLACE ";" "," LINK_OPTIONS "${LINK_OPTIONS}")

add_library(${PROJECT_NAME} SHARED EXCLUDE_FROM_ALL ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME} PUBLIC "include")

# Configure linking
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,${LINK_OPTIONS}")
set_target_properties(${PROJECT_NAME} PROPERTIES POSITION_INDEPENDENT_CODE FALSE)
target_link_libraries(${PROJECT_NAME} libk)

add_custom_target(${PROJECT_NAME}_copy
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT}/$<TARGET_FILE_NAME:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
)

# Update dependencies
list(APPEND KERNEL_DEPS ${PROJECT_NAME}_copy)
set(KERNEL_DEPS ${KERNEL_DEPS} PARENT_SCOPE)
