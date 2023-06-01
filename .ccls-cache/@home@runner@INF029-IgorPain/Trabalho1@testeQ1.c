#include <stdio.h>
#include <stdlib.h>
#include "IgorOliveira-20222160010.h"
/*
DataQuebrada quebraData(char data[]) {
  DataQuebrada dq;
  char sDia[3];
  char sMes[3];
  char sAno[5];
  int i;

  for (i = 0; data[i] != '/'; i++) {
    sDia[i] = data[i];
  }
  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sDia[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  int j = i + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '/'; j++) {
    sMes[i] = data[j];
    i++;
  }

  if (i == 1 || i == 2) { // testa se tem 1 ou dois digitos
    sMes[i] = '\0';       // coloca o barra zero no final
  } else {
    dq.valido = 0;
    return dq;
  }

  j = j + 1; // anda 1 cada para pular a barra
  i = 0;

  for (; data[j] != '\0'; j++) {
    sAno[i] = data[j];
    i++;
  }

  if (i == 2 || i == 4) { // testa se tem 2 ou 4 digitos
    sAno[i] = '\0';       // coloca o barra zero no final
  } else {
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

  if(resul != 0){
    return 0;
  else
    return 1;
}

int main(){
  DataQuebrada data_inteiro;
  char data[13];
  int retorno;
  printf("digite uma data: ");
  scanf("%s", &data);
  
  data_inteiro = quebraData(data);
  
  printf("%d\n", data_inteiro.iDia);
  printf("%d\n", data_inteiro.iMes);
  printf("%d\n", data_inteiro.iAno);
  printf("%d\n", data_inteiro.valido);

  if(data_inteiro.valido == 0){
    printf("data invalida");
    return 0;
  }

  // verificar se os meses e os dias batem
  if(data_inteiro.iDia > 31 || data_inteiro.iDia < 1){
    printf("data invalida, maior que 31");
    return 0;
  }
  if(data_inteiro.iMes > 12){
    printf("data invalida, maior que 12");
    return 0;
  }
  
  switch(data_inteiro.iMes){
    case 0:
      return 0;
      break;
    case 2:
      if(data_inteiro.iDia == 29){
        retorno = bissexto(data_inteiro.iAno);
        printf("retorno: %d\n", retorno);
        if(retorno == 0)
          printf("data invalida, ano n bissexto");
        return retorno;
      }
      break;
    case 4:
      if(data_inteiro.iDia > 30)
        printf("data invalida, maior que 30");
        return 0;
      break;
    case 6:
      if(data_inteiro.iDia > 30)
        printf("data invalida, maior que 30");
        return 0;
      break;
    case 9:
      if(data_inteiro.iDia > 30)
        printf("data invalida, maior que 30");
        return 0;
      break;
    case 11:
      if(data_inteiro.iDia > 30)
        printf("data invalida, maior que 30");
        return 0;
      break;
  }
  
}*/

int main(){
  
}