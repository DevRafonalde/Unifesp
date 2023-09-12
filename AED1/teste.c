//João Marcelo Constantino Nordemann
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int numero;
    char nome[21];
    int ultrapassagens;
    int posicao;
} Corredor;

int compararCorredores(const void *a, const void *b) {
    Corredor *corredorA = (Corredor *)a;
    Corredor *corredorB = (Corredor *)b;

    if (corredorB->ultrapassagens != corredorA->ultrapassagens) {
        return corredorB->ultrapassagens - corredorA->ultrapassagens;
    } else {
        return corredorA->posicao - corredorB->posicao;
    }
}

int main() {
    int N;
    scanf("%d", &N);

    Corredor *corredores = (Corredor *)malloc(N * sizeof(Corredor));

    for (int i = 0; i < N; i++) {
        scanf("%d %s", &corredores[i].numero, corredores[i].nome);
        corredores[i].ultrapassagens = 0;
        corredores[i].posicao = i + 1; 
    }

    int *largada = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &largada[i]);
    }

    for (int i = 0; i < N; i++) {
        corredores[largada[i] - 1].posicao = i + 1;
    }

    int ultrapassagem;
    do {
        scanf("%d", &ultrapassagem);

        if (ultrapassagem >= 1 && ultrapassagem <= N) {
            int ultrapassante;
            int ultrapassado;

            for (int i = 0; i < N; i++) {
                if (largada[i] == ultrapassagem) {
                    ultrapassante = largada[i];
                    ultrapassado = largada[i - 1];
                }
            }
            
            for (int i = 0; i < N; i++) {
                if (corredores[i].numero == ultrapassante) {
                    corredores[i].ultrapassagens--;
                    
                }
                if (corredores[i].numero == ultrapassado) {
                    corredores[i].posicao++;
                    corredores[i].ultrapassagens++;
                }
            }
            
            for (int i = 0; i < N; i++) {
                if (largada[i] == ultrapassagem) {
                    largada[i - 1] = ultrapassante;
                    largada[i] = ultrapassado;
                }
            }
        }
    } while (ultrapassagem != -1);

    qsort(corredores, N, sizeof(Corredor), compararCorredores);

    for (int i = 0; i < 3 && i < N; i++) {
        printf("%d %s\n", corredores[i].numero, corredores[i].nome);
    }

    free(corredores);
    free(largada);

    return 0;
}