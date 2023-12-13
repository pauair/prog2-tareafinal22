#include <stdio.h> 

void Primos(int a, int b) {
	for (int i = a; i < b; i++) {
		int j = 2;
		while ((i%j != 0) && (j <= i)) {
			j++; 
		}
		if (j >= i) {
			printf("%d\n", i);
		}
	}
}

int main() {
	int a, b;
	printf("Ingrese dos números: ");
	scanf("%d %d", &a, &b);
	Primos(a,b);
	return 0;
}