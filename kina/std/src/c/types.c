#include "kina.h"


int kina_lib_kina_std_types_ptrToInt(void* p) {
  return (int)*(int*)p;
}

struct KinaString kina_lib_kina_std_types_stringFromC(char* c_str, int length) {
  struct KinaString str;
  
  str.data = c_str;
  str.length = length;

  return str;
}