// OpenGL.cpp : Este arquivo cont�m a fun��o 'main'. A execu��o do programa come�a e termina ali.
//

#include <iostream>
#include <stdio.h>
#include <string.h>
#include<GLFW/glut.h>
#include<Windows.h>
#include<math.h>

using namespace std;
int XI, YI, XE, YE;

void init(void) {
	// Tr�s primeiros argumentos corresponde a valores normalizados de R, G e B. O �ltimo par�metro
	// � o "alpha value" que � utilzado para "blend operations", ou seja, determinar a cor resultante de dois
	// objetos que se sobrep�em.
	glClearColor(1.0, 1.0, 1.0, 0);
	// Nesse primeiro programa, ser� mostrada uma linha em duas dimens�es em tela. Para tanto,
	// � necess�rio "dizer" ao OpenGL como projetar nossa figura na tela, pois projetar uma figura bi-dimensional
	// � tratado pelo OpenGL como um caso especial de uma visualiza��o tridimensional. Os dois pr�ximos comandos
	// especificam que ser� utilizado uma proje��o ortogonal (proje��o de uma figura no espa�o em um plano) para
	// mapear o conteudo de uma �rea bidimensional retangular para a tela, sendo que a coordenada "x" variar� de 0 a 200
	// e a "y" de 0 a 150. Dessa forma, define-se a coordenada "lower left-corner" para 0 e 0 e a "upper right-corner"
	// para 200 e 150, respectivamente x e y.
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-1200, 1200, -1200, 1200);


}

void DesenhaLinha() {
	int Dx = XE - XI;
	int Dy = YE - YI;
	int steps, k;
	float pk;
	

	float xIncrement, yIncrement, x = XI, y = YI;

	if (fabs(Dx) > fabs(Dy))
	{
		steps = fabs(Dx);
	}
	else
	{
		steps = fabs(Dy);
	};

	xIncrement = float(Dx) / steps;
	yIncrement = float(Dy) / steps;

	glBegin(GL_POINTS);
	glVertex2i(round(x), round(y));
	glEnd();

	pk = 2 * Dy - 2 * Dx;
	for (k = 0; k < steps; k++)
	{	
		if(pk>=0){
			x += xIncrement;
			y += yIncrement;
			pk = pk + 2 * Dy - 2 * Dx;
		}
		else {
			x += xIncrement;
			pk = pk + 2 * Dy;
		}
		glBegin(GL_POINTS);
		glVertex2i(round(x), round(y));
		glEnd();
	};
	glFlush();
}

void lineSegment(void) {
	// glClearColor atrubui uma cor � janela, mas n�o coloca a janela na tela. Para tal, deve-se executar
	// o comando abaixo. O par�metro GL_COLOR_BUFFER_BIT indica que os bits do "color buffer (refresh buffer)", devem 
	// ser setados para os valores indicados no comando glClearColor. Toda vez que a janela precisar ser
	// redesenhada, quando for redimensionada, por exemplo, o glClear deve ser executado. Se colocar
	// no procedimento "Init" isso n�o ocorrer� e, ao redimensionar da janela, ela ficar� preta. Fa�a o teste!
	glClear(GL_COLOR_BUFFER_BIT);
	// Configura esquema de cor para os objetos que se que mostrar em tela. No exemplo abaixo, deseja-se 
	// setar a cor do objeto para verde escuro. o "f" indica que s�o valore de ponto flutuande ("float")
	glColor3f(1, 0.4, 0.5);
	//
	DesenhaLinha();
}

// Programa Principal 
int main(int argc, char** argv)
{
	// Inicializa GLUT. Par�metros s�o opcionais.
	glutInit(&argc, argv);
	// Configurar op��es para mostrar a janela. No caso abaixo, optou-se pelo "single refresh buffer" - GLUT_SINGLE, 
	// e queremos utilizar o sistema de cores RGB - GLUT_RGB. A "|" indica opera��o "OR". Contrapondo a "single refresh
	// buffer", pode-se ter "double refresh buffer" para anima��es.
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// Configura a posi��o inicial o "upper left-corner" da janela (acima e � esquerda)
	glutInitWindowPosition(100, 100);
	// Configura a largura, primeiro par�metro, e a altura da janela. Ap�s mostrar a janela na tela
	// � poss�vel reposicion�-la e redimension�-la.
	glutInitWindowSize(500, 500);
	// Criar uma janela com um t�tulo
	glutCreateWindow("Hello Word!");
	//Executa rotinas de inicializa��o
	init();
	// o procedimento lineSegment ser� "passado" para a janela criada. O procedimento "lineSegment" � denominado
	// de "display callback function" e esse procedimento � descrito com sendo "registrado" pela func�o
	// "glutDisplayFunc" como a rotina que ser� chamada sempre que a janela precisar ser mostrada novamente. Isso pode
	// ocorrer, por exemplo, se o usu�rio mover a janela. Nesse caso, "lineSegment" ser� novamente chamado.
	cout << "Informa X e Y iniciais:" << endl;
	cin >> XI;
	cin >> YI;
	cout << "Informa X e Y finais:" << endl;
	cin >> XE;
	cin >> YE;
	glutDisplayFunc(lineSegment);
	// Deve ser a �ltima fun��o de seu c�digo. Mostra o gr�fico inicial e coloca o programa em um loop que 
	// avalia inputs do usu�rio, tipo uso do mouse ou do teclado. Nesse primeiro exemplo, n�o haver� intera��o,
	// ent�o o programa mostrar� a figura at� que a janela seja fechada.
	glutMainLoop();

	return 0;

}