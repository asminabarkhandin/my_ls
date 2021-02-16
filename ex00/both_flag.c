#include "my_ls.h"

void both_print(char* str)
{
    struct file_tm *head = NULL;
    struct dirent  *entry;
    struct stat     statbuf;
    struct timespec    tm;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL) {

        stat(entry->d_name, &statbuf);
            //continue;

        tm = statbuf.st_mtim;
        
        head = insert_tm(head, entry->d_name, tm);
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

void both_flag(flags* flag)
{
    if(flag->dir_container == NULL)
    {
        char str[2] = ".";
        both_print(str);
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
            
            both_print(container->name);
            index++;
            container = container->next;

            if(flag->size != 1 && index != flag->size)
            {
                printf("\n");
            }
        }
    }
    
    
}