#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "Utilizadores.h"

//prototipos das funções utilizadas para melhor intrepertação do código
void criarUtilizador(UTILIZADOR* u, AMIGOS* lista);
void setUtilizador(UTILIZADOR* u, AMIGOS* lista);
void verUtilizador(UTILIZADOR u);
int existeUser(UTILIZADORL lista, char username[]);
UTILIZADOR getUtilizador(UTILIZADORL lista, char username[]);
void adicionarAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);
void verAmigos(AMIGOS amigos);
void removerAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);

//função para criar utilizador
void criarUtilizador(UTILIZADOR* u, AMIGOS* lista){
	char dn[10+1];
	FILE *fp;
  	fp = fopen("login.dat", "wb");
	
	
	fflush(stdin);
    printf("Introduza o seu nome: ");
    gets(u->nome);
    printf("Introduza o seu email: ");
    gets(u->email);
    printf("Introduza o seu telefone: ");
    gets(u->telefone);
    printf("Introduza a sua data de nascimento ('dd/mm/aaaa'): ");
    scanf("%s", dn);
	fflush(stdin);    
    printf("Introduza o seu username: ");
    gets(u->username);
    printf("Introduza a sua password: ");
    gets(u->password);
    
    char dia[3] = {dn[0], dn[1]};
    char mes[3] = {dn[3], dn[4]};
    char ano[5] = {dn[6], dn[7], dn[8], dn[9]};
    
    u->dataNascimento.dia = atoi(dia);//passagem de string para inteiro
    u->dataNascimento.mes = atoi(mes);
    u->dataNascimento.ano = atoi(ano);
    u->nrPublicacoes = 0;
    lista->nrAmigos = 0;
    lista->u = *u;
    puts("Utilizador criado com Sucesso!");
    fwrite(&u, 1, sizeof(UTILIZADOR), fp);
  	fclose(fp);
    system("pause");
}
//função para editar o utilizador
void setUtilizador(UTILIZADOR* u, AMIGOS* lista){
	int escolha;
	int escolha2;
	char dn[10+1];
	int x;
	FILE *fp;
  	fp = fopen("login.dat", "wb");
	
	do{
		x = 0;
		system("cls");
		fflush(stdin);
		puts("\n\tMenu de alteracao de dados\n\n");
		puts("\n\tO que pretende editar?\n\n1. Nome\n\n2. Email\n\n3. Telefone\n\n4. Data de Nascimento\n\n5. Username\n\n6. Password");
		printf("\n\nResposta: ");
		scanf("%d", &escolha);
		fflush(stdin);
		
		switch(escolha){
			case 1:
				printf("Introduza novo nome: ");
				gets(u->nome);
				puts("Nome mudado com sucesso!");
				break;
			case 2:
				printf("Introduza novo email: ");
				gets(u->email);
				puts("Email mudado com sucesso!");
				break;
			case 3:
				printf("Introduza novo número de telefone: ");
				gets(u->telefone);
				puts("Numero de telefone mudado com sucesso!");
				break;
			case 4:
				printf("Introduza nova data de nascimento: ");
				scanf("%s", dn);
				
				char dia[3] = {dn[0], dn[1]};
			    char mes[3] = {dn[3], dn[4]};
			    char ano[5] = {dn[6], dn[7], dn[8], dn[9]};
			    
			    u->dataNascimento.dia = atoi(dia);
			    u->dataNascimento.mes = atoi(mes);
			    u->dataNascimento.ano = atoi(ano);
			    puts("Data de Nascimento mudada com sucesso!");
				break;
			case 5:
				printf("Introduza novo username: ");
				gets(u->username);
				puts("Username mudado com sucesso!");
				break;
			case 6:
				printf("Introduza nova password: ");
				gets(u->password);
				puts("Password mudada com sucesso!");
				break;
			default:
				puts("Introduza opcao valida!");
				x = 1;
		}
		if(x == 0){
			int y = 0;
			do{
				puts("\n\tPretende continuar a editar?\n\n1. Sim\n\n2. Nao");
				printf("\n\nResposta: ");
				scanf("%d", &escolha2);
				
				switch(escolha2){
					case 1:
						x = 1;
						break;
					case 2:
						fwrite(&u, 1, sizeof(UTILIZADOR), fp);
  						fclose(fp);
						break;
					default:
						puts("Introduza opcao valida!");
						y = 1;
				}
			}while(y);
			lista->u = *u;	
		}
	}while(x);
}
//função para ver perfil de utilizador
void verUtilizador(UTILIZADOR u){
	printf("\n\tPerfil de utilizador\n\n\nNome: %s\n\nUsername: %s\n\nEmail: %s\n\nTelefone: %s\n\nData de Nascimento: %02d/%02d/%04d\n\n", u.nome, u.username, u.email, u.telefone, u.dataNascimento.dia, u.dataNascimento.mes, u.dataNascimento.ano);
	system("pause");
}

//função para verificar a existencia de um utilizador
int existeUtilizador(UTILIZADORL lista, char username[]){
	int cont;
	
	for(cont = 0; cont < lista.nrUtilizadores; cont++)
		if(strcmp(lista.lista[cont].username, username) == 0)
			return 1;
	return 0;
}
//função para selecionar um utilizador
UTILIZADOR getUtilizador(UTILIZADORL lista, char username[]){
	int cont;
	
	for(cont = 0; cont < lista.nrUtilizadores; cont++)
		if(strcmp(lista.lista[cont].username, username) == 0)
			return lista.lista[cont];
}
//função para adicionar amigo
void adicionarAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user){
	char username[50];
	int cont;

	printf("Introduza o username que quer adicionar: ");
	scanf("%s", username);
	
	if(existeUtilizador(*listaUtilizadores, username)){
		UTILIZADOR u = getUtilizador(*listaUtilizadores, username);
		amigos->lista[amigos->nrAmigos] = u;
		amigos->nrAmigos++;
		for(cont = 0; cont < listaUtilizadores->nrUtilizadores; cont++)
			if(strcmp(listaAmigos->lista[cont].u.username, username) == 0){
				listaAmigos->lista[cont].lista[listaAmigos->lista[cont].nrAmigos] = user;
				listaAmigos->lista[cont].nrAmigos++;
			}	
		printf("Utilizador adicionado com sucesso!\n");
	}else{
		printf("Utilizador nao existente!\n");
	}
	system("pause");
}
//função para ver amigo
void verAmigos(AMIGOS amigos){
	int cont;
	
	for(cont = 0; cont < amigos.nrAmigos; cont++)
		printf("%d. %s\n", cont+1, amigos.lista[cont].username);
	system("pause");
}
//função para remover amigo
void removerAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user){
	int cont, cont1, cont2, escolha;
	char username[50];

	for(cont = 0; cont < amigos->nrAmigos; cont++)
		printf("%d. %s\n", cont+1, amigos->lista[cont].username);
	
	printf("Introduza o numero do utilizador que deseja remover: ");
	scanf("%d", &escolha);
	
	if(escolha < amigos->nrAmigos || escolha > amigos->nrAmigos){
		puts("Opcao invalida!");
		system("pause");
		return;
	}
	strcpy(username, amigos->lista[escolha-1].username);
	
	for(cont = escolha-1; cont < amigos->nrAmigos; cont++)
		amigos->lista[cont] = amigos->lista[cont+1];
	amigos->nrAmigos--;
	
	for(cont = 0; cont < listaUtilizadores->nrUtilizadores; cont++)
		if(strcmp(listaAmigos->lista[cont].u.username, username) == 0)
			for(cont1 = 0; cont1 < listaAmigos->lista[cont].nrAmigos; cont1++)
				if(strcmp(listaAmigos->lista[cont].lista[cont1].username, user.username) == 0){
					for(cont2 = cont1; cont2 < listaAmigos->lista[cont].nrAmigos; cont2++)
						listaAmigos->lista[cont].lista[cont2] = listaAmigos->lista[cont].lista[cont2+1];
					listaAmigos->lista[cont].nrAmigos--;
					break;
				}
	system("pause");
}


