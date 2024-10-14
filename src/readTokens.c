#include <stdlib.h>
#include <stdio.h>
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

/* 
   while space char, iterate string
   then add 0 for token terminator
   to return
*/

char *token_start(char *str){
  if(non_space_char(*str)){
      return str;
  }
  else{
     return 0;
  }
}

char *token_terminator(char *token){
  char *end = "$";
  if(*token_start(token) == 0){
    return end;
  }
}

int count_tokens(char *s){
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
  *str = '\0';
  return str;
}

char **tokenize(char *str){
  /*
    count length of a token
    allocate size
    begin tokenize
    insert into token holder
    repeat
   */
  
  char **tokenHolder = malloc(100 * sizeof(char*));

  int count = 0;
  
  while(*str != '\0'){
    if(*token_start(str) != 0){
      count++;
    }
    if(*str == '\0'){
      printf("pesky zero terminator \n");
    }
    printf("%c \n", *str);
    printf("%d \n", count);
    str++;
    printf("almost end \n");
  }
  printf("clear end\n");
  return tokenHolder;
}
