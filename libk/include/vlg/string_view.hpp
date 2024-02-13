#pragma once
#include <common/attributes.hpp>
#include <common/types.hpp>

namespace vlg {

  class KAPI string_view {
  public:
    typedef char              value_type;
    typedef size_t            size_type;
    typedef ptrdiff_t         difference_type;
    typedef value_type*       pointer;
    typedef value_type const* const_pointer;
    typedef value_type&       reference;
    typedef value_type const& const_reference;
    typedef pointer           iterator;
    typedef const_pointer     const_iterator;

  public:
    static size_type npos;

  public:
    string_view() noexcept;
    string_view(value_type const* str) noexcept;
    string_view(value_type const* str, size_type size) noexcept;

  public:
    const_iterator begin() const noexcept;
    const_iterator cbegin() const noexcept;
    const_iterator end() const noexcept;
    const_iterator cend() const noexcept;

  public:
    const_reference operator[](size_type n) const;
    const_reference at(size_type n) const;
    const_reference front() const;
    const_reference back() const;
    const_pointer   data() const noexcept;

  public:
    size_type size() const noexcept;
    size_type max_size() const noexcept;
    bool      empty() const noexcept;

  public:
    void remove_prefix(size_type n);
    void remove_suffix(size_type n);
    void swap(string_view& other);

  private:
    const_pointer m_data;
    size_type     m_size;
  };

} // namespace vlg
