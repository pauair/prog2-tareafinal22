#include <stdio.h>

struct _rep_fecha {
	unsigned int d ;
	unsigned int m ;
	unsigned int a ;
};

bool esMenor(_rep_fecha i, _rep_fecha j) {
	bool esMen = false;
	if ((i.a < j.a) || (i.a == j.a) && (i.m < j.m) || ((i.a == j.a) && (i.m == j.m) && (i.d < j.d)) ) {
		esMen = true;
	}
	return esMen;
}

void ordenarFechas(_rep_fecha arr_fecha[], int arr_tope) {
	_rep_fecha aux;
	for (int i=0; i<arr_tope; i++) {
		for (int j=i+1; j<arr_tope; j++) {
			if (esMenor(arr_fecha[j],arr_fecha[j-1])) {
				aux = arr_fecha[j];
				arr_fecha[j] = arr_fecha[j-1];
				arr_fecha[j-1] = aux;
			}
		} 
	}
}

int main() {
	int arr_tope = 4;
	_rep_fecha arr_fecha[arr_tope];
	arr_fecha[0] = {10,10,2022};
    arr_fecha[1] = {20,11,1992};
    arr_fecha[2] = {15,5,2022};
    arr_fecha[3] = {20, 4, 1998};
    ordenarFechas(arr_fecha, arr_tope);
    for(int i = 0; i < arr_tope ; i++)
        printf("%d / %d / %d \n",arr_fecha[i].d,arr_fecha[i].m, arr_fecha[i].a);
	return 0;
}
