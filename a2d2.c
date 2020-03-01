#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a2.h"
#include "pu.h"
#include "d2.h"

void solver() {
    #pragma omp parallel
  {
    int l, j, i, k;

    for (i = n - 1; i >= 1; i--) {
      double ui = u[i];
      int    pi = p[i];
    #pragma omp for

      for (j = 0; j < eqs; j++) {
        double f = ui / s[j].d[i];
        s[j].d[pi] -= f * ui;
        s[j].b[pi] -= f * s[j].b[i];
      }
    }
    #pragma omp for

    for (j = 0; j < eqs; j++) {
      s[j].b[0] /=  s[j].d[0];
    }

    for (i = 1; i < n; i++) {
      double ui = u[i];
      int    pi = p[i];
    #pragma omp for

      for (j = 0; j < eqs; j++) {
        s[j].b[i] =  (s[j].b[i] - s[j].b[pi]  * ui) / s[j].d[i];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
