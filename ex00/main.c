#include "my_ls.h"

int main(int ac, char** av)
{
    flags* my_flag = load_flags(ac, av);
    print_flags(my_flag);
    struct dir* tofree;
    struct dir* head = my_flag->dir_container;
    while (head != NULL)
    {
        tofree = head;
        head = head->next;
        free(tofree);
    }
    free(my_flag);
}