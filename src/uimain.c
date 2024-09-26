# include <stdio.h>
# include <string.h>

#define MAXSIZE 1000

int main(){
  char input[MAXSIZE];
  char exitCase[] = "exit";
  
  printf("> ");

  scanf("%s", &input);

  printf("%s \n", input);
  
  while(strcmp(input, exitCase) != 0){

    printf("> ");

    scanf("%s", &input);

    printf("%s \n", input);
  }

  return 0;
}
