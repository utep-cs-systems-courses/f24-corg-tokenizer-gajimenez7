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
  while(space_char(*str)){
    printf("[1.1]true token_start\n");
    str++;
  }
  printf("[1.2]return token start\n");
  return str;
}

char *token_terminator(char *token){
  while(non_space_char(*token)){
    printf("[2.1]true token_terminator\n");
    token++;
  }
  printf("[2.2]return token_terminator\n");
  return token;
}

int count_tokens(char *s){
  int count = 0;
  char *p = token_start(s);
  while(*p != '\0'){
    printf("[3.1]true count tokens\n");
    count++;
    p = token_terminator(p);
  }
  printf("[3.2]count tokens return\n");
  return count;
}

char *copy_str(char *inStr, short len){
  /*need to allocate memory*/
  char *p = (char*)malloc(len+1*sizeof(char));
  
  int count = 0;
  while(count < len){
    printf("[4.1]true copy_str\n");
    *p = *inStr;
    p++;
    inStr++;
    count++;
  }
  p++;
  *p = '\0';
  printf("[4.2]return copy_str\n"); 
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
  printf("%d\n", strLen);
  char *tkn = str;
  char **tknHolder = malloc((strLen + 1)*sizeof(char*));

  int count = 0;
  
  while(count < strLen){
    printf("[5.1]true tokenize\n");
    tkn = token_start(tkn);
    char *tknEnd = token_terminator(tkn);
    int tknLen = tknEnd - tkn;

    *tknHolder = copy_str(tkn, tknLen);
    tkn = token_terminator(tkn);
    tknHolder++;
    count++;
  }
  tknHolder[strLen] = NULL;
  printf("[5.2]return tokenize\n");
  return tknHolder;
}

void print_tokens(char **tokens){
  int count = 0;
  while(**tokens != 0){
    printf("%s\n", tokens[count]);
    count++;
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



