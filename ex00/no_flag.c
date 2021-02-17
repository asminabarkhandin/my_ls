#include "my_ls.h"


void no_flag(char* str)
{
    
    struct file_tm *head = NULL;
    struct dirent  *entry;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL) 
    {
        if(entry->d_name[0] != '.')
        head = insert(head, entry->d_name);
    }
         
        struct file_tm *current = head;
        while (current != NULL) {
            printf("%s\n", current->name);
            current = current->next;
        }
        struct file_tm *tofree;
        while (head != NULL) {
            tofree = head;
            head = head->next;
            free(tofree);
        }
        closedir(dir);
}
/*
void no_flag(flags* flag){

    if(flag->dir_container == NULL)
    {
        char str[2] = ".";
        no_print(str);
    } else
    {
        struct dir *container = flag->dir_container;
        int index = 0;
        while(container != NULL)
        {
            if(flag->size != 1)
            {
                printf("%s:\n", container->name);
            }
            
            no_print(container->name);
            index++;
            container = container->next;
            if(flag->size != 1 && index != flag->size)
            {
                printf("\n");
            }
        }
    }

    
}*/
