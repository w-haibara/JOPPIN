#include <stdio.h>
#include <stdlib.h>
int main(){
  char fileData[100];

  FILE *file;

  const char command[100] = "python ~/JOPPIN/src/qrReader.py";
  system(command);

  if((file = fopen("userID.txt", "r+")) != NULL){
    fscanf(file, "%s", fileData);

    fclose(file);
  
    printf("%s\n", fileData);
  }

  return 0;
}
