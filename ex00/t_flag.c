#include "my_ls.h"



double my_difftime(long int tm1,long int tm2)
{   //here is minus cuz we are putting most recent in the beginnig,
    //most recent time has more milliseconds => the order is DESC order
    return -(tm1-tm2);
}

int comp_tm(struct file_tm *file1, struct file_tm *file2)
{
    //check the time of modification first
    if((file1->tm) != (file2->tm))
    {
        return my_difftime(file1->tm, file2->tm);
    } else
    {  //if they were modificated in one time, then sort in lexicographical order
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

void t_print(char* str)
{
    printf("%s\n", str);
    struct file_tm *head = NULL;
    struct dirent  *entry;
    struct stat     statbuf;
    long int      tm;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL) {

        if (stat(entry->d_name, &statbuf) == -1)
            continue;

        tm = statbuf.st_mtime;
        if(entry->d_name[0] != '.')
        {
            head = insert_tm(head, entry->d_name, tm);
        }
        
    }
         
        struct file_tm *current = head;
        while (current != NULL) {
            printf("%s\n", current->name);
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

void t_flag(flags* flag)
{
    if(flag->dir_container == NULL)
    {
        char str[2] = ".";
        t_print(str);
    } else
    {
        struct dir *container = flag->dir_container;
        while(container != NULL)
        {
            printf("%s:\n", container->name);
            t_print(container->name);
            container = container->next;
        }
    }
    
}