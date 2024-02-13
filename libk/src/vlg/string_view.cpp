#include <vlg/string_view.hpp>

using vlg::string_view;

static inline string_view::size_type _strlen(string_view::const_pointer start) {
  string_view::const_pointer end;
  for (end = start; *end != '\0'; ++end)
    ;
  return end - start;
}

string_view::size_type string_view::npos = SIZE_MAX;

string_view::string_view() noexcept
    : m_data(nullptr)
    , m_size(0) {}

string_view::string_view(value_type const* str) noexcept
    : m_data(str)
    , m_size(_strlen(str)) {}

string_view::string_view(value_type const* str, size_type size) noexcept
    : m_data(str)
    , m_size(size) {}

string_view::const_iterator string_view::begin() const noexcept {
  return m_data;
}

string_view::const_iterator string_view::cbegin() const noexcept {
  return m_data;
}

string_view::const_iterator string_view::end() const noexcept {
  return m_data + m_size;
}

string_view::const_iterator string_view::cend() const noexcept {
  return m_data + m_size;
}

string_view::const_reference string_view::operator[](size_type n) const {
  return this->at(n);
}

string_view::const_reference string_view::at(size_type n) const {
  if (this->empty() || m_size <= n) {
    // TODO: throw
    __builtin_unreachable();
  } else {
    return m_data[n];
  }
}

string_view::const_reference string_view::front() const {
  if (this->empty()) {
    // TODO: throw
    __builtin_unreachable();
  } else {
    return m_data[0];
  }
}

string_view::const_reference string_view::back() const {
  if (this->empty()) {
    // TODO: throw
    __builtin_unreachable();
  } else {
    return m_data[m_size - 1];
  }
}

string_view::const_pointer string_view::data() const noexcept { return m_data; }

string_view::size_type     string_view::size() const noexcept { return m_size; }

string_view::size_type string_view::max_size() const noexcept { return npos; }

bool                   string_view::empty() const noexcept {
  return m_data == nullptr || m_size == 0;
}

void string_view::remove_prefix(size_type n) {
  if (this->empty() || m_size < n) {
    // TODO: throw
    __builtin_unreachable();
  } else {
    m_size -= n;
    m_data += n;
  }
}

void string_view::remove_suffix(size_type n) {
  if (this->empty() || m_size < n) {
    // TODO: throw
    __builtin_unreachable();
  } else {
    m_size -= n;
  }
}

void string_view::swap(string_view& other) {
  // TODO: use std::move
  size_type     tmp_size;
  const_pointer tmp_data;

  tmp_size     = other.m_size;
  tmp_data     = other.m_data;
  other.m_size = this->m_size;
  other.m_data = this->m_data;
  this->m_size = tmp_size;
  this->m_data = tmp_data;
}
