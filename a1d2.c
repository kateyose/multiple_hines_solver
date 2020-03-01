#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a1.h"
#include "pu.h"
#include "d2.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs; j++) {
    for (i = n - 1; i >= 1; i--) {
      double f = u[i] / s[j].d[i];
      s[j].d[p[i]] -= f * u[i];
      s[j].b[p[i]] -= f * s[j].b[i];
    }
    s[j].b[0] /=  s[j].d[0];

    for (i = 1; i < n; i++) {
      s[j].b[i] =  (s[j].b[i] - s[j].b[p[i]]  * u[i]) / s[j].d[i];
    }
  }
}

char* getfilename() {
  return __FILE__;
}
