typedef struct hs{
    double *d;
    double *b;
} hs;

extern hs* s;
void malloc_array();

double get_d(int e, int i);
void set_d(int e, int i, double x);
double get_b(int e, int i);
void set_b(int e, int i, double x);
