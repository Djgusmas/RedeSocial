#include <stdio.h>
#include <time.h>
#include "Outros.h"

//prototipos das fun��es utilizadas para melhor intreperta��o do c�digo;
void definirHora(DATA* d); // fun��o para defini��o da data e a hora do sistema;
void login(UTILIZADORL* lista, UTILIZADOR* u); //fun��o para defini��o do login;
int entrarAdmin();

//fun��o para defini��o da data e a hora do sistema;
void definirHora(DATA* d){ //chamada da estrutura data com apontador e passagem por refer�ncia, chamada da variavel d
	time_t t = time(NULL); //data e hora do sistema 
	struct tm tm = *localtime(&t); //estrutura da data e hora do sistema 
	
	d->ano = tm.tm_year + 1900; //atribui��o do valor de d a ano atrav�s do operador seta para o valor de tm.tm_year + 1900 (ano do sistema)
	d->mes = tm.tm_mon + 1; //atribui��o do valor de d a mes atrav�s do operador seta para o valor de tm.tm_mon + 1 (mes do sistema)
	d->dia = tm.tm_mday; //atribui��o do valor de d a mes atrav�s do operador seta para o valor de tm.tm_mday (dia do sistema)
	d->hora = tm.tm_hour; //atribui��o do valor de d a mes atrav�s do operador seta para o valor de tm.tm_hour (hora do sistema)
	d->minuto = tm.tm_min; //atribui��o do valor de d a mes atrav�s do operador seta para o valor de tm.tm_min (minuto do sistema)
	d->segundo = tm.tm_sec; //atribui��o do valor de d a mes atrav�s do operador seta para o valor de tm.tm_sec (segundo do sistema)
}

//fun��o para defini��o do login
void login(UTILIZADORL* lista, UTILIZADOR* u){ //chamada da estrutura UTILIZADORL com apontador e passagem por refer�ncia do array lista com capacidade para 50 utilizadores, chamada da estrutura UTILIZADOR com apontador e passagem por refer�ncia e da variavel u 
	int escolha = 1, cont; //declara��o de variaveis escolha e contador 
	char username[50], password[50]; //declara��o das strings username e password
	
	FILE *fp; //declara��o do ficheiro fp
  	fp = fopen("login.dat", "rb"); //abertura do ficheiro bin�rio para leitura

	
	while(escolha){//estrutura de controlo while 
		printf("Introduza o seu username: "); //impress�o da frase
		scanf("%s", username); //leitura do username
		printf("Introduza a sua password: "); //impress�o da frase
		scanf("%s", password); //leitura da password
  							
		for(cont = 0; cont < lista->nrUtilizadores; cont++) //estrutura de controlo for com inicializa��o, condi��o do ciclo e com incremento
			if(strcmp(username, lista->lista[cont].username) == 0){ //estrutura condicional if para verifica��o de uma compara��o de strings se o username � igual ao que se encontra na lista de Utilizadores
				escolha = 0; //escolha 0 procede � aceita��o da condi��o
				break; //causa a sa�da imediata do ciclo if
						}
		if(escolha == 1){ //estrutura condicional if else onde n�o se verifica a comprara��o das strings
			puts("Username nao existe!"); //impress�o da frase
			continue; //ignora as restantes instru��es dentro do corpo do ciclo if e solicita novo username
		}else{ //estrutura condicional if else 
			if(strcmp(password, lista->lista[cont].password) == 0){ //estrutura if para verifica��o de uma compara��o de strings se a password � igual ao que se encontra na lista de Utilizadores
				puts("Logado com sucesso!"); //impress�o da frase
				*u =  lista->lista[cont]; //apontador u* com passagem de parametros para a lista que por sua vez atribui novo valor � lista
				escolha = 0; //escolha 0 procede � aceita��o da condi��o
			}else{ //estrutura condicional if else 
				puts("Password Incorreta!"); //impress�o da frase
				escolha = 1; //n�o se verifica a comprara��o de strings
				continue; //ignora as restantes instru��es dentro do corpo do ciclo if e solicita nova password
			}
		}
	}
}

//fun��o para entrar como aministrador
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
