#include <stdio.h>
#include <stdbool.h>

void printInt(int val) {
  printf("(int32) %d\n", val);
}

void printBool(bool val) {
  printf("(bool) %s\n", val ? "true" : "false");
}