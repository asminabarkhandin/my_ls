#include "my_ls.h"

struct file
{
    char* name;
    struct file *next;
};


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

struct file *insert (struct file *head, char* name)
{
    struct file *ptr = malloc(sizeof(struct file));
    ptr->name = name;
    ptr->next = NULL;
    struct file **temp = &head;
    while (*temp != NULL && my_strcmp(ptr->name, (*temp)->name) >= 0) {
        temp = &(*temp)->next;
    }
   
    ptr->next = *temp;
    *temp = ptr;
    return head;

}


void a_flag()
{
    struct file *head = NULL;
    struct dirent  *entry;
    DIR *dir;
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL) 
    {
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