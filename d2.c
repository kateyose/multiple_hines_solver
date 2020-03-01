#include <stdio.h>
#include <stdlib.h>
#include <numa.h>
#include "pu.h"
#include "d2.h"
#include "core_variable.h"
#include "utility.h"

hs *s;

void malloc_array() {
  malloc_pu();
  s = malloc(sizeof(hs) * eqs);
  int i;

  for (i = 0; i < eqs; i++) {
    #ifdef NUMA
    if (i < eqs / 2) {
      s[i].d = numa_alloc_onnode(sizeof(double) * n, 0);
      s[i].b = numa_alloc_onnode(sizeof(double) * n, 0);
    } else {
      s[i].d = numa_alloc_onnode(sizeof(double) * n, 1);
      s[i].b = numa_alloc_onnode(sizeof(double) * n, 1);
    }
    #else
    s[i].d = malloc(sizeof(double) * n);
    s[i].b = malloc(sizeof(double) * n);
    #endif
  }
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
