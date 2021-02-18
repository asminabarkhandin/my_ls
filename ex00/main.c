#include "my_ls.h"

int main(int ac, char** av)
{
    flags* my_flag = load_flags(ac, av);  // go to load_flags.c
    if (my_flag->size == -1)
    {
        struct dir* tofree;
        struct dir* head = my_flag->dir_container;
        while (head != NULL)
        {
            tofree = head;
            head = head->next;
            free(tofree);
        }
        free(my_flag);
        return -1;
    }
    print_flags(my_flag);  // go to print_flags.c
    struct dir* tofree;
    struct dir* head = my_flag->dir_container;
    while (head != NULL)
    {
        tofree = head;
        head = head->next;
        free(tofree);
    }
    free(my_flag);
    return 0;
}