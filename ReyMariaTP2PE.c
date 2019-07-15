#include <stdio.h>

// variables de entrada

int nroVendedor = 0;
int nroCurso = 0;
int cantidadAlumnos = 0;
int cursoPorVendedor[4][4] = {0,0};
float comisionPorVendedor[4] = {0};

int main(int argc, char *argv[])
{
	
	ingresarDatos();
	totalPorCurso();
	totalPorVendedor();
	imprimirComision();
	
    system("PAUSE");
    return 0;
}

int continuar = 1;

void ingresarDatos(){
	int input;
	int continuar = 1;
	
	while (continuar == 1) {
		
		printf("1. Cargar datos \n");
		printf("2. Salir \n");
	    scanf("%d", &input);
	       		
		  switch (input) {
		   	case 1:
		   		printf("Ingrese nro vendedor:\n");
	       		scanf("%d", &nroVendedor);
	       		printf("Ingrese nro curso: \n");
	       		scanf("%d", &nroCurso);
	       		printf("Ingrese cantidad de inscriptos:\n");
	       		scanf("%d", &cantidadAlumnos);
	       		cursoPorVendedor[nroCurso][nroVendedor] += cantidadAlumnos;
	       		printf("Ingrese comision\n:");
	       		scanf("%f", &comisionPorVendedor[nroVendedor]);
		   		printf("%d \n:", cursoPorVendedor[nroCurso][nroVendedor]);
				break;
		   		
		   	case 2:
		   		continuar = 0;
		   		printf("Fin\n");
		   		break;
		   		
		   	default:
		   		continuar = 0;
		   		printf("Fin\n");
		   		break;
		   }	
	}
}

void totalPorCurso () {
	int totalPorCurso = 0;
	int i, j = 0;
	for (i; i < 4; i++) {
		for (i; j < 4; j++) {
			totalPorCurso += cursoPorVendedor[i][j];
		}
		printf("Curso nro %d tiene %d alumnos \n", i, totalPorCurso);
		totalPorCurso = 0;
	}
}

void totalPorVendedor () {
	int totalPorVendedor = 0;
	int i, j = 0;
	for (i; i < 4; i++) {
		for (i; j < 4; j++) {
			totalPorVendedor += cursoPorVendedor[i][j];
			printf("Vendedor %d sumó %d alumnos \n", j, totalPorVendedor);
		}
		totalPorVendedor = 0;
	}
}

void imprimirComision () {
	int i = 0;
	for (i; i < 4; i++) {
		printf("Vendedor %d recibió %f de comisión \n",i, comisionPorVendedor);
	}
}
