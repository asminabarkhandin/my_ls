#include "my_ls.h"

flags* set_object(int ac)
{
    flags* result = (flags*)malloc(sizeof(flags));
    result->a = 0;
    result->t = 0;
    result->size = 0;
    result->dir_container = NULL;
    return result;
}

void set_flags(flags* result, char* str)
{
    int index = 1;
    while (str[index] != '\0')
    {
        if (str[index] == 'a')
        {
            result->a = 1;
        }
        if (str[index] == 't')
        {
            result->t = 1;
        }
        if (str[index] != 'a' && str[index] != 't')
        {
            printf("my_ls: invalid option -- \'%c\'\n", str[index]);
            //exit(1);
        }
        index++;
    }
}

int comp_dir_by_tm(struct dir *file1, struct dir *file2)
{
    if((file1->tm.tv_sec) != (file2->tm.tv_sec))
    {
        return my_difftime(file1->tm, file2->tm);
    } else if ((file1->tm.tv_nsec) != (file2->tm.tv_nsec))
    {
        return my_difftime(file1->tm, file2->tm);
    }
    else
    {  //if they were modificated in one time, then sort in lexicographical order
        return my_strcmp(file1->name, file2->name); 
    }
}

struct dir *set_dir (struct dir *head, char* name, struct timespec tm, flags* flag)
{
    struct dir *ptr = malloc(sizeof(struct dir));
    ptr->name = name;
    ptr->tm = tm;
    ptr->next = NULL;
    struct dir **temp = &head;
    if(flag->t == 0)
    {
        while (*temp != NULL && my_strcmp(ptr->name, (*temp)->name) >= 0) {
            temp = &(*temp)->next;
        }
    } else //trying to compare dirs on their mtime
    {
        while (*temp != NULL && comp_dir_by_tm(ptr, *temp) >= 0) {
            temp = &(*temp)->next;
        }
    }
    ptr->next = *temp;
    *temp = ptr;
    return head;

}

flags* load_flags(int ac, char** av)
{
    flags* result = set_object(ac);
    struct dir* head = NULL;
    int index = 1;
    int size = 0;
    while (index < ac)
    {
        if (av[index][0] == '-')
        {
            set_flags(result, av[index]);
        } else
        {
            struct stat statbuf;
            stat(av[index], &statbuf);
            struct timespec tm = statbuf.st_mtim;
            head = set_dir(head, av[index], tm, result);
            size++;
        }
        index++;
    }

    result->dir_container = head;
    result->size = size;
    return result;
}