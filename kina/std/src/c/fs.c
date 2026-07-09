#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "kina.h"

struct KinaString kina_lib_kina_std_fs_readFile(const char* path) {
  FILE* file = fopen(path, "rb");
  if (!file) {
    return (struct KinaString){ .data = NULL, .length = 0 }; // Return empty string on error
  }

  fseek(file, 0, SEEK_END);
  long file_size = ftell(file);
  fseek(file, 0, SEEK_SET);

  char* buffer = (char*)kina_mem_alloc(file_size + 1); // +1 for null terminator
  if (!buffer) {
    fclose(file);
    return (struct KinaString){ .data = NULL, .length = 0 }; // Return empty string on allocation error
  }

  size_t bytes_read = fread(buffer, 1, file_size, file);
  buffer[bytes_read] = '\0';
  fclose(file);

  return (struct KinaString){ .data = buffer, .length = (int)bytes_read };
}

bool kina_lib_kina_std_fs_writeFile(const char* path, const char* content, int content_length) {
  FILE* file = fopen(path, "wb");
  if (!file) {
    return false;
  }

  size_t bytes_written = fwrite(content, 1, content_length, file);
  fclose(file);

  return (bytes_written == content_length) ? true : false;
}