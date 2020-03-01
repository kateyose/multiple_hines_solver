#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <omp.h>
#include "core_variable.h"
#include "utility.h"
#include "a7.h"
#include "pu.h"
#include "d5.h"

void solver() {
  int l, j, i, k;

  if (BLOCK_SIZE_A != BLOCK_SIZE_D) {
    printf("block size must be same\n");
    exit(0);
  }
#pragma omp parallel for private(i,j)

  for (k = 0; k < eqs / BLOCK_SIZE_D; k++) {
    for (i = n - 1; i >= 1; i--) {
      int parent  = p[i];
      int current = i;
      {
        __m256d u_temp    = _mm256_set1_pd(u[i]);
        __m256d dkcurrent = _mm256_load_pd(d[k] + current);
        __m256d f         = _mm256_div_pd(u_temp, dkcurrent);
        f = _mm256_xor_pd(f, _mm256_set1_pd(-0.0));
        __m256d dkparent = _mm256_load_pd(d[k] + parent);
        dkparent = _mm256_fmadd_pd(f, u_temp, dkparent);
        __m256d bkcurrent = _mm256_load_pd(b[k] + current);
        __m256d bkparent  = _mm256_load_pd(b[k] + parent);
        bkparent = _mm256_fmadd_pd(f, bkcurrent, bkparent);
        _mm256_store_pd(b[k] + parent, bkparent);
        _mm256_store_pd(d[k] + parent, dkparent);
      }
    }
    int current = 0;

    for (j = 0; j < BLOCK_SIZE_D; j++, current += n) {
      b[k][current] /= d[k][current];
    }

    for (i = 1; i < n; i++) {
      int current = i;
      int parent  = p[i];
      {
        __m256d u_temp    = _mm256_set1_pd(u[i]);
        __m256d bkcurrent = _mm256_load_pd(b[k] + current);
        __m256d bkparent  = _mm256_load_pd(b[k] + parent);
        bkparent  = _mm256_xor_pd(bkparent, _mm256_set1_pd(-0.0));
        bkcurrent = _mm256_fmadd_pd(bkparent, u_temp, bkcurrent);
        __m256d dkcurrent = _mm256_load_pd(d[k] + current);
        bkcurrent = _mm256_div_pd(bkcurrent, dkcurrent);
        _mm256_store_pd(b[k] + current, bkcurrent);
      }
    }
  }
}

char* getfilename() {
  return __FILE__;
}
