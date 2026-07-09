#include "kina.h"

void* kina_lib_kina_std_memory_alloc(int size) {
  return kina_mem_alloc(size);
}

void kina_lib_kina_std_memory_retain(void* ptr) {
  kina_mem_retain(ptr);
}

void kina_lib_kina_std_memory_release(void* ptr) {
  kina_mem_release(ptr);
}

void kina_lib_kina_std_memory_free(void* ptr) {
  kina_mem_free(ptr);
}