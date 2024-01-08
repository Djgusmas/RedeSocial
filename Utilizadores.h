/* Procedemos à utilização header files para simplificar a contrução do código pelos vários elementos do grupo.
Para alem do apresentado, simplificou a deteção e correção de erros */


//definição de estruturas relacionadas com os utilizadores e com os amigos
//definição da struct de data
typedef struct{
	int dia, mes, ano;
}DATAN;

//definição da struct de utilizador
typedef struct{
    char username[20], password[50], nome[50], email[100], telefone[9+1];
    DATAN dataNascimento;
    int nrPublicacoes;
    //int nivel; //criar o nível de acesso
    //int amigos [100]; 
}UTILIZADOR;

//definição da struct de amigos
typedef struct{
	UTILIZADOR u;
	UTILIZADOR lista[100];
	int nrAmigos;
}AMIGOS;

//definição da struct de Lista de utilizadores
typedef struct{
	UTILIZADOR lista[50];
	int nrUtilizadores;
}UTILIZADORL;

//definição da struct de lista de amigos
typedef struct{
	AMIGOS lista[50];
}LISTAAMIGOS;

//prototipos das funções utilizadas para melhor intrepertação do código
void criarUtilizador(UTILIZADOR* u, AMIGOS* lista);
void setUtilizador(UTILIZADOR* u, AMIGOS* lista);
void verUtilizador(UTILIZADOR u);
int existeUtilizador(UTILIZADORL lista, char username[]);
UTILIZADOR getUtilizador(UTILIZADORL lista, char username[]);
void adicionarAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);
void verAmigos(AMIGOS amigos);
void removerAmigo(UTILIZADORL* listaUtilizadores, LISTAAMIGOS* listaAmigos, AMIGOS* amigos, UTILIZADOR user);
