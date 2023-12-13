/* 4926846 */


#include "../include/utils.h"
#include "../include/producto.h"
#include "../include/fecha.h"
#include "../include/listaProductos.h"


struct _rep_listaProductos{
    _rep_listaProductos* sig;
    Producto prod;
};


TListaProductos crearListaProductos() { 
    return NULL; 
}


void liberarListaProductos(TListaProductos &p) {
    while(p != NULL){
        TListaProductos aux = p;
        p = p->sig;
        delete aux;
    }
}


bool esVaciaListaProductos(TListaProductos p) { 
    return p == NULL; 
}


bool existeProductoListaProductos(TListaProductos p, char* nombreProducto) {
    while ((p != NULL) && (!igualesCadenaCHar(obtenerNombre(p->prod),nombreProducto))) {
        p = p->sig;
    }
    return p != NULL; 
}


TListaProductos agregarAListaProductos(TListaProductos p, Producto prod) { 
    TListaProductos aux = new _rep_listaProductos;
    aux->prod = prod;
    aux->sig = p;
    p = aux;
    return p;
}


Producto obtenerProductoListaProductos(TListaProductos p, char* nombreProducto) { 
    if (existeProductoListaProductos(p, nombreProducto)) {
        while ((p != NULL) && (!igualesCadenaCHar(obtenerNombre(p->prod),nombreProducto))) {
            p = p->sig;
        }
        return p->prod;
    } else {
        return NULL;
    }
}


TListaProductos quitarDeListaProductos(TListaProductos p, char* nombreProducto) { 
    if (p != NULL) {
        TListaProductos aux = p;
        TListaProductos prev = NULL;
        while ((aux != NULL) && (!igualesCadenaCHar(obtenerNombre(aux->prod),nombreProducto))) {
            prev = aux;
            aux = aux->sig;
        } 
        if (prev == NULL) {
            p = p->sig;
            delete aux;
        } else {
            prev->sig = aux->sig;
            delete aux;
        }
    }
    return p;
}
