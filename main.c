#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include<libgen.h>
#include "core_variable.h"
#include "utility.h"

extern void  malloc_array();
extern void  solver();
extern char* getfilename();

int          main(int argc, char **argv) {
  check_argc(argc);
  read_argv(argc, argv);

  elapsed = malloc(sizeof(int) * aver);

  load_n();
  malloc_array();
  load_p_u();

  struct timeval st, et;
  int l;

  for (l = 0; l < aver; l++) {
    load_d_b();
    gettimeofday(&st, NULL);
    solver();
    gettimeofday(&et, NULL);
    post_solving(l, st, et);
  }
  print_gflops();
  if (output) {
    print_b(basename(argv[0]));
  }
}
