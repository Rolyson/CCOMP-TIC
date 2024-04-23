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
            if (numeros[i] < numeros[j]) {
                int temp = numeros[i];
                numeros[i] = numeros[j];
                numeros[j] = temp;
            }
        }
    }
}

void ordenaArrayOcorrencia(int array_length, int ocorrencias[], int numeros[] ){
	for (int i = 0; i < array_length; i++){
        for (int j = i + 1; j < array_length; j++) {
            if (ocorrencias[i] < ocorrencias[j]) {
                int temp_ocorrencias = ocorrencias[i];
                int temp_numeros = numeros[i];
                ocorrencias[i] = ocorrencias[j];
                ocorrencias[j] = temp_ocorrencias;
                
								numeros[i] = numeros[j];
                numeros[j] = temp_numeros;
            }
        }
    }
}

int main(){
	int array_length, numero, aux;
	
	array_length = solicitarNumero();
	
	int numeros [array_length], ocorrencias [array_length], numeros_alutinados [array_length];
	
	for (int i = 0; i < array_length; i++){
		printf("Digite o numero inteiro que deseja armazenar: ");
		scanf("%d", &numero);

		numeros[i] = numero;
	}
	
	ordenaArray(array_length, numeros);
	
	int numero_checado, index_novo_array = -1;
	for (int i = 0; i < array_length; i++){
		if(numero_checado != numeros[i]){
			index_novo_array += 1;
			ocorrencias[index_novo_array] = 1;
			numeros_alutinados[index_novo_array] =  numeros[i];	
			numero_checado = numeros[i];			
		}else{
			ocorrencias[index_novo_array] ++;
		}
	}

	ordenaArrayOcorrencia(index_novo_array, ocorrencias, numeros_alutinados);

	for (int i = 0; i <= index_novo_array; i++){
		printf("%d: %d ocorrencias\n", numeros_alutinados[i], ocorrencias[i]);	
	} 

	return 0;	
}
