/* uses read & write to transliterate bytes, instead of using
getchar and putchar. The nbyte arguments to read and write
should be 1, so that the program reads and writes single
bytes at a time */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void checkInputs(int argc, char **argv) {
  if (argc > 3) {
    fprintf(stderr, "Error: too many operands.");
    exit(1);
  }
  else if (argc < 3) {
    fprintf(stderr, "Error: too few operands.");
    exit(1);
  }
  else if (strlen(argv[1]) != strlen(argv[2])) {
        fprintf(stderr, "Error: operands have different lengths");
        exit(1);
  }
  int len = strlen(argv[1]);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (argv[1][i] == argv[2][j]) {
        fprintf(stderr, "Error: contains duplicate bytes");
        exit(1);
      }
    }
  }
  return;
}

int main(int argc, char **argv) {

  checkInputs(argc, argv);

  
  char in[1];
  ssize_t fil = read(0, in, 1);
  while (fil > 0) {
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++) {
      if (in[0] == argv[1][i]) {
        in[0] = argv[2][i];
        break;
      }
    }
    write(1, in, 1);
    fil = read(0, in, 1);
  }

  exit(0);
  
}
