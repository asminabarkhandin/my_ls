#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
typedef struct flags
{
    int a;
    int t;
} flags;

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

void a_flag();

void t_flag();

void no_flag();