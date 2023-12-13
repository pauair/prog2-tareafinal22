/* 4926846 */


#include "../include/deposito.h"
#include "../include/fecha.h"
#include "../include/colProductos.h"
#include "../include/pila.h"
#include "../include/producto.h"
#include "../include/colProductosPorNombre.h"


struct _rep_deposito {
	TColProductos productos;
	TColProductosPorNombre productosPorNombre;
};


TDeposito crearDeposito() { 
	TColProductos prods = crearColProductos();
	TColProductosPorNombre prodsNombre = crearColProductosPorNombre();
	TDeposito deposito = new _rep_deposito;
	deposito->productos = prods;
	deposito->productosPorNombre = prodsNombre;
	return deposito;
}


void liberarDeposito(TDeposito deposito) {
	TPila pila = colProdAPila(deposito->productos);
	liberarColProductosPorNombre(deposito->productosPorNombre);
	liberarColProductos(deposito->productos);
	while (cantidadEnPila(pila) > 0) {
        liberarProducto(cima(pila));
        pila = desapilar(pila);
    }
    liberarPila(pila);
	delete deposito;
}


nat obtenerCantidadUnidades(TDeposito deposito, int identificador) {
	nat cantUnidades = 0;
	Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
	if (prod != NULL) {
		cantUnidades = obtenerCantidad(prod);
	}
	return cantUnidades;
}


void agregarProducto(TDeposito deposito, nat identificador, char* nombre) {
	bool existeProd = existeProductoEnColProductos(identificador, deposito->productos);
	if (!existeProd) {
		Producto prod = crearProducto(identificador, nombre);
		deposito->productos = insertarEnColProductos(prod, deposito->productos);
		deposito->productosPorNombre = insertarEnColProductosPorNombre(prod, deposito->productosPorNombre);
	}
}


bool existeProducto(TDeposito deposito, nat identificador) { 
	return existeProductoEnColProductos(identificador, deposito->productos);
}


bool existeProductoPorNombre(TDeposito deposito, char* nombreProducto) { 
	return existeProductoEnColProductosPorNombre(nombreProducto, deposito->productosPorNombre); 
}


void quitarVencidosDeposito(TDeposito deposito, TFecha fecha) {
	TPila pila = colProdAPila(deposito->productos);
	while(cantidadEnPila(pila) > 0){
		Producto prod = (Producto) cima(pila);
		pila = desapilar(pila);
		quitarVencidos(prod, fecha);
	}
	liberarPila(pila);
}


void agregarUnidades(TDeposito deposito, nat identificador, nat cantidad, TFecha fVenc) {
	if (existeProductoEnColProductos(identificador, deposito->productos)) {
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		agregarUnidades(prod, cantidad, fVenc);
	}
}


void quitarUnidades(TDeposito deposito, nat identificador, nat cantidad) {
	if (existeProductoEnColProductos(identificador, deposito->productos)) {
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		quitarUnidades(prod, cantidad);
	}
}


void eliminarProducto(TDeposito deposito, nat identificador) {
	if (existeProductoEnColProductos(identificador, deposito->productos)) {
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		deposito->productosPorNombre = removerDeColProductosPorNombre(obtenerNombre(prod),deposito->productosPorNombre);
		deposito->productos = removerDeColProductos(identificador, deposito->productos);
		liberarProducto(prod);
	}
}


void imprimirResumenDeposito(TDeposito deposito) { //NO USADA
	TPila pilaProd = colProdAPila(deposito->productos);
	while (cantidadEnPila(pilaProd) > 0){
		Producto prod = (Producto) cima(pilaProd);
		imprimirProducto(prod);
		pilaProd = desapilar(pilaProd);
	}
	liberarPila(pilaProd);
}


void imprimirProducto(TDeposito deposito, int identificador){
	if (existeProductoEnColProductos(identificador, deposito->productos)) {
		Producto prod = buscarProductoEnColProductos(identificador, deposito->productos);
		imprimirProducto(prod);
	}
}


void imprimirProductoPorNombre(TDeposito deposito, char* nombreProducto) {
	if (existeProductoEnColProductosPorNombre(nombreProducto, deposito->productosPorNombre)) {
		Producto prod = buscarProductoEnColProductosPorNombre(nombreProducto, deposito->productosPorNombre);
		imprimirProducto(prod);
	}
}
