function(import_VolgaKernel)
    cmake_parse_arguments(
        ARG
        ""
        "PATH;OUTPUT"
        ""
        ${ARGN}
    )

    ExternalProject_Add(VolgaKernel
        SOURCE_DIR ${ARG_PATH}
        BINARY_DIR ${ARG_PATH}/build
        EXCLUDE_FROM_ALL TRUE
        STEP_TARGETS build

        CMAKE_CACHE_ARGS
        "-DOUTPUT:PATH=${ARG_OUTPUT}"
    )

    set(VOLGAKERNEL_TARGET VolgaKernel-build PARENT_SCOPE)
endfunction(import_VolgaKernel)
