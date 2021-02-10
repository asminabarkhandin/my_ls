#include "my_ls.h"

flags* set_object()
{
    flags* result = (flags*)malloc(sizeof(flags));
    result->a = 0;
    result->t = 0;

    return result;
}

void set_flags(flags* result, char* str)
{
    int index = 0;
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
        index++;
    }
}

flags* load_flags(int ac, char** av)
{
    flags* result = set_object();
    int index = 0;
    while (index < ac)
    {
        if (av[index][0] == '-')
        {
            set_flags(result, av[index]);
        }
        index++;
    }
    return result;
}