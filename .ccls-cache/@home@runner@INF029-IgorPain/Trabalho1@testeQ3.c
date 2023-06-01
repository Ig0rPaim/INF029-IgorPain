#include <stdio.h>
#include <stdlib.h>
#include "IgorOliveira-20222160010.h"
#include <string.h>
/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa
 Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar
 diferenças entre maiúsculos e minúsculos. Se isCaseSensitive != 1, a pesquisa
 não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int percorrerstring(int indice, char *texto, char c, int qtdOcorrencias_f);
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = -1;
  int indice = 0, qtdOcorrencias_f = 0;
  percorrerstring(indice, texto, c, qtdOcorrencias_f);
  qtdOcorrencias = percorrerstring(indice, texto, c, qtdOcorrencias_f);
  //printf("*****2******");

  return qtdOcorrencias;
}



int percorrerstring(int indice, char *texto, char c, int qtdOcorrencias_f){
  if(texto[indice] == '\0'){
    printf("texto: %c\n");
    indice++;
    //printf("valor de indice: %d\n");
    return qtdOcorrencias_f;
  }if(texto[indice] == c){
      qtdOcorrencias_f++;
      //printf("%d\n", qtdOcorrencias_f);
  }
  indice++;
  return percorrerstring(indice, texto, c, qtdOcorrencias_f);
}

int main(){
  char str[250];
  strcpy(str, "Renato Lima Novais");
  int ocorrencias;
  ocorrencias = q3(str, "a", 1);
  printf("ocorrencias %d", ocorrencias);
}


