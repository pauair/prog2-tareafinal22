struct nodo_doble {
	int elem ;
	nodo_doble * sig ;
	nodo_doble * ant ;
};

typedef nodo_doble * lista ;

//null: retorna una lista vacía.
lista null () {
	lista l = NULL;
	return l;
}

//cons: dados un entero x y una lista l, retorna el resultado de insertar x al principio de l
lista cons (int x, lista l) {
	lista q = new nodo_doble;
	q->elem = x;
	q->sig = l;
	q->ant = NULL;
	l = q;
	q = NULL;
	return l;
}

//isEmpty: dada una lista l, verifica si l está vacía.
bool isEmpty (lista l) {
	return (l == NULL)
}

//isElement: dados un entero x y una lista l, verifica si x pertenece a l
bool isElement (int x, lista l) {
	while ((l != NULL) && (l->elem != x)) {
		l = l->sig;
	}
	return (l->elem != NULL);
}

//removeAll: dados un entero x y una lista l, retorna el resultado de eliminar todas las ocurrencias de x de l
lista removeAll (int x, lista l) {
	lista q, p = l; 
	if (l != NULL) {
		if (l->sig == NULL) || (l->elem == x) {
			if (l->elem == x) {
				l = q->sig;
				delete q;
				q = NULL;
			}
		} else {
			while (q != NULL) {
				if (q->elem == x) {
					p = q->ant;
					p->sig = q->sig;
					p->sig->ant = p;
					delete q;
					q = p;
				}
				q = q->sig;
		}
	}
}

//insOrd: dados un entero x y una lista l ordenada, retorna el resultado de insertar x en l ordenadamente.


//LISTA INDIZADA (Manejo explícito de posiciones)


//isDefined: dados un natural p y una lista l, retorna verdadero si, y solamente si, 
//existe un elemento en esa posición
bool isDefined (int p, lista l) {
	lista q = l;
	if (l != NULL) {
		while (q != NULL && p != 0) {
			q = q->sig;
			p--;
		}
		return (p == 0);
	} else {
		return false;
	}
}


//insert: dados un entero x, un natural p y una lista l de longitud m, inserta a x en la lista. 
//Si p no esta definida, inserta a x en la posición m. En otro caso, inserta a x en la posición p y 
//desplaza en una posición los elementos que estuvieran en las posiciones siguientes.


//element: dados un natural p y una lista l, retorna el elemento en la posición p. 
//Tiene como precondición que la posición p esté definida.


//remove: dados un natural p y una lista l, elimina de la lista el elemento que se encuentra 
//en la posición p. Si la posición no está definida, la operación no tiene efecto. 
//Si la posición está definida, elimina el elemento en dicha posición y desplaza en una posición 
//los elementos que estuvieran en las posiciones posteriores a p (contrae la lista).