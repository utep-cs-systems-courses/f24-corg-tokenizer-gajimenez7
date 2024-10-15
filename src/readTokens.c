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
  if(space_char(c) != 1 && c != '\0'){
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
  while(space_char(*str) && *str != '\0'){
    str++;
  }
  return str;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  return token;
}

int count_tokens(char *s){
  int count = 0;
  char *p = token_start(s);
  while(*p != '\0'){
    count++;
    p = token_start(token_terminator(p));
  }
  return count;
}

char *copy_str(char *inStr, short len){
  /*need to allocate memory*/
  char *p = (char*)malloc((len+1)*sizeof(char));
  int count = 0;
  while(count < len){
    *(p + count) = *(inStr + count);
    count++;
  }
  *(p + count) = '\0';
  return p;
}

char **tokenize(char *str){
  /*
    count length of a token
    allocate size
    begin tokenize
    insert into token holder
    repeat
   */
  int strLen = count_tokens(str);
  char *tkn = str;
  char **tknHolder = malloc((strLen + 1)*sizeof(char*));

  int count = 0;
  
  while(count < strLen){
    tkn = token_start(tkn);
    char *tknEnd = token_terminator(tkn);
    int tknLen = tknEnd - tkn;

    tknHolder[count] = copy_str(tkn, tknLen);
    tkn = token_start(token_terminator(tkn));
    count++;
  }
  tknHolder[strLen] = NULL;
  return tknHolder;
}

void print_tokens(char **tokens){
  int count = 0;
  while(tokens[count] != 0){
    printf("%s", tokens[count]);
    count++;
    if(tokens[count] != 0){
      printf("\n");
    }
  }
}

void free_tokens(char **tokens){
  short len = 0;
  int count = 0;

  while(**tokens != 0){
    free(tokens[count]);
    count++;
  }
  free(tokens[count]);
}
