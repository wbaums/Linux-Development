#include<stdio.h>
#include<stdlib.h>

int unfrob(char f);
int qcompare(const void *a, const void *b);
int frobcmp(char const *a, char const *b);

// unfrobnicate char f by XOR with 42                                               
int unfrob(char f) {
  return (42 ^ f);
}

int comparator(const void *a, const void *b) {
  const char *aa = *(const char**)a;
  const char *bb = *(const char**)b;
  return frobcmp(aa,bb);
}

int frobcmp(char const *a, char const *b) {
    while(1 == 1) {
    if (*a == '\0') {
      a++;
      continue;
    }
    if (*b == '\0') {
      b++;
      continue;
    }
    break;
  }
  // traverse a,b while they're equal
    while (*a == *b) {
      if (*a != ' ' || *b != ' ') {
        a++;
        b++;
      }
      else {
        return 0;
      }
    }
    // check which arg is larger
    // call unfrob to unfrobnicate a,b
    int ua = unfrob(*a);
    int ub = unfrob(*b);
    if (*a == ' ' || (ub > ua)) {
        return -1;
      }
      else {
            return 1;
      }
   
}
// free memory allocated earlier
void freelines(char **lines, int cols) {
  for (int i = 0; i < cols; i++) {
  free(lines[i]);
  }
  free(lines);
}
// print out lines
void printarr(char **lines, int cols) {
  for (int i = 0; i < cols; i++) {
    for (int j = 0; lines[i][j] != '\0'; j++) {
    	if (lines[i][j] != '\0') {
        printf("%c", lines[i][j]);
      }
      else if (lines[i][j] == ' ') {
        printf("%c", lines[i][j]);
	break;
      }
      else {
        break;
      }
    }
  }
}

int main(void) {
  // lines stores lines which are sequences of chars                                
  // each line will have a char *curr                                               
  char **lines;
  char *lin;
  // allocate memory using malloc()                                                 
  lines = (char**)malloc(sizeof(char*));
  lin = (char*)malloc(sizeof(char));

  // check for error allocating mem w/ malloc()                                     
  if (lines == NULL || lin == NULL) {
    fprintf(stderr, "Error allocating memory with malloc()");
    exit(1);
  }
  // variables for curr char, rows, cols                                    
  int chr;
  int r = 0;
  int c = 0;
  while (feof(stdin) == 0) {
  	chr = getchar();

    // if non-leading space, create new line                                                   
  	if (chr == ' ' && r > 0 || chr == EOF) {
      // reallocate mem and make last character a space                             
      lin = (char*)realloc(lin, (r + 1) * sizeof(char));
      lin[r] = ' ';
      // create new line, store addresses into next unused char*                    
      // character  in lines.                                                       
      lines = (char**)realloc(lines, (c + 1) * sizeof(char*));
      char *tmp = (char*)malloc(sizeof(char));
      // ensure realloc() and malloc() worked correctly                             
      if (lines == NULL || tmp == NULL) {
        fprintf(stderr, "Error allocating memory.");
        exit(1);
      }
      else {
        lines[c] = lin;
        lin = tmp;
        c += 1;
        r = 0;
      }
    }
    else {
      // add character to the array                             
      lin = (char*)realloc(lin, (r + 1) * sizeof(char));
      lin[r] = chr;
      r += 1;                                                      
    }
  }
// begin sorting, otherwise throw error
  if (feof(stdin)) {
    qsort(lines, c, sizeof(char*), comparator);
  }
  else if (ferror(stdin)) {
    fprintf(stderr, "Error reading file");
    exit(1);
  }
  else {
    fprintf(stderr, "Error");
    exit(1);
  }
  // print out and free memory
  printarr(lines, c);
  freelines(lines, c);
  exit(0);
}   
