#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a1.h"
#include "pu.h"
#include "d4.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)
  for (j = 0; j < eqs; j++) {
    for (i = n - 1; i >= 1; i--) {
      double f = u[i] / d[i * eqs + j];
      d[p[i] * eqs + j] -= f * u[i];
      b[p[i] * eqs + j] -= f * b[i * eqs + j];
    }
    b[j] /=  d[j];

    for (i = 1; i < n; i++) {
      b[i * eqs + j] =  (b[i * eqs + j] - b[p[i] * eqs + j] * u[i]) /
                       d[i * eqs + j];
    }
  }
}

char* getfilename() {
  return __FILE__;
}
