#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fetchJson(char* fileData);

int main(){
	char fileData[100];
	
	int i = fetchJson(fileData);

	if(i == 0){
		printf("%s\n",fileData);
	}

	return 0;
}

int fetchJson(char* fileData){
	FILE *file;
	int returnNum = 0;

	if((file = fopen("test.json", "r")) != NULL){
		fscanf(file, "%s", fileData);
		fclose(file);
	}else{
		returnNum = 1;
	}
	
	return returnNum;
}
