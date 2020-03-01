#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a2.h"
#include "d1.h"

void solver() {
    #pragma omp parallel
  {
    int l, j, i, k;

    for (i = n - 1; i >= 1; i--) {
            #pragma omp for

      for (j = 0; j < eqs; j++) {
        double f = s[j].u[i] / s[j].d[i];
        s[j].d[s[j].p[i]] -= f * s[j].u[i];
        s[j].b[s[j].p[i]] -= f * s[j].b[i];
      }
    }
        #pragma omp for

    for (j = 0; j < eqs; j++) {
      s[j].b[0] /=  s[j].d[0];
    }

    for (i = 1; i < n; i++) {
            #pragma omp for

      for (j = 0; j < eqs; j++) {
        s[j].b[i] =  (s[j].b[i] - s[j].b[s[j].p[i]]  * s[j].u[i]) / s[j].d[i];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
