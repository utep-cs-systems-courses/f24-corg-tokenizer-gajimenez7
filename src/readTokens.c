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

char *token_start(char *s){
  if(non_space_char(*s)){
      return s;
  }
  else{
     return 0;
  }
}

char *token_terminator(char *token){
  if(space_char(*token)){
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
  
  int count = 0;
  char *str = "";
  while(count < len){
    *str = *inStr;
    *str++;
    *inStr++;
    count++;
  }
  return str;
}

char **tokenize(char *str){

}
