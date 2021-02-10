#include "my_ls.h"

void print_flags(flags* flag)
{
    if(flag->a == 1)
    {
        a_flag();
    }
    if(flag->t == 1)
    {
        t_flag();
    }
    if(flag->a == 0 && flag->t == 0)
    {
        //no_flag();
        file_flag(flag->file, flag->size);
    }
    
}