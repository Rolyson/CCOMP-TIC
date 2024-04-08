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

void ordenaDoisArray(int array_length, int numero_ocorrencia[], int numero_ordem[] ){
	for (int i = 0; i < array_length; i++){
        for (int j = i; j < array_length; j++) {
            if (numero_ocorrencia[i] < numero_ocorrencia[j]) {
                int temp_ocorrencia = numero_ocorrencia[i];
                numero_ocorrencia[i] = numero_ocorrencia[j];
                numero_ocorrencia[j] = temp_ocorrencia;
                
								int temp_numero = numero_ordem[i];
                numero_ordem[i] = numero_ordem[j];
                numero_ordem[j] = temp_numero;	
            }
        }
    }
}

int main(){
	int array_length, numero, numero_temp, ocorrencia, contador = 0;
	
	array_length = solicitarNumero();
	
	int numeros [array_length];
	
	for (int i = 0; i < array_length; i++){
		printf("Digite o numero inteiro que deseja armazenar: ");
		scanf("%d", &numero);

		numeros[i] = numero;
	}
	
	ordenaArray(array_length, numeros);

	
	int numero_ordem [array_length];
	int numero_ocorrencia [array_length];

	for (int i = 0; i < array_length; i++){
		if(i == array_length){
			numero_ordem[contador] = numeros[i];
			numero_ocorrencia[contador] = ocorrencia;
			contador ++;
			
		}else	if(numeros[i] != numero_temp){
			if(i != 0){
				numero_ordem[contador] = numero_temp;
				numero_ocorrencia[contador] = ocorrencia;
				contador ++;
			}
			numero_temp = numeros[i];
			ocorrencia = 1;
		} else if(numeros[i] == numero_temp){
			ocorrencia ++;
		}
	} 

	// for(int i = 0; i<contador; i++){
	// 	printf("numero %d \n", numero_ordem[i]);
	// }
	
	ordenaDoisArray(contador, numero_ocorrencia, numero_ordem);

	for(int i = 0; i<contador; i++){
		printf("numero %d : ocorrencia %d\n", numero_ordem[i], numero_ocorrencia[i]);
	}

	return 0;	
}
