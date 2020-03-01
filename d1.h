typedef struct hs{
    unsigned short *p;
    double *u;
    double *d;
    double *b;
} hs;

extern hs *s;

void malloc_array();

unsigned short get_p(int e, int i);
void set_p(int e, int i, unsigned short x);
double get_u(int e, int i);
void set_u(int e, int i, double x);
double get_d(int e, int i);
void set_d(int e, int i, double x);
double get_b(int e, int i);
void set_b(int e, int i, double x);

