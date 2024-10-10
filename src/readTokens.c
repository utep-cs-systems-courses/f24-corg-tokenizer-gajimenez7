#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == '\t' || c == ' '){
    return 1;
  }
  return 0;
}

int non_space_char(char c){
  if(space_char(c) != 1){
    return 1;
  }
  return 0;
}

char *token_start(char *str){
  if(non_space_char(*str)){
      return str;
  }
  else{
     return 0;
  }
}

char *token_terminator(char *token){
  if(*token_start(token) == 0){
    return token;
  }
}

int count_tokens (char *s){
  int count = 0;
  while(*s != '\0'){
    count++;
    *s++;
  }
  return count;
}

char *copy_str(char *inStr, short len){
  /*need to allocate memory*/
  char *p = malloc(len+1);
  char *str = p;
  
  int count = 0;
  while(count < len){
    *str = *inStr;
    str++;
    inStr++;
    count++;
  }
  str++;
  *str = '\n';
  return str;
}

/*
char **tokenize(char *str){

}
*/
