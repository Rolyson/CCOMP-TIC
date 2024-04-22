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
        for (int j = i + 1; j < array_length; j++) {
            if (numeros[i] > numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

int main(){
	int array_length, numero, aux;
	
	array_length = solicitarNumero();
	
	int numeros [array_length];
	
	for (int i = 0; i < array_length; i++){
		printf("Digite o numero inteiro que deseja armazenar: ");
		scanf("%d", &numero);

		numeros[i] = numero;
	}
	
	ordenaArray(array_length, numeros);
	
	for (int i = 0; i < array_length; i++){
		printf("%d ",numeros[i]);	
	} 

	return 0;	
}
