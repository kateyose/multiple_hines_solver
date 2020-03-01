#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
#include "core_variable.h"

int           get_duration(struct timeval st,
                           struct timeval et);
extern void   set_p(int            e,
                    int            i,
                    unsigned short x);
extern void   set_u(int    e,
                    int    i,
                    double x);
extern void   set_d(int    e,
                    int    i,
                    double x);
extern void   set_b(int    e,
                    int    i,
                    double x);
extern double get_b(int e,
                    int i);
void print_b_last_element();

void          read_argv(int argc, char **argv) {
  mat_file = argv[1];
  eqs      = strtol(argv[2], NULL, 10);
  aver     = strtol(argv[3], NULL, 10);

  if (argc > 4) {
    output = strtol(argv[4], NULL, 10);
  }
}

void post_solving(int l, struct timeval st, struct timeval et) {
  int duration = get_duration(st, et);
  elapsed[l] = duration;
  print_b_last_element();
}

int get_duration(struct timeval st, struct timeval et) {
  return ((et.tv_sec - st.tv_sec) * 1000000) + (et.tv_usec - st.tv_usec);
}

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
void print_gflops() {
  qsort(elapsed, aver, sizeof(int), cmpfunc);
  int i;
  if(output){
      for(i = 0; i < aver; i++){
         printf("%d ", elapsed[i]);
      }
      printf("\n");
  }
  int elapsed_sum = 0;
  int threshold = aver / 2; 
  for(i = 0; i < threshold; i++){
    elapsed_sum += elapsed[i];
  }
  if (elapsed_sum == 0){
      printf("%.2lf", 8 * n * eqs * 0.001  / elapsed[0]);
      return;
  } 
  printf("%.2lf", 8 * n * eqs * 0.001 * threshold / elapsed_sum);
}

void load_n() {
  FILE *fp = fopen(mat_file, "r");
  int   e  = fscanf(fp, "%d", &n);

  fclose(fp);
}

void load_p_u() {
  int   i, j, e, temp;
  FILE *fp = fopen(mat_file, "r");

  e = fscanf(fp, "%hu", &temp);

  for (i = 0; i < n; i++) {
    unsigned short us;
    e = fscanf(fp, "%hu", &us);

    for (j = 0; j < eqs; j++) {
      set_p(j, i, us);
    }
  }

  for (i = 0; i < n; i++) {
    double v = (double)rand() / (RAND_MAX);
    for (j = 0; j < eqs; j++) {
      set_u(j, i, v); 
    }
  }
//  for (i = 0; i < n; i++) {
//    for (j = 0; j < eqs; j++) {
//      set_u(j, i, ((double)rand() / (RAND_MAX)));
//    }
//  }
  fclose(fp);
}

void load_d_b() {
  int    i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < eqs; j++) {
      set_d(j, i, 100 + ((double)rand() / (RAND_MAX)));
      set_b(j, i, ((double)rand() / (RAND_MAX)));
    }
  }
}

//void load_d_b() {
//  int    i, j, e;
//  FILE  *fp = fopen(mat_file, "r");
//  double v;
//
//  for (i = 0; i < 2 * n + 1; i++) {
//    e = fscanf(fp, "%f", &v);
//  }
//
//  for (i = 0; i < n; i++) {
//    e = fscanf(fp, "%lf", &v);
//
//    for (j = 0; j < eqs; j++) {
//      set_d(j, i, v + ((double)rand() / (RAND_MAX)));
//    }
//  }
//
//  for (i = 0; i < n; i++) {
//    e = fscanf(fp, "%lf", &v);
//
//    for (j = 0; j < eqs; j++) {
//      set_b(j, i, v + ((double)rand() / (RAND_MAX)));
//    }
//  }
//  fclose(fp);
//}

void print_b(char *filename) {
  FILE *fp;
  char  outputfile[100];

  sprintf(outputfile, "output_%s.txt", filename);
  fp = fopen(outputfile, "w");
  int i, j;

  for (i = 0; i < eqs; i++) {
    for (j = 0; j <  n; j++) {
      fprintf(fp, "%lf\n", get_b(i, j));
    }
  }
  fclose(fp);
}

void print_b_last_element() {
  int i, j;
  double s = 0;
  for (i = 0; i < eqs; i++) {
      s += get_b(i, n-1);
  }
  FILE* fp = fopen("prevent_optimization.txt", "w");
  fprintf(fp, "%lf\n",s);
  fclose(fp);
}
