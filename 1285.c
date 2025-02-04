#include <stdio.h>
#include <stdbool.h>

bool tem_digitos_repetidos(int numero) {
    int digitos[10] = {0};  // Vetor para contar a ocorrência de cada dígito (0 a 9)
    
    while (numero > 0) {
        int digito = numero % 10;
        if (digitos[digito] > 0) {
            return true;  // Se o dígito já apareceu, retorna true (tem repetição)
        }
        digitos[digito]++;  // Marca o dígito como visto
        numero /= 10;  // Remove o último dígito
    }
    
    return false;  // Se não encontrou dígitos repetidos
}

int contar_numeros_sem_digitos_repetidos(int N, int M) {
    int contagem = 0;
    
    for (int num = N; num <= M; num++) {
        if (!tem_digitos_repetidos(num)) {
            contagem++;
        }
    }
    
    return contagem;
}

int main() {
    int N, M;
    
    while (scanf("%d %d", &N, &M) != EOF) {
        printf("%d\n", contar_numeros_sem_digitos_repetidos(N, M));
    }
    
    return 0;
}
