#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>


/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
/    Quantidade de vezes que número de busca ocorre em número base
*/
int contar_digitos(int num) {
    int contador = 0;
    while (num != 0) {
        num /= 10;
        contador++;
    }
    return contador;
}

int verifica_numero(int qtdOcorrencias, char *str, char *str2, int tam2, int cont_busca){
  // printf("STR 2 %c\n", *str + 2);
  // printf("STR %c\n STR2 %c\n", *str, *str2);
  if(*str == '\0'){
    // printf("*******5******\n");
    return qtdOcorrencias;
  }
  if(*str == *str2){
    // printf("*******!******\n");
    if(cont_busca == tam2 - 1){
      // printf("*******2******\n");
      return verifica_numero(qtdOcorrencias + 1, str + 1, str2 - (tam2 -1), tam2, cont_busca = 0);
    }else{
      // printf("*******3******\n");
      return verifica_numero(qtdOcorrencias, str + 1,  str2 + 1, tam2, cont_busca + 1);
    }
  }else{
    // printf("*******4******\n");
    if(cont_busca != 0){
      return verifica_numero(qtdOcorrencias, str + 1, str2 - (tam2 -1), tam2, cont_busca = 0);
    }
    return verifica_numero(qtdOcorrencias, str + 1,  str2, tam2, cont_busca);
  }
  
}



int q6(int numerobase, int numerobusca) {    
  int qtdOcorrencias, cont_busca = 0;
  int tam = contar_digitos(numerobase);
  char str[tam + 1];
  // printf("TAM %d\n", tam);
  sprintf(str, "%d", numerobase);
  str[tam] = '\0';
  // printf("%s\n", str);

  int tam2 = contar_digitos(numerobusca);
  char str2[tam2 + 1];
  // printf("TAM2 : %d\n", tam2);
  sprintf(str2, "%d", numerobusca);
  str2[tam2] = '\0';
  // printf("%s\n", str2);

  qtdOcorrencias = verifica_numero(qtdOcorrencias, str, str2, tam2, cont_busca);
    
    return qtdOcorrencias;
}

int main(){
    int retorno;
    retorno = q6(313165431, 31);
    printf("RETORNO: %d\n", retorno);
}
