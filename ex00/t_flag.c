#include "my_ls.h"

struct file_tm
{
    char* name;
    long int tm;
    struct file_tm *next;
};

double my_difftime(long int tm1,long int tm2)
{
    printf("reacged\n");
    return -(tm1-tm2);
}

int comp_tm(struct file_tm *file1, struct file_tm *file2)
{
    printf("%ld hey %s\n", file1->tm, file1->name);
    printf("%ld hey %s\n", file2->tm, file2->name);
    if((file1->tm) != (file2->tm))
    {
        return my_difftime(file1->tm, file2->tm);
       
    } else
    {
        //printf("%s hey %s\n", file1->name, file2->name);
        return my_strcmp(file1->name, file2->name); 
    }
}

struct file_tm *insert_tm (struct file_tm *head, char* name, long int tm)
{
    struct file_tm *ptr = malloc(sizeof(struct file_tm));
    ptr->name = name;
    ptr->tm = tm;
    ptr->next = NULL;
    struct file_tm **temp = &head;
    while (*temp != NULL && comp_tm(ptr, *temp) >= 0) {
        temp = &(*temp)->next;
    }
    ptr->next = *temp;
    *temp = ptr;
    return head;

}


void t_flag()
{
    struct file_tm *head = NULL;
    struct dirent  *entry;
    struct stat     statbuf;
    long int      tm;
    DIR *dir;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) {

        if (stat(entry->d_name, &statbuf) == -1)
            continue;

        tm = statbuf.st_mtime;
        if(entry->d_name[0] != '.')
        head = insert_tm(head, entry->d_name, tm);
    }
         
        struct file_tm *current = head;
        while (current != NULL) {
            printf("%s\t", current->name);
            current = current->next;
        }
        struct file_tm *tofree;
        while (head != NULL) {
            tofree = head;
            head = head->next;
            free(tofree);
        }
        closedir(dir);
    
}