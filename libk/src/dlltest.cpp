#include <dlltest.hpp>
#include <stdint.h>

typedef uint8_t  byte_t;
typedef uint16_t word_t;
typedef uint32_t dword_t;
typedef uint64_t qword_t;

void inline outb(word_t port, byte_t value) {
  __asm__ volatile("outb %[value], %[port]"
                   :
                   : [value] "a"(value), [port] "Nd"(port));
}

byte_t inline inb(word_t port) {
  byte_t ret;
  __asm__ volatile("inb %[port], %[value]"
                   : [value] "=a"(ret)
                   : [port] "Nd"(port));
  return ret;
}

void inline serial_putch(char ch) {
  while ((inb(0x3F8 + 5) & 0x20) == 0) { continue; }
  outb(0x3F8, ch);
}

void dlltest() {
  for (char const* str = "Dll test"; *str != '\0'; ++str) {
    serial_putch(*str);
  }
}
