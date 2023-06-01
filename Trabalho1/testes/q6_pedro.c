#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>


int qtdNumeros(int numerobase, int numerobusca){
int qtdOcorrencias    =    0;
int contBase    =    0, contBusca = 0;
int rbase , rbusca; // é resto 
int qbase    =    numerobase/10, qbusca    =    numerobusca/10; // é o quociente da divisão 
int qtdDigitosBusca    =    1;
int qtdDigitosBase    =    1;
int aux;
//1234
//13
    if ( numerobase < numerobusca)
        return 0;
    else if ( numerobase == numerobusca)
        return 1;
    else if ( numerobase > numerobusca){
        rbase    =    numerobase    %    10;
        rbusca = numerobusca %    10;

        aux = numerobase;
        while( aux > 10){
            aux = aux    / 10;
            qtdDigitosBase++;
        }
        
        aux = numerobusca;
        while( aux > 10){
            aux =  aux /    10;
            qtdDigitosBusca++;
        }
        //34 = 2 digitos 
            
        for (int    i=    numerobase ;    i    <    qtdDigitosBase    ;    i/10){

            if( rbase == rbusca    ){
                contBusca++;
                if(    qbusca    <    10)
                    rbusca = qbusca;
            }else if(rbase != rbusca) {
                contBusca    =    0;
                rbase = qbase %    10;
            }
            if (    contBusca == qtdDigitosBusca    ){
                qtdOcorrencias++;
                contBusca    =    0;
                qbusca = numerobusca;
            }
            if(qbase > 10)
            qbase    =    qbase    /    10;
            else
            
            if(qbusca > 10)
            qbusca    =    qbusca    /    10;
        }
        
        return qtdOcorrencias;
    }
}

int main(){
  qtdNumeros(1234, 34);
}