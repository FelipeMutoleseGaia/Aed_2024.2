#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Aluno {
    char nome[21];
    struct Aluno* proximo;
} Aluno;

Aluno* criarAluno(char* nome) {
    Aluno* novoAluno = (Aluno*)malloc(sizeof(Aluno));
    strcpy(novoAluno->nome, nome);
    novoAluno->proximo = NULL;
    return novoAluno;
}

void inserirOrdenado(Aluno** inicio, char* nome) {
    Aluno* novoAluno = criarAluno(nome);
    if (*inicio == NULL || strcmp((*inicio)->nome, nome) > 0) {
        novoAluno->proximo = *inicio;
        *inicio = novoAluno;
    } else {
        Aluno* atual = *inicio;
        while (atual->proximo != NULL && strcmp(atual->proximo->nome, nome) < 0) {
            atual = atual->proximo;
        }
        novoAluno->proximo = atual->proximo;
        atual->proximo = novoAluno;
    }
}

char* obterNomeK(Aluno* inicio, int K) {
    for (int i = 1; i < K && inicio != NULL; i++) {
        inicio = inicio->proximo;
    }
    return inicio->nome;
}

void liberarFila(Aluno* inicio) {
    Aluno* temp;
    while (inicio != NULL) {
        temp = inicio;
        inicio = inicio->proximo;
        free(temp);
    }
}

int main() {
    int totalAlunos, sorteado;
    scanf("%d %d", &totalAlunos, &sorteado);

    Aluno* inicio = NULL;
    char nome[21];

    for (int i = 0; i < totalAlunos; i++) {
        scanf("%s", nome);
        inserirOrdenado(&inicio, nome);
    }

    printf("%s\n", obterNomeK(inicio, sorteado));

    liberarFila(inicio);

    return 0;
}
