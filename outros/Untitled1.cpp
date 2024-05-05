#include<stdio.h>

// 0 = lado esquerdo da margem e 1 = lado direito da margem;
int opcao, homen = 0, galinha = 0, milho = 0, raposa = 0;

void menu(){
		if(galinha == homen){
			printf("\n[0] Mover Galinha");	
		}
		if(milho == homen){
			printf("\n[1] Mover Milho");	
		}
		if(raposa == homen){
			printf("\n[2] Mover Raposa");		
		}
		if(homen == 1){
			printf("\n[3] Voltar sozinho");
		}
		
	printf("\n");
		
	scanf("%d", &opcao);
}
 


 

int main(){
	
	do{
		printf("Informe uma opcao: ");
		menu();
		if(opcao == 0){
			galinha = !galinha;
		}
		if(opcao == 1){
			milho = !milho;
		}
		if(opcao == 2){
			raposa = !raposa;
		}
		if(opcao == 3){
			homen = 0;
		}else{
			homen = !homen;	
		}
			
		if((raposa ==  galinha && galinha != homen) || (galinha ==  milho && milho != homen)){
			printf("HAHAHAHA voce perdeu!");
			opcao = -1;
		}
		
		if(homen == 1 && raposa == 1 && galinha == 1 && milho == 1){
			printf("Parabens, voce ganhou!");
			opcao = -1;
		}
		
	}while(opcao > -1);
	
	
	
	return 0;
}
