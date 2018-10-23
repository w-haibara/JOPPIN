#include <stdio.h>
#include <stdlib.h>

void fetchUserID(char* fileData);

int main(){
	char fileData[100];

	fetchUserID(fileData);
	
	printf("%s\n", fileData);
	//サーバーにfileDataを送る
	
	while(1){
		//サーバーからの返答を待つ
		char json[100];
		//jsonを文字列として読み込む
		/*
		if(){
		}
		*/
	}



	return 0;
}

void fetchUserID(char* fileData){
	FILE *file;

	const char command[20] = "python qrReader.py";
	system(command);

	if((file = fopen("userID.txt", "r+")) != NULL){
		fscanf(file, "%s", fileData);
    	fclose(file);
   	}
}
