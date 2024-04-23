#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
	char mensagem[127], direcao;
	int pulo;

	printf("Digite a mensagem a ser criptografada: ");
	fgets(mensagem, 127, stdin);
	
	printf("Digite o valor do pulo: ");
	scanf("%d", &pulo);

	printf("Digite a direcao da codificacao (E/D): ");
	scanf(" %c", &direcao);

	if(toupper(direcao) ==  'D'){
		for(int i = 0; i < strlen(mensagem); i++){
			if(mensagem[i] != ' '){
				int ascii = (char)mensagem[i];
				int mensagemCriptografada = ((ascii - 33 + pulo) % 94) + 33;
				mensagem[i] = (char)mensagemCriptografada;
			}
		}		
	}else if(toupper(direcao) ==  'E'){
		for(int i = 0; i < strlen(mensagem); i++){
			if(mensagem[i] != ' '){
				int ascii = (char)mensagem[i];
				int mensagemCriptografada = ((ascii - 33 - pulo + 94) % 94) + 33;
				mensagem[i] = (char)mensagemCriptografada;
			}
		}
	}else{
		printf("Opcao de direcao invalida!");
		return 0;
	}

	printf("Mensagem criptografada: %s", mensagem);
	return 0;
}
