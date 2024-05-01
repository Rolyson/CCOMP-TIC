#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char str1[50];
    
    printf("Digite uma palavra: ");
    scanf("%s", &str1);


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
    
    return 0;
}
