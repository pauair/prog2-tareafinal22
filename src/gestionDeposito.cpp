/* 4926846 */


#include "../include/utils.h"
#include "../include/fecha.h"
#include "../include/gestionDeposito.h"
#include "../include/deposito.h"


struct _rep_gestionDeposito{
	TDeposito deposito;
};


TGestionDeposito crearGestionDeposito() { 
	TGestionDeposito nuevo = new _rep_gestionDeposito;
	nuevo->deposito = crearDeposito();
	return nuevo;
}


void liberarGestionDeposito(TGestionDeposito gestionDeposito) {
	liberarDeposito(gestionDeposito->deposito);
	delete gestionDeposito;
}


void quitarVencidosDeposito(TGestionDeposito gestionDeposito, TFecha fecha) {
	quitarVencidosDeposito(gestionDeposito->deposito, fecha);
}


bool agregarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, char* nombreProducto) {
	if (!existeProducto(gestionDeposito->deposito, idProd)){
		agregarProducto(gestionDeposito->deposito, idProd, nombreProducto);
		return true;
	}
	else
		return false;
}


bool agregarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad, TFecha f, TFecha f_actual) { 
	if ((existeProducto(gestionDeposito->deposito, idProd)) && (definidaFecha(f_actual)) && (compararFechas(f_actual, f) != 1)){
		agregarUnidades(gestionDeposito->deposito, idProd, cantidad, f);
		return true;
	}
	else
		return false;
}


bool quitarCantidadProductoDeposito(TGestionDeposito gestionDeposito, nat idProd, nat cantidad) { 
	if (existeProducto(gestionDeposito->deposito, idProd)){
		quitarUnidades(gestionDeposito->deposito, idProd, cantidad);
		return true;
	}
	else
		return false; 
}


bool quitarProductoDeposito(TGestionDeposito gestionDeposito, nat idProd) { //usada
	bool ret = false;
	if (existeProducto(gestionDeposito->deposito, idProd)){
		if (obtenerCantidadUnidades(gestionDeposito->deposito, idProd) == 0){
			eliminarProducto(gestionDeposito->deposito, idProd);
			ret = true;
		}
	}
	return ret;
}


bool imprimirProductoResumenDeposito(TGestionDeposito gestionDeposito, nat idProd) {
	bool ret = false;
	if (existeProducto(gestionDeposito->deposito, idProd)) {
		imprimirProducto(gestionDeposito->deposito, idProd);
		ret = true;
	}
	return ret;
}


bool imprimirProductoResumenDepositoPorNombre(TGestionDeposito gestionDeposito, char* nombreProducto) { 
	if (existeProductoPorNombre(gestionDeposito->deposito, nombreProducto)) {
		imprimirProductoPorNombre(gestionDeposito->deposito, nombreProducto);
		return true;
	} else {
		return false; 
	}
}


void quitarProximosAVencerDeposito(TGestionDeposito gestionDeposito, TFecha fecha) {
	aumentarFecha(fecha, 7);
	quitarVencidosDeposito(gestionDeposito->deposito, fecha);
}


void imprimirResumenGestionDeposito(TGestionDeposito gestionDeposito) {
	imprimirResumenDeposito(gestionDeposito->deposito);
}
