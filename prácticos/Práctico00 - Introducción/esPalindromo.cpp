#include <stdio.h>
#include <string.h>
#include <cctype>

int ocurrencias (char *frase, int largo, char *letra);
bool esPalindromo (char *frase, int largo);

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
	bool esPal = esPalindromo(frase, largo);
	if (esPal) {
		printf("Es un palindromo.\n");
	} else if (!esPal) {
		printf("No es un palindromo.\n");
	}
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

bool esPalindromo (char *frase, int largo) {
	int inicio = 0;
	int final = largo-1;
	int mitad = (largo-1)/2;
	char *espacio = new char[1];
	espacio[0] = ' ';
	while (frase[inicio] == frase[final] && inicio <= mitad) {
		inicio++;
		final--;
		if (frase[inicio] == espacio[0]) {
			inicio++;
		}
		if (frase[final] == espacio[0]) {
			final--;
		}
	}
	return (inicio>mitad);
}