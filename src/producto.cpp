/* 4926846 */

#include "../include/utils.h"
#include "../include/fecha.h"
#include "../include/producto.h"
#include "../include/lista.h"


struct _rep_producto{
	nat id;
	char* nombre;
	nat cantidadUnidades;
	TLista unidades;
};


Producto crearProducto(nat identificadorDeProducto, char* nombre){
	Producto nuevo = new _rep_producto;
	nuevo->id = identificadorDeProducto;
	nuevo->nombre = copiarCadenaChar(nombre);
	nuevo->unidades = crearLista();
	nuevo->cantidadUnidades = 0;
	return nuevo;
} 


void liberarProducto(Producto producto){
	delete []producto->nombre;
	liberarLista(producto->unidades);
	delete producto;
}


nat obtenerCantidad(Producto producto){
	return producto->cantidadUnidades;
}


nat obtenerIdentificadorDeProducto(Producto producto){
	return producto->id;
}

char* obtenerNombre(Producto producto){
	return producto->nombre;
}


void agregarUnidades(Producto producto, nat cantidad, TFecha f_venc){
	producto->cantidadUnidades += cantidad;
	producto->unidades = agregarAListaOrdenado(producto->unidades, f_venc, cantidad);
} 


void quitarUnidades(Producto producto, nat cantidad){
	producto->cantidadUnidades < cantidad ? producto->cantidadUnidades = 0 : producto->cantidadUnidades -= cantidad;
	producto->unidades = quitarDeLista(producto->unidades, cantidad);
} 


void quitarVencidos(Producto producto, TFecha fecha){
	bool continuar = true;
	while(!esVaciaLista(producto->unidades) && continuar){
		Vencimiento venc = obtenerMasViejo(producto->unidades);
		TFecha f_venc = obtenerFVencimiento(venc);
		if (compararFechas(f_venc, fecha) != 1){ // el vencimiento es menor o igual a la fecha
			producto->cantidadUnidades -= obtenerCantidad(venc);
			producto->unidades = quitarMasViejo(producto->unidades);
			liberarVencimiento(venc);
		}else{
			continuar = false; 
		}
	}
} 


void quitarProximosAVencer(Producto producto, nat cantidadDias){}


void imprimirProducto(Producto producto){
  printf("Información del producto %d - %s\n", producto->id, producto->nombre);
  printf("Total de unidades: %d\n", producto->cantidadUnidades);
  imprimirInfoLista(producto->unidades);
} 