#include "my_ls.h"

int my_strcmp(const char *str1, const char *str2)
{
    while (*str1)
    {
        if (*str1 != *str2)
        {
            break;
        }
        str1++;
        str2++;
    }
    return *(const unsigned char *)str1 - *(const unsigned char *)str2;
}

struct file_tm *insert(struct file_tm *head, char *name)
{
    struct file_tm *ptr = malloc(sizeof(struct file_tm));
    ptr->name = name;
    ptr->next = NULL;
    struct file_tm **temp = &head;
    while (*temp != NULL && my_strcmp(ptr->name, (*temp)->name) >= 0)
    {
        temp = &(*temp)->next;
    }
    ptr->next = *temp;
    *temp = ptr;
    return head;
}

void a_flag(char *str)
{
    struct file_tm *head = NULL;
    struct dirent *entry;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL)
    {
        head = insert(head, entry->d_name);
    }
    struct file_tm *current = head;
    while (current != NULL)
    {
        printf("%s\n", current->name);
        current = current->next;
    }
    struct file_tm *tofree;
    while (head != NULL)
    {
        tofree = head;
        head = head->next;
        free(tofree);
    }
    closedir(dir);
}