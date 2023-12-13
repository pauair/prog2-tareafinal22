struct nodo {
	int elem ;
	nodo * sig ;
};

struct cabezal {
	nodo * primero ;
	nodo * actual ;
};

typedef cabezal * lista;

//null: crea una lista vacía.
lista null () {
	lista l = new cabezal;
	l->primero, l->actual = NULL;
	return l;
}

//start: dada una lista l no vacía, coloca la posición actual al inicio de l.
void start (lista &l) {
	if (l->primero != NULL) {
		l->actual = l->primero;
	}
}

//next: dada una lista l no vacía, mueve la posición actual al siguiente nodo (elemento). 
//En caso de que la posición actual sea el final de la lista, coloca la posición actual al inicio 
//de la lista (tiene un comportamiento circular).
void next (lista &l) {
	if (l->primero != NULL) {
		if (l->actual->sig != NULL) {
			l->actual = l->actual->sig;
		} else {
			l->actual = l->primero;
		}
	}
}

//insert: dados un entero x y una lista l, inserta el elemento x luego de la posición actual en la lista.
//La posición actual pasa a ser el elemento (nodo) recién insertado. Si la lista l está vacía, el 
//resultado es la lista unitaria que contiene a x, siendo este elemento la posición actual en la lista resultado. 
lista insert (int x, lista &l) {
	nodo* q =  new nodo;
	q->elem = x;
	if (l->actual == NULL) {
		l->primero, l->actual = q;
		q->sig = NULL;
	} else {
		q->sig = l->actual->sig;
		l->actual->sig = q;
		l->actual = q;
	}
	q = NULL;
	return l;
}

//element: dada una lista l no vacía, retorna el elemento en la posición actual de l.
int element (lista l) {
	return (l->actual->elem)
}