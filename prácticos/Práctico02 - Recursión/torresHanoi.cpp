#include <stdio.h>

void torresHanoiAux(int n, char origen, char aux, char destino) {
	if (n>0) {
		if (n==1) {
			printf("El disco %d se mueve desde %c hasta %c \n", n, origen, destino);
		} else {
			torresHanoiAux(n-1, origen, destino, aux);
			printf("El disco %d se mueve desde %c hasta %c \n", n, origen, destino);
			torresHanoiAux(n-1, aux, origen, destino);
		}
	}

}

void torresHanoi(int n) {
	torresHanoiAux(n, 'A', 'B', 'C');
}

int main() {
	int n = 10;
	torresHanoi(n);
	return 0;
}