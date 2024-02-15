#pragma once
#include <common/attributes.hpp>
#include <common/types.hpp>
#include <stdarg.h>

namespace vlg {

  KAPI int vsnprintf(char* s, size_t n, char const* format, va_list va);

  KAPI int __print_fmt(3, 4)
      snprintf(char* s, size_t n, char const* format, ...);

  KAPI int __print_fmt(2, 3) sprintf(char* s, char const* format, ...);

  KAPI int cbvprintf(
      void (*cb)(char ch, void* arg), void* arg, char const* format, va_list va
  );

  KAPI int __print_fmt(3, 4) cbprintf(
      void (*cb)(char ch, void* arg), void* arg, char const* format, ...
  );

} // namespace vlg
