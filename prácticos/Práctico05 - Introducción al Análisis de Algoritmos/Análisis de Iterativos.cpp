
EJERCICIO1 - TRASPONER

void trasponer (int ** A , int n ) {
	for (int i = 1; i < n ; i ++)
		for (int j = 0; j < i ; j ++) {
			int swap = A [ i ][ j ];
			A [ i ][ j ] = A [ j ][ i ];
			A [ j ][ i ] = swap ;
		}
}


T(n) ≤ c2 + SUM(desde i=1 hasta n-1) ((c3 + c4 + c2 + (SUM(desde j=0 hasta i-1) (((c3 + c4 + 3.c1))) + c3 ) + c3


c1: asignaciones que involucran elementos del arreglo
c2: otras asignaciones
c3: comparaciones
c4: incrementos

c2: Asigno i=1;
sumatoria de c3: comparo i con n + c4: incremento i + c2: inicializo j=0
sumatoria de c3: comparo j con i + c4: incremento j + 3.c1: asignaciones en el arreglo
c3: la última comparación entre i y j, cuando no entro al segundo for
c3: la última comparación entre i y n, cuando no entro al primer for

Desarrollo de la expresión:

T(n) ≤ c2 + c3 + (n-1) (2.c3 + c4 + c2) + (((n-1)n)/2) (c3 + c4 + 3.c1)


¿Cuáles de las siguientes afirmaciones es verdadera? Justifique
1. T(n) = O(n3)
2. T(n) = Ω(n2)
3. T(n) = O(n)
4. T(n) = O(3n2)

Tiene dos for anidados por lo que en principio sería orden n2. Y si es orden cuadrado también podría ser n3
Queremos verificar 1. T(n) = O(n3) y 4. T(n) = O(3n2)


