#include <stdio.h>
#include <limits.h>
#define V 10  // No de nós no grafo
#define E 20  // No de arestas no grafo

// representa uma aresta
typedef struct aresta {
    int origem, destino, peso;
} Aresta;

// funcao para imprimir
void impressao(int dist[])
{
    printf("Vertice 	 Distancia da origem\n");
    for (int i = 0; i < V; i++)
        printf("%d 		 %d\n", i, dist[i]);
}

// funcao que implementa o algoritmo Bellman-Ford
void bellmanFord(Aresta arestas[], int origem)
{
    int dist[V];

    // inicializa todas as distâncias como INFINITO
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
    }

    // a distância do vértice de origem para ele mesmo é 0
    dist[origem] = 0;

    // Relaxa todas as arestas |V| - 1 vezes
    for (int i = 0; i < V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = arestas[j].origem;
            int v = arestas[j].destino;
            int peso = arestas[j].peso;
            if (dist[u] != INT_MAX && dist[u] + peso < dist[v]) {
                dist[v] = dist[u] + peso;
            }
        }
    }

    // Verifica ciclos de peso negativo
    for (int i = 0; i < E; i++) {
        int u = arestas[i].origem;
        int v = arestas[i].destino;
        int weight = arestas[i].peso;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Grafo contém ciclo de peso negativo\n");
            return;
        }
    }

    // Imprime
    impressao(dist);
}

int main()
{
    /* Exemplo de grafo com 10 nós e 20 arestas */
    Aresta arestas[E] = {
        {0, 1, 6}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}, {7, 0, 8}, {8, 9, 9},
        {9, 4, 3}, {3, 9, 5}, {1, 9, 7}, {4, 2, 6}
    };

    bellmanFord(arestas, 0);

    return 0;
}
