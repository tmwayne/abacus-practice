//
// -----------------------------------------------------------------------------
// abacus-practice.c
// -----------------------------------------------------------------------------
//
// Generate random numbers for practicing abacus calculations
//
// Tyler Wayne © 2021
//

#include <stdio.h>
#include <stdlib.h> // srand, rand, abs, EXIT_FAILURE
#include <time.h>   // time
#include <math.h>   // pow, fmax, fmin
#include <string.h> // strcmp

enum ops { ADD, SUB, MUL, DIV };

int select_op(char *input) {
  
  if (strcmp(input, "add") == 0) return ADD;
  else if (strcmp(input, "sub") == 0) return SUB;
  else if (strcmp(input, "mul") == 0) return MUL;
  else if (strcmp(input, "div") == 0) return DIV;
  else return -1;

}

double add(int digits, int n) {

  int answer = 0;

  printf("(+)\n");

  for (int i=0; i<n; i++) {
    int tmp = rand() % (int) pow(10, digits);
    answer += tmp;
    printf("%d\n", tmp);
  }

  return answer;

}

double sub(int digits, int n) {
  
  int x = rand() % (int) pow(10, digits);
  int y = rand() % (int) pow(10, digits);

  printf("%d - %d ?\n", x, y);

  return x - y;

}

double mul(int digits) {

  int x = rand() % (int) pow(10, digits);
  int y = rand() % (int) pow(10, digits);

  printf("%d * %d ?\n", x, y);

  return x * y;

}

double divide(int digits) {

  double x = rand() % (int) pow(10, digits);
  double y = rand() % (int) pow(10, digits);

  printf("%g / %g ?\n", x, y);

  return x / y;

}

int main(int argc, char **argv) {

  int op;
  unsigned int seed = time(NULL);
  srand(seed);

  // TODO: add argopts
  // TODO: have digits be an optional flag

  if (argc == 1) {
    int rnd = rand() % 4;
    switch (rnd) {
      case 0: op = ADD; break;
      case 1: op = SUB; break;
      case 2: op = MUL; break;
      case 3: op = DIV; break;
    }
  }

  else if (argc > 2) {
    fprintf(stderr, "Usage: %s op\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  else if ((op = select_op(argv[1])) < 0) {
    fprintf(stderr, "Invalid selection. Options are add, sub, mul, div\n");
    exit(EXIT_FAILURE);
  }

  double answer;
  switch (op) {
    case ADD: answer = add(7, 4); break;
    case SUB: answer = sub(7, 1); break;
    case MUL: answer = mul(3);    break;
    case DIV: answer = divide(2); break;
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t nread;
  while((nread = getline(&line, &len, stdin)) != -1) {
    switch (op) {
      case ADD: case SUB: case MUL:
        printf("= %0.f\n", answer);
        break;
      case DIV: 
        printf("= %.4f\n", answer);
        break;
    }
    break;
  }

  free(line);

}