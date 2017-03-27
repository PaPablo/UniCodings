#include "fechas.h"
int esBisiesto(int anio){
	if(!(anio % 4) && (anio % 100)){
		return TRUE;
	}
	else {
		return !(anio % 400);
	}
}

int cantDiasMes(int mes, int anio){
	switch(mes){
		case 1: 
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 31;
			break;
		case 2:
			return esBisiesto(anio) ? 29 : 28;
			break;
		default:
			return ((mes<0)||(mes>12))?0:30;
	}
}

int esFechaValida(Fecha f){
	// si el año es negativo, OUT
	if(f.anio < 0) return 0;

	// si mes es negativo o mayor que doce, OUT
	if((f.mes < 0) || (f.mes > 12)) return 0;
	
	// si dia es negativo o mayor a la cantidad de dias del mes... in
	if((f.dia < 0) || (f.dia > cantDiasMes(f.mes, f.anio))) return 0;
	// haha, NO, OUT

	// si llegué hasta acá, es porque es verdadero
	return 1;
}