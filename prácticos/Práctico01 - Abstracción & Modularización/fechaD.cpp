#include <stdio.h>

struct _rep_fecha {
	unsigned int f ; // AAAAMMDD
};

typedef struct _rep_fecha * TFecha ;

TFecha crear_fecha (unsigned int f) {
	TFecha fecha = new _rep_fecha;
	fecha->f = f;
	return fecha;
};

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas ( TFecha f1 , TFecha f2 ) {
	bool esAnterior = false;
		if (f1->f < f2->f) {
			esAnterior = true;
		}
	return esAnterior;
}


unsigned int dia ( TFecha fecha ) {
	int dia = ((fecha->f)%100);
	return dia;
}


unsigned int mes ( TFecha fecha ) {
	int mes = (((fecha->f)%10000)/100);
	return mes;
}


unsigned int anio ( TFecha fecha ) {
	int anio = ((fecha->f)/10000);
	return anio;
}

void ordenarFechas (TFecha arr_fecha[], int arr_tope) {
	TFecha aux;
	for (int i=0; i<arr_tope; i++) {
		for (int j=i; j<arr_tope; j++) {
			if (comparar_fechas(arr_fecha[j],arr_fecha[i])) {
				aux = arr_fecha[j];
				arr_fecha[j] = arr_fecha[i];
				arr_fecha[i] = aux;
			}
		} 
	}
}

int main() {
	int arr_tope = 4;
	TFecha arr_fecha[arr_tope];
	arr_fecha[0] = crear_fecha(20221010);
    arr_fecha[1] = crear_fecha(19921120);
    arr_fecha[2] = crear_fecha(20220515);
    arr_fecha[3] = crear_fecha(19980420);
    ordenarFechas(arr_fecha, arr_tope);
    for(int i = 0; i < arr_tope ; i++) {
    	int d = dia(arr_fecha[i]);
    	int m = mes(arr_fecha[i]);
    	int a = anio(arr_fecha[i]);
    	printf("%d/%d/%d\n",d, m, a);
    }
	return 0;
}