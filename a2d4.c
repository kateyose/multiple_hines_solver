#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a2.h"
#include "pu.h"
#include "d4.h"

void solver() {
    #pragma omp parallel
  {
    int l, j, i, k;

    for (i = n - 1; i >= 1; i--) {
      double ui = u[i];
      int    pi = p[i];
            #pragma omp for

      for (j = 0; j < eqs; j++) {
        int current = i * eqs + j;
        int parent  = pi * eqs + j;
        double f    = ui / d[current];
        d[parent] -= f * ui;
        b[parent] -= f * b[current];
      }
    }
        #pragma omp for

    for (j = 0; j < eqs; j++) {
      b[j] /=  d[j];
    }

    for (i = 1; i < n; i++) {
      double ui = u[i];
      int    pi = p[i];
            #pragma omp for

      for (j = 0; j < eqs; j++) {
        int current = i * eqs + j;
        int parent  = pi * eqs + j;
        b[current] =  (b[current] - b[parent]  * ui) / d[current];
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
