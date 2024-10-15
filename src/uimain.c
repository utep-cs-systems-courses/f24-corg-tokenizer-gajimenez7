# include <stdio.h>
# include <string.h>
# include "tokenizer.h"

#define MAXSIZE 1000

int checkExit(char* arr);
int main(){
  char input[MAXSIZE];

  char **tokens = NULL;
  
  int exitFlag = 0;
  
  while (exitFlag != 1){
    
    printf("> ");

    fgets(input, MAXSIZE, stdin);

    printf("%s", input);

    if(checkExit(input) == 1){
      exitFlag = 1;
    }

    /* test tokenizer */
    tokens = tokenize(input);
    print_tokens(tokens);
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
