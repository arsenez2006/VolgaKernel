#include <common/attributes.hpp>
#include <debug/serial.hpp>

extern "C" void __noreturn _init() {
  while (true) { __asm__ volatile("hlt"); }
}
