#include "my_ls.h"

int my_strlen(char *str)
{
    int count = 0;
    char *ptr = str;
    while (*ptr != '\0')
    {
        ptr++;
        count++;
    }
    return count;
}

char *my_strcat(char *dest, const char *src)
{
    char *ptr = dest + my_strlen(dest);
    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }
    *ptr = '\0';
    return dest;
}

double my_difftime(struct timespec tm1, struct timespec tm2)
{  // here is minus cuz we are putting most recent in the begining,
// most recent time has more milliseconds => the order is DESC order
    if (tm1.tv_sec != tm2.tv_sec)
    {
        return -(tm1.tv_sec - tm2.tv_sec);
    }
    if (tm1.tv_nsec != tm2.tv_nsec)
    {
        return -(tm1.tv_nsec - tm2.tv_nsec);
    }
    return 0;
}

int comp_tm(struct file_tm *file1, struct file_tm *file2)
{
    if ((file1->tm.tv_sec) != (file2->tm.tv_sec))
    {
        return my_difftime(file1->tm, file2->tm);
    }
    else if ((file1->tm.tv_nsec) != (file2->tm.tv_nsec))
    {
        return my_difftime(file1->tm, file2->tm);
    }
    else
    {  // if they were modificated in one time, then sort in lexicographical 
    // order
        return my_strcmp(file1->name, file2->name);
    }
}

struct file_tm *insert_tm(struct file_tm *head, char *name, struct timespec tm)
{
    struct file_tm *ptr = malloc(sizeof(struct file_tm));
    ptr->name = name;
    ptr->tm = tm;
    ptr->next = NULL;
    struct file_tm **temp = &head;
    while (*temp != NULL && comp_tm(ptr, *temp) >= 0)
    {
        temp = &(*temp)->next;
    }
    ptr->next = *temp;
    *temp = ptr;
    return head;
}

void t_flag(char *str)
{
    struct file_tm *head = NULL;
    struct dirent *entry;
    struct stat statbuf;
    struct timespec tm;
    DIR *dir;
    dir = opendir(str);
    while ((entry = readdir(dir)) != NULL)
    {
        if (str[0] != '.') //if not local dir, we construct absolute path to access stat about files inside it
        {
                char abs_path[50] = "";
                char slash[2] = "/";
                my_strcat(abs_path, str);
                my_strcat(abs_path, slash);
                my_strcat(abs_path, entry->d_name);
                lstat(abs_path, &statbuf);
        }
        else
        {
            lstat(entry->d_name, &statbuf);
        }
        tm = statbuf.st_mtim;
        if (entry->d_name[0] != '.')
        {
            head = insert_tm(head, entry->d_name, tm);
        }
    }
    struct file_tm *current = head;
    while (current != NULL)
    {
        printf("%s  ", current->name);
        current = current->next;
    }
    printf("\n");
    struct file_tm *tofree;
    while (head != NULL)
    {
        tofree = head;
        head = head->next;
        free(tofree);
    }
    closedir(dir);
}