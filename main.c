#include <unistd.h>
#include <stdio.h>

typedef struct s_list
{
    void            *a;
    struct s_list   *next;
}   t_list;

int main(int ac, char **av)
{
    (void)ac;
    (void)av;    
}
