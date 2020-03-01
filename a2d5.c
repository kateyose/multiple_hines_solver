#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a2.h"
#include "pu.h"
#include "d5.h"

void solver() {
    #pragma omp parallel
  {
    int l, j, i, k;

    for (i = n - 1; i >= 1; i--) {
      double ui = u[i];
      int    pi = p[i];
    #pragma omp for

      for (j = 0; j < eqs; j++) {
        int k       = j / BLOCK_SIZE_D;
        int l       = j % BLOCK_SIZE_D;
        int parent  = pi + l * n;
        int current = i + l * n;
        double f    = ui / d[k][current];
        d[k][parent] -= f * ui;
        b[k][parent] -= f * b[k][current];
      }
    }
    #pragma omp for

    for (j = 0; j < eqs; j++) {
      int k = j / BLOCK_SIZE_D;
      int l = j % BLOCK_SIZE_D;
      b[k][l * n] /=  d[k][l * n];
    }

    for (i = 1; i < n; i++) {
      double ui = u[i];
      int    pi = p[i];
    #pragma omp for

      for (j = 0; j < eqs; j++) {
        int k       = j / BLOCK_SIZE_D;
        int l       = j % BLOCK_SIZE_D;
        int parent  = pi + l * n;
        int current = i + l * n;
        b[k][current] =  (b[k][current] - b[k][parent]  * ui) / d[k][current];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
