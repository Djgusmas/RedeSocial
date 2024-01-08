#include "Utilizadores.h"
#include <time.h>

/* Procedemos � utiliza��o header files para simplificar a contru��o do c�digo pelos v�rios elementos do grupo.
Para alem do apresentado, simplificou a dete��o e corre��o de erros */



//defini��o de estruturas relacionadas com as publica��es
typedef struct {
	int dia, mes, ano, hora, minuto, segundo;
}DATA;

//defini��o da struct de publica��o
typedef struct{
	UTILIZADOR u;
	char texto[150];
	DATA data;
	int privacidade; // 0 - publico 1 - reservado 2 - privado
	//int amizade; //
}PUBLICACAO;

//defini��o da struct de lista de publica��es
typedef struct{
	PUBLICACAO lista[50];
	int nrpublicacoes;
}LISTAPUBLICACOES;

//prototipos das fun��es utilizadas para melhor intreperta��o do c�digo
void criarPublicacao(PUBLICACAO* p, UTILIZADOR* u); // fun��o para criar de publica��o
void verPublicacao(LISTAPUBLICACOES lista, UTILIZADORL listaUtilizadores, UTILIZADOR u, AMIGOS amigos);// fun��o para ver uma publica��o
