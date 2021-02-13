#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    double d = 1.0;
    long *pl = (long*)&d;
    printf("d=%f,size=%d,long=%ld,long=%#lx\n", d, sizeof(d), *pl, *pl);
    long val = 9;
    double *dval = (double*)&val;
    printf("dval:%f\n", *dval);
    return 0;
}
