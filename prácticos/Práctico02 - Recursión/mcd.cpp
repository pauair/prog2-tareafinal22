
#include <stdio.h>

//precondicion: n1<n2
int maxcomdiv(int n1, int n2) {
	if (n1 == 0) {
		return n2;
	}
	return (maxcomdiv(n2%n1, n1));
}

int main() {
	int mcd = maxcomdiv(12,16);
	printf("%d\n", mcd);
	return 0;
}