#include "my_ls.h"



double my_difftime(struct timespec tm1,struct timespec tm2)
{   //here is minus cuz we are putting most recent in the begining,
    //most recent time has more milliseconds => the order is DESC order
    if(tm1.tv_sec != tm2.tv_sec)
    {
        return -(tm1.tv_sec - tm2.tv_sec);
    } else
    {
        return -(tm1.tv_nsec-tm2.tv_nsec);
    }
    
}

int comp_tm(struct file_tm *file1, struct file_tm *file2)
{
    //check the time of modification first
    if((file1->tm.tv_sec) != (file2->tm.tv_sec))
    {
        return my_difftime(file1->tm, file2->tm);
    } else
    {  //if they were modificated in one time, then sort in lexicographical order
        return my_strcmp(file1->name, file2->name); 
    }
}

struct file_tm *insert_tm (struct file_tm *head, char* name, struct timespec tm)
{
    struct file_tm *ptr = malloc(sizeof(struct file_tm));
    ptr->name = name;
    ptr->tm = tm;
    ptr->next = NULL;
    struct file_tm **temp = &head;
    while (*temp != NULL && comp_tm(ptr, *temp) >= 0) {
        temp = &(*temp)->next;
    }
    ptr->next = *temp;
    *temp = ptr;
    return head;

}

void t_print(char* str)
{
    //printf("%s\n", str);
    struct file_tm *head = NULL;
    struct dirent  *entry;
    struct stat     statbuf;
    struct timespec     tm;
    DIR *dir;
    dir = opendir(str);
    
    while ((entry = readdir(dir)) != NULL) {

        //if (stat(entry->d_name, &statbuf) == -1)
            //continue;

        tm = statbuf.st_mtim;
        
        if(entry->d_name[0] != '.')
        {
            head = insert_tm(head, entry->d_name, tm);
        }
        
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

void t_flag(flags* flag)
{
    if(flag->dir_container == NULL)
    {
        char str[2] = ".";
        t_print(str);
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
            t_print(container->name);
            index++;
            container = container->next;

            if(flag->size != 1 && index != flag->size)
            {
                printf("\n");
            }
        }
    }
    
}