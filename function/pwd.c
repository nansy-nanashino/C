#include <stdio.h>
#include <unistd.h>

char *pwd(void);

int main(void){
    printf("%s",pwd());
}

char *pwd(void){
    char tmp[256];
    getcwd(tmp,sizeof(tmp));
    if(tmp==0){
        printf("erroe");
    }else{
        return tmp;
    }
}