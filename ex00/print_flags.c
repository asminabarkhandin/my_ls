#include "my_ls.h"

void print_flags(flags* flag)
{
    if(flag->a == 1 && flag->t != 1)
    {
        a_flag();
    }
    if(flag->t == 1 && flag->a != 1)
    {
        t_flag();
    }
    if(flag->a == 1 && flag->t == 1)
    {
        at_flag();
        //file_flag(flag->file, flag->size);
    }
    if(flag->a == 0 && flag->t == 0)
    {
        no_flag();
        //file_flag(flag->file, flag->size);
    }
    
}