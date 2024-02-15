#pragma once
#include <common/attributes.hpp>

namespace debug {

  KAPI void serial_putch(char ch);

  KAPI int  __print_fmt(1, 2) serial_printf(char const* format, ...);

} // namespace debug
