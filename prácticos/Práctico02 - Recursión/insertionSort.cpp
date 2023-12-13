
typedef unsigned int uint ;

/* Inserta e en A [1.. n+1] de manera ordenada .
Precondición: n >=0. Si n >=1 => A [1.. n] está ordenado de manera creciente. 
A[n+1] es indeterminado.
Postcondición: A [1.. n +1] queda ordenado de manera creciente. */
void insertarOrdenado ( float * A , uint n , float e ) {
	if ((n==0) || (e>=A[n])) {
		A[n+1] = e;
	} 
	else {
		A[n+1] = A[n];
		insertarOrdenado(A,n-1,e);
	}
}

void insertarOrdenado ( float * A , uint n , float e ) {
	while ((n > 0) && (e > A[n])) {
		A[n+1] = A[n];
		n--;
	}
	A[n+1] = e;
}

/* Ordena A [1.. n] de manera creciente . */
void ordenar ( float * A , uint n ) {
	if (n>1) {
		ordenar(A,n-1);
		insertarOrdenado(A,n-1,A[n]);
	}
}

