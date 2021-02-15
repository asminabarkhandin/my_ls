#include "my_ls.h"

void both_flag()
{
    struct file_tm *head = NULL;
    struct dirent  *entry;
    struct stat     statbuf;
    long int      tm;
    DIR *dir;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) {

        if (stat(entry->d_name, &statbuf) == -1)
            continue;

        tm = statbuf.st_mtime;
        
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