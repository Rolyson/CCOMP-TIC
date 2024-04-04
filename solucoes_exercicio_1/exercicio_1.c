#include <stdio.h>

int main(){
	float celsius, fahrenheit, kelvin;
	
	printf("Informe os graus em Celsius: ");
	scanf("%f", &celsius);
	
	kelvin = celsius + 273.15;
	fahrenheit = (celsius * 9/5) + 32;
	
	printf("\n%.2f graus Celsius eh igual a:\n%.2f graus Fahrenheit;\n%.2f Kelvin.", celsius, fahrenheit, kelvin);
}
