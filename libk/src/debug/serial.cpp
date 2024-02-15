#include <debug/serial.hpp>
#include <vlg/printf.hpp>
#include <x86/io.hpp>

static void _kprintf_serial(char ch, void*) {
  if (ch == '\n') {
    debug::serial_putch('\r');
    debug::serial_putch('\n');
  } else {
    debug::serial_putch(ch);
  }
}

void debug::serial_putch(char ch) {
  while ((inb(0x3F8 + 5) & 0x20) == 0) { continue; }
  outb(0x3F8, ch);
}

int debug::serial_printf(char const* format, ...) {
  va_list va;
  int     ret;

  va_start(va, format);
  ret = vlg::cbvprintf(_kprintf_serial, nullptr, format, va);
  va_end(va);

  return ret;
}
