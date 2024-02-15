#include <bootinfo.hpp>
#include <common/attributes.hpp>
#include <debug/serial.hpp>
#include <vlg/printf.hpp>

extern "C" void __noreturn _init(void* test) {
  debug::serial_printf("test %d\n", 228);
  while (true) { __asm__ volatile("hlt"); }
}
