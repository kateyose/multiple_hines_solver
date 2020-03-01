#include <math.h>
#include <stdio.h>

double vec_vec_mul(int n, double *A, double *B) {
  int i;

  double ans = 0;

  for (i = 0; i < n; i++) {
    ans += A[i] * B[i];
  }
  return ans;
}

double* vec_mat_mul(int m, int n, double *A, double B[m][n], double *C) {
  int i, j;

  for (i = 0; i < n; i++) {
    C[i] = 0;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[j] += A[i] * B[i][j];
    }
  }
  return C;
}

double* mat_vec_mul(int m, int n, double A[m][n], double *B, double *C) {
  int i, j;

  for (i = 0; i < m; i++) {
    C[i] = 0;
  }

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      C[i] += A[i][j] * B[j];
    }
  }
  return C;
}

double** mat_mat_mul(int l, int m, int n, double A[l][m], double B[m][n],
                     double C[l][n]) {
  int i, j, k;

  for (i = 0; i < l; i++) {
    for (j = 0; j < n; j++) {
      C[i][j] = 0;
    }
  }

  for (i = 0; i < l; i++) {
    for (k = 0; k < m; k++) {
      for (j = 0; j < n; j++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return (double **)C;
}

void print_vec(int n, double *A) {
  int i;

  for (i = 0; i < n; i++) {
    printf("%1.3lf ", A[i]);
  }
  printf("\n");
}

void print_mat(int m, int n, double A[m][n]) {
  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      printf("%1.3lf ", A[i][j]);
    }
    printf("\n");
  }
}

void scalar_vec_mul(int n, double a, double *A, double *B) {
  int i;

  for (i = 0; i < n; i++) {
    B[i] = A[i] * a;
  }
}

void vec_vec_plus(int n, double *A, double *B, double *C) {
  int i;

  for (i = 0; i < n; i++) {
    C[i] = A[i] + B[i];
  }
}

void vec_vec_minus(int n, double *A, double *B, double *C) {
  int i;

  for (i = 0; i < n; i++) {
    C[i] = A[i] - B[i];
  }
}

void move_vec(int n, double *A, double *B) {
  int i;

  for (i = 0; i < n; i++) {
    B[i] = A[i];
  }
}

void move_mat(int m, int n, double A[m][n], double B[m][n]) {
  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      B[i][j] = A[i][j];
    }
  }
}

double l2_norm(int n, double *A) {
  int i;
  double ans = 0;

  for (i = 0; i < n; i++) {
    ans += A[i] * A[i];
  }
  return sqrt(ans);
}
