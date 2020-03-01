#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "pu.h"
#include "d3.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs / BLOCK_SIZE_A; j++) {
    int jjbase = j * BLOCK_SIZE_A;
    int jj;
    int k;

    for (i = n - 1; i >= 1; i--) {
      jj = jjbase;
      double ui = u[i];
      int    pi = p[i];

      for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
        int current = i + jj * n;
        int parent  = pi + jj * n;
        double f    = ui / d[current];
        d[parent] -= f * ui;
        b[parent] -= f * b[current];
      }
    }
    jj = jjbase;

    for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
      b[jj * n] /=  d[jj * n];
    }

    for (i = 1; i < n; i++) {
      double ui = u[i];
      int    pi = p[i];
      jj = jjbase;

      for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
        int current = i + jj * n;
        int parent  = pi + jj * n;
        b[current] =  (b[current] - b[parent] * ui) / d[current];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
