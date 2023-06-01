
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>

int verificapalavra(char *strtexto, char *strbusca, int tam_busca, int tam_posicao, int *posicoes, int cont_busca, int cont_texto, int ocorrencias, int cont_letra);

int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int qtdOcorrencias = -1, tam_busca = 0, tam_posicao = 0, cont_busca = 0, cont_texto = 0, ocorrencias = 0, cont_letra = 0;
  for(int i = 0; strBusca[i] != '\0'; i++){
    tam_busca++;
  }
  qtdOcorrencias = verificapalavra(strTexto, strBusca, tam_busca, tam_posicao, posicoes, cont_busca, cont_texto, ocorrencias, cont_letra);
  // printf("ocorrencias 2: %d\n", qtdOcorrencias);
  return qtdOcorrencias;
}

int verificapalavra(char *strtexto, char *strbusca, int tam_busca, int tam_posicao, int posicoes[30], int cont_busca, int cont_texto, int ocorrencias, int cont_letra) {
  // int ocorrencias = 0;
  // printf("ocorrencias: %d\n", ocorrencias);
  
  // char *pont_aux;
  char *pont_busca = strbusca; // variável auxiliar para comparação
  char *pont_aux = pont_busca; // ponteiro auxiliar mantido inalterad
  // printf("cont texto %d\n", cont_texto);
  if(cont_texto == 0){
    pont_aux = strbusca; 
    // printf("ponteiro aux %c\n", *pont_aux);
  }
  // printf("Ocorrencias 2: %d\n", ocorrencias);
  if (*strtexto == '\0') { // condição de parada
    return ocorrencias;
  }
  // printf("ANTES DO IF\n");
  // printf("strtexto: %c\n", *strtexto);
  // printf("strbusca: %c\n", *strbusca);
  // printf("cont busca: %d\n", cont_busca);
  // printf("verificacao: %d\n", tam_posicao);
  if (*strtexto == *strbusca) {
    cont_letra++;
    // printf("cont busca: %d\n", cont_busca);
    if (tam_posicao % 2 == 0 || cont_busca == tam_busca -1) {
      posicoes[tam_posicao] = cont_texto + 1;
      tam_posicao++;
      // printf("tam posicao 1: %d\n", tam_posicao);
      // printf("strbusca: %c\n", *strbusca);
      // printf("strtexto: %c\n", *strtexto);
    }
    if (tam_posicao % 2 == 0 && tam_posicao != 0) {
      // printf("tam_posicao 2 %d\n", tam_posicao);
      ocorrencias = tam_posicao / 2;
      // printf("ocorrencias: %d\n ",ocorrencias);
      // printf("ponteiro auxiliar %c\n", *pont_aux);
      cont_letra = 0;
      return verificapalavra(strtexto + 1, strbusca - (tam_busca - 1), tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra);
    }
    return verificapalavra(strtexto + 1, strbusca + 1, tam_busca, tam_posicao, posicoes, cont_busca + 1, cont_texto + 1, ocorrencias, cont_letra);
  } else {
    if(tam_posicao % 2 != 0){
      // printf("******\n");
      tam_posicao -= 1;
      // printf("tam posicao 2: %d\n", tam_posicao);
      // printf("cont_letra %d\n", cont_letra);
      return verificapalavra(strtexto + 1, strbusca - cont_letra, tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra);
    }
    return verificapalavra(strtexto + 1, strbusca - cont_letra, tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra = 0);
  }
}



int main(){
    char strTexto[250];
    char strBusca[50];
    int posicoes[30];
    int i;
    for (i = 0; i<30; i++){
        posicoes[i] = -1;
    }
    strcpy(strTexto,"Laboratorio de programacao: para ratos de programação");
    strcpy(strBusca,"rato");
    printf("%d\n",q4(strTexto, strBusca, posicoes) == 2);
    printf("%d\n",posicoes[0]==5);
    printf("%d\n",posicoes[1]==8);
    printf("%d\n",posicoes[2]==34);
  // printf("posicao do [2]: %d\n", posicoes[2]);
  // printf("posicao do [3]: %d\n", posicoes[3]);
    printf("%d\n",posicoes[3]==37);
}