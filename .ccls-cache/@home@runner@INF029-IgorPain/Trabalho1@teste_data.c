#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "IgorOliveira-20222160010.h"

DiasMesesAnos distancia_datas(char* data1, char* data2) {
  DiasMesesAnos distancia;
  struct tm tm1, tm2;
  memset(&tm1, 0, sizeof(struct tm));
  memset(&tm2, 0, sizeof(struct tm));
  sscanf(data1, "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
  time_t start_time1 = mktime(&tm1);
  sscanf(data2, "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);
  time_t start_time2 = mktime(&tm2);
  /*
  printf("DATA 1\n");
  printf("dia %d\n", tm1.tm_mday);
  printf("mes %d\n", tm1.tm_mon);
  printf("ano %d\n", tm1.tm_year);

  printf("\nDATA 2\n");
  printf("dia %d\n", tm2.tm_mday);
  printf("mes %d\n", tm2.tm_mon);
  printf("ano %d\n", tm2.tm_year);
  */
  double segundos = difftime(start_time2, start_time1);
  // printf("segundos: %if\n", segundos);
  int dias = segundos / (24*3600);
  dias -= 1;
  printf("nuunero de dias: %d\n", dias);
  if(dias == 366){    
    distancia.qtdDias = 0;
    distancia.qtdMeses = 0;
    distancia.qtdAnos = 1;
    return distancia;
  }
      
  // printf("o numro de dias: %d\n", dias);

  int mes = dias/30;
  // printf("meses: %d\n", mes);
  dias %= 30;
  // printf("dias atualizados: %d\n", dias);
  int ano = mes/12;
  // printf("ano: %d\n", ano);
  mes %= 12;
  // printf("mes atualizado: %d\n", mes);

  // printf("ano: %d\nmes: %d\ndias: %d\n", ano, mes, dias);
  distancia.qtdDias = dias;
  distancia.qtdMeses = mes;
  distancia.qtdAnos = ano;
  return distancia;
}


DiasMesesAnos q2(char datainicial[], char datafinal[]) {

  // calcule os dados e armazene nas três variáveis a seguir
  DiasMesesAnos dma;

  if (q1(datainicial) == 0) {
    printf("*******1******\n");
    dma.retorno = 2;
    return dma;
  } else if (q1(datafinal) == 0) {
    printf("********2*****\n");
    dma.retorno = 3;
    return dma;
  } else if(strcmp(datainicial, datafinal) > 0){
    printf("*******3******\n");
    dma.retorno = 4;
    return dma;
  }else{
    printf("*************\n");
    dma = distancia_datas(datainicial, datafinal);
    dma.retorno = 1;
    printf("qtdAno: %d\nqtdMeses: %d\nqtdDias: %d\n", dma.qtdAnos, dma.qtdMeses, dma.qtdDias);
    return dma;
  }
}


int main(){
  // compara_datas("19/02/1967", "19/02/1968");
  q2("06/06/2017", "07/07/2017");
}

/*
struct tm tm1, tm2;
  memset(&tm1, 0, sizeof(struct tm));
  memset(&tm2, 0, sizeof(struct tm));
  sscanf(datainicial, "%d/%d/%d", &tm1.tm_mday, &tm1.tm_mon, &tm1.tm_year);
  time_t start_time1 = mktime(&tm1);
  sscanf(datafinal, "%d/%d/%d", &tm2.tm_mday, &tm2.tm_mon, &tm2.tm_year);
  time_t start_time2 = mktime(&tm2);

  double segundos = difftime(start_time2, start_time1);

  int dias = segundos / (24*3600);
  int mes = dias/30;
  dias %= 30;
  int ano = mes/12;
  mes %= 12;
  dma.qtdDias = dias;
  dma.qtdMeses = mes;
  dma.qtdAnos = ano;
  // return distancia;
    printf("qtAnos: %d\nqtmeses: %d\nqtDias: %d ", dma.qtdAnos, dma.qtdMeses, dma.qtdDias);
*/