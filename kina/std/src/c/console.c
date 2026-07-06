#include <stdio.h>
#include <stdbool.h>

void kina_lib_kina_std_console_printInt(int val) {
  printf("(int32) %d\n", val);
}

void kina_lib_kina_std_console_printBool(bool val) {
  printf("(bool) %s\n", val ? "true" : "false");
}

void kina_lib_kina_std_console_printString(char* val) {
  printf("(string) %s\n", val);
}