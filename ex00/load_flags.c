#include "my_ls.h"

flags* set_object(int ac)
{
    flags* result = (flags*)malloc(sizeof(flags));
    result->a = 0;
    result->t = 0;
    result->size = 0;
    result->file = malloc(sizeof(char*) * ac);
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
        else
        {
            printf("invalid option\n");
        }
        index++;
    }
}

void set_file(flags* result, char* str)
{
    
        result->file[result->size] = malloc(sizeof(char)*strlen(str));
        strcpy(result->file[result->size], str);
        result->size++;
        printf("%i\n",result->size);
    

}

flags* load_flags(int ac, char** av)
{
    flags* result = set_object(ac);
    int index = 0;
    while (index < ac)
    {
        if (av[index][0] == '-')
        {
            set_flags(result, av[index]);
        } else
        {
            set_file(result, av[index]);
        }
        index++;
    }
    return result;
}