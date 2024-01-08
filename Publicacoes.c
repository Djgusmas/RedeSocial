#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include "Publicacoes.h"

//prototipos das funções utilizadas para melhor intrepertação do códigos
void criarPublicacao(PUBLICACAO* p, UTILIZADOR* u); // função para criar de publicação
void verPublicacao(LISTAPUBLICACOES lista, UTILIZADORL listaUtilizadores, UTILIZADOR u, AMIGOS amigos); // função para ver uma publicação


// função para criar de publicação
void criarPublicacao(PUBLICACAO* p, UTILIZADOR* u){//chamada das estruturas PUBLICACAO e UTILIZADOR com apontador e passagem por referência, chamada das variaveis p e u
	int x, escolha;
	char texto[125];
  	
	do{
		x = 0;
		fflush(stdin);
		puts("Escreva a sua publicacao");
		gets(texto);
		
		if(strlen(texto) > 150){
			puts("Texto demasiado longo");
			x = 1;
		}else{
			strcpy(p->texto, texto);
			definirHora(&(p->data));
			p->u = *u;
		}
			
	}while(x);
	
	do{
		x = 0;
		fflush(stdin);
		puts("Defina a privacidade da publicacao\n1. Publico\n2. Reservado\n3. Privado");
		printf("Resposta: ");
		scanf("%d", &escolha);
		
		switch(escolha){ //atribuição de privacidade à publicação
			case 1:
				p->privacidade = 0;
				break;
			case 2:
				p->privacidade = 1;
				break;
			case 3:
				p->privacidade = 2;
				break;
			default:
				puts("Opcao invalida!");
				x = 1;
		}
	}while(x);
	puts("Publicacao criada com sucesso!");

}
// função para ver uma publicação
void verPublicacao(LISTAPUBLICACOES lista, UTILIZADORL listaUtilizadores, UTILIZADOR u, AMIGOS amigos){ //chamada das estruturas LISTAPUBLICACOES, UTILIZADORL, UTILIZADOR e AMIGOS e chamada das variaveis das mesmas lista, listaUtilizadores, u e amigos
	int cont, cont1;
	if(strcmp(u.username, "convidado") == 0){
		for(cont = 0; cont < lista.nrpublicacoes; cont++){
			if(lista.lista[cont].privacidade == 0){
				printf("Publicado por: %s\n%s\nHora: %02d/%02d/%04d %02d:%02d:%02d\n\n", lista.lista[cont].u.username, lista.lista[cont].texto, lista.lista[cont].data.dia, lista.lista[cont].data.mes, lista.lista[cont].data.ano, lista.lista[cont].data.hora, lista.lista[cont].data.minuto, lista.lista[cont].data.segundo);
			}
		}
	}else{
		for(cont = 0; cont < lista.nrpublicacoes; cont++){
			switch(lista.lista[cont].privacidade){
				case 0://Publicação com priovacidade publica
					printf("Publicado por: %s\n%s\nHora: %02d/%02d/%04d %02d:%02d:%02d\nEstado: Publico\n\n", lista.lista[cont].u.username, lista.lista[cont].texto, lista.lista[cont].data.dia, lista.lista[cont].data.mes, lista.lista[cont].data.ano, lista.lista[cont].data.hora, lista.lista[cont].data.minuto, lista.lista[cont].data.segundo);
					break;
				case 1://Publicação com priovacidade Reservada
					printf("Publicado por: %s\n%s\nHora: %02d/%02d/%04d %02d:%02d:%02d\nEstado: Reservado\n\n", lista.lista[cont].u.username, lista.lista[cont].texto, lista.lista[cont].data.dia, lista.lista[cont].data.mes, lista.lista[cont].data.ano, lista.lista[cont].data.hora, lista.lista[cont].data.minuto, lista.lista[cont].data.segundo);
					break;
				case 2://Publicação com priovacidade privada
					if(strcmp(lista.lista[cont].u.username, u.username) == 0)
						printf("Publicado por: %s\n%s\nHora: %02d/%02d/%04d %02d:%02d:%02d\nEstado: Privado\n\n", lista.lista[cont].u.username, lista.lista[cont].texto, lista.lista[cont].data.dia, lista.lista[cont].data.mes, lista.lista[cont].data.ano, lista.lista[cont].data.hora, lista.lista[cont].data.minuto, lista.lista[cont].data.segundo);
					for(cont1 = 0; cont1 < amigos.nrAmigos; cont1++){//Publicação com priovacidade privada que amigos podem ver
						if(strcmp(amigos.lista[cont1].username, lista.lista[cont].u.username) == 0)
							printf("Publicado por: %s\n%s\nHora: %02d/%02d/%04d %02d:%02d:%02d\nEstado: Privado\n\n", lista.lista[cont].u.username, lista.lista[cont].texto, lista.lista[cont].data.dia, lista.lista[cont].data.mes, lista.lista[cont].data.ano, lista.lista[cont].data.hora, lista.lista[cont].data.minuto, lista.lista[cont].data.segundo);						
					}
			}
		}
	}
}
