#include <stdio.h>

int main(){
  char fileData[100];

  FILE *file;

  if((file = fopen("text.txt", "r+")) != NULL){

    fscanf(file, "%s", fileData);

    fclose(file);
  
    printf("%s\n", fileData);
  }

  return 0;
}
