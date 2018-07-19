#include<stdio.h>
#include<string.h>

int f(char * r);

int main(int argc, char const *argv[]) {
  f("sdkjsjd");
  return 0;
}

int f(char * r) {
  printf("%d\n", strlen(r));
}
