#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a3.h"
#include "d1.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs / BLOCK_SIZE_A; j++) {
    int jjbase = j * BLOCK_SIZE_A;
    int jj;
    int k;

    for (i = n - 1; i >= 1; i--) {
      jj = jjbase;

      for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
        double f = s[jj].u[i] / s[jj].d[i];
        s[jj].d[s[j].p[i]] -= f * s[jj].u[i];
        s[jj].b[s[j].p[i]] -= f * s[jj].b[i];
      }
    }
    jj = jjbase;

    for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
      s[jj].b[0] /=  s[jj].d[0];
    }

    for (i = 1; i < n; i++) {
      jj = jjbase;

      for (k = 0; k < BLOCK_SIZE_A; k++, jj++) {
        s[jj].b[i] =  (s[jj].b[i] - s[jj].b[s[jj].p[i]]  * s[jj].u[i]) /
                     s[jj].d[i];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
