#include "kina.h"
#include <string.h>

struct KinaString kina_lib_kina_std_process_args_getAt(int index) {
  int count = kina_process_args_get_count();
  if (index < 0 || index >= count) {
    return (struct KinaString){.data = NULL, .length = 0}; // Out of bounds
  }

  const char *arg = kina_process_args_get(index);
  int length = strlen(arg);

  // Allocate memory for the string data
  char *str_data = (char *)kina_mem_alloc(length + 1);
  if (!str_data) {
    return (struct KinaString){
        .data = NULL, .length = 0}; // Return empty string on allocation error
  }

  // Copy the argument into the allocated memory
  memcpy(str_data, arg, length + 1); // Include null terminator

  return (struct KinaString){.data = str_data, .length = length};
}

int kina_lib_kina_std_process_args_getCount() {
  return kina_process_args_get_count();
}