#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */
int contar_digitos(int num) {
    int contador = 0;
    while (num != 0) {
        num /= 10;
        contador++;
    }
    return contador;
}


char* inverteNumeros(char *str, int tam, int inicio){
  char aux;
  printf("incio : %d\n tam: %d\n", inicio, tam);
  printf("str inicio : %c\n str tam: %c\n", str[inicio], str[tam]);
  if(tam == inicio || tam < inicio){
    return str;
  }else{
    aux = str[inicio];
    printf("aux: %c\n", aux);
    str[inicio] = str[tam];
    str[tam] = aux;
    printf("DEPOIS DA TROCA\n");
    printf("str inicio : %c\n str tam: %c\n", str[inicio], str[tam]);
    return inverteNumeros(str, tam - 1, inicio + 1);
  } 
}

int q5(int num) {
  int tam = contar_digitos(num);
  char *str = NULL;
  int inicio = 0;
  str = (char*) malloc((tam + 1) * sizeof(char));
  sprintf(str, "%d", num);
  str[tam] = '\0';
  tam -= 1;
  num = atoi(inverteNumeros(str, tam, inicio));

  return num;
}

int main(){
  int retorno;
  retorno = q5(752);
  printf("retorno: %d", retorno);
}