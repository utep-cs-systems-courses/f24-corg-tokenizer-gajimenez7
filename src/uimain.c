# include <stdio.h>
# include <string.h>
# include "tokenizer.h"
# include "history.h"

#define MAXSIZE 1000

int checkExit(char* arr);
int checkHistory(char *arr);
int main(){
  char input[MAXSIZE];

  char **tokens = NULL;
  
  int exitFlag = 0;
  int historyFlag = 0;
  
  List *list = init_history();
  while (exitFlag != 1){
    
    printf("> ");

    fgets(input, MAXSIZE, stdin);

    add_history(list, input);
    
    if(checkExit(input) == 1){
      exitFlag = 1;
      break;
    }
    if(checkHistory(input) == 1){
      print_history(list);
    }
    if(checkHistory(input) > 1){
      printf("%s", get_history(list,checkHistory(input)-'0'));
    }
    else{
      /* test tokenizer */
      tokens = tokenize(input);
      print_tokens(tokens);
    }
  }
  return 0;
}

int checkHistory(char *arr){
  char *p_history = "history";
  int length = 7;
  int i = 1;
  
  while(*arr != '\0'){
    if(*(arr+2) >= 48 && *(arr+2) <= 57){
      return *(arr+2);
    }
    if(*arr != *p_history){
      return 0;
    }
    if(i > length){
      return 0;
    }
    if(i == length && *(arr++) == ' ' && *(arr++) != '\0'){
      break;
    }

    arr++;
    *p_history++;
    i++;
  }
  return 1;
}

int checkExit(char* arr){
  char *p_exit = "exit";
  
  int length = 4;
  int i = 1;

  /* traverse until the end of each string */
  /* check whether input is equal to "exit" */
  while(*arr != '\0'){
    if(*arr != *p_exit){
      return 0;
    }
    if(i > length){
      return 0;
    }
    if(i == length && *(arr++) == ' ' && *(arr++) != '\0'){
      break;
    }
    arr++;
    p_exit++;
    i++;
  }
  return 1;
}
