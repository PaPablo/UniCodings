#include <stdio.h>
#include <string.h>

#include "fechas.c"

typedef enum {
	EMPLEADO = 0,
	GERENTE
} t_cargo;

typedef enum {
	MAQUINISTA = 0,
	SECRETARIO,
	CADETE
} t_funcion_empleado;

typedef struct {
	char nombre[50];
	Fecha fecha_nac;
} t_persona;

typedef struct {
	char nombre_oficina[100];
	int empleados_a_cargo;
} t_datos_gerente;

typedef struct {
	t_funcion_empleado funcion;
} t_datos_empleado;

typedef struct {
	t_persona datos_personales;
	t_cargo cargo;
	union {
		t_datos_gerente datos_gerente;
		t_datos_empleado datos_empleado;
	} info_adicional;
} Personal;


int main(int argc, char const *argv[])
{
	
	Personal p;

	strcpy(p.datos_personales.nombre, "Juan Carlos Garcia");
	p.datos_personales.fecha_nac.dia = 1;
	p.datos_personales.fecha_nac.mes = 1;
	p.datos_personales.fecha_nac.anio = 1996;
	p.cargo = GERENTE;
	strcpy(p.info_adicional.datos_gerente.nombre_oficina, "Mantenimiento Oficinas");
	p.info_adicional.datos_gerente.empleados_a_cargo = 10;

	printf("Nombre: %s\nFecha de Nacimiento %d/%d/%d\nCargo: %d\nOficina a cargo: %s\nEmpleados a cargo: %d\n",
		p.datos_personales.nombre, p.datos_personales.fecha_nac.dia, p.datos_personales.fecha_nac.mes, p.datos_personales.fecha_nac.anio, p.cargo,p.info_adicional.datos_gerente.nombre_oficina,p.info_adicional.datos_gerente.empleados_a_cargo);

	return 0;
}