#include<stdio.h>

int solicitarNumero(){
	int numero_digitado;
	printf("Informe a quantidade de numeros que deseja armazenar: ");
	scanf("%d", &numero_digitado);
	
	if(numero_digitado <= 0){
		printf("Informe um numeo > 0 \n");
		solicitarNumero();
	}else{
		return numero_digitado;
	}
}

void ordenaArray(int array_length, int numeros[] ){
	for (int i = 0; i < array_length; i++){
        for (int j = i; j < array_length; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

int main(){
	int array_length, numero, aux, index;
	
	array_length = solicitarNumero();
	
	int numeros [array_length];
	
	for (int i = 0; i < array_length; i++){
		printf("Digite o numero inteiro que deseja armazenar: ");
		scanf("%d", &numero);

		numeros[i] = numero;
	}
	
	ordenaArray(array_length, numeros);

	if(array_length % 2 == 0){
		index = array_length / 2;
		float media = (numeros[index - 1] + numeros[index] )/ 2;		
		printf("\nA mediana do array eh igual ah: %.2f\n", media);
	}else{
		index = array_length / 2;
		printf("\nA mediana do array eh igual ah: %d\n", numeros[index]);
	}

	return 0;	
}
