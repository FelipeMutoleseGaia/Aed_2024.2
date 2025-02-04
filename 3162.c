#include <stdio.h>
#include <math.h>

typedef struct {
    int x, y, z;
    double distancia;
    char intensidade;
} Nave;

double calcular_distancia(Nave a, Nave b) {
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2) + pow(a.z - b.z, 2));
}

int main() {
    int N;
    scanf("%d", &N);

    Nave naves[N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &naves[i].x, &naves[i].y, &naves[i].z);
        naves[i].distancia = INFINITY;
    }

    for (int i = 0; i < N; i++) {
        double menor_distancia = INFINITY;
        int indice_nave_mais_proxima = -1;

        for (int j = 0; j < N; j++) {
            if (i != j) {
                double distancia = calcular_distancia(naves[i], naves[j]);
                if (distancia < menor_distancia) {
                    menor_distancia = distancia;
                    indice_nave_mais_proxima = j;
                }
            }
        }

        naves[i].distancia = menor_distancia;

        if (menor_distancia <= 20) {
            naves[i].intensidade = 'A'; // Alta
        } else if (menor_distancia <= 50) {
            naves[i].intensidade = 'M'; // Média
        } else {
            naves[i].intensidade = 'B'; // Baixa
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%c\n", naves[i].intensidade);
    }

    return 0;
}
