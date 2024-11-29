#include <stdio.h>
#include <limits.h>
#define V 10  // No de nós no grafo

// encontra o vértice com a menor distância que ainda não foi incluído no caminho mais curto
int distanciaMinima(int dist[], int visitado[])
{
    int min = INT_MAX;
    int min_index;

    for (int i = 0; i < V; i++) {
        if (visitado[i] == 0 && dist[i] <= min) {
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

// Função para imprimir o vetor de distâncias
void impressao(int dist[])
{
    printf("Vertice \t Distancia da origem\n");
    for (int i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, dist[i]);
    }
}

// Função que implementa o algoritmo Dijkstra
void dijkstra(int grafo[V][V], int origem)
{
    int dist[V];     // Vetor que guarda a menor distância do origem até cada vértice
    int visitado[V];   // visitado[i] será 1 se visitado e 0 se nao visitado

    // inicializa todas as distâncias como INFINITO e visitado[] como falso (nao visitado)
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        visitado[i] = 0;
    }

    // a distância do vértice de origem para ele mesmo é 0
    dist[origem] = 0;

    // Encontra o caminho mais curto para todos os vértices
    for (int i = 0; i < V - 1; i++) {
        // Escolhe o vértice de menor distância que ainda não foi processado
        int u = distanciaMinima(dist, visitado);

        // Marca o vértice como visitado
        visitado[u] = 1;

        // atualiza o valor da distancia dos vértices adjacentes ao vértice escolhido
        for (int v = 0; v < V; v++) {

            // Atualiza dist[v] apenas se não estiver em um nó já visitado, houver uma aresta de u para v,
            // e o peso total do caminho de origem até v através de u for menor que o valor atual de dist[v]
            if (!visitado[v] && grafo[u][v] && dist[u] != INT_MAX
                && dist[u] + grafo[u][v] < dist[v]) {
                dist[v] = dist[u] + grafo[u][v];
            }
        }
    }

    // Imprime
    impressao(dist);
}

int main()
{
    /* Exemplo de grafo com 10 nós e 20 arestas */
    int grafo[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0, 0},
        {4, 0, 8, 0, 0, 0, 0, 11, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 2, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6, 0},
        {8, 11, 0, 0, 0, 0, 1, 0, 7, 0},
        {0, 0, 2, 0, 0, 0, 6, 7, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 0, 9, 0}
    };

    dijkstra(grafo, 0);

    return 0;
}
