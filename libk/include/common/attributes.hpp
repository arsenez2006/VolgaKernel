#pragma once

#if defined(libk_EXPORTS)
#  define KAPI __declspec(dllexport)
#else
#  define KAPI __declspec(dllimport)
#endif

#define __noreturn           __attribute__((noreturn))
#define __packed             __attribute__((packed))
#define __print_fmt(fmt, va) __attribute__((format(printf, fmt, va)))
