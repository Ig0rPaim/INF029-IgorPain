int buscaBinaria(int matriz[][2], int valor, int inicio, int fim) {
    if (fim >= inicio) {
        int meio = inicio + (fim - inicio) / 2;

        // Se o valor estiver no meio da matriz, retornamos a posição
        if (matriz[meio][0] == valor)
            return meio;

        // Se o valor for menor do que o elemento do meio, procuramos na metade esquerda
        if (matriz[meio][0] > valor)
            return buscaBinaria(matriz, valor, inicio, meio - 1);

        // Caso contrário, procuramos na metade direita
        return buscaBinaria(matriz, valor, meio + 1, fim);
    }

    // Se não encontrarmos o valor na matriz, retornamos -1
    return -1;
}

void excluirElemento(No* elemento){
  
}

void tiraElemento(No* inicio, int vetorAux[]){
  int tam = sizeof(vetorAux);
  int retorno = 0, sinal = 0, matriz[tam][2];

  retorno = getDadosOrdenadosDeTodasEstruturasAuxiliares(vetorAux);
  if(retorno == SUCESSO){
    for(int i = 0, h = 0; i < tam; i++, h++){
      if(vetorAux[i] == vetorAux[i+1]){
        h++;
        matriz[i-1][0] = vetorAux[i];
        matriz[i-1][1] = h; 
      }else{
        h = 1;
        matriz[i][0] = vetorAux[i];
        matriz[i-1][1] = h;
      }
    }
    No* atual = inicio->prox;
    int posicao;
    while(atual->prox != NULL){
      posicao = buscabinaria(matriz[2], atual->valor, 0, tam);
      if(matriz[posicao][1] > 1){
          matriz[posicao][1]--;
          //função de destruir nó 
      }
      atual = atual->prox;
    }
    
  }
}