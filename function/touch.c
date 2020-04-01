#include <stdio.h>
#include <sys/stat.h>
​
int touch(char file_name);
​
int main(void)
{
	touch("test.txt");
	return 0;
}
​
​
int touch(char *file_name){
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



