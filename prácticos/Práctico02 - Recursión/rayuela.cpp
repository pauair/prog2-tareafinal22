#include <stdio.h>

int rayuela(int n) {
	if ((n == 1) || (n == 0)) {
		return 1;
	} else {
		return ((rayuela(n-1)) + rayuela(n-2));
	}
}

int main () {
	for (int i=1; i<11; i++) {
		int caminos = rayuela(i);
		printf("%d\n", caminos);
	}
	return 0;
}


//n=1 caminos = 1 --> (0,1)
//n=2 caminos = 2 --> (0,1,2) (0,2)
//n=3 caminos = 3 --> (0,1,2,3) (0,1,3) (0,2,3)
//n=4 caminos = 5 --> (0,1,2,3,4) (0,2,4) (0,1,2,4) (0,1,3,4) (0,2,3,4)
//n=5 caminos = 8  
//n=6 caminos = 13
//n=7 caminos = 21  
//n=8 caminos = 34 
//n=9 caminos = 55
//n=10 caminos = 89