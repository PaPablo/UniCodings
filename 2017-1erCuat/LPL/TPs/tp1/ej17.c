#include <stdio.h>

#define TRUE 1
#define FALSE 0
struct fecha {
	int dia;
	int mes;
	int anio;
};

typedef struct fecha Fecha;

/* cantDiasMes(mes,año), esBisiesto(año) y esFechaValida(fecha) */


int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);
int esFechaValida(struct fecha f);

int main(int argc, char const *argv[]) {

	Fecha f2;
	f2.dia = 29;
	f2.mes = 2;
	f2.anio = 2016;

	struct fecha f1;
	f1.dia = 29;
	f1.mes = 2;
	f1.anio = 2016;

	printf("%d es bisiesto: %s\nEl mes %d tiene %d dias\nY %d/%d/%d %ses una fecha valida\n",
		f1.anio, esBisiesto(f1.anio)?"si":"no",f1.mes, cantDiasMes(f1.mes,f1.anio),f1.dia,f1.mes,f1.anio,esFechaValida(f1)?"":"no ");
	printf("%d es bisiesto: %s\nEl mes %d tiene %d dias\nY %d/%d/%d %ses una fecha valida\n",
		f2.anio, esBisiesto(f2.anio)?"si":"no",f2.mes, cantDiasMes(f2.mes,f2.anio),f2.dia,f2.mes,f2.anio,esFechaValida(f2)?"":"no ");
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
			return ((mes<0)||(mes>12))?0:30;
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