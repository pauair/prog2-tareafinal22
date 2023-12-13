#include <stdio.h>

struct nodo {
	int elem ;
	nodo * sig ;
};

typedef nodo * lista ;


//last: dada una lista no vacía, retorna su último elemento.
int last (lista l) {
	lista q = l;
	while (q->sig != NULL) {
		q = q->sig;
	}
	return (q->elem);
}

//average: dada una lista no vacía, retorna el promedio de sus elementos.
int average (lista l) {
	lista q = l;
	int aux = (q->elem)/2;
	while (q->sig != NULL) {
		q = q->sig;
		aux = aux + (q->elem/2);
	}
	return aux;
}

//insOrd: dados un entero x y una lista l ordenada: inserta x en l ordenadamente. 
//Comparar con la solución recursiva.
lista insOrd (int x, lista &l) {
	lista q, p = l;
	if (l == NULL) {
		q = new nodo;
		q->elem = x;
		q->sig = NULL;
		l = q;
	} else if (l->sig == NULL) {
		q = new nodo;
		q->elem = x;
		if (q->elem > l->elem) {
			q->sig = NULL;
			l->sig = q;
		} else {
			q->sig = l;
			l = q;
		}
	} else {
		while (((q->sig->elem) < x) && (q->sig->sig != NULL)) {
			q = q->sig;
		}
		p = new nodo;
		p->elem = x;
		p->sig = q->sig;
		q->sig = p;
		p = NULL;
	}
	q = NULL;
	return l;
}

//snoc: dados un entero x y una lista l, inserta x al final de l.

lista snoc (int x,lista &l) {
	lista q = l;
	if (l == NULL) {
		q = new nodo;
		q->elem = x;
		q->sig = NULL;
		l = q;
	} else {
		while (q->sig != NULL) {
			q = q->sig;
		}
		q->sig = new nodo;
		q->elem = x;
		q->sig = NULL;
	}
	return l;
}

//removeAll: dados un entero x y una lista l, elimina a x de l.
lista removeAll (int x, lista &l) {
	lista q, p = l;
	if (l != NULL) {
		if ((q->sig == NULL) || (q->elem == x)) {
			if (q->elem == x) {
				l = q->sig;
				delete q;
				q = NULL;
			}
		} else {
			while (q->sig != NULL) {
				if (q->sig->elem == x) {
					p = q->sig;
					q->sig = p->sig;
					delete p;
					p = NULL;
				}
				if (q != NULL) {
					q = q->sig;
				}
			}
		}

	}
	return l;
}

//isIncluded: dadas dos listas l y p, verifica si l está incluida en p. Una lista l1 está incluida en 
//l2 si y sólo sí existen dos listas, l3 y l4, tal que cumplen que l2 = l3l1l4. Tenga en cuenta que 
//las listas li, con i ∈ {1, ..., 4} pueden ser vacías.
bool isIncluded (lista l, lista p) {
	bool isInc = false;
	lista p_aux = p;
	lista l_aux = l;
	if (l == NULL) {
		isInc = true;
	} else {
		while ( p != NULL && !isInc) {
			while (p != NULL && p->elem != l->elem) {
				p = p->sig;
			}
			while (p_aux != NULL && l_aux != NULL && p_aux->elem == l_aux->elem) {
				p_aux = p_aux->sig;
				l_aux = l_aux->sig;
			}
			isInc = (l_aux == NULL);
			if (p != NULL) {
				p = p->sig;
			}	
		}
	}
	return isInc;
}

/*
la lista es vacia? 
	retorna true
si no es vacia
	mientras no llego al final de p && l no está incluida, hacer
		mientras no es el final de p && p elem es distinto de l elem
			sigo buscando en p
		mientras no es el final de p aux && no es el final de l && p elem y l elem iguales
			sigo comparando l aux y p aux
		esta incluida si es el final de l aux 
		si no es el final de p,
			sigo buscando en p,
*/


//take: dado un natural i y una lista l, retorna la lista resultado de tomar los primeros i elem de l  
lista take (int i, lista l) {
	lista p, p_aux = NULL;
	int aux = i;
	if (l != NULL) {
		lista l_aux = l->sig;
		p = new nodo;
		p->elem = l->elem;
		p->sig = NULL;
		p_aux = p;
		while (l_aux != NULL && aux != 1) {
			p_aux->sig = new nodo;
			p_aux = p_aux->sig;
			p_aux->elem = l_aux;
			p_aux->sig = NULL;
			l_aux = l_aux->sig;
			aux--;
		}
	}
	return p;
}

//drop: dado un natural i y una lista l, retorna la lista resultado de eliminar los primeros i elementos de l.

//mergeSort: dadas dos listas ordenadas l y p, genera una lista intercalando ordenadamente ambas listas.

//concat: dadas dos listas l y p, retorna una lista que contiene a los elementos de l y luego a los elementos de p, en el mismo orden. Comparar con la solución recursiva

