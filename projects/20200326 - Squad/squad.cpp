#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>
#include<time.h> 

using namespace std;

int qtdeQuadrados;

void init(void) {
	
	glClearColor(0.0, 0.0, 0.0, 0);
	
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 400, 0, 400);
}


void gerarQuadrado() {
	int j;
	float r, g, b;

	int contador;
	int tamanhoQuadrado = 10;

	srand(time(0));

	for (contador = 1; contador <= qtdeQuadrados; contador++) {
		glPointSize(tamanhoQuadrado*(contador));
		glBegin(GL_POINTS);

		j = rand() % 100;
		r = (float)j / 100;

		j = rand() % 100;
		g = (float)j / 100;

		j = rand() % 100;
		b = (float)j / 100;

		glColor3f(r,g, b);
		glVertex2i((contador * 10) + (contador-1)*10, (contador * 10) + (contador - 1) * 10);
		glEnd();

	}

	glFlush();
}

// Programa Principal 
int main(int argc, char** argv)
{	
	/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/
	
	cout << "Qual a quantidade de pontos? \n";
	cin >> qtdeQuadrados;
	
	
	/*:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::*/

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Exercício 26/03");
	init();
	glutDisplayFunc(gerarQuadrado);
	glutMainLoop();

	return 0;
}