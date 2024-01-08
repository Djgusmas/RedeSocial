#include <stdio.h>
#include <time.h>
#include "Outros.h"

//prototipos das funções utilizadas para melhor intrepertação do código;
void definirHora(DATA* d); // função para definição da data e a hora do sistema;
void login(UTILIZADORL* lista, UTILIZADOR* u); //função para definição do login;
int entrarAdmin();

//função para definição da data e a hora do sistema;
void definirHora(DATA* d){ //chamada da estrutura data com apontador e passagem por referência, chamada da variavel d
	time_t t = time(NULL); //data e hora do sistema 
	struct tm tm = *localtime(&t); //estrutura da data e hora do sistema 
	
	d->ano = tm.tm_year + 1900; //atribuição do valor de d a ano através do operador seta para o valor de tm.tm_year + 1900 (ano do sistema)
	d->mes = tm.tm_mon + 1; //atribuição do valor de d a mes através do operador seta para o valor de tm.tm_mon + 1 (mes do sistema)
	d->dia = tm.tm_mday; //atribuição do valor de d a mes através do operador seta para o valor de tm.tm_mday (dia do sistema)
	d->hora = tm.tm_hour; //atribuição do valor de d a mes através do operador seta para o valor de tm.tm_hour (hora do sistema)
	d->minuto = tm.tm_min; //atribuição do valor de d a mes através do operador seta para o valor de tm.tm_min (minuto do sistema)
	d->segundo = tm.tm_sec; //atribuição do valor de d a mes através do operador seta para o valor de tm.tm_sec (segundo do sistema)
}

//função para definição do login
void login(UTILIZADORL* lista, UTILIZADOR* u){ //chamada da estrutura UTILIZADORL com apontador e passagem por referência do array lista com capacidade para 50 utilizadores, chamada da estrutura UTILIZADOR com apontador e passagem por referência e da variavel u 
	int escolha = 1, cont; //declaração de variaveis escolha e contador 
	char username[50], password[50]; //declaração das strings username e password
	
	FILE *fp; //declaração do ficheiro fp
  	fp = fopen("login.dat", "rb"); //abertura do ficheiro binário para leitura

	
	while(escolha){//estrutura de controlo while 
		printf("Introduza o seu username: "); //impressão da frase
		scanf("%s", username); //leitura do username
		printf("Introduza a sua password: "); //impressão da frase
		scanf("%s", password); //leitura da password
  							
		for(cont = 0; cont < lista->nrUtilizadores; cont++) //estrutura de controlo for com inicialização, condição do ciclo e com incremento
			if(strcmp(username, lista->lista[cont].username) == 0){ //estrutura condicional if para verificação de uma comparação de strings se o username é igual ao que se encontra na lista de Utilizadores
				escolha = 0; //escolha 0 procede à aceitação da condição
				break; //causa a saída imediata do ciclo if
						}
		if(escolha == 1){ //estrutura condicional if else onde não se verifica a compraração das strings
			puts("Username nao existe!"); //impressão da frase
			continue; //ignora as restantes instruções dentro do corpo do ciclo if e solicita novo username
		}else{ //estrutura condicional if else 
			if(strcmp(password, lista->lista[cont].password) == 0){ //estrutura if para verificação de uma comparação de strings se a password é igual ao que se encontra na lista de Utilizadores
				puts("Logado com sucesso!"); //impressão da frase
				*u =  lista->lista[cont]; //apontador u* com passagem de parametros para a lista que por sua vez atribui novo valor à lista
				escolha = 0; //escolha 0 procede à aceitação da condição
			}else{ //estrutura condicional if else 
				puts("Password Incorreta!"); //impressão da frase
				escolha = 1; //não se verifica a compraração de strings
				continue; //ignora as restantes instruções dentro do corpo do ciclo if e solicita nova password
			}
		}
	}
}

//função para entrar como aministrador
int entrarAdmin(){
	fflush(stdin);
	char admin[30];
	static char password[5]; 
	int a, i, escolha;
	printf("\nIntroduza a username de administrador\n");
	scanf("%s",&admin);
	if(strcmp(admin,"rede-social")==0)
	{ puts("\nUsername de administrador verificado!\n");
	printf("\nIntroduza a senha de administrador\n");
	for(i=0;i<5;i++){
	password[i]=getch();
	if(password[i]=='\r') {break;
	}else
	printf("*");
	}
	if(strcmp(password,"12345")==0){
		system("cls");
		puts("\n\tSessao de administrador\n\n\n1. Ver total de utilizadores registados:\n\n2. Ver utilizador com mais amigos:\n\n3. Ver utilizador com mais publicacoes:\n\n4. Eliminar utilizador registado:\n\n5. Eliminar publicacao:\n\n6. Logout");
		printf("\n\nResposta: ");
		scanf("%d", &escolha);
		switch (escolha){
		case 1 :
		break;
		case 2 :
		break;
		case 3 :
		break;
		case 4 :
		break;
		case 5 :
		break;
		case 6 :
		break;
	}
	}else{
	puts("Sem acesso!"); a=0;}
	return a;
	}
}
