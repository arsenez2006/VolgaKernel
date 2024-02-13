#pragma once
#include <common/types.hpp>

qword_t inline rdtsc() {
  dword_t low, high;
  __asm__ volatile("rdtsc"
                   : "=a"(low), "=d"(high));
  return ((qword_t)high << 32) | low;
}

void inline wrmsr(qword_t msr, qword_t value) {
  dword_t low = value & 0xFFFFFFFF, high = value >> 32;
  __asm__ volatile("wrmsr"
                   :
                   : "c"(msr), "a"(low), "d"(high));
}

qword_t inline rdmsr(qword_t msr) {
  dword_t low, high;
  __asm__ volatile("rdmsr"
                   : "=a"(low), "=d"(high)
                   : "c"(msr));
  return ((qword_t)high << 32) | low;
}
