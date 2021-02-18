#include "my_ls.h"

void print_f(flags* flag, void (*printer)())
{
    if (flag->dir_container == NULL)
    {
        char str[2] = ".";
        printer(str);
    }
    else
    {
        struct dir* container = flag->dir_container;
        int index = 0;
        while (container != NULL)
        {
            if (flag->size != 1)
            {
                printf("%s:\n", container->name);
            }
            printer(container->name);
            index++;
            container = container->next;

            if (flag->size != 1 && index != flag->size)
            {
                printf("\n");
            }
        }
    }
}

void print_flags(flags* flag)
{
    if (flag->a == 1 && flag->t != 1)
    {
        print_f(flag, a_flag);  // a_flag.c
    }
    if (flag->t == 1 && flag->a != 1)
    {
        print_f(flag, t_flag);  // t_flag.c
    }
    if (flag->a == 1 && flag->t == 1)
    {
        print_f(flag, both_flag);  // both_flag.c
    }
    if (flag->a == 0 && flag->t == 0)
    {
        print_f(flag, no_flag);  // no_flag.c
    }
}