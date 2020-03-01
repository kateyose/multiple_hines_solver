#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a1.h"
#include "pu.h"
#include "d5.h"

void solver() {
  int j, i;

#pragma omp parallel for private(i,j)

  for (j = 0; j < eqs; j++) {
    int k    =  j / BLOCK_SIZE_D;
    int l    =  j % BLOCK_SIZE_D;
    int base = l * n;

    for (i = n - 1; i >= 1; i--) {
      int parent  = base + p[i];
      int current = base + i;
      double f    = u[i] / d[k][current];
      d[k][parent] -= f * u[i];
      b[k][parent] -= f * b[k][current];
    }
    b[k][base] /=  d[k][base];

    for (i = 1; i < n; i++) {
      int parent  = base + p[i];
      int current = base + i;
      b[k][current] = (b[k][current] - u[i] * b[k][parent]) / d[k][current];
    }
  }
}

char* getfilename() {
  return __FILE__;
}
