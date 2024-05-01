#include <stdio.h>
#include <string.h>


void ordenaArray(int array_length, char numeros[] ){
	for (int i = 0; i < array_length; i++){
        for (int j = i + 1; j < array_length; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

int main() {
	char str1[50], str2[50], str1_temp[50], str2_temp[50];
    
	printf("Digite uma palavra: ");
    scanf("%s", &str1);
    
    printf("Digite uma palavra: ");
    scanf("%s", &str2);
    
    strcpy(str1_temp, str1);
    strcpy(str2_temp, str2);
    
	ordenaArray(strlen(str1_temp), str1_temp);
	ordenaArray(strlen(str2_temp), str2_temp);


   	if (strcmp(str1_temp, str2_temp) == 0) {
       printf("%s e %s sao anagramas.\n", str1, str2);
	}else{
		printf("%s e %s nao sao anagramas.\n", str1, str2);
	}

    return 0;
}
