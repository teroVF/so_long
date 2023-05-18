#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("before\n");
  sleep(2);
  printf("after");
  return 0;
}
