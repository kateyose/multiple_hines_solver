#include <stdio.h>
#include <stdlib.h>
#include "core_variable.h"

unsigned short *p;
double *u;

void malloc_pu() {
  p = malloc(sizeof(unsigned short) * n);
  u = malloc(sizeof(double) * n);
}

unsigned short get_p(int e, int i) {
  return p[i];
}

void set_p(int e, int i, unsigned short x) {
  p[i] = x;
}

double get_u(int e, int i) {
  return u[i];
}

void set_u(int e, int i, double x) {
  u[i] = x;
}
