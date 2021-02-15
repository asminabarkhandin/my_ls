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
        /*else
        {
            printf("invalid option\n");
        }*/
        index++;
    }
}

struct dir *set_dir (struct dir *head, char* name)
{
    struct dir *ptr = malloc(sizeof(struct dir));
    ptr->name = name;
    ptr->next = NULL;
    struct dir **temp = &head;
    while (*temp != NULL && my_strcmp(ptr->name, (*temp)->name) >= 0) {
        temp = &(*temp)->next;
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
            head = set_dir(head, av[index]);
            size++;
        }
        index++;
    }

    result->dir_container = head;
    result->size = size;
    return result;
}