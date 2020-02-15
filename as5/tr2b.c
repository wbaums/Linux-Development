/* uses getchar & putchar to transliterate bytes as described
in spec */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Your implementations should report an error from and to are not the same length, or if from has duplicate bytes.
void checkInputs(int argc, char **argv) {
  if (argc > 3) {
    fprintf(stderr, "Error: too many operands.");
    exit(1);
  }
  else if (argc < 3) {
    fprintf(stderr, "Error: too few operands.");
    exit(1);
  }
  else if (strlen(argv[0]) != strlen(argv[1])) {
	fprintf(stderr, "Error: operands have different lengths");
	exit(1);
  }
  int len = strlen(argv[1]);
  for (int i = 0; i < len; i++) {
    for (int j = 0; j < len; j++) {
      if (argv[0][i] == argv[1][j]) {
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
    int len = strlen(argv[0]);
    for (int i = 0; i < len; i++) {
      if (curr == argv[0][i]) {
	curr = argv[1][i];
	break;
      }
    }
    putchar(curr);
    curr = getchar();
  }
  
  return 0;
}
