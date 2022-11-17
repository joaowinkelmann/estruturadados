#include <stdio.h>
#include <conio.h>

//define o numero maximo de vertices
#define MAX_NUM_VERT 30
#define MAX_DIST 9999

struct no{
	int vertice;
	int peso;
	no *prox;
};

int flag = 0;
int numVertices = 0;
int vInicial = 0;
int distVertice[MAX_NUM_VERT];
int pai[MAX_NUM_VERT];
no* lista_adj[MAX_NUM_VERT];
no* lista_arestas;

void inicializa_grafo(no* adj[]);
void insere_adjacente(no* adj[], int v, int sucessor, int peso);
void dsaloca_grafo(no* adj[], int n);
void ler_grafo(char caminho[100]);
void imprime_grafo(no* adj[], int n);

void menorDist(no* adj[], int n, int inicio);
void inicializaLista(no **lista);
void mudarEstimativa(no *lista, int v, int num);
void removerMenor(no **lista);
void removeVertice(no **lista, int v);
int retornaMenor(no* *lista);
void print_path(int s);

int main(){
	inicializa_grafo(lista_adj);
	ler_grafo("grafo1.txt");
	if(flag==1){
		printf("\nGrafo Invalido - Vertice negativo");
	}
	
	imprime_grafo(lista_adj, numVertices);
	
	menorDist(lista_adj, numVertices, vInicial);
	
	desaloca_grafo(lista_adj, numVertices);
	
	getch();
	
	return 0;
}

