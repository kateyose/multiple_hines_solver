#include <stdio.h>
#include <stdlib.h>
#include "core_variable.h"
#include "utility.h"
#include "pu.h"
#include "d4.h"

double *d;
double *b;
void malloc_array() {
  malloc_pu();
  d = malloc(sizeof(double) * n * eqs);
  b = malloc(sizeof(double) * n * eqs);
}

double get_d(int e, int i) {
  return d[i * eqs + e];
}

void set_d(int e, int i, double x) {
  d[i * eqs + e] = x;
}

double get_b(int e, int i) {
  return b[i * eqs + e];
}

void set_b(int e, int i, double x) {
  b[i * eqs + e] = x;
}
