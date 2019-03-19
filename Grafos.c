/* Implementação de Grafos em uma matríz
		O sistema conta com uma função de alocação, criação,
		inserção, remoção	e impressão do mesmo.

*/
#include <stdlib.h>
#include <stdio.h>

typedef struct grafo{
	int V;//Vértices
	int E;//Arestas
	int **adj;//
}Grafo;

/*
Aloca a matriz na memória, a preenche com um valor.

R = row = Número de Vértices;
C = collum = Número de Arestas;
val = valor salvo na matriz vazia
*/
int **alocaMatrizAdj(int r, int c, int val){
	int i, j;
	int **m = (int**) malloc(r* sizeof(int*));
	for(i=0; i<r; i++)
		m[i] = (int*) malloc(c* sizeof(int));
	for(i=0; i<r; i++)
		for(j=0; j<c; j++)
			m[i][j] = val;
	return m;
}

/*
Cria
*/
Grafo *criaGrafo(int V){
	Grafo *G = malloc(sizeof(Grafo));
	G->V = V;
	G->E = 0;
	G->adj = alocaMatrizAdj(V,V,0);

	return G;
}

/*
Dado um grafo G, a função insere uma aresta dado o valor V e W.
*/
void insereAresta(Grafo *G, int v, int w){
	if( v != w && G->adj[v][w] == 0 ){
		G->adj[v][w] = 1;
		G->adj[w][v] = 1;
		G->E++;
	}
}

/*
Dado um grafo G, a função remove uma aresta dado o valor V e W.
*/
void removeAresta(Grafo *G, int v, int w){
	if(G->adj[v][w] == 1 ){
		G->E--;
		G->adj[v][w] = 0;
		G->adj[w][v] = 0;
	}
}

void imprimeGrafo(Grafo *G){
	printf("O seu grafo atual: \n" );
	int v,w;
	for(v=0; v < G->V; v++){
		printf("%2d: ",v);
		for(w=0; w < G->V; w++)
			if(G->adj[v][w]==1) printf("%2d", w);
		printf("\n");
	}
	printf("\n" );
}

void imprimeMatriz(Grafo *G){
	// TODO: Implementar o código de implementar a matriz

}

int main(int argc, char const *argv[]) {
	int V, v, w, resp=1;
	printf("Este código tem como objetivo transcrever um grafo para sua representação em forma em forma de matriz.\n");
	printf("Primeiro deve ser criado o grafo, quantos vertices contém seu grafo?\n");
	scanf("%d", &V);

	Grafo *G = criaGrafo(V);

  do {
		imprimeGrafo(G);
		printf("Selecione uma opção\n");
		printf("1 - Inserir Arestas\n");
		printf("2 - Remover Arestas\n");
		printf("0 - Sair\n");

		scanf("%d",&resp);

		switch (resp) {
			case 1:
				// Código do primeiro Case
				printf("Em qual vértice você deseja criar uma aresta?\n");
				scanf("%d", &v);
				printf("Em qual aresta o vértice %d se ligar?\n", v );
				scanf("%d", &w);

				insereAresta(G, v, w);
				break;

			case 2:
				// Código do primeiro Case
				printf("Em qual vértice você deseja remover uma aresta?\n");
				scanf("%d", &v);
				printf("Em qual aresta o vértice %d se ligar?\n", v );
				scanf("%d", &w);

				removeAresta(G, v, w);
				break;

			default:
				break;
		}

	}while(resp!=0);

	return 0;
}
