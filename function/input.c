#include <stdio.h>

int main()
{
    char buf[1024];
    char tokun1[512];
    char tokun2[512];
    for(;;)
    {
        fgets(buf,sizeof(buf),stdin);
        sscanf(buf,"%s %[^\n]%*c",tokun1,tokun2);
        printf("%s %s\n",tokun1,tokun2);
    }
    return 0;
}