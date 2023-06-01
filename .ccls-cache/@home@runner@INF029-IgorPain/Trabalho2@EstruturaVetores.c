#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 10

#include "EstruturaVetores.h"

vetor_aux vetorPrincipal[TAM];
int tamVetorAux = 0;
// int **vetorPoneiros = (int**)malloc(TAM * sizeof(int));

/*
Objetivo: criar estrutura auxiliar na posição 'posicao'.
com tamanho 'tamanho'

Rertono (int)
    SUCESSO - criado com sucesso
    JA_TEM_ESTRUTURA_AUXILIAR - já tem estrutura na posição
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    SEM_ESPACO_DE_MEMORIA - Sem espaço de memória
    TAMANHO_INVALIDO - o tamanho deve ser maior ou igual a 1
*/
int criarEstruturaAuxiliar(int posicao, int tamanho)
{
    int retorno = 0;
    posicao -= 1;
    if(vetorPrincipal[posicao].valor != NULL)
      retorno = JA_TEM_ESTRUTURA_AUXILIAR;
    else if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
      retorno = POSICAO_INVALIDA;
    else if(tamanho < 1)
      retorno = TAMANHO_INVALIDO;
    else{
    	vetorPrincipal[posicao].valor = (int*)malloc(tamanho * sizeof(int));
    	if(vetorPrincipal[posicao].valor == NULL)
      	retorno = SEM_ESPACO_DE_MEMORIA;
	    else{
        vetorPrincipal[posicao].tam = tamanho;
        vetorPrincipal[posicao].use = 0;
        retorno = SUCESSO;
    }
   }
  return retorno;   
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
  posicao -= 1;
  int retorno = 0;
  int existeEstruturaAuxiliar = 0;
  int temEspaco = 0;
  int posicao_invalida = 0;

  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    posicao_invalida = 1;
  
  if(vetorPrincipal[posicao].valor != NULL)
    existeEstruturaAuxiliar = 1;

  if(vetorPrincipal[posicao].use < vetorPrincipal[posicao].tam)
    temEspaco = 1;
  if (posicao_invalida){
      retorno = POSICAO_INVALIDA;
  }
  else
  {
      if (existeEstruturaAuxiliar)
      {
          if (temEspaco)
          {
            int onde_colocar = vetorPrincipal[posicao].use;
            vetorPrincipal[posicao].valor[onde_colocar] = valor;
            vetorPrincipal[posicao].use += 1;
            retorno = SUCESSO;
          }
          else
          {
              retorno = SEM_ESPACO;
          }
      }
      else
      {
          retorno = SEM_ESTRUTURA_AUXILIAR;
      }
  }
  return retorno;
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{
  
  int retorno = SUCESSO;
  posicao -= 1;
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else if(vetorPrincipal[posicao].valor == NULL){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else if(vetorPrincipal[posicao].use == 0){
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }
  else{
    vetorPrincipal[posicao].use -= 1;
  } 
  
  return retorno;
  
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
  
    int retorno = NUMERO_INEXISTENTE;
  posicao -= 1;
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  
  else if(vetorPrincipal[posicao].valor == NULL){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
   
  else if(vetorPrincipal[posicao].use == 0){
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  }
  else{
    for(int i = 0; i < vetorPrincipal[posicao].use; i++){
      if(vetorPrincipal[posicao].valor[i] == valor){
        for(int j = i+1; j < vetorPrincipal[posicao].use; j++, i++)
          vetorPrincipal[posicao].valor[i] = vetorPrincipal[posicao].valor[j]; 
        vetorPrincipal[posicao].use -= 1;
        retorno = SUCESSO;
        break;
      }
    }
  }
    return retorno;
}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 0 || posicao > 9)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  posicao -= 1;
  int retorno = SUCESSO;
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else if(vetorPrincipal[posicao].valor == NULL){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else{
    if(vetorPrincipal[posicao].use == 0){
      retorno =  ESTRUTURA_AUXILIAR_VAZIA;
      return retorno;
    }
    for(int i = 0; i < vetorPrincipal[posicao].use; i++){
      vetorAux[i] = vetorPrincipal[posicao].valor[i];
    }
  }
  
    return retorno;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{
  int retorno = 0;
  retorno = getDadosEstruturaAuxiliar(posicao, vetorAux);
  if(retorno == SUCESSO){
    mergeSort(vetorAux, posicao);
  }
    return retorno;
}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/

int  getDadosDeTodasEstruturasAuxiliares ( int vetorAux[])
{
  int retorno = 0, posicao = 1, contEstruturas = 0, tamnhoVetor = 0, h = 0, contSucesso = 0;
  int vetorTemp[50];
  for(posicao = 1; posicao < TAM; posicao++){
    memset(vetorTemp, '\0', sizeof(int)*50);
    retorno = getDadosEstruturaAuxiliar(posicao, vetorTemp);
    
    if(retorno == SUCESSO){
      contSucesso++;
      for(int i = 0; i < 50; i++, h++){
          vetorAux[h] = vetorTemp[i];
        if(vetorTemp[i] == '\0'){
          i++;
          h++;
          break;
        }
      }
      // printf("\n");
    }
    if(retorno == ESTRUTURA_AUXILIAR_VAZIA ){
      contEstruturas++;
      
    }
  }

  if(contSucesso != 0)
    retorno = SUCESSO;
  else
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
  // free(vetorTemp);
  return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{
int tam = sizeof(vetorAux);
  int retorno = 0, tamVet = 0;
  retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  if(retorno == SUCESSO){
    mergeSort(vetorAux, tam+1);
    for(int i = 0; i<tam; i++ )
    return retorno;
  }else{
    retorno = TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
    return retorno;
  }
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
  posicao -= 1;
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA){
    retorno = POSICAO_INVALIDA;
  }
  else if(vetorPrincipal[posicao].valor == NULL){
    retorno = SEM_ESTRUTURA_AUXILIAR;
  }
  else if((vetorPrincipal[posicao].tam+novoTamanho) < 1){
    retorno = NOVO_TAMANHO_INVALIDO;
  }
  else{
    int valor = vetorPrincipal[posicao].tam + novoTamanho;
    int* temp = realloc(vetorPrincipal[posicao].valor, valor * sizeof(int));
    if(temp == NULL){
      retorno = SEM_ESPACO_DE_MEMORIA;
    }
    else{
      retorno = SUCESSO;
       vetorPrincipal[posicao].valor = temp;
       vetorPrincipal[posicao].tam = valor;
      if(vetorPrincipal[posicao].use > 1 && vetorPrincipal[posicao].use > vetorPrincipal[posicao].tam){
        vetorPrincipal[posicao].use = vetorPrincipal[posicao].tam;
      } 
    }
  }
  
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{
  posicao -=1;
    int retorno = 0;
  if(ehPosicaoValida(posicao) == POSICAO_INVALIDA)
    retorno = POSICAO_INVALIDA;
  else if(vetorPrincipal[posicao].valor == NULL)
    retorno = SEM_ESTRUTURA_AUXILIAR;
  else if(vetorPrincipal[posicao].use == 0)
    retorno = ESTRUTURA_AUXILIAR_VAZIA;
  else
    retorno = vetorPrincipal[posicao].use ;
  
    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/

No* inserirNoInicio(No* lista, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = lista;
    return novo;
}


No* montarListaEncadeadaComCabecote() {
    int* vetorAux = (int*)malloc(sizeof(int) * 50);
    int retorno;
    retorno = getDadosDeTodasEstruturasAuxiliares(vetorAux);
  
    No* lista = (No*)malloc(sizeof(No));

    lista->prox = NULL;
    lista->index = 0;
    lista->valor = 0;

    if (retorno == TODAS_ESTRUTURAS_AUXILIARES_VAZIAS)
        return lista;
    else {
        for (int i = 0; i < TAM; i++){
            lista = inserirNoInicio(lista, vetorAux[i]);
        
        }
        return lista;
    }
  free(vetorAux);
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No* inicio, int vetorAux[]) {
    No* atual = inicio;
    int i = 0;
    int tam  = sizeof(vetorAux);
    while (tam>=0) {
        if(atual->valor != 0){
          vetorAux[tam] = atual->valor;
          atual = atual->prox;
          tam--;
        }else{
            atual = atual->prox;
        }
    }
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No** inicio) {
    No* atual = *inicio;

    while (atual != NULL) {
        No* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *inicio = NULL;
}


/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
  for(int i = 0; i < TAM; i++){
    vetorPrincipal[i].valor = NULL;
    vetorPrincipal[i].tam = 0;
    vetorPrincipal[i].use = 0;
  }

}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
  for(int i = 0; i < TAM; i++)
    free(vetorPrincipal[i].valor);
}
void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int size) {
    if (size <= 1) {
        return;
    }

    int mid = size / 2;
    int left[mid];
    int right[size - mid];

    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }

    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    mergeSort(left, mid);
    mergeSort(right, size - mid);
    merge(arr, left, mid, right, size - mid);
}