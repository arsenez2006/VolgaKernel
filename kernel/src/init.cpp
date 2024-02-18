#include <bootinfo.hpp>
#include <common/attributes.hpp>
#include <debug/serial.hpp>
#include <sysinit.hpp>

extern "C" void __noreturn _init(void* bootinfo) {
  init_info initinfo;
  sysinit(bootinfo, &initinfo);

  while (true) { __asm__ volatile("hlt"); }
}
