#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int verificaCaractere(char* str, char c, int isCaseSensitive);
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = verificaCaractere(texto, c, isCaseSensitive);
  return qtdOcorrencias;
}


int verificaCaractere(char* str, char c, int isCaseSensitive) {
    int ocorrencias = 0;
    int letra;
    if(c > 64 && c < 91){
      letra = 0; 
    }else if(c > 96 && c < 123){
      letra = 1; 
    }else{
      return ocorrencias = -1;
    }if(isCaseSensitive == 1){
      if (*str == '\0') {
        return ocorrencias;
      }else if(isCaseSensitive != 1 && *str == c){
          ocorrencias++;
          return ocorrencias + verificaCaractere(str + 1, c, isCaseSensitive);
      }else if (*str == c) {
          ocorrencias++;
          return ocorrencias + verificaCaractere(str + 1, c, isCaseSensitive);
      } else {
          return verificaCaractere(str + 1, c, isCaseSensitive);
      }
    }else if(isCaseSensitive != 1){
      if (*str == '\0') {
        return ocorrencias;
      }else if(isCaseSensitive != 1 && *str == c){
          ocorrencias++;
          return ocorrencias + verificaCaractere(str + 1, c, isCaseSensitive);
      }else if ((*str == c  || *str == c+32) && letra == 0) {
          ocorrencias++;
          return ocorrencias + verificaCaractere(str + 1, c, isCaseSensitive);
      }else if ((*str == c  || *str == c-32) && letra == 1) {
          ocorrencias++;
          return ocorrencias + verificaCaractere(str + 1, c, isCaseSensitive);
      } 
      else {
          return verificaCaractere(str + 1, c, isCaseSensitive);
      }
    }  
}


int main(){
  char str[250];
  strcpy(str, "Renato Lima NovaisA");
  int ocorrencias;
  ocorrencias = q3(str, '/', 0);
  printf("ocorrencias %d", ocorrencias);
}