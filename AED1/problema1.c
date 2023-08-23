#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    // 1 a mais do que o limite indicado no problema, pois estou contando com o "\0"
    char string[257];

    // As frequencias das 26 letras do alfabeto
    int frequencias[26] = {0};

    // O input de entrada da string
    fgets(string, sizeof(string), stdin);

    // Nesse for eu pego um caractere da string, transformo para minúsculo e adiciono 1 à frequência dele
    for (int i = 0; string[i]; i++) {
        string[i] = tolower(string[i]);
        
        if (isalpha(string[i])) {
            // Aqui, ao manipular a frequência, eu subtraio 'a' do caractere lido. Vamos considerar um exemplo:
            // Se você tem a letra 'c' e quer armazenar sua frequência no array "frequencias", você precisará convertê-la para um índice apropriado.
            // O caractere 'c' corresponde ao número 99 na tabela ASCII, e a letra 'a' corresponde ao número 97.
            // Se subtrairmos 'a' (97) de 'c' (99), obtemos 2, que é o índice onde devemos armazenar a frequência da letra 'c' no array frequencies.
            frequencias[string[i] - 'a']++;
        }
    }

    for (int i = 0; i < 26; i++) {
        if (frequencias[i] > 0) {
            // Da mesma forma, ao exibir as letras aqui, precisamos reverter o processo para obter a letra correspondente ao índice.
            // Somamos o valor do índice ao caractere 'a' para obter a letra correspondente. Se o índice for 2, somar 'a' (97) a 2 resultará em 99, que é o código ASCII para a letra 'c'.
            // E assim eu faço para imprimir em ordem lexicográfica
            printf("%c: %d\n", toupper('a' + i), frequencias[i]);
        }
    }

    return 0;
}
