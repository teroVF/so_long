#include <stdio.h>
#include <unistd.h>

int main(void) {
  printf("before");
  sleep(4);
  printf("after");
  return 0;
}
