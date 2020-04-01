#include <stdio.h>
#include <dirent.h>
#include <string.h>

int ls(void);

int main(void){
    printf("[user@localhost ~/] ls\n");
    ls();
}

int ls(void){
    DIR *dir;
    struct dirent *dp;
    char tmp_1[]=".";
    char tmp_2[]="..";
    dir=opendir(tmp_1);
    int n;
    for(dp=readdir(dir);dp!=NULL;dp=readdir(dir)){
        if(strcmp(tmp_1,dp->d_name)==0){
            continue;
        }else if(strcmp(tmp_2,dp->d_name)==0){
            continue;
        }else{
            n++;
            if(n%4==0){
                printf("%s\n",dp->d_name);
            }else{
                printf("%s ",dp->d_name);
            }
        }
    }
    closedir(dir);
    return 0;
}