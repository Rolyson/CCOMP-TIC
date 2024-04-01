#include<stdio.h>

int main(){
	int array_length, numero, aux;
	
	printf("Informe a quantidade de numeros que deseja armazenar: ");
	scanf("%d", & array_length);
	
	int numeros [array_length];
	
	for (int i = 0; i < array_length; i++){
		numero;
		printf("Digite o numero inteiro que deseja armazenar: ");
		scanf("%d", &numero);

		numeros[i] = numero;
	}
	
	for (int i = 0; i < array_length; i++){
        for (int j = i; j < array_length; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
	
	for (int i = 0; i < array_length; i++){
		printf("%d ",numeros[i]);	
	} 
	
}
