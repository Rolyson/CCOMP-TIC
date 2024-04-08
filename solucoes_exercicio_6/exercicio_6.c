#include <stdio.h>

int contador = 0;

int converterBinario(int num, int array_binario[]){
    if(num % 2 == 0){
        array_binario[contador] = 0;
    }else{
        array_binario[contador] = 1;
    }

    int novo_numero = num / 2;

    if(novo_numero > 0){
        contador ++;
        converterBinario(novo_numero, array_binario);
    }else{
        return 0;
    }
}

int main(){
    int numero;
    
    do{
        int array_binario[32] = {};
        contador = 0;
        printf("Informe um numero > 0 para transformar em binario: ");
	    scanf("%d", &numero);
        
        converterBinario(numero, array_binario);
        
        for(int i = contador; i >= 0; i--){
            printf("%d",array_binario[i]);
        }
        printf("\n");
    }while(numero >= 0);

}