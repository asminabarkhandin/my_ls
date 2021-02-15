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

struct file
{
    char* name;
    struct file *next;
};

struct file_tm
{
    char* name;
    long int tm;
    struct file_tm *next;
};

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

struct file *insert (struct file *head, char* name);

void a_flag();

int my_strcmp(const char *str1, const char *str2);
struct file_tm *insert_tm (struct file_tm *head, char* name, long int tm);
int comp_tm(struct file_tm *file1, struct file_tm *file2);
double my_difftime(long int tm1,long int tm2);



void at_flag();


void t_flag();

void no_flag();

void file_flag(char** file, int size);