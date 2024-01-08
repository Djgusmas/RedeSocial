#include "Utilizadores.h"
#include <time.h>

/* Procedemos à utilização header files para simplificar a contrução do código pelos vários elementos do grupo.
Para alem do apresentado, simplificou a deteção e correção de erros */



//definição de estruturas relacionadas com as publicações
typedef struct {
	int dia, mes, ano, hora, minuto, segundo;
}DATA;

//definição da struct de publicação
typedef struct{
	UTILIZADOR u;
	char texto[150];
	DATA data;
	int privacidade; // 0 - publico 1 - reservado 2 - privado
	//int amizade; //
}PUBLICACAO;

//definição da struct de lista de publicações
typedef struct{
	PUBLICACAO lista[50];
	int nrpublicacoes;
}LISTAPUBLICACOES;

//prototipos das funções utilizadas para melhor intrepertação do código
void criarPublicacao(PUBLICACAO* p, UTILIZADOR* u); // função para criar de publicação
void verPublicacao(LISTAPUBLICACOES lista, UTILIZADORL listaUtilizadores, UTILIZADOR u, AMIGOS amigos);// função para ver uma publicação
