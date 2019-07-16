#include <stdio.h>
#include "ReyMariaTP2PE.h"

// variables de entrada

int nroVendedor = 0;
int nroCurso = 0;
int cantidadAlumnos = 0;
int costoCursos[20] = { 0 };
int cursoPorVendedor[5][20] = { 0,0 };
float comisionPorVendedor[5] = { 0 };

int main(int argc, char* argv[])
{
	ingresarCursos();
	ingresarDatos();
	totalPorCurso();
	totalPorVendedor();
	recaudacionPorCurso();
	mayorAsistenciaCurso();
	vendedorTopCurso(3);
	cursosCero();
	cursoCeroPorVendedor(4);
	imprimirComision();

	system("PAUSE");
	return 0;
}

ingresarCursos() {

	for (int i = 0; i < 20; i++) {
		printf("Cargando curso  nro %d\n", i);
		//TODO: falta nombre
		printf("Ingrese costo curso:\n");
		scanf_s("%d", &costoCursos[i]);
	}
}

ingresarDatos() {
	int input;
	int continuar = 1;

	while (continuar == 1) {

		printf("1. Cargar datos \n");
		printf("2. Salir \n");
		scanf_s("%d", &input);

		switch (input) {
		case 1:
			printf("Ingrese nro vendedor:\n");
			scanf_s("%d", &nroVendedor);
			printf("Ingrese nro curso:\n");
			scanf_s("%d", &nroCurso);
			printf("Ingrese cantidad de inscriptos:\n");
			scanf_s("%d", &cantidadAlumnos);
			printf("Ingrese comision:\n");
			scanf_s("%f", &comisionPorVendedor[nroVendedor]);


			cursoPorVendedor[nroCurso][nroVendedor] += cantidadAlumnos;
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

recaudacionPorCurso() {

	for (int i = 0; i < 5; i++) {
		int recaudacionPorCurso = 0;
		for (int j = 0; j < 20; j++) {
			recaudacionPorCurso += cursoPorVendedor[i][j] * costoCursos[j];
		}
		printf("Curso nro %d recaudo %d \n", i+1, recaudacionPorCurso);
		recaudacionPorCurso = 0;
	}
}

vendedorTopCurso(int curso) {
	int vendedorMaximo = 0;
	int maximoVendedor = 0;

	for (int i = 0; i < 5; i++) {
		int totalPorCurso = 0;
		totalPorCurso += cursoPorVendedor[i][curso];

		if (maximoVendedor < cursoPorVendedor[i][curso]) {
			maximoVendedor = cursoPorVendedor[i][curso];
			vendedorMaximo = i;
		}
	}

	printf("El vendedor que mas vendio en el curso %d fue %d\n", curso+1, vendedorMaximo);
}

mayorAsistenciaCurso() {
	int vendedorMaximo = 0;
	int maximoVendedor = 0;
	int cursoMaximo = 0;
	int maximoCurso = 0;
	for (int j = 0; j < 20; j++) {
		int totalPorCurso = 0;
		for (int i = 0; i < 5; i++) {
			totalPorCurso += cursoPorVendedor[i][j];

			if (maximoVendedor < cursoPorVendedor[i][j]) {
				maximoVendedor = cursoPorVendedor[i][j];
				vendedorMaximo = i;
			}
		}

		if (maximoCurso < totalPorCurso) {
			maximoCurso = totalPorCurso;
			cursoMaximo = j;
		}
	}

	printf("El curso nro %d tiene la mayor cantidad de alumnos, y la mayoria provienen del vendedor %d \n", cursoMaximo+1, vendedorMaximo+1);
}

cursosCero() {

	int totalCeros = 0;

	for (int j = 0; j < 20; j++) {
		int totalPorCurso = 0;
		for (int i = 0; i < 5; i++) {
			totalPorCurso += cursoPorVendedor[i][j];
		}
		if (totalPorCurso == 0)
			totalCeros++;
	}

	printf("%d cursos tienen 0 alumnos\n", totalCeros);
}

cursoCeroPorVendedor(int vendedor) {
	int totalCeros = 0;
	for (int j = 0; j < 20; j++) {
		if (cursoPorVendedor[vendedor][j] == 0)
			totalCeros++;
	}
	printf("El vendedor %d no vendio nada en %d cursos \n", vendedor+1, totalCeros);
}


totalPorCurso() {
	int totalPorCurso = 0;
	for (int j = 0; j < 20; j++) {
		for (int i = 0; i < 5; i++) {
			totalPorCurso += cursoPorVendedor[i][j];
		}
		printf("Curso nro %d tiene %d alumnos \n", j+1, totalPorCurso);
		totalPorCurso = 0;
	}
}

totalPorVendedor() {
	int totalPorVendedor = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 20; j++) {
			totalPorVendedor += cursoPorVendedor[i][j];
		}
		printf("Vendedor %d sumó %d alumnos \n", i+1, totalPorVendedor);
		totalPorVendedor = 0;
	}
}

imprimirComision() {
	for (int i = 0; i < 5; i++) {
		printf("Vendedor %d recibió %f de comisión \n", i+1, comisionPorVendedor[i]);
	}
}
