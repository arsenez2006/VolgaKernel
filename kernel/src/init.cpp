#include <common/attributes.hpp>
#include <debug/serial.hpp>

void __declspec(dllimport) dlltest();

extern "C" void __noreturn _init() {
  for (char const* str = "Hello world"; *str != '\0'; ++str) {
    debug::serial_putch(*str);
  }

  dlltest();

  while (true) { __asm__ volatile("hlt"); }
}
