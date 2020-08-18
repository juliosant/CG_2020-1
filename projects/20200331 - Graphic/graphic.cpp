//Júlio Victor Santiago;

#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>

GLint xRaster = 25, yRaster = 150;

GLubyte label[36] = { 'J','a', 'n',		'F', 'e', 'v',	'M' , 'a', 'r',
					  'A','b', 'r',		'M', 'a', 'i',  'J' , 'u', 'n',
					  'J','u', 'l',		'A', 'g', 'o',  'S', 'e', 't',
					  'O','u', 't',		'N', 'o', 'v',  'D', 'e', 'z' };

GLint dataValue[12]{ 420, 342, 324, 310, 262, 185,
					  190, 196, 217, 240, 312, 438 };


void init(void) {

	glClearColor(0.0, 0.0, 0.0, 0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 600, 0, 500);
}

void lineSegment(void) {
	GLint month, k;
	GLint x = 30;
	int n;

	glClear(GL_COLOR_BUFFER_BIT);

	glShadeModel(GL_SMOOTH);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 12; k++) {

		n = dataValue[k];
		if(n>= 300){
			glColor3f(1.0, 0.0, 0.0);
		}
		if (n> 200 and n< 300) {

			glColor3f(1.0, 1.0, 0.0);
		}

		if (n <= 200) {
			glColor3f(0.0, 1.0, 0.0);
		}
		glVertex2i(x + k * 50, dataValue[k] - 4);

		
	}
	glEnd();
	
	glColor3f(1.0, 0.0, 0.0); // Set marker color to red.
	for (k = 0; k < 12; k++) { 
		
		n = dataValue[k];
		if (n>= 300) {
			glColor3f(1.0, 0.0, 0.0);
		}
		if (n > 200 and dataValue[k] < 300) {
			glColor3f(1.0, 1.0, 0.0);
		}

		if (n <= 200) {
			glColor3f(0.0, 1.0, 0.0);
		}
		glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}


	glColor3f(1.0, 1.0, 1.0); // Set text color to white.
	xRaster = 20; // Display chart labels.
	for (month = 0; month < 12; month++) {
		glRasterPos2i(xRaster, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, label[k]);
		xRaster += 50;
	};

	glFlush();
}

// Programa Principal 
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50, 100);
	glutInitWindowSize(400, 300);
	glutCreateWindow("Capitulo 5");
	init();
	glutDisplayFunc(lineSegment);
	glutMainLoop();

	return 0;
}