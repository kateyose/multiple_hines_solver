#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "pu.h"
#include "d2.h"

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
        double f = ui / s[jj].d[i];
        s[jj].d[pi] -= f * ui;
        s[jj].b[pi] -= f * s[jj].b[i];
      }
    }
    jj = jjbase;

    for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
      s[jj].b[0] /=  s[jj].d[0];
    }

    for (i = 1; i < n; i++) {
      jj = jjbase;
      double ui = u[i];
      int    pi = p[i];

      for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
        s[jj].b[i] =  (s[jj].b[i] - s[jj].b[pi]  * ui) / s[jj].d[i];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
