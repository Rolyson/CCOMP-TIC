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

int compare(const void *a, const void *b) {
    return strcmp((const char *)a, (const char *)b);
}

int main() {
    char *str1 = NULL, *str2 = NULL, *str1_temp = NULL, *str2_temp = NULL;
    
    str1 = solicitaString();
    str2 = solicitaString();
    
//    str1_temp = str1;
//    str2_temp = str2;
    str1_temp = (char *)malloc(strlen(str1) + 1);
    str2_temp = (char *)malloc(strlen(str2) + 1);
    
    strcpy(str1_temp, str1);
    strcpy(str2_temp, str2);
    
    qsort(str1_temp, strlen(str1_temp), sizeof(char), compare);
    qsort(str2_temp, strlen(str2_temp), sizeof(char), compare);


   	if (strcmp(str1_temp, str2_temp) == 0) {
       printf("%s e %s sao anagramas.\n", str1, str2);
	}else{
		printf("%s e %s nao sao anagramas.\n", str1, str2);
	}

    free(str1);
    free(str2);

    return 0;
}
