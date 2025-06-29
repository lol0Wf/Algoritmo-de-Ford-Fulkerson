#include <iostream>
#include <queue>
using namespace std;

const int V = 6;  // esse define quantos vertices tem o grafo
const int VALOR_MAX = 999999; // esse define um valor maximo hipoteticamente inatingivel

// Função para realizar uma busca em largura (BFS)
// Retorna verdadeiro se existir caminho entre 'inicio' e 'fim'
bool buscaLargura(int grafoRes[V][V], int inicio, int fim, int caminho[])
{
    bool visitado[V] = {false};

    queue<int> fila;
    fila.push(inicio);
    visitado[inicio] = true;
    caminho[inicio] = -1;

    while (!fila.empty()) {
        int atual = fila.front();
        fila.pop();

        for (int prox = 0; prox < V; prox++) {
            if (!visitado[prox] && grafoRes[atual][prox] > 0) {
                fila.push(prox);
                caminho[prox] = atual;
                visitado[prox] = true;

                if (prox == fim) {
                    return true;
                }
            }
        }
    }

    return false;
}

// Função algoritmo de Ford-Fulkerson
int fluxoMaximo(int grafo[V][V], int origem, int destino)
{
    int grafoRes[V][V];

    // Cópia do grafo original para o grafo residual
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            grafoRes[i][j] = grafo[i][j];
        }
    }

    int caminho[V];
    int fluxoTotal = 0;

    // Enquanto existir caminho da origem até o destino
    while (buscaLargura(grafoRes, origem, destino, caminho)) {
        // Encontra o menor fluxo possível no caminho encontrado (gargalo)
        int fluxoCaminho = VALOR_MAX;
        int v = destino;
        while (v != origem) {
            int u = caminho[v];
            fluxoCaminho = min(fluxoCaminho, grafoRes[u][v]);
            v = u;
        }

        // Atualiza o grafo residual
        v = destino;
        while (v != origem) {
            int u = caminho[v];
            grafoRes[u][v] -= fluxoCaminho;
            grafoRes[v][u] += fluxoCaminho;
            v = u;
        }

        // Adiciona o fluxo encontrado ao total
        fluxoTotal += fluxoCaminho;
    }

    return fluxoTotal;
}

int main()
{
    // é o grafo em forma de matriz
    int grafo[V][V] = {
        { 0, 16, 13, 0, 0, 0 },
        { 0, 0, 10, 12, 0, 0 },
        { 0, 4, 0, 0, 14, 0 },
        { 0, 0, 9, 0, 0, 20 },
        { 0, 0, 0, 7, 0, 4 },
        { 0, 0, 0, 0, 0, 0 }
    };

    cout << "Fluxo máximo na rede = "
         << fluxoMaximo(grafo, 0, 5) << endl;

    return 0;
}
