#include <stdio.h>

void converterBinario(int num){
    if (num == 0) {
        return;
    }
    converterBinario(num / 2);
    printf("%d", num % 2);
}

int main(){
    int numero;
    
    do{
        printf("Informe um numero > 0 para transformar em binario: ");
	    scanf("%d", &numero);
        
        converterBinario(numero);

        printf("\n");
    }while(numero >= 0);

}