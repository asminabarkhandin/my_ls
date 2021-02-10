#include "my_ls.h"
void a_flag(){

    DIR *folder;
    folder = opendir(".");
    struct dirent *entry;
    if(folder == NULL){
        printf("is null\n");
    } else
    {
        while (entry = readdir(folder))
        {   
            printf("%s\n", entry->d_name);
        }
        
        
    }
    closedir(folder);
   
}