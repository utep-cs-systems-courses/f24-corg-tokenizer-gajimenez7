# include <stdio.h>
# include <string.h>

int main(){
  char input[30];
  char exitFlag[] = "exit";
  
  printf("> ");

  scanf("%s", &input);

  printf("%s \n", input);
  
  while(strcmp(input, exitFlag) != 0){

    printf("> ");

    scanf("%s", &input);

    printf("%s \n", input);
  }

  return 0;
}
