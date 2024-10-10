# include <stdio.h>
# include <string.h>
# include "tokenizer.h"

#define MAXSIZE 1000

int checkExit(char* arr);
int main(){
  char input[MAXSIZE];

  int exitFlag = 0;
  
  while (exitFlag != 1){
    
    printf("> ");

    fgets(input, MAXSIZE, stdin);

    printf("%s", input);

    /* test space_char method */
    printf("%d \n", space_char(input[0]));

    /* test non_space_char method */
    printf("%d \n", non_space_char(input[0]));

    /* test token_start method */
    printf("%c \n", *token_start(input));

    /* test token_terminator method */
    while(*input != '\0'){
      printf("%c \n", *token_terminator(input));
    }
    
    if(checkExit(input) == 1){
      exitFlag = 1;
    }
  }
  return 0;
}

int checkExit(char* arr){
  char *p_exit = "exit";
  
  int length = 0;

  /* traverse until the end of each string */
  /* check whether input is equal to "exit" */
  while(*arr != '\0' || *p_exit != '\0'){
    if(*arr != *p_exit){
      if(*p_exit == '\0'){
	break;
      }
      return 0;
    }
    arr++;
    *p_exit++;
  }
  return 1;
}
