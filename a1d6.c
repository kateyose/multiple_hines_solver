#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a1.h"
#include "pu.h"
#include "d6.h"

void solver() {
  int j, i;

#pragma omp parallel for private(i,j)

  for (j = 0; j < eqs; j++) {
    int k =  j / BLOCK_SIZE_D;
    int l =  j % BLOCK_SIZE_D;

    for (i = n - 1; i >= 1; i--) {
      int parent  = l + p[i] * BLOCK_SIZE_D;
      int current = l + i * BLOCK_SIZE_D;
      double f    = u[i] / d[k][current];
      d[k][parent] -= f * u[i];
      b[k][parent] -= f * b[k][current];
    }
    b[k][l] /=  d[k][l];

    for (i = 1; i < n; i++) {
      int parent  = l + p[i] * BLOCK_SIZE_D;
      int current = l + i * BLOCK_SIZE_D;
      b[k][current] = (b[k][current] - u[i] * b[k][parent]) / d[k][current];
    }
  }
}

char* getfilename() {
  return __FILE__;
}
