#include <stdio.h>

void fetchUserID(char* fileData);

int main(){
	char fileData[100];
	FILE *file;

	if((file = fopen("userID.txt", "r+")) != NULL){
		fscanf(file, "%s", fileData);
    	fclose(file);
   	}

	return 0;
}
