#include <stdio.h>
#include <stdlib.h>

int main(){
  int digitos, Ano = 24, ano;
  ano = Ano;
      while (Ano != 0) {
        digitos++;
        Ano /= 10;
    }

  printf("digitos: %d\n", digitos);

  
  if(digitos == 2){
    ano += 2000;
    printf("********\n");
  }
  printf("ano: %d\n", ano);
  int resul;
  resul = ano%4;
  printf("resul: %d\n", resul);
  if(resul != 0){
    return 0;
  }
  
  return 1;
}