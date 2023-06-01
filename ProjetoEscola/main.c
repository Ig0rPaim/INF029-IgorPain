#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int escolha_PA(const char* nome_arquivo ,const char* str_fopen);
int opcao_invalida(void);
int excluir_cadas(const char* nome_arquivo, const char* modo_abertura, const char* modo_abertura_2);
int validacao_data(char data_0, char data_1, int ASCII_1, int ASCII_2, int ASCII_3, int ASCII_4, int ASCII_5, int ASCII_6, char verificacao);
int validacao_ano(char data_0, char data_1, char data_2, char data_3);
int leitura_arquivo(const char* nome_arquivo ,const char* str_fopen);
int ordenar_por_genero(const char* nome_arquivo, const char* str_open);
int listar_data_nas_PA(const char* nome_arquivo, const char* modo);// (adaptar para PA)
int niver_mes(const char* nome_arquivo, const char* modo, const char* PA); //(chama 2 vezes, PA)
int busca_letra(const char* nome_arquivo, const char* modo, const char*PA, char letras[]);// (chama 2 vezes, PA)

int escolha_D(const char* nome_arquivo ,const char* str_fopen);
int modificar_disciplina();
int opcao_invalida(void);
int excluir_disciplina();
int incluir_em_disciplinas();
int excluir_de_disciplina();
int listagem_disciplinas();
int menos_3disciplinas();
int vagas_disciplinas();


	int funcao_menu(void){
	
	int num, continuar = 1, resposta, escolha;
	
	do{
    printf("___________________________________________\n");
  	printf("-------------------------------------------\n");
  	printf("||           MENU PRINCIPAL              ||");
  	printf("\n___________________________________________\n");
  	printf("-------------------------------------------\n");
  	
		printf("\ndigite 1 se deseja incluir/excluir/atualizar alunos\n\n"); 
		printf("digite 2 se deseja incluir/excluir/atualizar professores\n\n"); 
		printf("digite 3 se deseja incluir/excluir/modificar disciplinas\n\n"); 
		printf("digite 4 se deseja cadastrar ou excluir alunos em uma disciplina\n\n"); 
		printf("digite 5 se deseja listar os alunos ou professores por ordem de cadastro ou idade\n\n"); 
		printf("digite 6 se deseja listar as diciplinas\n\n");
		printf("digite 7 se deseja listar os alunos ou professores por gÃªnero\n\n");
	    printf("digite 8 se deseja obter o aniversariante do mes\n\n");
	    printf("digite 9 se deseja obter pessoas que contenham 3 letras que vocÃª digitarÃ¡\n\n");
	    printf("digite 10 se deseja obter o numero de vagas das disciplinas \n\n");
	    printf("digite 11 se deseja obter alunos cadastrados em menos de 3 diciplinas\n\n");
	    printf("digite 12 se deseja sair\n\n");
	    
		scanf("%d", &resposta);
		switch(resposta){
			case 1:
				 printf("digite 1 se essa Ã© a primeira vez que vocÃª vai cadastrar, caso queira atualizar incluindo alunos "
		         "digite 2, caso deseje excluir digite 3:\n ");
		        scanf("%d", &escolha);
		        
		        if(escolha == 1){
		          escolha_PA("cadastro_alunos.txt", "w");
		        }else if(escolha == 2){
		          escolha_PA("cadastro_alunos.txt", "a");
		        }else if(escolha == 3){
		          excluir_cadas("cadastro_alunos.txt", "r", "w");
		        }else{
		          opcao_invalida();
		        }
					break;
			case 2:
				printf("digite 1 se essa Ã© a primeira vez que vocÃª vai cadastrar, caso queira atualizar incluindo alunos "
		         "digite 2, caso deseje excluir digite 3:\n ");
		        scanf("%d", &escolha);
		        
		        if(escolha == 1){
		          escolha_PA("cadastro_professores.txt", "w");
		        }else if(escolha == 2){
		          escolha_PA("cadastro_professores.txt", "a");
		        }else if(escolha == 3){
		          excluir_cadas("cadastro_professores.txt", "r", "w");
		        }else{
		          opcao_invalida();
		        }
					break;
			case 3:
				printf("digite 1 se essa Ã© a primeira vez que vocÃª vai cadastrar disciplinas, caso queira inserir novas disciplinas digite 2, caso queira modificar alguma digite 3, caso queira excluir digite 4:\n ");
		        scanf("%d", &escolha);
		        
		        if(escolha == 1){
		        	escolha_D("cadastro_disciplinas.txt", "w");
		        }else if(escolha == 2){
		      		escolha_D("cadastro_disciplinas.txt", "a");
		    	  }else if(escolha == 3){
		          modificar_disciplina();
		        }else if(escolha == 4){
		          excluir_disciplina();
		        }else{
		      		opcao_invalida();
		    	  }
					break;
			case 4:
				printf("digite 1 se deseja incluir alunos em disciplinas ou 2 se deseja excluir\n");
		      	scanf("%d", & escolha);
		      
		      	if(escolha == 1) {
		      		incluir_em_disciplinas();
		      	} else if(escolha == 2) {
		      		excluir_de_disciplina();
		      	} else {
		          printf("opÃ§Ã£o invalida");
		      		return 1;
		      	}
					break;
			case 5:
				printf("digite 1 se deseja listar alunos ou 2 se deseja listar professores\n");
		        scanf("%d", escolha);
		        if(escolha == 1){
		          listar_data_nas_PA("cadastro_alunos.txt", "r");
		        }else if(escolha == 2){
		          listar_data_nas_PA("cadastro_professores.txt", "r");
		        }
					break;
			case 6:
				listagem_disciplinas();
				break;
			case 7:
				printf("digite 1 se deseja listar alunos ou 2 se deseja listar professores\n");
		        scanf("%d", escolha);
		        if(escolha == 1){
		          ordenar_por_genero("cadastro_alunos.txt", "r");
		        }else if(escolha == 2){
		          ordenar_por_genero("cadastro_professores.txt", "r");
		        }
					break;
			case 8:
				niver_mes("cadastro_alunos.txt", "r", "alunos");
	      		niver_mes("cadastro_professores.txt", "r", "professores");
				break;
			case 9:
				char letras[3];
		      	printf("digite 3 letras se o nome de algum aluno ou professor tiver essas 3 letra no nome será impresso na tela: \n");
		      	fgets(letras, 4, stdin);
		      	
		      	busca_letra("cadastro_alunos.txt", "r", "aluno(s)", letras);	
		      	busca_letra("cadastro_professores.txt", "r", "professor(s)", letras);	
				break;
			case 10:
				vagas_disciplinas();
				break;
      		case 11:
       			 menos_3disciplinas();
			case 12:
				printf("obrigado por usar nosso sitema, atÃ© mais");
				continuar = 0;
			default:
				printf("resposta invalida, insira um numero valido: ");
				funcao_menu();
			}
		}while(continuar);{
			funcao_menu();
		}
		return 0;
	}

main(){
	funcao_menu();
  return 0;
}


int escolha_PA(const char* nome_arquivo ,const char* str_fopen){
		struct data_nas{
		    char dia[10];
		    char mes[10];
		    char ano[10];
		};
		struct cadastro{
		    char nome[100];
		    char matricula[20];
		    char sexo[10]; 
		    struct data_nas data_nas; 
		};
		
		int cont, n, ln, retorno;
		FILE *arquivo;
        printf("quantos deseja cadastrar? \n");
        scanf("%d", &n);
        struct cadastro cadas[n];
            
        arquivo = fopen(nome_arquivo, str_fopen);

        if (arquivo == NULL) {
          printf("Erro ao abrir arquivo de texto.\n");
          return 1;
        }
        
        for(cont = 0; cont < n; cont++){
	        getchar();
	        printf("digite o nome %d:\n", cont+1);
	        fgets(cadas[cont].nome, 100, stdin);
	        cadas[cont].nome[strcspn(cadas[cont].nome, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].nome);
			 
			 
	        printf("digite o CPF para matricula %d. OBS: sem '.' nem '-', exemplo 07465356480:\n", cont+1);
	        fgets(cadas[cont].matricula, 20, stdin);
	        ln = strlen(cadas[cont].matricula) -1;
	        if(ln != 11){
	        	printf("entrada invalida, te reeinviaremos ao menu principal");
	        	funcao_menu();
	        	return 0;
			    }
          for(int i = 0; i < 11; i++){
            if("%d", cadas[cont].matricula[i] < 48 || "%d", cadas[cont].matricula[i] > 57){
                printf("entrada invalida te reinviaremos ao menu principal");
                    funcao_menu();
                    return 1;
            }
          }
			    cadas[cont].matricula[strcspn(cadas[cont].matricula, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].matricula); 
    
	        printf("digite o sexo %d, 'M' para masculino e 'F' para feminino:\n", cont+1);
	        fgets(cadas[cont].sexo, 10, stdin);
	        ln = strlen(cadas[cont].sexo) -1;
	        if(ln != 1){
	        	printf("entrada invalida, te reeinviaremos ao menu principal");
	        	funcao_menu();
	        	return 0;
    			}
    			if(("%d", cadas[cont].sexo[0] != 77) && ("%d", cadas[cont].sexo[0] != 70)){
    				printf("entrada invalida, te reeinviaremos ao menu principal");
    	        	funcao_menu();
    	        	return 0;
    			}
	        cadas[cont].sexo[strcspn(cadas[cont].sexo, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].sexo);  
            
	        printf("agora vamos a idade do %d:\n", cont+1);
	            
	        printf("digite o dia com dois digitos, ex: '03' ou '17'\n");
	        fgets(cadas[cont].data_nas.dia, 10, stdin); 
	        ln = strlen(cadas[cont].data_nas.dia) -1;
	        if(ln != 2){
	        	printf("entrada invalida, te reeinviaremos ao menu principal");
	        	funcao_menu();
	        	return 0;
			    }
			retorno = validacao_data(cadas[cont].data_nas.dia[0], cadas[cont].data_nas.dia[1], 48, 51, 48, 49, 48, 57, '3');
			if(retorno == 1){
				return 0;
			}
	        cadas[cont].data_nas.dia[strcspn(cadas[cont].data_nas.dia, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].data_nas.dia);  
             
	        printf("digite o mes com dois digitos, ex: '03' ou '10'\n");
	        fgets(cadas[cont].data_nas.mes, 10, stdin);
	        ln = strlen(cadas[cont].data_nas.mes) -1;
	        if(ln != 2){
	        	printf("entrada invalida, te reeinviaremos ao menu principal");
	        	funcao_menu();
	        	return 0;
			    }
			retorno = validacao_data(cadas[cont].data_nas.mes[0], cadas[cont].data_nas.mes[1], 48, 49, 48, 50, 48, 57, '1');
			if(retorno == 1){
				return 0;
			}
	        cadas[cont].data_nas.mes[strcspn(cadas[cont].data_nas.mes, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].data_nas.mes);
        	
	        printf("digite o mes com dois digitos, ex: '2003' ou '2010'\n");
	        fgets(cadas[cont].data_nas.ano, 10, stdin);
	        ln = strlen(cadas[cont].data_nas.ano) -1;
	        if(ln != 4){
	        	printf("entrada invalida, te reeinviaremos ao menu principal");
	        	funcao_menu();
	        	return 0;
			    }
			retorno = validacao_ano(cadas[cont].data_nas.ano[0], cadas[cont].data_nas.ano[1], cadas[cont].data_nas.ano[2], cadas[cont].data_nas.ano[3]);
			if(retorno == 1){
				return 0;
			}
	        cadas[cont].data_nas.ano[strcspn(cadas[cont].data_nas.ano, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].data_nas.ano);
        	
        	fprintf(arquivo, "\n\n");
			}
        fclose(arquivo);
        return 0;
		}


 int opcao_invalida(void){
        int escolha;
      	printf("opção invalida digite 1 se é o primeiro cadastro 2 se deseje continuar cadastrando ou 3 se deseje sair:\n");
  		scanf("%d", &escolha);
  		switch(escolha){
  			case 1:
  				escolha_PA("cadastro_alunos.txt", "w");
  				return 0;
  			case 2:
  				escolha_PA("cadastro_alunos.txt", "a");
  				return 0;
  			case 3:
  				return 0;
  			default:
  				printf("Resposta inválida o programa será encerrado\n");
  				system("PAUSE");
  				return 0;
		  }
    }


int excluir_cadas(const char* nome_arquivo, const char* modo_abertura, const char* modo_abertura_2){
	#define LINHAS 100
	#define COLUNAS 100
	char cpf[12], nome, matriz_dados[LINHAS][COLUNAS], matriz_cpf[LINHAS][COLUNAS];
	int linha = 0, coluna = 0;
	FILE *arquivo;
	arquivo = fopen(nome_arquivo, modo_abertura);
	
	if (arquivo == NULL){
	    perror("Erro ao abrir arquivo");
	    return 1;
	}
	
	
	printf("Digite o  cpf do aluno que dejesa excluir ");
	scanf("%s", &cpf);
	
//	trazendo os dados para uma matriz
	while ((nome = fgetc(arquivo)) != EOF) {
	    if (nome == '\n') {
	        continue;
	    }
	    if (nome != ';') {
	        matriz_dados[linha][coluna] = nome;
	        coluna++;
	    } else {
	        matriz_dados[linha][coluna] = '\0'; 
	        coluna = 0;
	        linha++;
	    }
	}
	
	int num_linhas = linha;
//  trazando os dados do CPF informado para verificação
	int cont = 0, teste = 1;
	linha = 0; coluna = 0;
	while(linha < num_linhas){
		teste = strcmp(cpf, matriz_dados[linha]);
		if(teste == 0){
			int linha_passagem = linha -1;
			for(int i = 0; i < 6; i++){
				strcpy(matriz_cpf[i], matriz_dados[linha_passagem]);
				linha_passagem++;
			}
			break;
		}else{
			linha++;
		}	
	}
	
//	 imprimindo dados do aluno
	for(int j = 0; j < 4; j++){
		switch(j){
			case 0:
				printf("nome: %s\n", matriz_cpf[j]);
				break;
			case 1:
				printf("CPF: %s\n", matriz_cpf[j]);
				break;
			case 2:
				printf("gênero: %s\n", matriz_cpf[j]);
				break;
			case 3:
				printf("data de nascimento: ");
				for(int i = 3; i < 6; i++){
					if(i == 5){
						printf("%s", matriz_cpf[i]);	
						break;
					}
					printf("%s/", matriz_cpf[i]);
				}
				break;
		}
	}
	
	int escolha;
	printf("\n\nDigite 0 se esse é o aluno que deseja excluir?\n");
	scanf("%d", &escolha);

//	passando os dados dos alunos para uma matriz sem o alunoa ser excluido
	char matriz_final[LINHAS][COLUNAS];
	if(escolha == 0){
		int stop = linha - 1;
		linha = 0;
		
		for(int i = 0; i < (num_linhas - 6); i++){
			if(linha != stop){
				strcpy(matriz_final[i], matriz_dados[linha]);
				linha++;
			}else{
				linha += 6;
				i -= 1;
			}
		}
	}else{
		printf("digite o cpf corretamente para que seja possível encontrar o aluno\n");
	}
	
	fclose(arquivo);
	
	arquivo = fopen(nome_arquivo, modo_abertura_2);
	
	if (arquivo == NULL){
	    perror("Erro ao abrir arquivo");
	    return 1;
	}
	
//	passando os dados para o arquivo sem o aluno a ser excluido
	linha = 0; cont = 0;
	while(linha < (num_linhas -6)){
		if(cont < 6){
			fprintf(arquivo, "%s;", matriz_final[linha]);
			linha++;
			cont++;
		}else{
			fprintf(arquivo, "\n\n");
			cont = 0;
		}
	}
	
	fclose(arquivo);
}


int validacao_data(char data_0, char data_1, int ASCII_1, int ASCII_2, int ASCII_3, int ASCII_4, int ASCII_5, int ASCII_6, char verificacao){
		if("%d", data_0 < ASCII_1 || "%d", data_0 > ASCII_2){
			printf("entrada invalida te reinviaremos ao menu principal");
			funcao_menu();
			return 1;
		}
		if("%d", data_0 == verificacao){
			if("%d", data_1 < ASCII_3 || "%d", data_1 > ASCII_4){
				printf("entrada invalida te reinviaremos ao menu principal");
				funcao_menu();
				return 1;
			}
		}
		if(data_1 < ASCII_5 || data_1 > ASCII_6){
			printf("entrada invalida te reinviaremos ao menu principal");
			funcao_menu();
			return 1;
		}
		return 0;
	}


int validacao_ano(char data_0, char data_1, char data_2, char data_3){
		if("%d", data_0 < 48 || "%d", data_0 > 50){
			printf("entrada invalida te reinviaremos ao menu principal");
			funcao_menu();
			return 1;
		}
		if("%d", data_0 == 48){
				printf("entrada invalida te reinviaremos ao menu principal");
				funcao_menu();
				return 1;
		}
		if("%d", data_0 == 49){
			if("%d", data_1 < 48 || "%d", data_1 > 57){
				printf("entrada invalida te reinviaremos ao menu principal");
				funcao_menu();
				return 1;
			}
		}
		if("%d", data_0 == 49){
			if("%d", data_2 < 48 || "%d", data_2 > 57){
				printf("entrada invalida te reinviaremos ao menu principal");
				funcao_menu();
				return 1;
			}
		}
		if("%d", data_0 == 49){
			if("%d", data_3 < 48 || "%d", data_3 > 57){
				printf("entrada invalida te reinviaremos ao menu principal");
				funcao_menu();
				return 1;
			}
		}
		if("%d", data_0 == 50 && "%d", data_3 < 48 || "%d", data_3 > 57 ){
			printf("entrada invalida te reinviaremos ao menu principal");
			funcao_menu();
			return 1;
		}	
		return 0;
	}


int leitura_arquivo(const char* nome_arquivo ,const char* str_fopen){
	#define MAX_NOMES 100
	#define MAX_LEN_NOME 100
    FILE *arquivo;
    char linha[150], nome;
    int tam = 0, cont = 0, colunas = 0;

    arquivo = fopen(nome_arquivo, str_fopen);
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        tam++;
    }
    tam /= 2;  

    char matriz_nomes[MAX_NOMES][MAX_LEN_NOME];

    rewind(arquivo);
    
    while ((nome = fgetc(arquivo)) != EOF) {
    if (nome == '\n') {
        continue;
    }
    if (nome != ';') {
        matriz_nomes[cont][colunas] = nome;
        colunas++;
      }else {
        matriz_nomes[cont][colunas] = '\0'; 
        for (int i = 0; i < 5; i++) {
            while ((nome = fgetc(arquivo)) != EOF && nome != ';') {
            }
        }
        cont++;
        colunas = 0;
      } 
    }
	int i, escolha;
	printf("listagem por ordem e cadastro - digite 1 - ou por ordem alfabética - digite 2?\n");
  scanf("%d", &escolha);
  if(escolha == 1){
    for (i = 0; i < tam; i++) {
        printf("%s\n", matriz_nomes[i]);
    }
  }else if(escolha == 2){
    	   printf("listagem por ordem e alfabética\n");
	    char key[MAX_LEN_NOME];
	    for(int j = 1; j < tam; j++){
	    	strcpy(key, matriz_nomes[j]);
	    	i = j -1;
	    	while(i >= 0 && matriz_nomes[i] > key){
	    		strcpy(matriz_nomes[i+1], matriz_nomes[i]);
	    		i = i - 1;
			}
		strcpy(matriz_nomes[i + 1], key);
		}
		
		    for (i = 0; i < tam; i++) {
	        	printf("%s\n", matriz_nomes[i]);
	    	}
  }
    fclose(arquivo);
    int menuPrincipal;
    printf("digite 1 se deseja voltar ao menu principal, 2 se deseja encerrar o programa\n");
    scanf("%d", &menuPrincipal);

    if(menuPrincipal == 1){
      funcao_menu();
        return 0;
    }else{
    return 0;   
    }
}


int ordenar_por_genero(const char* nome_arquivo, const char* str_open){
	#define LINHAS 100
	#define COLUNAS 100
	char matriz_masculino[LINHAS][COLUNAS];
	char matriz_feminino[LINHAS][COLUNAS];
	char matriz_geral[LINHAS][COLUNAS];
	FILE *arquivo_cadastro_alunos;
	arquivo_cadastro_alunos = fopen(nome_arquivo, str_open);
	
	if(arquivo_cadastro_alunos == NULL){
		perror("Falha ao abrir o arquivo\n");
	}
	
	int cont1 = 0, linhas = 0, colunas = 0, cont = 0;
	char nome, str_masc;
	// trazendo os nomes e o genero dos alunos do arquivo
    while ((nome = fgetc(arquivo_cadastro_alunos)) != EOF) {
	    if (nome == '\n') {
	        continue;
	    }
	    if (nome != ';') {
	        matriz_geral[linhas][colunas] = nome;
	        colunas++;
	    } else {
	    	cont++;
	        matriz_geral[linhas][colunas] = '\0'; 
	        for (int i = 0; i < 5; i++) {
	            while ((nome = fgetc(arquivo_cadastro_alunos)) != EOF && nome != ';') {
	            	if(cont == 2){
		            	linhas++;
		        		colunas = 0;
							matriz_geral[linhas][colunas] = nome;
					}
	            }cont++;
	        }cont = 0;
	        linhas++;
	        colunas = 0;
	    }
	}

	int i = 0;
	//jogando os alunos da genero masculino para outra matriz 
	for(int k = 0; k < linhas; k++){
		if(matriz_geral[k][0] == 'M'){
//			printf("*****1******\n");
			strcpy(matriz_masculino[i], matriz_geral[k-1]);
			i++;
		}
	}
	//jogando os alunos da genero feminino para outra matriz
	for(int k = 0; k < linhas; k++){
		if(matriz_geral[k][0] == 'F'){
			strcpy(matriz_feminino[i], matriz_geral[k-1]);
			i++;
		}
	}
	
	//imprimindo as matrizes
	printf("Esses são os do gênero masculino\n\n");
	for(int k = 0; k < i; k++){
		printf("%s\n", matriz_masculino[k]);
	}
	
	
	
	printf("Esses são os do gênero feminino");
	for(int k = 0; k < i; k++){
		printf("%s\n", matriz_feminino[k]);
	}
	
	fclose(arquivo_cadastro_alunos);
	return 0;
}


int listar_data_nas_PA(const char* nome_arquivo, const char* modo){
		FILE *arquivo_cadastro;
	arquivo_cadastro = fopen(nome_arquivo, modo);
	if(arquivo_cadastro == NULL){
		perror("Falha ao abrir o arquivo\n");
	}
	#define LINHAS 100
	#define COLUNAS 100
	char matriz_nome_data[LINHAS][COLUNAS], matriz_nome_data_2[LINHAS][COLUNAS], matriz_nome_data_3[LINHAS][COLUNAS], nome;
	int linhas = 0, colunas = 0;
	
  	//trazendo os dados do arquivo para a matriz
  	while((nome = fgetc(arquivo_cadastro)) != EOF){
  		if(nome == '\n'){
  			continue;
		  }
  		if(nome != ';'){
  			matriz_nome_data[linhas][colunas] = nome;
  			colunas++;
		  }else{
		  	matriz_nome_data[linhas][colunas] = '\0';
		  	linhas++;
		  	colunas = 0;
		  }
	  }

	int num_alunos;
	num_alunos = linhas/6; 
	
	int linhas_matriz_nomes_datas;
	linhas_matriz_nomes_datas = num_alunos * 4;
	
	printf("numero de linhas 2 %d\n", linhas_matriz_nomes_datas);

	//passando os valores dos nomes e datas para a matriz segundaria
	int tam = 0, linhas_2 = 0, cont = 0;
	while(tam < linhas_matriz_nomes_datas){
		if(cont == 6){
			cont = 0;
		}
		if(cont != 1 && cont != 2){
			strcpy(matriz_nome_data_2[tam], matriz_nome_data[linhas_2]);
			tam++;
		}
		linhas_2++;
		cont++;
	}
    int linhas_matriz_apenas_datas = linhas_matriz_nomes_datas - num_alunos;
    
    // passando só as datas para outra matriz
    tam = 1; linhas_2 = 0; cont = 0;
    while(tam < linhas_matriz_nomes_datas){
    	if(cont < 3){
    	strcpy(matriz_nome_data_3[linhas_2], matriz_nome_data_2[tam]);
    	linhas_2++;
    	tam++;
    	cont++;
		}else{
			tam++;
			cont = 0;
		}
	}

	//colocando a data(dia, mes, ano) para apenas uma linha
	tam = 0; cont = 0;
	char temp[5], temp2[12] = "";
	while(tam < linhas_matriz_apenas_datas){
		for(int k = tam+2; k >= tam; k--){
			strcpy(temp, matriz_nome_data_3[k]);
			strcat(temp2, temp);
		}
		strcpy(matriz_nome_data[cont], temp2);
		cont++;
		tam = tam + 3;
		strcpy(temp2, "");
	}
	
//	colocando '/' na data
	int colunas_pronta = 0;
	tam = 0; colunas = 0; cont = 0;
	char data_pronta[11];
	int linhas_matriz_data_ano_mes_dia = linhas_matriz_apenas_datas/3;
	
	while(tam < linhas_matriz_data_ano_mes_dia){
		for(int k = 0; k < 12; k++){
			if(cont != 4 && cont != 7){
				data_pronta[colunas_pronta] = matriz_nome_data[tam][colunas];
				colunas++;
				colunas_pronta++;
				cont++;
			}else{
				data_pronta[colunas_pronta] = '/';
				colunas_pronta++;
				cont++;
			}
		}
		colunas_pronta = 0;
		colunas = 0;
		cont = 0;
		strcpy(matriz_nome_data[tam], data_pronta);
		tam++;
		
	}
	
	//ordenando as datas
	strcpy(data_pronta, "");
	int min, teste2;
	for(int k = 0; k < linhas_matriz_data_ano_mes_dia; k++){
		min = k;
		for(int j = k+1; j < linhas_matriz_data_ano_mes_dia; j++){
			teste2 = strcmp(matriz_nome_data[min], matriz_nome_data[j]);
			if(teste2 > 0){
				min = j;
			}
		}
		if(min != k){
			strcpy(data_pronta, matriz_nome_data[k]);
			strcpy(matriz_nome_data[k], matriz_nome_data[min]);
			strcpy(matriz_nome_data[min], data_pronta);
		}
	}


//	matriz_nome_data - datas ordenadas
//	matriz_nome_data_2 - nomes e datas
// matriz_nome_data_3 - recebe os nomes e as datas ordenadas

  printf("\nas datas estão no formato ano/mes/dia\n\n");
	//juntar os nomes e as datas
	char data[5];
	linhas = 0;
	int teste, linhas2 = 0, linhas3 = 0;
	while(linhas3 < 8){
		for(int k = 0; k < 4; k++){
			data[k] = matriz_nome_data[linhas][k];
		}
		while(linhas3 < (num_alunos * 2)){
			teste = strcmp(data, matriz_nome_data_2[linhas2]);
			if(teste == 0){
				strcpy(matriz_nome_data_3[linhas3], matriz_nome_data_2[linhas2 - 3]);
				printf("%s\n", matriz_nome_data_3[linhas3]);
				linhas3++;
				strcpy(matriz_nome_data_3[linhas3], matriz_nome_data[linhas]);
				printf("%s\n", matriz_nome_data_3[linhas3]);
				linhas3++;
				break;
			}else{
				linhas2++;
			}
			if(linhas2 == linhas_matriz_nomes_datas){
				linhas2 = 0;
			}
		}
		linhas++;
	}	
		
	fclose(arquivo_cadastro);
	
	return 0;	
}


int niver_mes(const char* nome_arquivo, const char* modo, const char* PA){
	time_t t = time(NULL);
    struct tm *p = localtime(&t);
    char data_atual[3];
    strftime(data_atual, sizeof(data_atual), "%m", p);
    
    FILE *arquivo_cadastro;
	arquivo_cadastro = fopen(nome_arquivo, modo);
	if(arquivo_cadastro == NULL){
		perror("Falha ao abrir o arquivo\n");
	}
	#define LINHAS 100
	#define COLUNAS 100
	char matriz_nome_data[LINHAS][COLUNAS], matriz_nome_data_2[LINHAS][COLUNAS], matriz_nome_data_3[LINHAS][COLUNAS], nome;
	int linhas = 0, colunas = 0;
	
  	//trazendo os dados do arquivo para a matriz
  	while((nome = fgetc(arquivo_cadastro)) != EOF){
  		if(nome == '\n'){
  			continue;
		  }
  		if(nome != ';'){
  			matriz_nome_data[linhas][colunas] = nome;
  			colunas++;
		  }else{
		  	matriz_nome_data[linhas][colunas] = '\0';
		  	linhas++;
		  	colunas = 0;
		  }
	  }

	int num_alunos;
	num_alunos = linhas/6; 	
	int linhas_matriz_nomes_datas;
	linhas_matriz_nomes_datas = num_alunos * 4;
	

	//passando os valores dos nomes e datas para a matriz segundaria
	int tam = 0, linhas_2 = 0, cont = 0;
	while(tam < linhas_matriz_nomes_datas){
		if(cont == 6){
			cont = 0;
		}
		if(cont != 1 && cont != 2){
			strcpy(matriz_nome_data_2[tam], matriz_nome_data[linhas_2]);
			tam++;
		}
		linhas_2++;
		cont++;
	}
	
    int linhas_matriz_apenas_datas = linhas_matriz_nomes_datas - num_alunos;
	
	
	int linha = 0, teste = 1;
	char aniversariante[50][50];
	 for(int k = 2; k < tam; k += 4){
	 	teste = strcmp(matriz_nome_data_2[k], data_atual);
	 	if(teste == 0){
	 		strcpy(aniversariante[linha], matriz_nome_data_2[k-2]);
	 		linha++;
		 }
	 }
  
	if(teste != 0){
		printf("Não ha %s que fazem aniversário esse mes\n", PA);
	}else{
		printf("Os %s aniversariantes do mes são:\n", PA);
		for(int k = 0; k <= linha; k++){
			printf("%s\n", aniversariante[k]);
		}
	}
  
	fclose(arquivo_cadastro);
	return 0;
}


int busca_letra(const char* nome_arquivo, const char* modo, const char*PA, char letras[]){
	FILE *arquivo;
	
	arquivo = fopen(nome_arquivo, modo);
	if(arquivo == NULL){
		perror("erro ao abrir o arquivo");
		return 1;
	}
	
	//buscando os nomes no arquivo
	char dados, matriz_nome[100][100];
	int linha = 0, coluna = 0, flag = 1;
	while((dados = fgetc(arquivo)) != EOF){
		if(dados == '\n'){
			continue;
		}
		if(dados != ';'){
			matriz_nome[linha][coluna] = dados;
			coluna++;
		}else{
			matriz_nome[linha][coluna] = '\0';
			for(int i = 0; i < 5; i++){
				while((dados = fgetc(arquivo)) != EOF && dados != ';');
			}
			linha++;
			coluna = 0;
		}
	}
	
	int tam = linha, cont = 0, caracter = 0, stop = 0;
	
	//buscando as lestras no nome
	for(linha = 0; linha < tam; linha++){
		for(;;){
			if(matriz_nome[linha][coluna] == letras[caracter]){
				cont++;
				caracter++;
			}
			coluna++;
			if(matriz_nome[linha][coluna] == '\0'){
				coluna = 0;
				stop++;
				if(caracter > 2 || stop > 2){
					break;
				}
			}
		}
		coluna = 0;
		if(cont == 3){
			printf("%s com essas letras no nome: %s\n", PA, matriz_nome[linha]);
			flag = 0;
		}
		cont = 0;
		caracter = 0;
		}
		
	if(flag){
		printf("Não há %s com esse nome\n", PA);
	}
	
	fclose(arquivo);
	
	return 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int escolha_D(const char* nome_arquivo ,const char* str_fopen){
		struct cadastro{
			char nome[100];
			char matricula[10];
			char semestre[10];
			char professor[100];
		};
		
		int cont, n, ln;
		FILE *arquivo;
		
        printf("quantos deseja cadastrar? \n");
        scanf("%d", &n);
        struct cadastro cadas[n];
        
        arquivo = fopen(nome_arquivo, str_fopen);

        if (arquivo == NULL) {
          printf("Erro ao abrir arquivo de texto.\n");
          return 1;
        }
        
        for(cont = 0; cont < n; cont++){
	        getchar();
	        printf("digite o nome %d:\n", cont+1);
	        fgets(cadas[cont].nome, 100, stdin);
			    cadas[cont].nome[strcspn(cadas[cont].nome, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].nome);
			 
	        printf("digite o código da materia %d:\n", cont+1);
	        fgets(cadas[cont].matricula, 10, stdin);
			    cadas[cont].matricula[strcspn(cadas[cont].matricula, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].matricula); 
    
	        printf("digite o semestre:\n", cont+1);
	        fgets(cadas[cont].semestre, 10, stdin);
			    cadas[cont].semestre[strcspn(cadas[cont].semestre, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].semestre); 
			
			    printf("digite o nome do professor:\n", cont+1);
	        fgets(cadas[cont].professor, 10, stdin);
	        cadas[cont].professor[strcspn(cadas[cont].professor, "\n")] = '\0';
	        fprintf(arquivo, "%s;", cadas[cont].professor);  
	        
        	fprintf(arquivo, "\n\n");
			}
        fclose(arquivo);
        return 0;
		}


int modificar_disciplina(){
	#define LINHAS 100
	#define COLUNAS 100
		FILE *arquivo;
  	
  	arquivo = fopen("cadastro_disciplina.txt", "r");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
  	
  	// trazendo os dados das disciplinas para uma matriz
  	int linha = 0, coluna = 0;
	char dados, matriz_disciplinas[LINHAS][COLUNAS];
	while((dados = fgetc(arquivo)) != EOF) {
		if(dados == '\n') {
			continue;
		}
		if(dados != ';') {
			matriz_disciplinas[linha][coluna] = dados;
			coluna++;
		} else {
			matriz_disciplinas[linha][coluna] = '\0';
			linha++;
			coluna = 0;
		}
	}
	printf("As disciplinas cadastradas atualmente são:\n\n");
	for(int i = 0; i < linha; i += 4){
		printf("%s\n", matriz_disciplinas[i]);
	}
	
	int num_linha = linha;
	fclose(arquivo);
	
	char nome_disciplina[100];
	printf("\ndigite o nome da disciplina que deseja modificar\n");
	scanf("%s", &nome_disciplina);
	
//	trazendo os dados da disciplina desejada para dados_disciplinas
	char dados_disciplina[4][100];
	int disciplina_encontrada = 0;
	for (int k = 0; k < linha; k++) {
	if(strcmp(matriz_disciplinas[k], nome_disciplina) == 0) {
	disciplina_encontrada = 1;
			for(int h = 0; h < 4; h++) {
				strcpy(dados_disciplina[h], matriz_disciplinas[k+h]);
			}
			break;
		}
	}
	
	
	if(disciplina_encontrada){
		printf("\nesse são os dados atuais da disciplina\n\n");
			for(int j = 0; j < 4; j++) {
			switch(j) {
				case 0:
					printf("nome: %s\n", dados_disciplina[j]);
					break;
				case 1:
					printf("codigo: %s\n", dados_disciplina[j]);
					break;
				case 2:
					printf("semestre: %s\n", dados_disciplina[j]);
					break;
				case 3:
					printf("professor: %s\n", dados_disciplina[j]);

					break;
			}
		}
	} else {
		printf("\n\ndisciplina não encontrada, recomece o cadastro.\n");
//		incluir_em_disciplinas();
		return 0;
	}
	
	
	int oq_alterar, flag = 0;
	printf("\n\nO que deseja alterar? digite 1 se dejesa alterar o código da disciplina, 2 se dejesa alterar o semestre ou 3 se deseja alterar o professor: \n");
	scanf("%d", &oq_alterar);
	
	char modificacao[50];
	switch(oq_alterar){
		case 1:
			printf("qual o novo código da disciplina\n");
			scanf("%s", &modificacao);
			strcpy(dados_disciplina[1], modificacao);
			flag = 1;
			break;
		case 2:
			printf("qual o novo semestre da disciplina\n");
			scanf("%s", &modificacao);
			strcpy(dados_disciplina[2], modificacao);
			flag = 1;
			break;
		case 3:
			printf("qual o novo professor da disciplina\n");
			scanf("%s", &modificacao);
			strcpy(dados_disciplina[3], modificacao);
			flag = 1;
			break;
	}
	
	if(flag){
		printf("\n\ndisciplina alterada\n\n");
		for(int j = 0; j < 4; j++) {
			switch(j) {
				case 0:
					printf("nome: %s\n", dados_disciplina[j]);
					break;
				case 1:
					printf("codigo: %s\n", dados_disciplina[j]);
					break;
				case 2:
					printf("semestre: %s\n", dados_disciplina[j]);
					break;
				case 3:
					printf("professor: %s\n", dados_disciplina[j]);

					break;
			}
		}
	}
	
//	passando a disciolina alterada para a matriz com todas as disciplinas
	for (int k = 0; k < linha; k++) {
		if(strcmp(matriz_disciplinas[k], nome_disciplina) == 0) {
		disciplina_encontrada = 1;
				for(int h = 0; h < 4; h++) {
					strcpy(matriz_disciplinas[k+h], dados_disciplina[h]);
				}
				break;
			}
		}	
	
	arquivo = fopen("cadastro_disciplina.txt", "w");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
    // passando a matriz para o arquivo de cadastro disciplinas 
    int cont = 0;
    for(int i = 0; i < num_linha; i++){
    	fprintf(arquivo, "%s;", matriz_disciplinas[i]);
    	cont++;
    	if(cont > 3){
    		fprintf(arquivo, "\n\n");
    		cont = 0;
		}
	}
	fclose(arquivo);
	
	char extencao[5] = ".txt", nome_arquivo_disciplina[50];
	sprintf(nome_arquivo_disciplina, "%s%s", nome_disciplina, extencao);
	
	arquivo = fopen(nome_arquivo_disciplina, "r");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
	
	//	trazendo os dados do arquivo para uma matriz

	linha = 0, coluna = 0;
	char matriz_alunos_em_disciplinas[LINHAS][COLUNAS];
	while((dados = fgetc(arquivo)) != EOF) {
		if(dados == '\n') {
			continue;
		}
		if(dados != ';') {
			matriz_alunos_em_disciplinas[linha][coluna] = dados;
			coluna++;
		} else {
			matriz_alunos_em_disciplinas[linha][coluna] = '\0';
			linha++;
			coluna = 0;
		}
	}
	num_linha = linha;
	fclose(arquivo);
	
	for(linha = 0; linha < 4; linha++){
		strcpy(matriz_alunos_em_disciplinas[linha], dados_disciplina[linha]);
	}
	
	arquivo = fopen(nome_arquivo_disciplina, "w");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
	
	linha = 0; cont = 0;
	int cont2 = 0;
// passando a disciplina alterada para o arquivo proprio dela
	while(linha < num_linha){
		fprintf(arquivo, "%s;", matriz_alunos_em_disciplinas[linha]);
		cont++;
		cont2++;
		linha++;
		if(cont == 4){
			fprintf(arquivo, "\n\n");
			cont2 = 0;
		}if(cont2 == 6){
			fprintf(arquivo, "\n");
			cont2 = 0;
		}
	}
	
	printf("a disciplina foi alterada com sucesso");
	fclose(arquivo);
	
	return 0;
}


int excluir_disciplina(){
	   	
	#define LINHAS 100
	#define COLUNAS 100
	char nome_disciplina[50], nome, matriz_dados[LINHAS][COLUNAS], matriz_disciplina[LINHAS][COLUNAS];
	int linha = 0, coluna = 0;
	FILE *arquivo;
	arquivo = fopen("cadastro_disciplinas.txt", "r");
	
	if (arquivo == NULL){
	    perror("Erro ao abrir arquivo");
	    return 1;
	}
	
	
	printf("Digite o nome da materia que dejesa excluir ");
	scanf("%s", &nome_disciplina);
	
//	trazendo os dados para uma matriz
	while ((nome = fgetc(arquivo)) != EOF) {
	    if (nome == '\n') {
	        continue;
	    }
	    if (nome != ';') {
	        matriz_dados[linha][coluna] = nome;
	        coluna++;
	    } else {
	        matriz_dados[linha][coluna] = '\0'; 
	        coluna = 0;
	        linha++;
	    }
	}
	
	int num_linhas = linha;
//  trazando os dados da disciplina informado para verificação
	int cont = 0, teste = 1;
	linha = 0; coluna = 0;
	while(linha < num_linhas){
		teste = strcmp(nome_disciplina, matriz_dados[linha]);
		if(teste == 0){
			for(int i = 0; i < 4; i++){
				strcpy(matriz_disciplina[i], matriz_dados[linha]);
				linha++;
			}
			break;
		}else{
			linha++;
		}	
	}
	
//	 imprimindo dados da disciplina
	if(teste == 0){
		printf("\nesse são os dados atuais da disciplina\n\n");
			for(int j = 0; j < 4; j++) {
			switch(j) {
				case 0:
					printf("nome: %s\n", matriz_disciplina[j]);
					break;
				case 1:
					printf("codigo: %s\n", matriz_disciplina[j]);
					break;
				case 2:
					printf("semestre: %s\n", matriz_disciplina[j]);
					break;
				case 3:
					printf("professor: %s\n", matriz_disciplina[j]);

					break;
			}
		}
	} else {
		printf("\n\ndisciplina não encontrada, recomece o cadastro.\n");
//		incluir_em_disciplinas();
		return 0;
	}
	
	int escolha;
	printf("\n\nDigite 0 se essa é a disciplina que deseja excluir?\n");
	scanf("%d", &escolha);

//	passando os dados dos alunos para uma matriz sem a disciplina ser excluida
	char matriz_final[LINHAS][COLUNAS];
	if(escolha == 0){
		int stop = linha - 4;
		linha = 0;
		
		for(int i = 0; i < (num_linhas - 4); i++){
			if(linha != stop){
				strcpy(matriz_final[i], matriz_dados[linha]);
				linha++;
			}else{
				linha += 4;
				i -= 1;
			}
		}
	}else{
		printf("digite o nome corretamente para que seja possível encontrar a disciplina\n");
		excluir_disciplina();
		return 0;
	}
	
	fclose(arquivo);
	
	arquivo = fopen("cadastro_disciplina.txt", "w");
	// removendo a disciplina do arquivo de cadastro
	cont = 0;
	for(int i = 0; i < linha; i++){
		fprintf(arquivo, "%s;", matriz_final[i]);
		cont++;
		if(cont == 4){
			fprintf(arquivo, "\n\n");
			cont = 0;
		}
	}
	
	fclose(arquivo);
	
	char nome_arquivo_disciplina[50], extencao[5] = ".txt";
	
	sprintf(nome_arquivo_disciplina, "%s%s", nome_disciplina, extencao);
	// removendo o arquivo da disciplina
	if(remove(nome_arquivo_disciplina) == 0){
		printf("A disciplina foi removida com sucesso\n");
	}else{
		printf("Erro ao remover a disciplina\n");
	}
	
	
	return 0;
}


int incluir_em_disciplinas() {

	FILE *arquivo_PA;
#define LINHAS 100
#define COLUNAS 100
	char matriz_alunos[LINHAS][COLUNAS];
	char dados;

	arquivo_PA = fopen("cadastro_alunos.txt", "r");
	if (arquivo_PA == NULL) {
		perror("Erro ao abrir arquivo");
		return 1;
	}
//	 trazendo os dados dos alunos para uma matriz
	int i = 0, j = 0;
	while((dados = fgetc(arquivo_PA)) != EOF) {
		if(dados == '\n') {
			continue;
		}
		if(dados != ';') {
			matriz_alunos[i][j] = dados;
			j++;
		} else {
			matriz_alunos[i][j] = '\0';
			i++;
			j = 0;
		}
	}
	int num_linhas = i;
//	printf("valor de i: %d//  valor de num_linhas: %d", i, num_linhas);
	char cpf_desejado[12];
	getchar();
	printf("Digite o CPF do aluno que deseja buscar: ");
	gets(cpf_desejado);

//	procurando o aluno e passando seus dados para a matriz 'dados_aluno'
	char dados_aluno[6][100];
	int teste = 1, cont = 0, aluno_encontrado = 0;
	i = 0;
	while(i < num_linhas) {
		teste = strcmp(cpf_desejado, matriz_alunos[i]);
		if(teste == 0) {
			aluno_encontrado = 1;
			int passagem_linha = i -1;
			for(int k = 0; k < 6; k++) {
				strcpy(dados_aluno[k], matriz_alunos[passagem_linha]);
				passagem_linha++;
			}
			break;
		} else {
			i++;
		}
	}

	if (aluno_encontrado) {
//	 imprimindo dados do aluno
		for(int j = 0; j < 4; j++) {
			switch(j) {
				case 0:
					printf("nome: %s\n", dados_aluno[j]);
					break;
				case 1:
					printf("CPF: %s\n", dados_aluno[j]);
					break;
				case 2:
					printf("gênero: %s\n", dados_aluno[j]);
					break;
				case 3:
					printf("data de nascimento: ");
					for(int i = 3; i < 6; i++) {
						if(i == 5) {
							printf("%s", dados_aluno[i]);
							break;
						}
						printf("%s/", dados_aluno[i]);
					}
					break;
			}
		}
	} else {
		printf("Aluno não encontrado, recomece o cadastro\n");
		incluir_em_disciplinas();
		return 0;
	}
	fclose(arquivo_PA);


	FILE *arquivo_D;
	char matriz_disciplinas[LINHAS][COLUNAS];
	char dados_2;

	arquivo_D = fopen("cadastro_disciplinas.txt", "r");
	if (arquivo_D == NULL) {
		printf("Erro ao abrir arquivo\n");
		return 1;
	}
//	 trazendo os dados das disciplinas
	int t = 0, c = 0;
	cont = 0;
	while((dados_2 = fgetc(arquivo_D)) != EOF) {
		if(dados_2 == '\n') {
			continue;
		}
		if(dados_2 != ';') {
			matriz_disciplinas[t][c] = dados_2;
			c++;
		} else {
			matriz_disciplinas[t][c] = '\0';
			t++;
			c = 0;
		}
	}
	
	char nome_desejado[50];
	printf("\n\nDigite o nome da disciplina que deseja buscar: ");
	gets(nome_desejado);
	
	
	
	
	
//	concatenação do nome da disciplina com a exteção '.txt' para criação do arquivo
	char extencao_arquivo[10] = ".txt";
	char arquivos_disciplinas[100];
	strcpy(arquivos_disciplinas, nome_desejado);
	strcat(arquivos_disciplinas, extencao_arquivo);

//	buscando os dados da disciplina desejada na "matriz_disciplinas" e passando para "dados_disciplina"
	char dados_disciplina[4][100];
	int disciplina_encontrada = 0;
	for (int k = 0; k < t; k++) {
		if(strcmp(matriz_disciplinas[k], nome_desejado) == 0) {
			disciplina_encontrada = 1;
			for(int h = 0; h < 4; h++) {
				strcpy(dados_disciplina[h], matriz_disciplinas[k+h]);
			}
			break;
		}
	}

	if(disciplina_encontrada) {
//	 imprimindo dados da disciplina
		for(int j = 0; j < 4; j++) {
			switch(j) {
				case 0:
					printf("nome: %s\n", dados_disciplina[j]);
					break;
				case 1:
					printf("codigo: %s\n", dados_disciplina[j]);
					break;
				case 2:
					printf("semestre: %s\n", dados_disciplina[j]);
					break;
				case 3:
					printf("professor: %s\n", dados_disciplina[j]);

					break;
			}
		}
	} else {
		printf("\n\ndisciplina não encontrada, recomece o cadastro.\n");
		incluir_em_disciplinas();
		return 0;
	}
	fclose(arquivo_D);

// criando arquivo da disciplina solicitada e/ou incluindo o aluno desejado nela
	FILE *arquivo_IE;
	int escolha;
	printf("\n\nDigite 1 se esse é a primeiro cadastro nessa disciplinas, 2 se já foram feitos cadastros antes\n ");
	scanf("%d", &escolha);
	switch(escolha) {
		case 1:
			arquivo_IE = fopen(arquivos_disciplinas, "w");
			for(int k = 0; k < 4; k++) {
				fprintf(arquivo_IE, "%s;", dados_disciplina[k]);
			}
			fprintf(arquivo_IE, "\n\n");
			for(int k = 0; k < 6; k++) {
				fprintf(arquivo_IE, "%s;", dados_aluno[k]);
			}
			fprintf(arquivo_IE, "\n");
			printf("O aluno '%s' foi incluso na disciplina '%s' \n", dados_aluno[0], dados_disciplina[0]);
			fclose(arquivo_IE);
			printf("digite 1 para continuar cadastrando alunos em disciplinas ou 2 para sair\n");
			scanf("%d", &escolha);
			if(escolha == 1) {
				incluir_em_disciplinas();
			} else {
				return 0;
			}
			break;

		case 2:
			arquivo_IE = fopen(arquivos_disciplinas, "a");
			for(int k = 0; k < 6; k++) {
				fprintf(arquivo_IE, "%s;", dados_aluno[k]);
			}
			fprintf(arquivo_IE, "\n");
			printf("O(a) aluno(a) '%s' foi incluso(a) na disciplina '%s' \n", dados_aluno[0], dados_disciplina[0]);
			fclose(arquivo_IE);
			printf("digite 1 para continuar cadastrando alunos em disciplinas ou 2 para sair\n");
			scanf("%d", &escolha);
			if(escolha == 1) {
				incluir_em_disciplinas();
			}
			break;

		default:
			printf("opção invalida digite 1 se deseja reiniciar a inclusão de alunos em disciplinas ou 2 se deseja voltar ao menu principal ");
			scanf("%d", &escolha);

			if(escolha = 1) {
				incluir_em_disciplinas();
				break;
			} else if(escolha == 2) {
				//chama função
				break;
			}
	}
	return 0;
}


int excluir_de_disciplina() {
#define LINHAS 100
#define COLUNAS 100
	char matriz_alunos_em_disciplinas[LINHAS][COLUNAS];
	char matriz_alunos_em_disciplinas_2[LINHAS][COLUNAS];
	char dados;

	FILE *arquivo_incluir_em_disciplinas;

	getchar();
	char nome_desejado[100];
	printf("Digite o nome da disciplina que deseja buscar: ");
	gets(nome_desejado);

//	colocando a extensão do arquivo
	char extencao_arquivo[10] = ".txt";
	char arquivos_disciplinas[100];
	strcpy(arquivos_disciplinas, nome_desejado);
	strcat(arquivos_disciplinas, extencao_arquivo);


	arquivo_incluir_em_disciplinas = fopen(arquivos_disciplinas, "r");
	if (arquivo_incluir_em_disciplinas == NULL) {
		perror("Erro ao abrir arquivo, verifique se escreveu corretamente o nome da matéria");
		return 1;
	} else {
		printf("nome do arquivo: %s\n", arquivos_disciplinas);
	}

	char cpf_desejado[12];
	printf("Digite o CPF do aluno que deseja excluir: ");
	gets(cpf_desejado);

//	trazendo os dados do arquivo para uma matriz
//	getchar();
	int linha = 0, coluna = 0;
	while((dados = fgetc(arquivo_incluir_em_disciplinas)) != EOF) {
		if(dados == '\n') {
			continue;
		}
		if(dados != ';') {
			matriz_alunos_em_disciplinas[linha][coluna] = dados;
			coluna++;
		} else {
			matriz_alunos_em_disciplinas[linha][coluna] = '\0';
			linha++;
			coluna = 0;
		}
	}

// buscando posição do cpf na matriz
	int num_linha = linha;
	int teste = 1;
	linha = 0;
	int posicao_cpf;
	for(int k = 0; k < num_linha; k++) {
		teste = strcmp(cpf_desejado, matriz_alunos_em_disciplinas[k]);
		if(teste == 0) {
			posicao_cpf = k;
			break;
		}
	}

	if(teste == 0) {
		int linha_aluno = posicao_cpf -1;
		printf("\n\ndados do aluno \n\n");
		for(int i = 0; i < 4; i++) {
			if(i == 0)
				printf("Nome: %s\n", matriz_alunos_em_disciplinas[linha_aluno]);
			if(i == 1)
				printf("CPF: %s\n", matriz_alunos_em_disciplinas[linha_aluno]);
			if(i == 2)
				printf("gênero: %s\n", matriz_alunos_em_disciplinas[linha_aluno]);
			if(i == 3) {
				printf("data de nascimento: ");
				for(int i = 0; i < 3; i++) {
					if(i == 2) {
						printf("%s", matriz_alunos_em_disciplinas[linha_aluno]);
						break;
					}
					printf("%s/", matriz_alunos_em_disciplinas[linha_aluno]);
					linha_aluno++;
				}
			}
			linha_aluno++;
		}
	} else {
		printf("aluno não encontrado. tente novamente\n");
		excluir_de_disciplina();
		return 0;
	}


// passando os dados para a "matriz_alunos_em_disciplinas_2"
	linha = 0;
	for(int k = 0; k < (num_linha); k++) {
		if(k == (posicao_cpf-1)) {
			k += 6;
		}
		strcpy(matriz_alunos_em_disciplinas_2[linha], matriz_alunos_em_disciplinas[k]);
		linha++;
	}

//	passando a matriz atualizada (sem o aluno excluido) para o arquivo
	linha = linha - 1;
	arquivo_incluir_em_disciplinas = fopen(arquivos_disciplinas, "w");

	int cont_mat = 0, cont_alu = 0;
	for(int k = 0; k < (linha); k++) {
		if(cont_mat == 4) {
			fprintf(arquivo_incluir_em_disciplinas, "\n\n");
			cont_alu = 0;
		}
		if(cont_alu == 6) {
			fprintf(arquivo_incluir_em_disciplinas, "\n");
			cont_alu = 0;
		}
		fprintf(arquivo_incluir_em_disciplinas, "%s;", matriz_alunos_em_disciplinas_2[k]);
		cont_mat++;
		cont_alu++;
		if(k == (linha -1)) {
			fprintf(arquivo_incluir_em_disciplinas, "\n");
		}
	}

	fclose(arquivo_incluir_em_disciplinas);
	if(teste == 0) {
		printf("Aluno(a) excluido(a) com sucesso\n");
	}
	int escolha;
	printf("\n\nDeseja excluir mais alunos? digite 1 se sim ou 2 para voltar ao menu principal: ");
	scanf("%d", &escolha);

	if(escolha == 1) {
		excluir_de_disciplina();
		return 0;
	} else {
		//chamar função
		return 0;
	}

	return 0;
}


int listagem_disciplinas(){
	FILE *arquivo;
	#define LINHAS 100
	#define COLUNAS 100
	char matriz_disciplinas[LINHAS][COLUNAS];
	char dados;
	
	arquivo = fopen("cadastro_disciplinas.txt", "r");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
	int i = 0, j = 0, cont = 0;
	while((dados = fgetc(arquivo)) != EOF){
		if(dados != ';'){
			matriz_disciplinas[i][j] = dados;
			j++;
		}else{
			matriz_disciplinas[i][j] = '\0';
			i++;
			j = 0;
			cont++;
			if(cont == 4){
				matriz_disciplinas[i][j] = '\n';
				matriz_disciplinas[i][j + 1] = '\0';
				i++;
				j = 0;	
			}
		}
	}
	for (int tam = 0; tam < i; tam++) {
        printf("%s\n", matriz_disciplinas[tam]);
  }
    fclose(arquivo);
    return 0;
}


int menos_3disciplinas(){
  	#define LINHAS 100
	#define COLUNAS 100
	setlocale(LC_ALL, "portuguese");
	
	FILE *arquivo;
	char matriz_nome[LINHAS][COLUNAS];
	char dados, cpf[12];
	
	arquivo = fopen("cadastro_disciplinas.txt", "r");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
	int linha = 0, coluna = 0;
	while((dados = fgetc(arquivo)) != EOF){
		if(dados == '\n'){
			continue;
		}
		if(dados != ';'){
			matriz_nome[linha][coluna] = dados;
			coluna++;
		}else{
			matriz_nome[linha][coluna] = '\0';
			for(int i = 0; i < 3; i++){
				while((dados = fgetc(arquivo)) != EOF && dados != ';');
			}
			linha++;
			coluna = 0;
		}
	}
	int num_mat = linha;
	
	int aluno_encontrado = 0;

    fclose(arquivo);

//	 trazendo os dados dos alunos para uma matriz

	arquivo = fopen("cadastro_alunos.txt", "r");
	if (arquivo == NULL) {
		perror("Erro ao abrir arquivo");
		return 1;
	}


	linha = 0, coluna = 0;
	char matriz_alunos[LINHAS][COLUNAS];
	while((dados = fgetc(arquivo)) != EOF){
		if(dados == '\n') {
			continue;
		}
		if(dados != ';') {
			matriz_alunos[linha][coluna] = dados;
			coluna++;
		} else {
			matriz_alunos[linha][coluna] = '\0';
			linha++;
			coluna = 0;
		}
	}
	int num_linha = (linha/6)*2;
	
//	colocando apenas os nomes e os cpfs em uma matriz
  	char matriz_nome_cpf[LINHAS][COLUNAS];
  	linha = 0;
  	int tam = 0, cont = 0;
  	while(tam < num_linha){
  		if(cont < 2){
  			strcpy(matriz_nome_cpf[tam], matriz_alunos[linha]);
  			cont++;
  			tam++;
  			linha++;
		  }else{
		  	linha += 4;
		  	cont = 0;
		  }
	  }
	
	char extencao[5] = ".txt", argumento_fopen[50];
	char matriz_alunos_em_disciplinas[LINHAS][COLUNAS], matriz_materias[LINHAS][COLUNAS];
	int contador_while = 1;
	
	while(contador_while < num_linha){
		
		strcpy(cpf, matriz_nome_cpf[contador_while]);
		
		for(int tam = 0; tam < num_mat; tam++){
			sprintf(argumento_fopen, "%s%s", matriz_nome[tam], extencao);
			arquivo = fopen(argumento_fopen, "r");
			if (arquivo == NULL) {
				perror("Erro ao abrir arquivo");
				return 1;
			}
				
		//	trazendo os dados do arquivo para uma matriz
			linha = 0, coluna = 0;
			while((dados = fgetc(arquivo)) != EOF) {
				if(dados == '\n') {
					continue;
				}
				if(dados != ';') {
					matriz_alunos_em_disciplinas[linha][coluna] = dados;
					coluna++;
				} else {
					matriz_alunos_em_disciplinas[linha][coluna] = '\0';
					linha++;
					coluna = 0;
				}
			}
			
		// buscando posição do cpf na matriz
			int num_linha = linha;
			int teste = 1;
			linha = 0;
			int posicao_cpf;
			for(int k = 0; k < num_linha; k++) {
				teste = strcmp(cpf, matriz_alunos_em_disciplinas[k]);
				if(teste == 0) {
					posicao_cpf = k;
					break;
				}
			}
		
			if(teste == 0) {
				aluno_encontrado++;
			}
		
			fclose(arquivo);
		}
		
		if(aluno_encontrado < 3){
			printf("*****************!******************\n");
			printf("o alunno %s de cpf %s esta matriculado em %d materias\n", matriz_nome_cpf[contador_while - 1], cpf, aluno_encontrado);
		}
		aluno_encontrado = 0;
		contador_while += 2;
	}
	  return 0;	
  }


int vagas_disciplinas(){
	#define LINHAS 100
	#define COLUNAS 100
		
	FILE *arquivo;
	char matriz_nome[LINHAS][COLUNAS];
	char dados, cpf[12];
	
	arquivo = fopen("cadastro_disciplinas.txt", "r");
	if (arquivo == NULL) {
        printf("Erro ao abrir arquivo\n");
        return 1;
    }
	int linha = 0, coluna = 0;
	//trazendo as disciplinas e seus dados para uma matriz
	while((dados = fgetc(arquivo)) != EOF){
		if(dados == '\n'){
			continue;
		}
		if(dados != ';'){
			matriz_nome[linha][coluna] = dados;
			coluna++;
		}else{
			matriz_nome[linha][coluna] = '\0';
			for(int i = 0; i < 3; i++){
				while((dados = fgetc(arquivo)) != EOF && dados != ';');
			}
			linha++;
			coluna = 0;
		}
	}
	int num_mat = linha;
	
	
	
	char extencao[5] = ".txt", argumento_fopen[50];
	char matriz_alunos_em_disciplinas[LINHAS][COLUNAS], matriz_materias[LINHAS][COLUNAS];
	for(int tam = 0; tam < num_mat; tam++){
			sprintf(argumento_fopen, "%s%s", matriz_nome[tam], extencao);
			arquivo = fopen(argumento_fopen, "r");
			if (arquivo == NULL) {
				perror("Erro ao abrir arquivo");
				return 1;
			}
			
			//	trazendo os dados do arquivo para uma matriz
			linha = 0, coluna = 0;
			while((dados = fgetc(arquivo)) != EOF) {
				if(dados == '\n') {
					continue;
				}
				if(dados != ';') {
					matriz_alunos_em_disciplinas[linha][coluna] = dados;
					coluna++;
				} else {
					matriz_alunos_em_disciplinas[linha][coluna] = '\0';
					linha++;
					coluna = 0;
				}
			}
			int cont = 0;
			for(int i = 4; i < linha; i+=6){
				if(matriz_alunos_em_disciplinas[i] != '\0'){
					cont++;
				}
			}
			
			printf("o numero de aluno na disciplina %s é: %d\n", matriz_nome[tam], cont);
			cont = 0;
			
		fclose(arquivo);		
	}
	return 0;
}