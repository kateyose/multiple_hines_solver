#include <stdio.h>
#include <stdlib.h>
#include "pu.h"
#include "d3.h"
#include "core_variable.h"

double *d;
double *b;

void malloc_array() {
  malloc_pu();
  d = malloc(sizeof(double) * n * eqs);
  b = malloc(sizeof(double) * n * eqs);
}

double get_d(int e, int i) {
  return d[i + e * n];
}

void set_d(int e, int i, double x) {
  d[i + e * n] = x;
}

double get_b(int e, int i) {
  return b[i + e * n];
}

void set_b(int e, int i, double x) {
  b[i + e * n] = x;
}
