#include <iostream>
#include <cmath>
#include <stdio.h>
#include <string.h>
#include <GLFW/glut.h>
#include <Windows.h>

using namespace std;

int base;
int nTriangulos;

void init(void) {
	glClearColor(1.0, 1.0, 1.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 200, 0, 200);

}
void triangulos(void) {
	int i = 0;

	while (i != nTriangulos) {
		glColor3f(1, 0.1, 0.6);
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);//para deixar triagulo sem cor sólida
		glBegin(GL_TRIANGLES);

		double d = sqrt(pow(base,2) - pow(base / 2, 2));

		double x1 = 100 - base / 2; //metade do valor da base ficará à esquerda do ponto central
		double x2 = 100 + base / 2; //metade do valor da base ficará à direita do ponto central

		double y = 100 - d / 2; //metade da altura ficará abaixo do eixo y

		double y2 = 100 + d; //metade da altura ficará acima do eixo y

		glVertex2i(x1, y);
		glVertex2i(x2, y);
		glVertex2i(100, y2);

		i++;
		base = base + 10;
	}

	glEnd();
	glFlush();
}

int main()
{	
	cout << ":::::::::::::::::::Triangulo Equilatero:::::::::::::::::::\n\n";
	cout << "Quantidade de tringulos:\n\n";
	cin >> nTriangulos;
	cout << "Tamanho da base:\n\n";
	cin >> base;

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);

	glutCreateWindow("Hello Word!");


	init();

	glutDisplayFunc(triangulos);

	glutMainLoop();

	return 0;
}