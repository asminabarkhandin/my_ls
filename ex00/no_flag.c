#include "my_ls.h"
void no_flag(){

    DIR *folder;
    folder = opendir(".");
    struct dirent *entry;
    if(folder == NULL){
        printf("is null\n");
    } else
    {
        while(entry = readdir(folder))
        {
            if(entry->d_name[0] != '.')
            printf("%s\n", entry->d_name);
        }
    }
    closedir(folder);
    
}