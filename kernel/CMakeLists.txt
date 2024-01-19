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
add_executable(${PROJECT_NAME} ${SRCS} ${HDRS})
target_include_directories(${PROJECT_NAME} PRIVATE "include")

# Configure linking
target_link_options(${PROJECT_NAME} PRIVATE "-Wl,${LINK_OPTIONS}")
