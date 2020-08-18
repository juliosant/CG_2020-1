#include <stdlib.h>
#include<GLFW/glut.h>
#include<math.h>
#include <iostream>

using namespace std;

const double PI = 6.2831853;

GLdouble theta;
GLint wTamPad = 300;

static void init(void) {

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 1280, 0, 680);
}

void DesenharLinha(GLsizei X1, GLsizei Y1, GLsizei X2, GLsizei Y2) {
	int Dx = X2 - X1;
	int Dy = Y2 - Y1;
	int steps, k;

	float X1ncrement, Y1ncrement, x = X1, y = Y1;

	if (fabs(Dx) > fabs(Dy))
	{
		steps = fabs(Dx);
	}
	else
	{
		steps = fabs(Dy);
	};

	X1ncrement = float(Dx) / steps;
	Y1ncrement = float(Dy) / steps;

	glBegin(GL_POINTS);
	glVertex2i(round(x), round(y));
	glEnd();

	for (k = 0; k < steps; k++)
	{
		x += X1ncrement;
		y += Y1ncrement;
		glBegin(GL_POINTS);
		glVertex2i(round(x), round(y));
		glEnd();
	};
}


void DesenharCaracol(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);

	for (int k = 150; k > 0; k--, wTamPad -= 2) {
		theta = PI * k / 150;
		GLsizei cosTheta = 640 + wTamPad * cos(theta);
		GLsizei sinTheta = 340 + wTamPad * sin(-theta);

		DesenharLinha(640, 340, cosTheta, sinTheta);
	}
	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 680);
	glutCreateWindow("Caracol");
	init();
	glutDisplayFunc(DesenharCaracol);
	glutMainLoop();

	return 0;
}