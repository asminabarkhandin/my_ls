#include "my_ls.h"

flags* set_object(int ac)
{
    flags* result = (flags*)malloc(sizeof(flags));
    result->a = 0;
    result->t = 0;
    result->size = 0;
    //result->dir = malloc(sizeof(char*) * (ac-1));
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

/*char** set_dir(char* str)
{
        char** dir = malloc(sizeof(char*) * 2);
        dir[0] = malloc(sizeof(char)*strlen(str));
        strcpy(dir[0], str);
        return dir;
        //printf("%i\n",result->size);
    

}*/

flags* load_flags(int ac, char** av)
{
    flags* result = set_object(ac);
    int index = 1;
    while (index < ac)
    {
        if (av[index][0] == '-')
        {
            set_flags(result, av[index]);
        } /*else
        {
            result->dir = set_dir(av[index]);
        }*/
        index++;
    }
    return result;
}