#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *solicitaString() {
    char *minhaString = NULL;

    printf("Digite uma palavra: ");
    char buffer[100]; // Buffer temporário para armazenar a entrada
    scanf("%s", buffer);

    // Alocar memória para a string
    minhaString = (char *)malloc(strlen(buffer) + 1); // +1 para o caractere nulo
    
    // Copiar a palavra para a string alocada
    strcpy(minhaString, buffer);

    // Não podemos retornar minhaString aqui, pois ela será liberada no final da função
    // Retornar a string diretamente
    return minhaString;
}

int main() {
    char *str1 = NULL;
    
    str1 = solicitaString();

    int tamanho = strlen(str1);
    char strTemp[tamanho];
    int index = 0;
    for (int i = tamanho - 1; i >=0 ; i--) {
        strTemp[index] = str1[i];
        index ++;
    }
    strTemp[index] = '\0'; // Eu preciso colocar um caractere nulo no final da string, caso eu não coloque ele não fica igual a str1

    if (strcmp(str1, strTemp) == 0) {
        printf("%s eh palindromo.\n", str1);
    } else {
        printf("%s nao eh palindromo.\n", str1);
    }
    
    free(str1);

    return 0;
}
