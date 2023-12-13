#include <stdio.h>

// Registro con dia d, mes m y año a
struct _rep_fecha {
unsigned int d ;
unsigned int m ;
unsigned int a ;
};

typedef struct _rep_fecha* TFecha;

/* Devuelve un 'TFecha ' con dia d, mes m y año a */
TFecha crear_fecha ( unsigned int d , unsigned int m , unsigned int a ) {
	TFecha fecha = new _rep_fecha;
	fecha->d = d;
	fecha->m = m;
	fecha->a = a;
	return fecha; 
};

/* Devuelve true si f1 es anterior a f2 , false en otro caso */
bool comparar_fechas ( TFecha f1 , TFecha f2 ) {
	bool anterior = false;
	if ((f1->a < f2->a) || ((f1->a == f2->a) && (f1->m < f2->m)) || ((f1->a == f2->a) && (f1->m == f2->m) && (f1->d < f2->d))) {
		anterior = true;
	}
	return anterior;
};

/* Devuelve el día correspondiente a fecha */
unsigned int dia ( TFecha fecha ) {
	return (fecha->d);
};

/* Devuelve el mes correspondiente a fecha */
unsigned int mes ( TFecha fecha ) {
	return (fecha->m);
};
/* Devuelve el año correspondiente a fecha */
unsigned int anio ( TFecha fecha ) {
	return (fecha->a);
};


void ordenarFechas(TFecha arr_fecha[], int arr_tope) {
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
	int tope = 4;
	TFecha arr_fecha[4];
	arr_fecha[0] = crear_fecha(10,10,2022);
	arr_fecha[1] = crear_fecha(20,04,1998);
	arr_fecha[2] = crear_fecha(20,11,1992);
	arr_fecha[3] = crear_fecha(15,05,2022);
	ordenarFechas(arr_fecha, tope);
	for(int i = 0; i < tope ; i++) {
		int d = dia(arr_fecha[i]);
		int m = mes(arr_fecha[i]);
		int a = anio(arr_fecha[i]);
    	printf("%d/%d/%d\n", d, m, a);
	}
	return 0;
}

