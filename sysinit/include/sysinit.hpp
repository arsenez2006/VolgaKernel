#pragma once

#if defined(sysinit_EXPORTS)
#  define SYSINITAPI _declspec(dllexport)
#else
#  define SYSINITAPI _declspec(dllimport)
#endif

struct init_info {};

SYSINITAPI int sysinit(void* bootinfo, init_info* initinfo);
