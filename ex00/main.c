#include "my_ls.h"

int main(int ac, char** av)
{
    flags* my_flag = load_flags(ac, av);
    print_flags(my_flag);
    
    free(my_flag);

}