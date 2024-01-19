extern "C" void __attribute__((noreturn)) _init() {
  while (true) { __asm__ volatile("hlt"); }
}
