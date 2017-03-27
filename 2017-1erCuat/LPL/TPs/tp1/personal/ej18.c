#include <stdio.h>
#include <string.h>

#include "fechas.c"

typedef enum {
	EMPLEADO = 0,
	GERENTE
} Cargo;
typedef enum {
	MAQUINISTA = 0,
	SECRETARIO,
	CADETE
} Funcion_Empleado;

typedef struct {
	char nombre[50];
	Fecha fecha_nac;
	Cargo cargo;
	union info_personal{
		struct d_gerente {
			char nombre_oficina[100];
			int empleados_a_cargo;
		} datos_gerente;
		struct d_empleado{
			Funcion_Empleado funcion;
		} datos_empleado;
	} info_adicional;
} Personal;

int main(int argc, char const *argv[])
{
	Personal p;

	strcpy(p.nombre, "Juan Carlos Garcia");
	p.fecha_nac.dia = 1;
	p.fecha_nac.mes = 1;
	p.fecha_nac.anio = 1996;
	p.cargo = GERENTE;
	strcpy(p.info_adicional.datos_gerente.nombre_oficina, "Mantenimiento Oficinas");
	p.info_adicional.datos_gerente.empleados_a_cargo = 10;

	printf("Nombre: %s\nFecha de Nacimiento %d/%d/%d\nCargo: %d\nOficina a cargo: %s\nEmpleados a cargo:%d\n",
		p.nombre, p.fecha_nac.dia, p.fecha_nac.mes, p.fecha_nac.anio, p.cargo,p.info_adicional.datos_gerente.nombre_oficina,p.info_adicional.datos_gerente.empleados_a_cargo);

	return 0;
}