#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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
    int participantes;
    
    scanf("%d", &participantes);

    if (participantes < 3 || participantes > 1000){
        return 0;
    }
    
    struct Corredor *corredores = (struct Corredor *)malloc(participantes * sizeof(struct Corredor));

    if (corredores == NULL) {
        return 1;
    }
    
    for (int i = 0; i < participantes; i++) {
        scanf("%d %s", &corredores[i].numeroCarro, &corredores[i].nome);
        corredores[i].posicaoAtual = i + 1; 
    }

    int *posicoes = (int *)malloc(participantes * sizeof(int));
    for (int i = 0; i < participantes; i++) {
        scanf("%d", &posicoes[i]);
    }

    for (int i = 0; i < participantes; i++) {
        corredores[posicoes[i] - 1].posicaoAtual = i + 1;
    }
    
    int ultrapassagem;

    do {
        scanf("%d", &ultrapassagem);
        
        if (ultrapassagem >= 1 && ultrapassagem <= participantes) {
            int carroUltrpassou;
            int carroUltrapassado;
            bool primeiroLugar = false;

            for (int i = 0; i < participantes; i++) {
                if (posicoes[i] == ultrapassagem) {
                    if (i == 0) {
                        primeiroLugar = true;
                    } else {
                        carroUltrpassou = posicoes[i];
                        carroUltrapassado = posicoes[i - 1];
                    }
                }
            }

            if (!primeiroLugar) {
                for (int i = 0; i < participantes; i++) {
                    if (corredores[i].numeroCarro == carroUltrpassou) {
                        corredores[i].posicaoAtual--;
                    }
                    if (corredores[i].numeroCarro == carroUltrapassado) {
                        corredores[i].posicaoAtual++;
                    }
                }
                
                for (int i = 0; i < participantes; i++) {
                    if (posicoes[i] == ultrapassagem) {
                        posicoes[i - 1] = carroUltrpassou;
                        posicoes[i] = carroUltrapassado;
                    }
                }
            }
        }
        
    } while (ultrapassagem != -1);
    
    qsort(corredores, participantes, sizeof(struct Corredor), compararPosicoes);
    
    for (int i = 0; i < 3; i++) {
        printf("%d %s\n", corredores[i].numeroCarro, corredores[i].nome);
    }
    
    free(corredores);
    free(posicoes);

    return 0;
}
