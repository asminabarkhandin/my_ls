#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
struct dir{
    char* name;
    struct timespec tm;
    struct dir *next;
};
typedef struct flags
{
    int a;
    int t;
    int size;
    struct dir* dir_container;
    
} flags;

struct file_tm
{
    char* name;
    struct timespec tm;
    struct file_tm *next;
};



char* my_strcat(char* dest, const char* src);

flags* load_flags(int ac, char** av);

void print_flags(flags* flag);

struct file_tm *insert (struct file_tm *head, char* name);

void a_flag(char* str);

int my_strcmp(const char *str1, const char *str2);
struct file_tm *insert_tm (struct file_tm *head, char* name, struct timespec tm);
int comp_tm(struct file_tm *file1, struct file_tm *file2);
double my_difftime(struct timespec tm1,struct timespec tm2);



void both_flag(char* str);


void t_flag(char* str);

void no_flag(char* str);

void file_flag(char** file, int size);