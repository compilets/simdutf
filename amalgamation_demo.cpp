#include <memory>

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
  return EXIT_SUCCESS;
}
