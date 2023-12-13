
struct nodoAB {
	uint elem ;
	nodoAB * izq , * der ;
};

typedef nodoAB * AB ;


//función crear árbol
AB crearArbol() {
	AB t = NULL;
	return t;
}

//función consArbol: que retorna un árbol no vacío a partir de un natural y otros dos árboles
AB consArbol (uint x, AB l, AB r) {
	AB t = new nodoAB;
	t->elem = x;
	t->izq = l;
	t->der = r;
}

//función contarElems: que recibe un árbol y retorna la cantidad de elementos del mismo.
uint contarElems (AB t) {
	if (t == NULL) {
		return 0;
	} else {
		return 1 + contarElems(t->izq) + contarElems(t->der);
	}
}

//función contarHojas: que recibe un árbol y retorna la cantidad de hojas (nodos cuyos ambos
//subárboles son vacíos).
uint contarHojas (AB t) {
	if (t == NULL) {
		return 0;
	} else {
		if () {

		}
	}
}

//función altura: que recibe un árbol y retorna la altura del mismo. Si el árbol es vacío 
//su altura es 0.

//función copiar: que recibe un árbol y retorna una copia limpia (que no comparte registros de
//memoria) del mismo.

//procedimiento liberarArbol: que recibe un árbol y elimina del mismo todos los nodos, liberando
//la memoria asociada a cada uno de ellos.


//---------------------------------------------------------------------------

struct nodoAB {
	uint elem ;
	nodoAB * izq , * der ;
};

typedef nodoAB * AB ;

struct nodoLista {
	uint elem ;
	nodoLista * sig ;
};

typedef nodoLista * Lista ;


//enOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
//recorrida en orden de b

//preOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
//recorrida en pre orden de b.

//postOrden: que recibe un árbol b y retorna una lista con los elementos de b ordenados según la
//recorrida en post orden de b.

//esCamino: que recibe un árbol b y una lista l, y retorna TRUE si y solo si l es igual a un camino
//desde la raíz a un hoja de b.

//caminoMasLargo: que recibe un árbol b y retorna una lista con los elementos del camino más
//largo de b (desde la raíz a una hoja). En caso de haber más de un camino de igual longitud a la del
//camino más largo, retorna cualquiera de ellos.

//función booleana que dados un árbol binario b y un natural h, retorne TRUE si y solo si b es 
//un árbol perfecto de altura h. Se dice que un árbol es perfecto si todas las hojas están en 
//el mismo nivel, o sea, si todos los niveles están completos.

//función booleana que dados un árbol binario b y un natural h, retorne TRUE si y solo si b es 
//un árbol completo de altura h.



