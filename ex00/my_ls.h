#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
typedef struct flags
{
    int a;
    int t;
    int size;
    //char** dir;
    
} flags;

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

void a_flag();

int my_strcmp(const char *str1, const char *str2);

void t_flag();

void no_flag();

void file_flag(char** file, int size);