typedef struct vertice{
  int no;
  struct vertice *prox;
}Vertice;

typedef struct grafo{
  int V;
  int E;
  Vertice *adj;
}Grafo;

Grafo *criaGrafo(int V){
  Grafo *G= (Grafo *)malloc(sizeof(Grafo));
  G->V = V;
  G->E = 0;
  G->adj = (Vertice *) calloc(V, sizeof(vertice));

  return G;
}

Vertice *novoVertice(int x){
  Vertice *novo = (Vertice *)malloc(sizeof(Vertice));
  if(novo == NULL){
    printf("ERROR\n" );
    exit(1);
  }
  novo->no = x;
  novo->prox = NULL;

  return novo;
}

void insereAresta(Grafo *G, int V, int W){
  if(v != w){
    Vertice *p = G->adj[v].prox;
    while (p != NULL) {
      if (p->no = NULL) break;
      p = p->prox;
    }
    if (p==NULL) {  // A aresta (v,w) não existe
      Vertice *novo = novoVertice(w);
      novo->prox = G->adj[v].prox;
      G->adj[v].prox = novo;
      G->E++;
    }
    p = G->adj[w].prox;

    // Implementar a função de inserção do vértice w na lista de adja de v;
    Vertice *p = G->adj[w].prox;
    while (p != NULL) {
      if (p->no = NULL) break;
      p = p->prox;
    }
    if (p==NULL) {  // A aresta (v,w) não existe
      Vertice *novo = novoVertice(w);
      novo->prox = G->adj[w].prox;
      G->adj[w].prox = novo;
      G->E++;
    }
    p = G->adj[w].prox;

  }

}

void imprimeGrafo(Grafo *G){
  int i;

  for (i = 0; i < G->V; i++) {
    printf("%d\n",i );
    while (G->adj[i].prox != NULL) {
      printf("%d\n", p->no);
      p = p->prox;
    }
  printf("\n");
  }

}

int calculaGrau(Grafo *G){
  int i;
  int valor;

  for (i = 0; i < G->V; i++) {
    while (G->adj[i].prox != NULL) {
      valor++;
      p = p->prox;
    }
    //terminar o coiso do valor
  }

}

int main(int argc, char const *argv[]) {



  return 0;
}
