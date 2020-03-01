#include <stdio.h>
#include <stdlib.h>
#include "d1.h"
#include "core_variable.h"

hs *s;

void malloc_array() {
  s = malloc(sizeof(hs) * eqs);
  int i;

  for (i = 0; i < eqs; i++) {
    s[i].p = malloc(sizeof(unsigned short) * n);
    s[i].u = malloc(sizeof(double) * n);
    s[i].d = malloc(sizeof(double) * n);
    s[i].b = malloc(sizeof(double) * n);
  }
}

unsigned short get_p(int e, int i) {
  return s[e].p[i];
}

void set_p(int e, int i, unsigned short x) {
  s[e].p[i] = x;
}

double get_u(int e, int i) {
  return s[e].u[i];
}

void set_u(int e, int i, double x) {
  s[e].u[i] = x;
}

double get_d(int e, int i) {
  return s[e].d[i];
}

void set_d(int e, int i, double x) {
  s[e].d[i] = x;
}

double get_b(int e, int i) {
  return s[e].b[i];
}

void set_b(int e, int i, double x) {
  s[e].b[i] = x;
}
