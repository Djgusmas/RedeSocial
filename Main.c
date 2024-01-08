#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Outros.h"




main(){
	int escolha, escolha1, cont; //declara��o de variaveis
	UTILIZADORL listaUtilizadores; //declara��o de variaveis das fun��es utilizador
	listaUtilizadores.nrUtilizadores = 0; //declara��o de variaveis das fun��es utilizador
	LISTAAMIGOS listaAmigos; //declara��o de variaveis das fun��es utilizador
	LISTAPUBLICACOES listaPublicacoes; //declara��o de variaveis das fun��es publica��es
	listaPublicacoes.nrpublicacoes = 0; //declara��o de variaveis das fun��es publica��es
	
	UTILIZADOR u; //declara��o de variaveis das fun��es utilizador
	AMIGOS amigos; //declara��o de variaveis das fun��es utilizador
	PUBLICACAO pub; //declara��o de variaveis das fun��es publica��es
	
	

	//defini��o da estrutura while do menu inicial da rede social
	while(1){
		system("cls"); //limpeza do ecr�
		puts("\n\t\tMenu Inicial\n\n\n1. Iniciar sessao enquanto administrador:\n\n2. Iniciar sessao enquanto utilizador registado:\n\n3. Iniciar sessao de convidado:\n\n4. Efetue o registo:\n\n5. Sair");
		printf("\n\nResposta: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			case 1://login de administrador e chamada da fun��o entrarAdmin
				entrarAdmin();
				break;
			case 2://login atrav�s da chamada da fun��o login
				login(&listaUtilizadores, &u);	
				for(cont = 0; cont < listaUtilizadores.nrUtilizadores; cont++)
					if(strcmp(listaAmigos.lista[cont].u.username, u.username) == 0)
						amigos = listaAmigos.lista[cont];
				break;
			case 3://login de convidado e strcpy do convidado
				strcpy(u.username, "convidado");
				break;
			case 4://cria��o do utilizador atrav�s da chamada da fun��o criarUtilizador
				criarUtilizador(&u, &amigos);
				listaUtilizadores.lista[listaUtilizadores.nrUtilizadores] = u; //coloca��o do utilizador na lista que se encontra a 0
				listaAmigos.lista[listaUtilizadores.nrUtilizadores] = amigos; //coloca��o do utilizador na lista de amigos
				listaUtilizadores.nrUtilizadores++;
				break;
			case 5:
				exit(1);
			default:
				puts("Opcao invalida!");
				continue;

		}
		//defini��o da estrutura if while para convidado e utilizador registado
		if(strcmp(u.username, "convidado") != 0){
			while(1){
				int x = 0;
				system("cls"); //limpeza do ecr�
				puts("\n\tSessao de utilizador registado\n\n\n1. Criar publicacoes\n\n2. Ver publicacoes\n\n3. Editar perfil\n\n4. Ver perfil\n\n5. Ver amigos\n\n6. Adicionar amigo\n\n7. Remover amigos\n\n8. Encerrar sessao");
				printf("\n\nResposta: ");
				scanf("%d", &escolha);
				
				switch(escolha){
					case 1://cria��o de publica��es e chamada das fun��es criarPublicacao e listaPublicacoes
						criarPublicacao(&pub, &u);
						listaPublicacoes.lista[listaPublicacoes.nrpublicacoes] = pub;
						listaPublicacoes.nrpublicacoes++;
						break;
					case 2://ver publica��es e chamada da fun��o verPublicacao
						verPublicacao(listaPublicacoes, listaUtilizadores, u, amigos);
						system("pause");
						break;
					case 3://edi��o do perfil e chamada da fun��o setUtilizador
						setUtilizador(&u, &amigos);
						for(cont = 0; cont < listaUtilizadores.nrUtilizadores; cont++)
							if(strcmp(listaUtilizadores.lista[cont].username, u.username) == 0)
								listaUtilizadores.lista[cont] = u;
						break;
					case 4://ver perfil e chamada da fun��o verUtilizador
						verUtilizador(u);
						break;
					case 5://ver amigos e chamada da fun��o verAmigos
						verAmigos(amigos);
						break;
					case 6://ver amigos e chamada da fun��o adicionarAmigo
						adicionarAmigo(&listaUtilizadores, &listaAmigos, &amigos, u);
						for(cont = 0; cont < listaUtilizadores.nrUtilizadores; cont++)
							if(strcmp(listaAmigos.lista[cont].u.username, u.username) == 0)
								listaAmigos.lista[cont] = amigos;
						break;
					case 7://ver amigos e chamada da fun��o removerAmigo
						removerAmigo(&listaUtilizadores, &listaAmigos, &amigos, u);
						for(cont = 0; cont < listaUtilizadores.nrUtilizadores; cont++)
							if(strcmp(listaAmigos.lista[cont].u.username, u.username) == 0)
								listaAmigos.lista[cont] = amigos;
						break;
					case 8:
						x = 1;
						break;
					default:
						puts("Opcao invalida!");
				}
				if(x)
					break;
			}	
		}else{//defini��o da estrutura else while para sess�o convidado
			while(1){
				int y = 0;
				system("cls"); //limpeza do ecr�
				puts("\n\tSessao de convidado\n\n\n1. Ver publicacoes\n\n2. Logout");
				printf("\n\nResposta: ");
				scanf("%d", &escolha);
				
				switch(escolha){
					case 1://ver publica��es e chamada da fun��o verPublicacao enquanto convidado
						verPublicacao(listaPublicacoes, listaUtilizadores, u, amigos);
						system("pause");
						break;
					case 2:
						y = 1;
						break;
					default:
						puts("Opcao invalida!");
				}
				if(y)
					break;	
			}
			
		}
	}
}
