cmake_minimum_required(VERSION 3.20)
project(libk)

# LibK Sources
file(GLOB_RECURSE SRCS "src/*.cpp")
file(GLOB_RECURSE HDRS "include/*.hpp")

# Output symbols map
set(SYM_MAP "${PROJECT_BINARY_DIR}/${PROJECT_NAME}.map")

# Link Options
list(APPEND LINK_OPTIONS
    "/map:${SYM_MAP}"
)
string(REPLACE ";" "," LINK_OPTIONS "${LINK_OPTIONS}")

add_library(${PROJECT_NAME} SHARED EXCLUDE_FROM_ALL ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME} PUBLIC "include")

# Configure linking
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,${LINK_OPTIONS}")

# Update dependencies
list(APPEND KERNEL_DEPS ${PROJECT_NAME})
set(KERNEL_DEPS ${KERNEL_DEPS} PARENT_SCOPE)
