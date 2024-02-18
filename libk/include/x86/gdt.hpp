#pragma once
#include <common/attributes.hpp>
#include <common/types.hpp>

namespace x86 {

  class KAPI GDTent {
  public:
    static void load(void* gdt, word_t size);

  public:
    void set_null() noexcept;
    void set_data(dword_t base, dword_t limit, byte_t dpl) noexcept;
    void set_code(dword_t base, dword_t limit, byte_t dpl) noexcept;

  private:
    qword_t m_data;
  };

} // namespace x86
