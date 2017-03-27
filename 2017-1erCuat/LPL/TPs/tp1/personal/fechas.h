#ifndef FECHAS_
#define FECHAS_

#define TRUE 1
#define FALSE 0
typedef struct {
	int dia;
	int mes;
	int anio;
} Fecha;

int esBisiesto(int anio);
int cantDiasMes(int mes, int anio);
int esFechaValida(Fecha f);

#endif