#include <stdio.h>

#define TRUE 1
#define FALSE 0
struct fecha {
	int dia;
	int mes;
	int anio;
};

/* cantDiasMes(mes,año), esBisiesto(año) y esFechaValida(fecha) */


int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);
int esFechaValida(struct fecha f);

int main(int argc, char const *argv[]) {

	return 0;
}

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
			return 30;
	}
}

int esFechaValida(struct fecha f){
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