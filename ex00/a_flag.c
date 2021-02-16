#include "my_ls.h"



int my_strcmp(const char *str1, const char *str2)
{
    while(*str1)
    {
        // if characters differ or end of second string is reached
        if (*str1 != *str2)
            break;
 
        // move to next pair of characters
        str1++;
        str2++;
    }
 
    // return the ASCII difference after converting char* to unsigned char*
    return *(const unsigned char*)str1 - *(const unsigned char*)str2;
}

struct file_tm *insert (struct file_tm *head, char* name)
{
    struct file_tm *ptr = malloc(sizeof(struct file_tm));
    ptr->name = name;
    ptr->next = NULL;
    struct file_tm **temp = &head;
    while (*temp != NULL && my_strcmp(ptr->name, (*temp)->name) >= 0) {
        temp = &(*temp)->next;
    }
   
    ptr->next = *temp;
    *temp = ptr;
    return head;

}

void a_print(char* str)
{
    struct file_tm *head = NULL;
    struct dirent  *entry;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL) 
    {
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

void a_flag(flags* flag)
{
    if(flag->dir_container == NULL)
    {
        char str[2] = ".";
        a_print(str);
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
            
            a_print(container->name);
            index++;
            container = container->next;

            if(flag->size != 1 && index != flag->size)
            {
                printf("\n");
            }
        }
    }
    
    
}