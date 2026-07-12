#include "kina.h"
#include <stdio.h>
#include <string.h>

int kina_lib_kina_std_types_ptrToInt(void *p) { return (int)*(int *)p; }

struct KinaString kina_lib_kina_std_types_stringFromC(char *c_str, int length) {
  struct KinaString str;

  str.data = c_str;
  str.length = length;

  return str;
}

struct KinaString kina_lib_kina_std_types_intToString(int value) {
  char buffer[12]; // Enough to hold -2147483648 and null terminator
  int length = snprintf(buffer, sizeof(buffer), "%d", value);

  // Allocate memory for the string data
  char *str_data = (char *)kina_mem_alloc(length + 1);
  if (!str_data) {
    return (struct KinaString){
        .data = NULL, .length = 0}; // Return empty string on allocation error
  }

  // Copy the formatted string into the allocated memory
  memcpy(str_data, buffer, length + 1); // Include null terminator

  return (struct KinaString){.data = str_data, .length = length};
}