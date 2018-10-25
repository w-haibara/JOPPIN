#include <stdio.h>
#include <stdlib.h>

int fetchUserID(char* fileData);

int main(){
	char fileData[100];
	while(1){
		sleep(5);
		if(fetchUserID(fileData) == 0) printf("%s\n", fileData);
		//サーバーにfileDataを送る
	
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

int fetchUserID(char* fileData){
	FILE *file;
	int retNum = 0;

	const char command[20] = "python qrReader.py";
	system(command);

	if((file = fopen("userID.txt", "r+")) != NULL){
		fscanf(file, "%s", fileData);
    	fclose(file);
   	}else{
		retNum = 1;
	}

	return retNum;
}
