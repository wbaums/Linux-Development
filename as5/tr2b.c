/* uses getchar & putchar to transliterate bytes as described
in spec */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

  char curr = getchar();
  while (curr != EOF) {
    int len = strlen(argv[1]);
    for (int i = 0; i < len; i++) {
      if (curr == argv[1][i]) {
	curr = argv[2][i];
	break;
      }
    }
    putchar(curr);
    curr = getchar();
  }
  
  return 0;
}
