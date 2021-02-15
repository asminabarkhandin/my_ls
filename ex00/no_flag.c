#include "my_ls.h"
void no_flag(){

    struct file *head = NULL;
    struct dirent  *entry;
    DIR *dir;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) 
    {
        if(entry->d_name[0] != '.')
        head = insert(head, entry->d_name);
    }
         
        struct file *current = head;
        while (current != NULL) {
            printf("%s\n", current->name);
            current = current->next;
        }
        struct file *tofree;
        while (head != NULL) {
            tofree = head;
            head = head->next;
            free(tofree);
        }
        closedir(dir);
    
}