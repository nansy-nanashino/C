#include <stdio.h>
#include <string.h>
typedef struct
{
    char name[128];
    char pc[128];
}data;

int input(data *user);
char *id(data *user);
char *pc(data *user);

int main(void)
{
    data user;
    input(&user);
    printf("[%s@",id(&user));
    printf("%s ~/]\n",pc(&user));
}

int input(data *user)
{
    char name[]="user";
    char pc[]="localhost";
    strcpy(user->name,name);
    strcpy(user->pc,pc);
    return 0;
}

char *id(data *user)
{
    char user_name[128];
    strcpy(user_name,user->name);
    return user_name;
}

char *pc(data *user)
{
    char pc_name[128];
    strcpy(pc_name,user->pc);
    return pc_name;
}
