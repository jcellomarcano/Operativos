//#include <bits/stdc++.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  char *comand = "find /annehelen/Escritorio -type d -print | tee archivo.txt";
  system(comand);
  return 0;
}
