#include "kina.h"
#include <stdio.h>

// Read single character from stdin and return it as a KinaString
struct KinaString kina_lib_kina_std_stdio_stdin_read() {
  int c = getchar();
  if (c == EOF) {
    return (struct KinaString){.data = NULL,
                               .length = 0}; // Return empty string on EOF
  }

  char *buffer =
      kina_mem_alloc(2); // Allocate space for 1 char + null terminator
  if (!buffer) {
    return (struct KinaString){
        .data = NULL, .length = 0}; // Return empty string on allocation error
  }

  buffer[0] = (char)c;
  buffer[1] = '\0'; // Null terminator

  return (struct KinaString){.data = buffer, .length = 1};
}

struct KinaString kina_lib_kina_std_stdio_stdin_readLine() {
  size_t n = 1024;

  char *buffer = kina_mem_alloc(n);
  if (!buffer) {
    return (struct KinaString){
        .data = NULL, .length = 0}; // Return empty string on allocation error
  }

  size_t bytes_read = getline(&buffer, &n, stdin);
  if (bytes_read == -1) {
    kina_mem_free(buffer);
    return (struct KinaString){.data = NULL,
                               .length = 0}; // Return empty string on error
  }

  // Remove the newline character if present
  if (bytes_read > 0 && buffer[bytes_read - 1] == '\n') {
    buffer[bytes_read - 1] = '\0';
    bytes_read--;
  }

  return (struct KinaString){.data = buffer, .length = (int)bytes_read};
}