#include <stdio.h>
#include <string.h>
#include <cctype>

int ocurrencias (char *frase, int largo, char *letra);

int main() {
	char *frase = new char[100];
	char *letra = new char[1];
	printf("Ingrese una frase: ");
	scanf("%[^\n]s", frase);
	int largo = strlen(frase);
	printf("Ingrese una letra: ");
	scanf("%s", letra);
	int ocu = ocurrencias(frase, largo, letra); 
	printf("La cantidad de ocurrencias de %s es: %d \n", letra, ocu);
	return 0;
}

int ocurrencias (char *frase, int largo, char *letra) {
	int contador = 0;
	for (int i=0; i<largo; i++) {
		if (frase[i] == letra[0]) {
			contador++;
		};
	};
	return contador;
}