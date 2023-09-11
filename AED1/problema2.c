#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Corredor {
    int numeroCarro;
    char nome[21];
    int posicaoAtual;
};

int compararPosicoes(const void *a, const void *b) {
    const struct Corredor *corredorA = (const struct Corredor *)a;
    const struct Corredor *corredorB = (const struct Corredor *)b;
    return corredorA->posicaoAtual - corredorB->posicaoAtual;
}

int main() {
    int N;
    
    do {
        scanf("%d", &N);
    } while (3 > N || N > 1000);
    
    struct Corredor *corredores = (struct Corredor *)malloc(N * sizeof(struct Corredor));

    if (corredores == NULL) {
        exit(1);
    }
    
    for (int i = 0; i < N; i++) {
        scanf("%d %s", &corredores[i].numeroCarro, &corredores[i].nome);
        corredores[i].posicaoAtual = i + 1; 
    }
    
    int *ordemLargada = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &ordemLargada[i]);
    }

    for (int i = 0; i < N; i++) {
        corredores[ordemLargada[i] - 1].posicaoAtual = i + 1;
    }
    
    int ultrapassagem;

    do {
        scanf("%d", &ultrapassagem);
        
        if (ultrapassagem >= 1 && ultrapassagem <= N) {
            int carroUltrpassou;
            int carroUltrapassado;

            for (int i = 0; i < N; i++) {
                if (ordemLargada[i] == ultrapassagem) {
                    carroUltrpassou = ordemLargada[i];
                    carroUltrapassado = ordemLargada[i - 1];
                }
            }
            
            for (int i = 0; i < N; i++) {
                if (corredores[i].numeroCarro == carroUltrpassou) {
                    corredores[i].posicaoAtual--;
                }
                if (corredores[i].numeroCarro == carroUltrapassado) {
                    corredores[i].posicaoAtual++;
                }
            }
            
            for (int i = 0; i < N; i++) {
                if (ordemLargada[i] == ultrapassagem) {
                    ordemLargada[i - 1] = carroUltrpassou;
                    ordemLargada[i] = carroUltrapassado;
                }
            }
        }
        
    } while (ultrapassagem != -1);
    
    qsort(corredores, N, sizeof(struct Corredor), compararPosicoes);
    
    for (int i = 0; i < 3; i++) {
        printf("%d %s\n", corredores[i].numeroCarro, corredores[i].nome);
    }
    
    free(corredores);
    free(ordemLargada);

    return 0;
}
