
#include <stdlib.h>
#include<GLFW/glut.h>
#include<math.h>
#include <iostream>

using namespace std;

const double TWO_PI = 6.2831853;

// GLsizei é um tipo inteiro não negativo, usalmente usado para tamanhos
GLsizei winWidth = 1280, winHeight = 720;
GLuint regHex, wTamPad = 0;
GLdouble theta;

struct coordenada{
	float x;
	float y;
};
coordenada coord[10];

int qtdeEstrelas;

static void init(void) {

	// Três primeiros argumentos corresponde a valores normalizados de R, G e B. O último parâmetro
	// é o "alpha value" que é utilzado para "blend operations", ou seja, determinar a cor resultand de dois
	// objetos que se sobrepõem.
	glClearColor(0.5, 0.5, 0.5, 0.0);
	glMatrixMode(GL_PROJECTION);
	// Carrega a matriz identidade para como matriz de projeção. para garantir que a definição das coordenadas
	// a ser realizada em gluOrtho2D não considerarão sujeiras.
	glLoadIdentity();
	gluOrtho2D(0, winWidth, 0, winHeight);
}
void contornoEstrelar(void){
	glColor3f(0.7, 0.7, 0.7);
	glLineWidth(1.0);
	glPolygonMode(GL_FRONT, GL_LINE);

	glBegin(GL_TRIANGLES);
	glVertex2i(coord[0].x, coord[0].y);
	glVertex2i(coord[1].x, coord[1].y);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[2].x, coord[2].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(coord[2].x, coord[2].y);
	glVertex2i(coord[3].x, coord[3].y);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[4].x, coord[4].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(coord[4].x, coord[4].y);
	glVertex2i(coord[5].x, coord[5].y);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[6].x, coord[6].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(coord[6].x, coord[6].y);
	glVertex2i(coord[7].x, coord[7].y);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[8].x, coord[8].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex2i(coord[8].x, coord[8].y);
	glVertex2i(coord[9].x, coord[9].y);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[0].x, coord[0].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
	glBegin(GL_POLYGON);
	glEdgeFlag(GL_FALSE);
	glVertex2i(coord[0].x, coord[0].y);
	glVertex2i(coord[2].x, coord[2].y);
	glVertex2i(coord[4].x, coord[4].y);
	glVertex2i(coord[6].x, coord[6].y);
	glVertex2i(coord[8].x, coord[8].y);
	glEdgeFlag(GL_TRUE);
	glEnd();
}
void criacaoEstrelar(float base, float altura, float raio){
	float r = rand() % 2;
	float g = rand() % 2;
	float b = rand() % 2;

	glColor3f(r, g, b);
	glPolygonMode(GL_FRONT, GL_FILL);
	GLint k;

	for (k = 0; k < 10; k++) {
		theta = 6.2831853 * k / 10;
		glVertex2i(base, altura);
		if(k%2 ==1){
			wTamPad = raio;
		}
		else {
			wTamPad = raio -50;
		}
		coord[k].x = base + wTamPad * cos(theta);
		coord[k].y = altura + wTamPad * sin(theta);

	}
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2i(coord[0].x, coord[0].y);
		glVertex2i(coord[1].x, coord[1].y);
		glVertex2i(coord[2].x, coord[2].y);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2i(coord[2].x, coord[2].y);
		glVertex2i(coord[3].x, coord[3].y);
		glVertex2i(coord[4].x, coord[4].y);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2i(coord[4].x, coord[4].y);
		glVertex2i(coord[5].x, coord[5].y);
		glVertex2i(coord[6].x, coord[6].y);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2i(coord[6].x, coord[6].y);
		glVertex2i(coord[7].x, coord[7].y);
		glVertex2i(coord[8].x, coord[8].y);
	glEnd();
	glBegin(GL_TRIANGLES);
		glVertex2i(coord[8].x, coord[8].y);
		glVertex2i(coord[9].x, coord[9].y);
		glVertex2i(coord[0].x, coord[0].y);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(coord[0].x, coord[0].y);
		glVertex2i(coord[2].x, coord[2].y);
		glVertex2i(coord[4].x, coord[4].y);
		glVertex2i(coord[6].x, coord[6].y);
		glVertex2i(coord[8].x, coord[8].y);
	glEnd();

	contornoEstrelar();
	
	glFlush();
}
void estruturaEstrelar(void) {
	
	glClear(GL_COLOR_BUFFER_BIT);
	int deNovo = 0;
	
	float base;
	float altura;
	float raio;

	for (deNovo = 0; deNovo < qtdeEstrelas; deNovo++) {
		raio = 0;
		while (raio < 60) {
			raio = rand() % 120;

		}
		base = 0;
		while (base < 100) {
			base = rand() % 1100;

		}
		altura = 0;
		while (altura < 250) {
			altura = rand() % 600;

		}
		criacaoEstrelar(base, altura, raio);
	}
}


// Programa Principal 

int main(int argc, char** argv)
{
	cout << "Qtde de estrelas:" << endl;
	cin >> qtdeEstrelas;
	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1280, 780);
	glutCreateWindow("Atividade VP2 - Estrela");
	init();
	glutDisplayFunc(estruturaEstrelar);
	glutMainLoop();

	return 0;
}