#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

struct dir{
    char* name;
    struct dir *next;
};
typedef struct flags
{
    int a;
    int t;
    struct dir* dir_container;
    
} flags;

struct file_tm
{
    char* name;
    long int tm;
    struct file_tm *next;
};

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

struct file_tm *insert (struct file_tm *head, char* name);

void a_flag(flags* flag);

int my_strcmp(const char *str1, const char *str2);
struct file_tm *insert_tm (struct file_tm *head, char* name, long int tm);
int comp_tm(struct file_tm *file1, struct file_tm *file2);
double my_difftime(long int tm1,long int tm2);



void both_flag();


void t_flag(flags* flag);

void no_flag();

void file_flag(char** file, int size);