#include <stdio.h>

void ordenarArreglo (int *arreglo, int tope) {
	int aux;
	for (int i=0; i<tope; i++) {
		for (int j=i; j<tope; j++) {
			if (arreglo[j] < arreglo[i]) {
				aux = arreglo[i];
				arreglo[i] = arreglo[j];
				arreglo[j] = aux;
			}
		}

	}
}

int main () {
	int* arreglo = new int[7];
	arreglo[0] = 2;
	arreglo[1] = 7; 
	arreglo[2] = 4; 
	arreglo[3] = 5; 
	arreglo[4] = 5;
	arreglo[5] = 1;
	arreglo[6] = 8;
	int tope = 7;
	ordenarArreglo(arreglo, tope);
	for (int i = 0; i < tope; i++) {
		printf("%d ", arreglo[i]);
	}
	return 0;
}

