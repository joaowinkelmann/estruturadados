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
void desaloca_grafo(no* adj[], int n);
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

void menorDist(no* adj[], int n, int inicio){
	//n = numero de vertices
	//inicio = vertice inicial
	int u, menor = -1;
	int menorV;
	no *aux;
	char printpath[50];
	
	inicializaLista(&lista_arestas);
	
	distVertice[inicio] = 0;
	mudarEstimativa(lista_arestas, inicio, 0);
	pai[0] = -1;
	
	printf("\nDjikstra\n");
	
	while(lista_arestas){
		u = removerMenor(&lista_arestas);
		
		aux = adj[u];
		printf("[%d] - ", u);
		while(aux){
			if(distVertice[aux->vertice] > (distVertice[u] + aux->peso)){
				distVertice[aux->vertice] = distVertice[u] +  aux->peso;
				
				pai[aux->vertice] = u;
				mudarEstimativa(lista_arestas, aux->vertice, distVertice[aux->vertice]);
				menor = distVertice[aux->vertice];
			}
			aux = aux->prox;
		}
		print_path(retornaMenor(&lista_arestas));
		printf("\n");
 }
 printf("\nMenor distancia %d", menor);
}

void print_path(int s){
	if(s >= 0){
		if(pai[s] == -1){
			printf("%d", s);
		}
		else{
			print_path(pai[s]);
			printf("-> %d", s);
		}
	}
}

//criar lista com todos os vertices
void inicializaLista(no* *lista){
	no* novo;
	for (int i = 0; i < numVertices; i++){
		novo = new no;
		novo->vertice = i;
		novo->peso = distVertice[i];
		novo->prox = *lista;
		*lista = novo;
	}
}

//retorna menor
int retornaMenor(no* *lista){
	int menor = -1;
	int peso = MAX_DIST;
	no *aux = *lista;
	while(aux){
		if (aux->peso < peso){
			menor = aux->vertice;
			peso = aux->peso;
		}
		aux = aux->prox;
	}
	return menor;
}

//percorre a fila e remove o indice do menor vertice
int removerMenor(no* *lista){
	int menor = -1;
	int peso = MAX_DIST;
	no *aux = *lista;
	while(aux){
		if(aux->peso < peso){
			menor = aux->vertice;
			peso = aux->peso;
		}
		aux = aux->prox;
	}
	removeVertice(lista, menor);
	return menor;
}

void removeVertice(no **lista, int v){
	no *aux, *ant;
	aux = *lista;
	if((*lista)->vertice == v){
		*lista = (*lista)->prox;
		delete aux;
	}
	else{
		while(aux->prox){
			ant = aux;
			if(aux->prox->vertice == v){
				aux = aux->prox;
				ant->prox = aux->prox;
				delete aux;
				return;
			}
			aux = aux->prox;
		}
	}
}

//altera distancia do vertice indicado na lista de arestas
void mudarEstimativa(no *lista, int v, int num){
	while(lista){
		if(lista->vertice == v) lista->peso = num;
		lista = lista->prox;
	}
}

//inicializa as listas de adjacencias
void inicializa_grafo(no* adj[]){
	for(int i = 0; i < MAX_NUM_VERT; i++){
		adj[i] = NULL;
		distVertice[i] = MAX_DIST;
		pai[i] = -1;
	}
	listas_arestas = NULL;
}

//insere o vertice sucessor no final da lista de adjacencias de v, ou seja, insere o arco
void insere_adjacent(no *adj[], int v, int sucessor, int peso){
	no* aux;
	no* novo;
	novo = new no;
	novo->vertice = sucessor;
	novo->peso = peso;
	novo->prox = NULL;
	
	if (adj[v] == NULL){
		//se for o primeiro elemento inserido na lista, a cabeça da lista passa a apontar para ele
		adj[v] = novo;
	}
	else{
		//se nao for o primeiro, percorre a lista interia, e insere o elemento apos a ultima posicao
		aux = adj[v];
		while(aux->prox != NULL){
			aux = aux->prox;
		}	
		aux->prox = novo;
	}
}

//le um grafo a partir do arquivo passado por parametro
void ler_grafo(char caminho[100]){
	FILE * arquivo;
	int v, sucessor, peso;
	
	arquivo = fopen(caminho, "r");
	
	if (arquivo == NULL){
		printf("Erro ao abrir o arquivo\n\n");
	}
	else{
		//le a primeira linha
		fscanf(arquivo, "%d", &numVertices);
		fscanf(arquivo, "%d", &vInicial);
		
		//le cada uma das demais linhas
		for (v = 0; v < numVertices; v++){
			fscanf(arquivo, "%d", &sucessor);
			fscanf(arquivo, "%d", &peso);
			
			while (sucessor != -1 && peso != -1){
				if(peso < 0){
					fclose(arquivo);
					flag = 1; //grafo invalido, vertice com valor negativo
					return;
				}
				insere_adjacente(lista_adj, v, succesor, peso);
				fscanf(arquivo, "%d", sucessor);
				fscanf(arquivo, "%d", peso);
			}
		}
		fclose(arquivo);
	}
}

//imprime as listas de adjacencias dadas
void imprime_grafo(no* adj[], int n){
	int i;
	no* aux;
	
	for (i = 0; i < n; i++){
		//imprime o vertice
		printf("Adj[%d] - ", i);
		//imprime os sucessores do vertice
		aux = adj[i];
		while(aux != NULL){
			printf("%d (%d) -> ", aux->vertice, aux->peso);
			aux = aux->prox;
		}
		printf("\n");
	}
}

//percorre as listas desalocando memoria
void desaloca_grafo(no* adj[], int n){
	int i;
	no* anterior;
	no* atual;
	for(i = 0; i < n; i++){
		atual = adj[i];
		while(atual != NULL){
			anterior = atual;
			atual = atual->prox;
			delete anterior;
		}
	}
}
