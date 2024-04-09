#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char frase[1000];
	
	printf("Digite uma frase: ");
	fgets(frase, sizeof(frase), stdin);
	
	int espaco = 1; // verificar se o caracter anterior era um espaco; 0= false, 1= verdadeiro. (Já começa em 1 para contar a primeira palavra)
	int contador = 0;
	for (int i = 0; i < strlen(frase); i++) {
	    if (frase[i] == ' ') {
	        espaco = 1;
	    } else {
	        if (espaco == 1) {
	            contador++;
	        }
	        espaco = 0;
	    }
	}
	
	printf("contador %d", contador);
	
	return 0;
}
