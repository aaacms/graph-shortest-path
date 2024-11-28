#include <stdio.h>
#include <limits.h>
#define V 10  // Número de vértices no grafo
#define E 20  // Número de arestas no grafo

// Estrutura para representar uma aresta
struct Edge {
    int src, dest, weight;
};

// Função para imprimir o vetor de distâncias
void printSolution(int dist[])
{
    printf("Vértice 	 Distância da origem\n");
    for (int i = 0; i < V; i++)
        printf("%d 		 %d\n", i, dist[i]);
}

// Função que implementa o algoritmo de Bellman-Ford para encontrar o caminho mais curto de src até todos os outros vértices
void bellmanFord(struct Edge edges[], int src)
{
    int dist[V];

    // Inicializa todas as distâncias como INFINITO
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[src] = 0;

    // Relaxa todas as arestas |V| - 1 vezes
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }

    // Verifica ciclos de peso negativo
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            printf("Grafo contém ciclo de peso negativo\n");
            return;
        }
    }

    // Imprime o vetor de distâncias
    printSolution(dist);
}

int main()
{
    /* Exemplo de grafo com 10 nós e 20 arestas:
       0 -- 4 --> 1, 0 -- 8 --> 7, etc. (peso das arestas indicado) */
    struct Edge edges[E] = {
        {0, 1, 4}, {0, 7, 8}, {1, 2, 8}, {1, 7, 11},
        {2, 3, 7}, {2, 8, 2}, {2, 5, 4}, {3, 4, 9},
        {3, 5, 14}, {4, 5, 10}, {5, 6, 2}, {6, 7, 1},
        {6, 8, 6}, {7, 8, 7}, {7, 0, 8}, {8, 9, 9},
        {9, 4, 3}, {3, 9, 5}, {1, 9, 7}, {4, 2, 6}
    };

    bellmanFord(edges, 0);

    return 0;
}
