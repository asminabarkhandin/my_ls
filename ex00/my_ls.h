#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
typedef struct flags
{
    int a;
    int t;
    int size;
    char** file;
    
} flags;

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

void a_flag();

void t_flag();

void no_flag();

void file_flag(char** file, int size);