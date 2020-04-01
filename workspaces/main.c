#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <sys/stat.h>
#include <sys/types.h>



typedef struct {
    char pash[512];
    char fullpash[1024];
    int hierarchy;
}data;



data tmp(data *user);
data ls(data *user);
data touch(char *new_file);
data mkdir(char *mkdir);
data cat(char *file_name);
data move_dir(char *move_dir,data *user);
data hierarchy(data *user);
data fullpash(data *user);
data fullpash_echo(data *user);
data help(data *user);

int main(void){
	char com_ls[]="ls";
	char com_touch[]="touch";
	char com_mkdir[]="mkdir";
	char com_cat[]="cat";
	char com_cd[]="cd";
	char com_fullpath[]="fullpash";
	char com_help[]="help";
	char com_qu[]="?";

	data user;

	for(;;){
	　  char inp[256];
        char inp2[1024];

        tmp(&user);
        hierarchy(&user);
        fullpash(&user);
        scanf("%s %s",inp,inp2);


        if(strcmp(inp,com_ls) == 0){
	 	//ls
	 	ls(&user);
	  }else if(strcmp(inp,com_touch)==0){
	    //touch
	  	touch(&inp2);
	  }else if(strcmp(inp,com_mkdir)==0){
	  	//mkdir
	   	mkdir(&inp2);
	  }else if(strcmp(inp, com_cat)==0){
	  	//cat
	  	cat(&inp2);
	  }else if(strcmp(inp, com_cd)==0){
	  	//cd 
	    move_dir(&inp2,&user);
	  }else if(strcmp(inp,com_fullpath)==0){
	    fullpash_echo(&user);
	  }else if(strcmp(inp,com_help)==0){
	  	help();
	  }else if(strcmp(inp,com_qu)==0){
	   	help();
	   }else{
	  	printf("%s %s\n",inp,inp2);
	  }
	}
}



data tmp(data *user){
    char tmp[256];
    
	getcwd(tmp,sizeof(tmp));
	
	if(tmp==0){
		printf("erroe");
	}else{
		strcpy(user->pash,tmp);
		printf("%s ",user->pash);
	}
	return 0;
	
}



data ls(data *user){
	DIR *dir;
	struct dirent *dp;
	char tmp_1[]=".";
	char tmp_2[]="..";
	
	dir=opendir(user->pash);
	
	for(dp=readdir(dir);dp!=NULL;dp=readdir(dir)){
		    if(strcmp(tmp_1,dp->d_name)==0){
		    	continue;
		    }else if(strcmp(tmp_2,dp->d_name)==0){
		        continue;
		    }else{
		    printf("%s\n",dp->d_name);
		    }
      }

	closedir(dir);

	return 0;
}



data touch(char *file_name){
	struct stat statBuf;
	FILE *file;
	
	if(stat(file_name, &statBuf)==0){
		printf("%sは存在します。\n",file_name);
	}else{
	file = fopen(file_name,"w");
		
	fclose(file);
	}
	
	return 0;
}



data mkdir(char *dir_name){
	struct stat statBuf;	
	
	if (stat(dir_name, &statBuf) == 0){
        printf("%sは存在します。\n", dir_name);
    }else{
        mkdir(dir_name, 0755);
    }
    
    return 0;
}



data cat(char *file_name){
	struct stat statBuf;
	
	if(stat(file_name, &statBuf)==0){
	    char  i[1024];
	    char  h[1024];
	    FILE *fp;
	
	    fp = fopen(file_name,"r");

        while((fgets(i,256,fp))!=NULL){
            printf("%s\n",i);
        }	
        
        fclose(fp);
    }else{
    	printf("%sは存在しません。",file_name);
    }
    
	return 0;
}




data move_dir(char *move_dir,data *user){
    char buf[PATH_MAX];
    char sum_pash[256];
    struct stat statBuf;
    
    sprintf(sum_pash,"%s/%s",user->pash,move_dir);
  
    if(stat(sum_pash,&statBuf)==0){
    	chdir(sum_pash);
    }else{
    	chdir(move_dir);
    }
    return 0;
}

data fullpash(data *user){
    int n;
    char *ptr;
    char cpy_str[512];
    char fixstr[512];
    struct stat statBuf;
    
    
   // printf("%d\n",user->hierarchy);
    

    strcpy(cpy_str, user->pash);
    ptr = strtok(cpy_str, "/");
    //printf("%s\n",ptr);
    sprintf(fixstr,"%s",ptr);
  
    
    // 2回目以降
  
    for(int i;i<11;i++){
  
  
        // strtok関数により変更されたNULLのポインタが先頭
        ptr = strtok(NULL, "/");
       
       
        // ptrがNULLの場合エラーが発生するので対処
        if(ptr != NULL) {
        
         //   printf("%s\n", ptr);
            sprintf(fixstr,"%s/%s",fixstr,ptr);
           
       }
     }
     //printf("%s\n",fixstr);
     strcpy(user->fullpash,fixstr);
     return 0;
}


data hierarchy(data *user){
	int n;
    char *ptr;
    char cpy_str[1024];
    char fixstr[1024];
    //printf("%s",user->pash);
    
    
    strcpy(cpy_str,user->pash);
    
   // printf("%s\n",cpy_str);
    ptr = strtok(cpy_str, "/");
    sprintf(fixstr,"%s",ptr);
   // printf("%s\n",ptr);
    n++;
    
    // 2回目以降
    while(ptr != NULL) {
        // strtok関数により変更されたNULLのポインタが先頭
        ptr = strtok(NULL, "/");
        // ptrがNULLの場合エラーが発生するので対処
        if(ptr != NULL) {
           
           n++;
        }
    }
  
    user->hierarchy=n;
	return 0;
}

data fullpash_echo(data *user){
	printf("%s\n",user->fullpash);
	
	return 0;
}

data help(){
    printf("cd (path)\n");
    printf("ls\n");
    printf("fullpash\n");
    printf("toch (filename)\n");
    printf("mkdir (dirname)\n");
    printf("cat (filepath)\n");
    
    return 0;
}
