#include <x86/gdt.hpp>

using x86::GDTent;

void GDTent::load(void* gdt, word_t size) {
  struct {
    word_t length;
    void*  base;
  } GDTR = { .length = size, .base = gdt };

  __asm__ volatile("lgdt %[gdtr]"
                   :
                   : [gdtr] "m"(GDTR));
}

void GDTent::set_null() noexcept { m_data = 0; }

void GDTent::set_data(dword_t base, dword_t limit, byte_t dpl) noexcept {
  qword_t limitl = limit & 0xFFFF;
  qword_t limith = ((qword_t)limit & 0xF0000) << (48 - 16);
  qword_t basel  = ((qword_t)base & 0xFFFFFF) << 16;
  qword_t baseh  = ((qword_t)base & 0xFF000000) << (56 - 24);
  qword_t access = ((qword_t)0x92 | ((dpl & 3) << 5)) << 40;
  qword_t flags  = ((qword_t)0xC) << 52;
  m_data         = limitl | limith | basel | baseh | access | flags;
}

void GDTent::set_code(dword_t base, dword_t limit, byte_t dpl) noexcept {
  qword_t limitl = limit & 0xFFFF;
  qword_t limith = ((qword_t)limit & 0xF0000) << (48 - 16);
  qword_t basel  = ((qword_t)base & 0xFFFFFF) << 16;
  qword_t baseh  = ((qword_t)base & 0xFF000000) << (56 - 24);
  qword_t access = ((qword_t)0x9A | ((dpl & 3) << 5)) << 40;
  qword_t flags  = ((qword_t)0xA) << 52;
  m_data         = limitl | limith | basel | baseh | access | flags;
}
