if(__VOLGAOS_CLANG)
    return()
endif(__VOLGAOS_CLANG)

set(__VOLGAOS_CLANG 1)

macro(__volgaos_compiler_clang lang)
    # Compile options
    set(CMAKE_${lang}_COMPILER_TARGET "x86_64-pc-win32")
    set(CMAKE_${lang}_FLAGS "-ffreestanding -nodefaultlibs")

    # Link executable rules
    set(CMAKE_${lang}_LINK_EXECUTABLE "<CMAKE_${lang}_COMPILER> -fuse-ld=lld-link -nostartfiles -nostdlib <FLAGS> <CMAKE_${lang}_LINK_FLAGS> -Xlinker /entry:main <LINK_FLAGS> <OBJECTS> -o <TARGET> -Xlinker /implib:<TARGET_IMPLIB> -Xlinker /pdb:<TARGET_PDB> -Xlinker /subsystem:native -Xlinker /machine:x64 -Xlinker /dynamicbase -Xlinker /base:0x100000 -Xlinker /version:<TARGET_VERSION_MAJOR>.<TARGET_VERSION_MINOR> ${CMAKE_GNULD_IMAGE_VERSION} <LINK_LIBRARIES> <MANIFESTS>")

    # Link shared library rules
    set(CMAKE_${lang}_CREATE_SHARED_LIBRARY "<CMAKE_${lang}_COMPILER> -fuse-ld=lld-link -nostartfiles -nostdlib <CMAKE_SHARED_LIBRARY_${lang}_FLAGS> <LANGUAGE_COMPILE_FLAGS> <LINK_FLAGS> <CMAKE_SHARED_LIBRARY_CREATE_${lang}_FLAGS> -o <TARGET> ${CMAKE_GNULD_IMAGE_VERSION} -Xlinker /implib:<TARGET_IMPLIB> -Xlinker /pdb:<TARGET_PDB> -Xlinker /subsystem:native -Xlinker /machine:x64 -Xlinker /dynamicbase -Xlinker /base:0x100000 -Xlinker /version:<TARGET_VERSION_MAJOR>.<TARGET_VERSION_MINOR> <OBJECTS> <LINK_LIBRARIES> <MANIFESTS>")
endmacro(__volgaos_compiler_clang lang)
