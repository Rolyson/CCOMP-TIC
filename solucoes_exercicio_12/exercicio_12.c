#include <stdio.h>

int main(){
	int numero, salto, casos_teste;

	printf("Informe a quantidade de casos de teste: ");
	scanf("%d", &casos_teste);

	for(int i = 0; i < casos_teste; i++){
		printf("Informe a quantidade de pessoas no circulo: ");
		scanf("%d", &numero);
		
		printf("Informe a quantidade de saltos que sera realizada: ");
		scanf("%d", &salto);

		int sobreviventes = 0;
		for (int j = 2; j <= numero; j++){
			sobreviventes = (sobreviventes + salto) % j;
		}
		printf("\nO sobrevivente esta na posicao: %d\n", sobreviventes + 1);
	}

	return 0;
}
