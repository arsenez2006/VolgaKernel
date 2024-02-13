#include <debug/serial.hpp>
#include <x86/io.hpp>

void debug::serial_putch(char ch) {
  while ((inb(0x3F8 + 5) & 0x20) == 0) { continue; }
  outb(0x3F8, ch);
}
