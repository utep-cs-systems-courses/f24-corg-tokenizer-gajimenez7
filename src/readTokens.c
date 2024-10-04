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
