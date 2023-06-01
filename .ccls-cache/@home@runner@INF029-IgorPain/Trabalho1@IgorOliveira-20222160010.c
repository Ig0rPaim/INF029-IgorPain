// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do
//  trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016

// #################################################

#include "IgorOliveira-20222160010.h" // Substitua pelo seu arquivo de header renomeado
#include <stdio.h>
#include <stdlib.h>
// #include<time.h>
#include<string.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y) {
  int soma;
  soma = x + y;
  return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x) { // função utilizada para testes
  int i, fat = 1;

  for (i = x; i > 1; i--)
    fat = fat * i;

  return fat;
}


int teste(int a) {
  int val;
  if (a == 2)
    val = 3;
  else
    val = 4;

  return val;
}


DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}


int bissexto(int Ano){
  int digitos, ano;
  ano = Ano;
      while (Ano != 0) {
        digitos++;
        Ano /= 10;
    }

  if(digitos == 2){
    ano += 2000;
  }
  int resul;
  resul = ano%4;
  if(resul == 0){
    resul = ano%400;
    if(resul == 0){
      return 1;
    }
    resul = ano%100;
    if(resul != 0)
      return 1;
  }
  return 0;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia,
mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa
podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char Data[]) {
  int datavalida = 1;
  DataQuebrada data_inteiro;
  int retorno;
  data_inteiro = quebraData(Data);
  if(data_inteiro.valido == 0){
    return 0;
  }
   // verifica se os dias no geral são validos
  if(data_inteiro.iDia > 31 || data_inteiro.iDia < 1){
    return 0;
  }//verifica se os meses são validos
  if(data_inteiro.iMes > 12 || data_inteiro.iMes < 1){
    return 0;
  }//verifica casos especiais 
  switch(data_inteiro.iMes){
    case 0:
      return 0;
      break;
    case 2:
      if(data_inteiro.iDia == 29){
        retorno = bissexto(data_inteiro.iAno);
        if(retorno == 0)
          return retorno;
      }
      break;
    case 4:
      if(data_inteiro.iDia > 30)
        return 0;
      break;
    case 6:
      if(data_inteiro.iDia > 30)
        return 0;
      break;
    case 9:
      if(data_inteiro.iDia > 30)
        return 0;
      break;
    case 11:
      if(data_inteiro.iDia > 30)
        return 0;
      break;
  }
  if (datavalida)
    return 1;
  else
    return 0;
}


int diferenca_ano_f(DataQuebrada data_inicial, DataQuebrada data_final){
  if(data_final.iAno >= data_inicial.iAno){
    int difenca_ano = data_final.iAno - data_inicial.iAno;
    return difenca_ano;
  }else
    return 4;
}


int diferenca_mes_f(DataQuebrada data_inicial, DataQuebrada data_final){
  if(data_final.iMes >= data_inicial.iMes){
    int diferenca_mes = data_final.iMes - data_inicial.iMes;
    return diferenca_mes;
  }else{
    int diferenca_mes = (12 - (data_inicial.iMes - data_final.iMes)) ;
    return diferenca_mes;
  } 
}


int diferenca_dia_f(DataQuebrada data_inicial, DataQuebrada data_final){
  if(data_final.iDia >= data_inicial.iDia){
    int diferenca_dia = data_final.iDia - data_inicial.iDia;
    return diferenca_dia;
  }else{
    int diferenca_dia = (data_inicial.iDia - data_final.iDia);
    return diferenca_dia; // subtrair da quantidade de dias do mes
  }
}
/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal.
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis
 valores abaixo 1 -> cálculo de diferença realizado com sucesso 2 -> datainicial
 inválida 3 -> datafinal inválida 4 -> datainicial > datafinal Caso o cálculo
 esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos
 com os valores correspondentes.
*/



DiasMesesAnos q2(char datainicial[], char datafinal[]){
    
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
      }else{       //   0   1    2   3   4   5   6   7  8    9  10  11   12 
        int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        DataQuebrada data_inicial, data_final, diferenca;
        data_inicial = quebraData (datainicial);
        data_final = quebraData (datafinal);
        // testando se a data inicial é maior que a final
        if(data_inicial.iAno > data_final.iAno){
        dma.retorno = 4;
        return dma;
        }
        if(data_inicial.iAno == data_final.iAno){
          if(data_inicial.iMes > data_final.iMes){
            dma.retorno = 4;
            return dma;
          }else if(data_inicial.iMes == data_final.iMes){
            if(data_inicial.iDia > data_final.iDia){
              dma.retorno = 4;
              return dma;
            }
          }
        }      
        int diferenca_ano, diferenca_mes, diferenca_dia;
        diferenca_ano = diferenca_ano_f(data_inicial, data_final);
        diferenca_mes = diferenca_mes_f(data_inicial, data_final);
        diferenca_dia = diferenca_dia_f(data_inicial, data_final);
        int anos_bissextos = 0, aux;
        aux = data_inicial.iAno;
        for(int i = 0; i <= (data_final.iAno - data_inicial.iAno) + 1; i++){
          anos_bissextos += bissexto(data_inicial.iAno);
          data_inicial.iAno++; 
        }
        data_inicial.iAno = aux;
        if(data_inicial.iMes > data_final.iMes)
          diferenca_ano -= 1;
        if(data_inicial.iDia > data_final.iDia)
          diferenca_mes -= 1;
        if(data_inicial.iDia > data_final.iDia){
          if(bissexto(data_inicial.iAno)){
            diferenca_dia = meses[data_inicial.iMes] - diferenca_dia;
          }else{
            diferenca_dia = meses[data_inicial.iMes] - diferenca_dia + anos_bissextos;
          }
        }  
        dma.qtdDias = diferenca_dia;
        dma.qtdMeses = diferenca_mes;
        dma.qtdAnos = diferenca_ano;
        dma.retorno = 1;
        return dma;
    }
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
int q3(char *texto, char c, int isCaseSensitive) {
  int qtdOcorrencias = verificaCaractere(texto, c, isCaseSensitive);
  return qtdOcorrencias;
}


int verificapalavra(char *strtexto, char *strbusca, int tam_busca, int tam_posicao, int posicoes[30], int cont_busca, int cont_texto, int ocorrencias, int cont_letra) {
  
  if (*strtexto == '\0') { // condição de parada
    return ocorrencias;
  }
  if (*strtexto == *strbusca) {
    cont_letra++;
    if (tam_posicao % 2 == 0 || cont_busca == tam_busca -1) { 
      posicoes[tam_posicao] = cont_texto + 1;
      tam_posicao++;
    }
    if (tam_posicao % 2 == 0 && tam_posicao != 0) { // verifica se a palavra foi encontrada atualiza ocorrencias e chama a função com os devidos argumentos
      ocorrencias = tam_posicao / 2;
      cont_letra = 0;
      return verificapalavra(strtexto + 1, strbusca - (tam_busca - 1), tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra);
    }
    return verificapalavra(strtexto + 1, strbusca + 1, tam_busca, tam_posicao, posicoes, cont_busca + 1, cont_texto + 1, ocorrencias, cont_letra);
  } else {
    if(tam_posicao % 2 != 0){ // caso encontre letras iguais, mas que não forma a palavra desejada
      tam_posicao -= 1;
      return verificapalavra(strtexto + 1, strbusca - cont_letra, tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra);
    }
    return verificapalavra(strtexto + 1, strbusca - cont_letra, tam_busca, tam_posicao, posicoes, cont_busca = 0, cont_texto + 1, ocorrencias, cont_letra = 0);
  }
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros
 (posicoes) que irá guardar as posições de início e fim de cada ocorrência da
 palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída
 correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do
 vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve
 ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a
 segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente.
 Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como
 há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da
 seguinte forma: posicoes[0] = 13; posicoes[1] = 16; Observe que o índice da
 posição no texto deve começar ser contado a partir de 1. O retorno da função,
 n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30]) {
  int qtdOcorrencias = -1, tam_busca = 0, tam_posicao = 0, cont_busca = 0, cont_texto = 0, ocorrencias = 0, cont_letra = 0;
  for(int i = 0; strBusca[i] != '\0'; i++){
    tam_busca++;
  }
  qtdOcorrencias = verificapalavra(strTexto, strBusca, tam_busca, tam_posicao, posicoes, cont_busca, cont_texto, ocorrencias, cont_letra);
  return qtdOcorrencias;
}


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
  // printf("incio : %d\n tam: %d\n", inicio, tam);
  // printf("str inicio : %c\n str tam: %c\n", str[inicio], str[tam]);
  if(tam == inicio || tam < inicio){
    return str;
  }else{
    aux = str[inicio];
    // printf("aux: %c\n", aux);
    str[inicio] = str[tam];
    str[tam] = aux;
    // printf("DEPOIS DA TROCA\n");
    // printf("str inicio : %c\n str tam: %c\n", str[inicio], str[tam]);
    return inverteNumeros(str, tam - 1, inicio + 1);
  } 
}
/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

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


int verifica_numero(int qtdOcorrencias, char *str, char *str2, int tam2, int cont_busca){
  if(*str == '\0'){
    return qtdOcorrencias;
  }
  if(*str == *str2){
    if(cont_busca == tam2 - 1){
      return verifica_numero(qtdOcorrencias + 1, str + 1, str2 - (tam2 -1), tam2, cont_busca = 0);
    }else{
      return verifica_numero(qtdOcorrencias, str + 1,  str2 + 1, tam2, cont_busca + 1);
    }
  }else{
    if(cont_busca != 0){
      return verifica_numero(qtdOcorrencias, str + 1, str2 - (tam2 -1), tam2, cont_busca = 0);
    }
    return verifica_numero(qtdOcorrencias, str + 1,  str2, tam2, cont_busca);
  }
  
}
/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca) {    
  int qtdOcorrencias, cont_busca = 0;
  int tam = contar_digitos(numerobase);
  char str[tam + 1];
  sprintf(str, "%d", numerobase);
  str[tam] = '\0';

  int tam2 = contar_digitos(numerobusca);
  char str2[tam2 + 1];
  sprintf(str2, "%d", numerobusca);
  str2[tam2] = '\0';

  qtdOcorrencias = verifica_numero(qtdOcorrencias, str, str2, tam2, cont_busca);
    
  return qtdOcorrencias;
}