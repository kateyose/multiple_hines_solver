#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include <emmintrin.h>
#include <immintrin.h>
#include "core_variable.h"
#include "utility.h"
#include "a4.h"
#include "pu.h"
#include "d4.h"

void solver() {
  int l, j, i, k;

#pragma omp parallel for private(i)

  for (j = 0; j < eqs / BLOCK_SIZE_A; j++) {
    int k;
    int base = j * BLOCK_SIZE_A;

    for (i = n - 1; i >= 1; i--) {
      int current = i * eqs + base;
      int parent  = p[i] * eqs + base;
      {
        __m256d u_temp    = _mm256_set1_pd(u[i]);
        __m256d dkcurrent = _mm256_loadu_pd(d + current);
        __m256d f         = _mm256_div_pd(u_temp, dkcurrent);
        f = _mm256_xor_pd(f, _mm256_set1_pd(-0.0));
        __m256d dkparent = _mm256_loadu_pd(d + parent);
        dkparent = _mm256_fmadd_pd(f, u_temp, dkparent);
        __m256d bkcurrent = _mm256_loadu_pd(b + current);
        __m256d bkparent  = _mm256_loadu_pd(b + parent);
        bkparent = _mm256_fmadd_pd(f, bkcurrent, bkparent);
        _mm256_storeu_pd(b + parent, bkparent);
        _mm256_storeu_pd(d + parent, dkparent);
      }
    }

    for (k = base; k < base +  BLOCK_SIZE_A; k++) {
      b[k] /=  d[k];
    }

    for (i = 1; i < n; i++) {
      int current = i * eqs + base;
      int parent  = p[i] * eqs + base;
      {
        __m256d u_temp    = _mm256_set1_pd(u[i]);
        __m256d bkcurrent = _mm256_loadu_pd(b + current);
        __m256d bkparent  = _mm256_loadu_pd(b + parent);
        bkparent  = _mm256_xor_pd(bkparent, _mm256_set1_pd(-0.0));
        bkcurrent = _mm256_fmadd_pd(bkparent, u_temp, bkcurrent);
        __m256d dkcurrent = _mm256_loadu_pd(d + current);
        bkcurrent = _mm256_div_pd(bkcurrent, dkcurrent);
        _mm256_storeu_pd(b + current, bkcurrent);
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
