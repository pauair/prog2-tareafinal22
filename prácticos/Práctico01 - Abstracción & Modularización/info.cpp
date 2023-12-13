#include <stdio.h>

struct _rep_info {
	unsigned int n;
	double r;	
};

typedef struct _rep_info * TInfo ;


TInfo crearInfo ( unsigned int natural , double real ) {
	TInfo info = new _rep_info;
	info->n = natural;
	info->r = real;
	return info;
};

//Devuelve el componente natural de 'info '.

unsigned int natInfo ( TInfo info ) {
	return info->n;
};

//Devuelve el componente real de 'info '.

double realInfo ( TInfo info ) {
	return info->r;
};

int main () {
	TInfo info[3];
	info[0] = crearInfo(3,67.1);
	info[1] = crearInfo(2,52.1);
	info[2] = crearInfo(7,48.3);
	for (int i=0; i<3; i++) {
		double real = realInfo(info[i]);
		int nat = natInfo(info[i]);
		printf("%d %0.2f\n", nat, real);
	}
}
