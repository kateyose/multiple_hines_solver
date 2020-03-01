#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "pu.h"
#include "d5.h"

void solver() {
  int l, j, i, k;

  if (BLOCK_SIZE_A != BLOCK_SIZE_D) {
    printf("block size must be same\n");
    exit(0);
  }
#pragma omp parallel for private(i,j)

  for (k = 0; k < eqs / BLOCK_SIZE_D; k++) {
    for (i = n - 1; i >= 1; i--) {
      int parent  = p[i];
      int current = i;
      double ui   = u[i];

      for (j = 0; j < BLOCK_SIZE_D; j++, parent += n, current += n) {
        double f = ui / d[k][current];
        d[k][parent] -= f * ui;
        b[k][parent] -= f * b[k][current];
      }
    }
    int current = 0;

    for (j = 0; j < BLOCK_SIZE_D; j++, current += n) {
      b[k][current] /= d[k][current];
    }

    for (i = 1; i < n; i++) {
      int current = i;
      int parent  = p[i];
      double ui   = u[i];

      for (j = 0; j < BLOCK_SIZE_D; j++, parent += n, current += n) {
        b[k][current] = (b[k][current] - ui * b[k][parent]) / d[k][current];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
