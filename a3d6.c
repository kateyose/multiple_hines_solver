#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "pu.h"
#include "d6.h"

void solver() {
  int l, j, i, k;

  if (BLOCK_SIZE_A != BLOCK_SIZE_D) {
    printf("block size must be same\n");
    exit(0);
  }
#pragma omp parallel for private(i,j)

  for (k = 0; k < eqs / BLOCK_SIZE_D; k++) {
    for (i = n - 1; i >= 1; i--) {
      int current = i * BLOCK_SIZE_D;
      int parent  = p[i] * BLOCK_SIZE_D;
      double ui   = u[i];
      int    to   = current +  BLOCK_SIZE_D;

      for (j = current; j < to; j++, parent++) {
        double f = ui / d[k][j];
        d[k][parent] -= f * ui;
        b[k][parent] -= f * b[k][j];
      }
    }

    for (j = 0; j < BLOCK_SIZE_D; j++) {
      b[k][j] = b[k][j] / d[k][j];
    }

    for (i = 1; i < n; i++) {
      int current = i * BLOCK_SIZE_D;
      int parent  = p[i] * BLOCK_SIZE_D;
      double ui   = u[i];
      int    to   = current +  BLOCK_SIZE_D;

      for (j = current; j < to; j++, parent++) {
        b[k][j] = (b[k][j] - ui * b[k][parent]) / d[k][j];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
