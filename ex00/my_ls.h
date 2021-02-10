#include <stdio.h>
#include <stdlib.h>
typedef struct flags
{
    int a;
    int t;
} flags;

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

