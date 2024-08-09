#include <memory>

#include "simdutf.cpp"
#include "simdutf.h"

int main(int , char *[]) {
  const char *source = "1234";
  // 4 == strlen(source)
  bool validutf8 = simdutf::validate_utf8(source, 4);
  if (validutf8) {
    puts("valid UTF-8");
  } else {
    puts("invalid UTF-8");
    return EXIT_FAILURE;
  }
  // We need a buffer of size where to write the UTF-16LE words.
  size_t expected_utf16words = simdutf::utf16_length_from_utf8(source, 4);
  std::unique_ptr<char16_t[]> utf16_output{new char16_t[expected_utf16words]};
  // convert to UTF-16LE
  size_t utf16words =
      simdutf::convert_utf8_to_utf16le(source, 4, utf16_output.get());
  printf("wrote %zu UTF-16LE words.", utf16words);
  // It wrote utf16words * sizeof(char16_t) bytes.
  bool validutf16 = simdutf::validate_utf16le(utf16_output.get(), utf16words);
  if (validutf16) {
    puts("valid UTF-16LE");
  } else {
    puts("invalid UTF-16LE");
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}
