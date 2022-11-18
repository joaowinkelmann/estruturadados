#include <stdio.h> 
#include <conio.h> 

//numero maximo de vertices 
#define  MAX_NUM_VERT   30 
#define  MAX_DIST       9999  

//entrada da lista de adjacencias 
struct no { 
    int vertice; 
    int peso; 
    no *prox; 
}; 

// variaveis globais que representam o grafo 
int flag=0; 
int numVertices = 0; 
int vInicial = 0; 
int distVertice[MAX_NUM_VERT]; 
int pai[MAX_NUM_VERT]; 
no* lista_adj[MAX_NUM_VERT]; 
no* lista_arestas; 


// prototipos das funcoes auxiliares 
void inicializa_grafo(no* adj[]); 
void insere_adjacente(no* adj[], int v, int sucessor, int peso); 
void desaloca_grafo(no* adj[], int n); 
void ler_grafo(char caminho[100]); 
void imprime_grafo(no* adj[], int n); 

void menorDist(no* adj[], int n, int inicio); 
void inicializaLista(no **lista); //cria lista com todos os vertices do grafo 
void mudarEstimativa(no *lista, int v, int num); 
int removerMenor(no **lista); //retorna o vertice com menor dist. 
void removeVertice(no **lista, int v); 
int retornaMenor(no* *lista); 
void print_path(int s); 


int main() { 
    //inicializa o grafo 
    inicializa_grafo(lista_adj); 
    //le grafo a partir do arquivo 
    ler_grafo("grafo1.txt"); 
    if(flag==1) { 
        printf("\nGrafo Invalido - Vertice negativo"); 
    } 
    //imprime as listas de adjacencia do grafo 
    imprime_grafo(lista_adj, numVertices); 

    //Algoritmo Dijikstra 
    menorDist(lista_adj, numVertices, vInicial); 

    //libera memória 
    desaloca_grafo(lista_adj, numVertices); 

    //espera digitar um caracter 
    getch(); 

    return 0; 
} 

void menorDist(no* adj[], int n, int inicio) { 
    //n = numero de vertices 
    //inicio = vertice inicial 
    int u, menor = -1; 
    int menorV; 
    no *aux; 
    char printpath[50]; 

    //Coloca todos os vertices do grafo numa lista 
    inicializaLista(&lista_arestas); 

    distVertice[inicio] = 0; 
    mudarEstimativa(lista_arestas, inicio, 0); 
    pai[0] = -1; 

    printf("\nDjikstra\n"); 

    while(lista_arestas) { 
        u = removerMenor(&lista_arestas); 

        aux = adj[u]; 
        printf("[%d] - ", u); 
        while(aux) { 
            if(distVertice[aux->vertice] > (distVertice[u] + aux->peso)) { 
                distVertice[aux->vertice] = distVertice[u] + aux->peso; 
             
                pai[aux->vertice] = u; 
                mudarEstimativa(lista_arestas, aux->vertice, distVertice[aux->vertice]); 
                menor = distVertice[aux->vertice]; 

            } 
            aux = aux->prox; 
        } 
        print_path(retornaMenor(&lista_arestas));         
        printf("\n"); 
    } 
    printf("\nMenor distancia: %d ", menor); 
} 

void print_path(int s) { 
    if(s >= 0) { 
         if(pai[s] == -1) { 
             printf("%d ", s); 
         } else { 
             print_path(pai[s]); 
             printf("-> %d", s); 
        }    
    } 
} 
//Criar lista com todos os vertices 
void inicializaLista(no* *lista) { 
    no* novo; 
    for (int i = 0; i < numVertices; i++)  { 
        novo = new no; 
        novo->vertice = i; 
        novo->peso = distVertice[i]; 
        novo->prox = *lista; 
        *lista = novo; 
    }    
} 
//Retorna menor 
int retornaMenor(no* *lista) { 
    int menor = -1; 
    int peso = MAX_DIST; 
    no *aux = *lista; 
    while(aux) { 
        if(aux->peso < peso) { 
            menor = aux->vertice; 
            peso = aux->peso; 
        } 
        aux = aux->prox; 
    } 
    return menor; 
} 
//Percorre a fila e remove/retorna o indice do menor vertice 
int removerMenor(no* *lista) { 
    int menor = -1; 
    int peso = MAX_DIST; 
    no *aux = *lista; 
    while(aux) { 
        if(aux->peso < peso) { 
            menor = aux->vertice; 
            peso = aux->peso; 
        } 
        aux = aux->prox; 
    } 
    removeVertice(lista, menor); 
    return menor; 
} 

void removeVertice(no **lista, int v) { 
    no *aux, *ant; 
    aux = *lista; 
    if((*lista)->vertice == v) { 
        *lista = (*lista)->prox; 
        delete aux; 
    } else { 
        while(aux->prox) { 
            ant = aux; 
            if(aux->prox->vertice == v) { 
                aux = aux->prox; 
                ant->prox = aux->prox; 
                delete aux; 
                return; 
            } 
            aux = aux->prox; 
        } 
    } 
} 
//Altera distancia do vertice indicado na lista de arestas 
void mudarEstimativa(no *lista, int v, int num) { 
    while(lista) { 
        if(lista->vertice == v) lista->peso = num; 
        lista = lista->prox; 
    } 
} 
// Inicializa as listas de adjacencias. 
void inicializa_grafo(no* adj[]) { 
    for (int i = 0; i < MAX_NUM_VERT; i++)  { 
        adj[i] = NULL; 
        distVertice[i] = MAX_DIST; 
        pai[i] = -1; 
    } 
    lista_arestas = NULL; 
} 
// Insere o vertice "sucessor" no final da lista de adjacencias  
// de "v", ou seja, insere o arco (v -> sucessor) 
void insere_adjacente(no *adj[], int v, int sucessor, int peso) { 
    no* aux; 
    no* novo; 
    novo = new no; 
    novo->vertice = sucessor; 
    novo->peso = peso; 
    novo->prox = NULL; 

    if (adj[v] == NULL) { 
        // se for o primeiro elemento inserido na lista,  
        // a cabeça da lista passa a apontar para ele 
        adj[v] = novo; 
    } else { 
        // se nao for o primeiro, percorre a lista inteira 
        // e insere o elemento após a ultima posição 
        aux = adj[v]; 
        while (aux->prox != NULL) 
            aux = aux->prox; 
        aux->prox = novo; 
    } 
} 
// Le um grafo a partir do arquivo passado por parametro 
void ler_grafo(char caminho[100]) { 
    FILE* arquivo; 
    int v, sucessor, peso; 

    arquivo = fopen(caminho, "r"); 

    if (arquivo == NULL) { 
        printf("Erro: nao foi possivel abrir o arquivo.\n"); 
    } else { 
        //le a primeira linha         
        fscanf(arquivo, "%d", &numVertices);  //numero de vertices 
        fscanf(arquivo, "%d", &vInicial);     //vertice inicial 

        //le cada uma das demais linhas 
        for (v = 0; v < numVertices; v ++) { 
            fscanf(arquivo, "%d", &sucessor); 
            fscanf(arquivo, "%d", &peso); 

            while (sucessor != -1 && peso != -1) { 
                if(peso < 0) { 
                    fclose(arquivo); 
                    flag=1; //GRAFO INVALIDO - Vertices negativos 
                    return; //Abortar programa 
                } 
                insere_adjacente(lista_adj, v, sucessor, peso);  
                fscanf(arquivo, "%d", &sucessor); 
                fscanf(arquivo, "%d", &peso); 
            } 
        } 
        fclose(arquivo); 
    } 
}    
// Imprime as listas de adjacencias dadas 
void imprime_grafo(no* adj[], int n) { 
    int i; 
    no* aux; 
    for (i = 0; i < n; i++) { 
        //imprime o vertice 
        printf("Adj[%d] - ", i); 
        //imprime os sucessores do vertice 
        aux = adj[i]; 
        while(aux != NULL) { 
            printf("%d (%d) -> ", aux->vertice, aux->peso); 
            aux = aux->prox; 
        } 
        printf("\n"); 
    } 
} 
// Percorre as listas desalocando memória 
void desaloca_grafo(no* adj[], int n) { 
    int i; 
    no* anterior; 
    no* atual; 
    for (i = 0; i < n; i++) { 
        atual = adj[i]; 
        while (atual != NULL) { 
            anterior = atual; 
            atual = atual->prox; 
            delete anterior; 
        } 
    } 
} 
