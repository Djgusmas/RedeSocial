/* Procedemos � utiliza��o header files para simplificar a contru��o do c�digo pelos v�rios elementos do grupo.
Para alem do apresentado, simplificou a dete��o e corre��o de erros */


//defini��o de estruturas relacionadas com os utilizadores e com os amigos
//defini��o da struct de data
typedef struct{
	int dia, mes, ano;
}DATAN;

//defini��o da struct de utilizador
typedef struct{
    char username[20], password[50], nome[50], email[100], telefone[9+1];
    DATAN dataNascimento;
    int nrPublicacoes;
    //int nivel; //criar o n�vel de acesso
    //int amigos [100]; 
}UTILIZADOR;

//defini��o da struct de amigos
typedef struct{
	UTILIZADOR u;
	UTILIZADOR lista[100];
	int nrAmigos;
}AMIGOS;

//defini��o da struct de Lista de utilizadores
typedef struct{
	UTILIZADOR lista[50];
	int nrUtilizadores;
}UTILIZADORL;

//defini��o da struct de lista de amigos
typedef struct{
	AMIGOS lista[50];
}LISTAAMIGOS;

//prototipos das fun��es utilizadas para melhor intreperta��o do c�digo
void criarUtilizador(UTILIZADOR* u, AMIGOS* lista);
void setUtilizador(UTILIZADOR* u, AMIGOS* lista);
void verUtilizador(UTILIZADOR u);
int existeUtilizador(UTILIZADORL lista, char username[]);
UTILIZADOR getUtilizador(UTILIZADORL lista, char username[]);
void adicionarAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);
void verAmigos(AMIGOS amigos);
void removerAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);
