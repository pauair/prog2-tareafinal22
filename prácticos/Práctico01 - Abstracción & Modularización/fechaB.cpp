#include <stdio.h>

struct _rep_fecha {
	unsigned int f ; // AAAAMMDD
};

void ordenarFechas (_rep_fecha arr_fecha[], int arr_tope) {
	_rep_fecha aux;
	for (int i=0; i<arr_tope; i++) {
		for (int j=i; j<arr_tope; j++) {
			if (arr_fecha[j].f<arr_fecha[i].f) {
				aux = arr_fecha[j];
				arr_fecha[j] = arr_fecha[i];
				arr_fecha[i] = aux;
			}
		} 
	}
}

int main() {
	int arr_tope = 4;
	_rep_fecha arr_fecha[arr_tope];
	arr_fecha[0] = {20221010};
    arr_fecha[1] = {19921120};
    arr_fecha[2] = {20220515};
    arr_fecha[3] = {19980420};
    ordenarFechas(arr_fecha, arr_tope);
    for(int i = 0; i < arr_tope ; i++) {
    	int dia = arr_fecha[i].f%100;
    	int mes = (arr_fecha[i].f%10000)/100;
    	int ano = arr_fecha[i].f/10000;
    	printf("%d/%d/%d\n",dia, mes, ano);
    }
	return 0;
}