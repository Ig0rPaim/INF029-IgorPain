#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<string.h>
// #include "IgorOliveira-20222160010.h"
  typedef struct DQ
  {
      int iDia; 
      int iMes;
      int iAno;
      int valido; // 0 se inválido, e 1 sevalido 
  
  } DataQuebrada;

typedef struct Qtd
{
    int qtdDias;
    int qtdMeses;
    int qtdAnos;
    int retorno;

} DiasMesesAnos;

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

int distancia_datas(char datainicial[], char datafinal[]){
 /*DataQuebrada data_inicial, data_final, diferenca;
  data_inicial = quebraData (datainicial);
  data_final = quebraData (datafinal);

  diferenca.iAno = data_final.iAno - data_inicial.iAno;
  if(data_final.iMes < data_inicial.iMes){
    diferenca.iAno - 1;
    if(data_final.iMes != data_inicial.iMes)
      difereca.iMes = data_inicial.iMes - data_final.iMes;
    else{
      if(data_final.iDia == data_inicial.iDia)
        diferenca.iDia = 0
      if(data_final.iDia > data_inicial.iDia)
        difereca.iDia = data_final.iDia - data_inicial.iDia;
      else
        difereca.iDia = data_inicial.iDia - data_final.iDia
    }
  }

  */
  
}
/*
DataQuebrada data_inicial, data_final, diferenca;
  data_inicial = quebraData (datainicial);
  data_final = quebraData (datafinal);*/

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


DiasMesesAnos q2(char datainicial[], char datafinal[])
{
    
    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if ((datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if ((datafinal) == 0){
      dma.retorno = 3;
      return dma;
     }else{ //        0   1    2   3   4   5   6   7  8    9  10  11   12
      
      int meses[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
      DataQuebrada data_inicial, data_final, diferenca;
      data_inicial = quebraData (datainicial);
      data_final = quebraData (datafinal);
      // int diferenca_ano, diferenca_mes, diferenca_dia;
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
      
      int diferenca_ano = diferenca_ano_f(data_inicial, data_final);
      int diferenca_mes = diferenca_mes_f(data_inicial, data_final);
      int diferenca_dia = diferenca_dia_f(data_inicial, data_final);

      int anos_bissextos = 0, aux;
      aux = data_inicial.iAno;
      for(int i = 0; i <= (data_final.iAno - data_inicial.iAno) + 1; i++){
        // printf("D.I.A******** %d\n", data_inicial.iAno);
        anos_bissextos += bissexto(data_inicial.iAno);
        data_inicial.iAno++; 
      }
      data_inicial.iAno = aux;
      // printf("anos bissextos %d\n", anos_bissextos);
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
  
      
      dma.qtdDias = diferenca_ano;
      dma.qtdMeses = diferenca_mes;
      dma.qtdAnos = diferenca_ano;
      printf("diferenca:\nANO: %d\nMES: %d\nDIA: %d\n", diferenca_ano, diferenca_mes, diferenca_dia);
      // calculando numero de dias
      diferenca_ano *= 365;
      int dias = 0;
      if(diferenca_ano == 0)
        diferenca_mes -= 1;
      for(int i = 0; i <= diferenca_mes; i++){
        // printf("_mes %d: %d\n", data_inicial.iMes, meses[data_inicial.iMes]);
        dias += meses[data_inicial.iMes];
        // printf("DIAS %d\n", dias);
        data_inicial.iMes++;
        
        if(data_inicial.iMes > 12)
          data_inicial.iMes = 1;
      }
      // printf("D***** %d\n", dias);
      // calculando anos bissextos
      /*int anos_bissextos = 0;
      for(int i = 0; i <= (data_final.iAno - data_inicial.iAno); i++){
        // printf("D.I.A******** %d\n", data_inicial.iAno);
        anos_bissextos += bissexto(data_inicial.iAno);
        data_inicial.iAno++;
        
      }*/
      // printf("AB******** %d\n", anos_bissextos);
      
      dias += (diferenca_ano - diferenca_dia)+ anos_bissextos;
      // printf("DIAS NOS MESMES %d\n", dias);
      dma.retorno = 1;
      return dma;
      
    }
}  


int main(){
 char datainicial[11], datafinal[11];
    strcpy(datainicial,"01/06/2016");
    strcpy(datafinal,"01/06/2015");
  DiasMesesAnos retorno;
  retorno = q2(datainicial, datafinal);
  printf("retorno %d", retorno.retorno);

  
}


// resolucao com a biblioteca time.h
/*
DiasMesesAnos distancia_datas(char* data1, char* data2) {
  DiasMesesAnos distancia;
  struct tm tm1, tm2;
  memset(&tm1, 0, sizeof(struct tm));
  memset(&tm2, 0, sizeof(struct tm));
  sscanf(data1, "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
  time_t start_time1 = mktime(&tm1);
  sscanf(data2, "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);
  time_t start_time2 = mktime(&tm2);

  double segundos = difftime(start_time2, start_time1);
  int dias = segundos / (24*3600);
  if(dias == 366){    
    distancia.qtdDias = 0;
    distancia.qtdMeses = 0;
    distancia.qtdAnos = 1;
    return distancia;
  }
  dias -= 1;
  int mes = dias/30;
  dias %= 30;
  // if(data2)
  int ano = mes/12;
  mes %= 12;

  distancia.qtdDias = dias;
  distancia.qtdMeses = mes;
  distancia.qtdAnos = ano;
  return distancia;
}
*/