#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a1.h"
#include "pu.h"
#include "d3.h"


void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs; j++) {
    for (i = n - 1; i >= 1; i--) {
      double f = u[i] / d[i + j * n];
      d[p[i] + j * n] -= f * u[i];
      b[p[i] + j * n] -= f * b[i + j * n];
    }
    b[j * n] /=  d[j * n];

    for (i = 1; i < n; i++) {
      b[i + j * n] =  (b[i + j * n] - b[p[i] + j * n] * u[i]) / d[i + j * n];
    }
  }
}

char* getfilename() {
  return __FILE__;
}
