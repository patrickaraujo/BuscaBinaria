#include <stdio.h>

// Versão recursiva (já fornecida)
int busca_binaria_recursiva(int *dados, int l, int r, int x) {
    int m = (l + r)/2;
    if (l > r)
        return -1;
    if (dados[m] == x)
        return m;
    else if (dados[m] < x)
        return busca_binaria_recursiva(dados, m + 1, r, x);
    else
        return busca_binaria_recursiva(dados, l, m - 1, x);
}

// Versão iterativa
int busca_binaria_iterativa(int *dados, int tamanho, int x) {
    int l = 0;
    int r = tamanho - 1;
    
    while (l <= r) {
        int m = (l + r)/2;
        
        if (dados[m] == x)
            return m;
        else if (dados[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    
    return -1;
}

int main() {
    int vetor[] = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    int tamanho = sizeof(vetor)/sizeof(vetor[0]);
    int valor;
    
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
    
    printf("Digite um valor para buscar: ");
    scanf("%d", &valor);
    
    // Testando versão recursiva
    int pos_rec = busca_binaria_recursiva(vetor, 0, tamanho - 1, valor);
    if (pos_rec != -1) {
        printf("(Recursiva) Valor encontrado na posição %d\n", pos_rec);
    } else {
        printf("(Recursiva) Valor não encontrado\n");
    }
    
    // Testando versão iterativa
    int pos_it = busca_binaria_iterativa(vetor, tamanho, valor);
    if (pos_it != -1) {
        printf("(Iterativa) Valor encontrado na posição %d\n", pos_it);
    } else {
        printf("(Iterativa) Valor não encontrado\n");
    }
    
    return 0;
}
