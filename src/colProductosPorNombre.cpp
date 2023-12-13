/* 4926846 */


#include "../include/producto.h"
#include "../include/utils.h"
#include "../include/listaProductos.h"
#include "../include/colProductosPorNombre.h"


struct rep_colproductospornombre {
	TListaProductos listaProds[CANTIDAD_PROD];
};


TColProductosPorNombre crearColProductosPorNombre() { 
	TColProductosPorNombre nuevo = new rep_colproductospornombre;
	for (nat i = 0; i<CANTIDAD_PROD; i++) {
			nuevo->listaProds[i] = crearListaProductos();
		}
	return nuevo; 
}


void liberarColProductosPorNombre(TColProductosPorNombre& colProd) {
	if (colProd != NULL) {
		for (nat i = 0; i<CANTIDAD_PROD; i++) {
			liberarListaProductos(colProd->listaProds[i]);
		}
	}
	delete colProd;
	colProd = NULL;
}


bool existeProductoEnColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd) { 
	if (colProd != NULL) {
		return (existeProductoListaProductos(colProd->listaProds[funcionHash(nombreProducto)], nombreProducto));
	} else {
		return false;
	}
}


Producto buscarProductoEnColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd) { 
	return (obtenerProductoListaProductos(colProd->listaProds[funcionHash(nombreProducto)], nombreProducto));
}


TColProductosPorNombre insertarEnColProductosPorNombre(Producto dato, TColProductosPorNombre colProd) { 
	if (!existeProductoEnColProductosPorNombre(obtenerNombre(dato),colProd)) {
		TListaProductos p =  colProd->listaProds[funcionHash(obtenerNombre(dato))];
		p = agregarAListaProductos(p, dato);
		colProd->listaProds[funcionHash(obtenerNombre(dato))] = p;
		p = NULL;
	}
	return colProd; 
}


TColProductosPorNombre removerDeColProductosPorNombre(char* nombreProducto, TColProductosPorNombre colProd) { 
	if (existeProductoListaProductos(colProd->listaProds[funcionHash(nombreProducto)],nombreProducto)) {
		TListaProductos p = colProd->listaProds[funcionHash(nombreProducto)];
		p = quitarDeListaProductos(p, nombreProducto);
		colProd->listaProds[funcionHash(nombreProducto)] = p;
	}
	return colProd; 
}
