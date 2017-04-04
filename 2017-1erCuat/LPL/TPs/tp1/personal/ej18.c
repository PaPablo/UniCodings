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

int listado_personal(Personal personales[], int tope);
int listado_empleados(Personal personales[], int tope);
int listado_gerentes(Personal personales[], int tope);
int print_encabezado_personal();
int print_encabezado_empleado();
int print_encabezado_gerente();

int main(int argc, char const *argv[])
{
	
	Personal p;
	Personal personales[] = {
		{{"Alejandro Perez",{18,3,1996}},GERENTE,{"Adminsitracion Aviaria",10}},
		{{"Alberto Rios",{22,4,1982}},GERENTE,{"Adminsitracion Aviaria",10}},
		{{"Carlos Garcia",{31,12,1990}},GERENTE,{"Adminsitracion Aviaria",10}},
		{{"Juan Osvaldo",{14,5,1986}},GERENTE,{"Adminsitracion Aviaria",10}},
		{{"Juan Santiago",{26,3,1992}},GERENTE,{"Adminsitracion Aviaria",10}},
		{{"Rudecindo Perez",{17,7,1984}},EMPLEADO,{CADETE}},
		{{"Celedonio Perez",{2,8,2000}},EMPLEADO,{SECRETARIO}},
		{{"Juan Perez",{1,10,1978}},EMPLEADO,{MAQUINISTA}},
		{{"Juan Perez",{12,11,1991}},EMPLEADO,{CADETE}},
		{{"Juan Perez",{9,3,1995}},EMPLEADO,{CADETE}}};

	listado_personal(personales,10);
	printf("\n\n");
	listado_empleados(personales,10);
	printf("\n\n");
	listado_gerentes(personales,10);

	//printf("Nombre: %s\nFecha de Nacimiento %d/%d/%d\nCargo: %d\nOficina a cargo: %s\nEmpleados a cargo: %d\n",
	//	p.datos_personales.nombre, p.datos_personales.fecha_nac.dia, p.datos_personales.fecha_nac.mes, p.datos_personales.fecha_nac.anio, p.cargo,p.info_adicional.datos_gerente.nombre_oficina,p.info_adicional.datos_gerente.empleados_a_cargo);

	return 0;
}

int print_encabezado_personal(){
	printf("NOMBRE\t\t\t|DIA\t|MES\t|AÑO\t|\n");
	printf("------------------------------------------------|\n");
}
int print_encabezado_empleado(){
	printf("NOMBRE\t\t\t|DIA\t|MES\t|AÑO\t|FUNCION\n");
	printf("--------------------------------------------------------------------\n");
}
int print_encabezado_gerente(){
	printf("NOMBRE\t\t\t|DIA\t|MES\t|AÑO\t|NOMBRE DE OFICINA\t|EMPLEADOS A CARGO\n");
	printf("--------------------------------------------------------------------------------\n");
}

int listado_personal(Personal personales[], int tope){
	print_encabezado_personal();
	for(int i = 0; i < tope; i++){
		printf("%s\t\t|%d\t|%d\t|%d\t|\n",
			personales[i].datos_personales.nombre,
			personales[i].datos_personales.fecha_nac.dia,
			personales[i].datos_personales.fecha_nac.mes,
			personales[i].datos_personales.fecha_nac.anio);
	}
};
int listado_empleados(Personal personales[], int tope){
	print_encabezado_empleado();
	for(int i = 0; i < tope; i++){
		if(personales[i].cargo==EMPLEADO){
			printf("%s\t\t|%d\t|%d\t|%d\t|%d\n",
				personales[i].datos_personales.nombre,
				personales[i].datos_personales.fecha_nac.dia,
				personales[i].datos_personales.fecha_nac.mes,
				personales[i].datos_personales.fecha_nac.anio,
				personales[i].info_adicional.datos_empleado.funcion);
		}
	}
};
int listado_gerentes(Personal personales[], int tope){
	print_encabezado_gerente();
	for(int i = 0; i < tope; i++){
		if(personales[i].cargo==GERENTE){
			printf("%s\t\t|%d\t|%d\t|%d\t|%s\t|%d\n",
				personales[i].datos_personales.nombre,
				personales[i].datos_personales.fecha_nac.dia,
				personales[i].datos_personales.fecha_nac.mes,
				personales[i].datos_personales.fecha_nac.anio,
				personales[i].info_adicional.datos_gerente.nombre_oficina,
				personales[i].info_adicional.datos_gerente.empleados_a_cargo);
		}
	}
};