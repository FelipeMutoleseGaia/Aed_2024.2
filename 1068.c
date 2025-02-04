#include <stdio.h>
#include <string.h>

#define MAX_EXPRESSAO 1000

const char* verificar_expressao(const char* expressao) {
    int pilha = 0;
    
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (expressao[i] == '(') {
            pilha++;
        } else if (expressao[i] == ')') {
            if (pilha == 0) {
                return "incorrect";
            }
            pilha--;
        }
    }
    
    return (pilha == 0) ? "correct" : "incorrect";
}

int main() {
    char expressao[MAX_EXPRESSAO];
    
    while (fgets(expressao, MAX_EXPRESSAO, stdin)) {
        expressao[strcspn(expressao, "\n")] = 0;
        
        printf("%s\n", verificar_expressao(expressao));
    }
    
    return 0;
}
