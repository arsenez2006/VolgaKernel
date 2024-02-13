#pragma once

#if defined(libk_EXPORTS)
#  define KAPI __declspec(dllexport)
#else
#  define KAPI __declspec(dllimport)
#endif

#define __noreturn __attribute__((noreturn))
