#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "pu.h"
#include "d4.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs / BLOCK_SIZE_A; j++) {
    int k;
    int base = j * BLOCK_SIZE_A;

    for (i = n - 1; i >= 1; i--) {
      double ui      = u[i];
      int    current = i * eqs + base;
      int    parent  = p[i] * eqs + base;
      int    to      = current +  BLOCK_SIZE_A;

      for (k = current; k < to; k++, parent++) {
        double f = ui / d[k];
        d[parent] -= f * ui;
        b[parent] -= f * b[k];
      }
    }

    int to = base +  BLOCK_SIZE_A;

    for (k = base; k < to; k++) {
      b[k] /=  d[k];
    }

    for (i = 1; i < n; i++) {
      double ui      = u[i];
      int    current = i * eqs + base;
      int    parent  = p[i] * eqs + base;
      int    to      = current +  BLOCK_SIZE_A;

      for (k = current; k < to; k++, parent++) {
        b[k] =  (b[k] - b[parent] * ui) / d[k];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
