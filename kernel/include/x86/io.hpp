#pragma once
#include <common/types.hpp>

void inline outb(word_t port, byte_t value) {
  __asm__ volatile("outb %[value], %[port]"
                   :
                   : [value] "a"(value), [port] "Nd"(port));
}

void inline outw(word_t port, word_t value) {
  __asm__ volatile("outw %[value], %[port]"
                   :
                   : [value] "a"(value), [port] "Nd"(port));
}

void inline outl(word_t port, dword_t value) {
  __asm__ volatile("outl %[value], %[port]"
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

word_t inline inw(word_t port) {
  word_t ret;
  __asm__ volatile("inw %[port], %[value]"
                   : [value] "=a"(ret)
                   : [port] "Nd"(port));
  return ret;
}

dword_t inline inl(word_t port) {
  dword_t ret;
  __asm__ volatile("inl %[port], %[value]"
                   : [value] "=a"(ret)
                   : [port] "Nd"(port));
  return ret;
}
