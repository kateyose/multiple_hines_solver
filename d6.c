#include <stdio.h>
#include <stdlib.h>
#include <numa.h>
#include "core_variable.h"
#include "utility.h"
#include "pu.h"
#include "d6.h"

double **d;
double **b;
void malloc_array() {
  malloc_pu();
  d = malloc(sizeof(double *) * eqs / BLOCK_SIZE_D);
  b = malloc(sizeof(double *) * eqs / BLOCK_SIZE_D);
  int j;

  for (j = 0; j < eqs / BLOCK_SIZE_D; j++) {
    #ifdef NUMA
    if (j < eqs / BLOCK_SIZE_D / 2) {
      d[j] = numa_alloc_onnode(sizeof(double) * n * BLOCK_SIZE_D, 0);
      b[j] = numa_alloc_onnode(sizeof(double) * n * BLOCK_SIZE_D, 0);
    } else {
      d[j] = numa_alloc_onnode(sizeof(double) * n * BLOCK_SIZE_D, 1);
      b[j] = numa_alloc_onnode(sizeof(double) * n * BLOCK_SIZE_D, 1);
    }
    #else
    d[j] = malloc(sizeof(double) * n * BLOCK_SIZE_D);
    b[j] = malloc(sizeof(double) * n * BLOCK_SIZE_D);
    #endif
  }
}

double get_d(int e, int i) {
  return d[e / BLOCK_SIZE_D][i * BLOCK_SIZE_D + e % BLOCK_SIZE_D];
}

void set_d(int e, int i, double x) {
  d[e / BLOCK_SIZE_D][i * BLOCK_SIZE_D + e % BLOCK_SIZE_D] = x;
}

double get_b(int e, int i) {
  return b[e / BLOCK_SIZE_D][i * BLOCK_SIZE_D + e % BLOCK_SIZE_D];
}

void set_b(int e, int i, double x) {
  b[e / BLOCK_SIZE_D][i * BLOCK_SIZE_D + e % BLOCK_SIZE_D] = x;
}
