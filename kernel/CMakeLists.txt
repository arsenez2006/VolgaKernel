cmake_minimum_required(VERSION 3.20)
project(kernel)

# Kernel Sources
file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.hpp")

# Output symbols map
set(SYM_MAP "${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

# Link Options
list(APPEND LINK_OPTIONS
    "/entry:_init"
    "/map:${SYM_MAP}"
)
string(REPLACE ";" "," LINK_OPTIONS "${LINK_OPTIONS}")

# Add kernel target
add_executable(${PROJECT_NAME} EXCLUDE_FROM_ALL ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

# Configure linking
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,${LINK_OPTIONS}")
target_link_libraries(${PROJECT_NAME} libk)

add_custom_target(${PROJECT_NAME}_copy
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:${PROJECT_NAME}> ${OUTPUT}/$<TARGET_FILE_NAME:${PROJECT_NAME}>
    DEPENDS ${PROJECT_NAME}
)

# Update dependencies
list(APPEND KERNEL_DEPS ${PROJECT_NAME}_copy)
set(KERNEL_DEPS ${KERNEL_DEPS} PARENT_SCOPE)
