#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

#define WINDOW_WIDTH  400
#define WINDOW_HEIGHT 400

void init()
{
	glClearColor((float)0.7, (float)0.9, (float)1.0, (float)0.0);
	glEnable(GL_DEPTH_TEST);
}

void draw()
{

}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glFlush();
	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei) width, (GLsizei) height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glFrustum(-(float) 2.0, (float) 2.0, -(float) 2.0, 
			   (float) 2.0, (float) 3.0,  (float)40.0);

	glMatrixMode(GL_MODELVIEW);
}

void input()
{

}

void idle(void)
{
	glutPostRedisplay();
}

int main(int argc, char** argv)
{
	/*Initialise window*/
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);

	/*Create window and init*/
	glutCreateWindow("Assignment");
	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutKeyboardFunc(input);
	glutIdleFunc(idle);

	glutMainLoop();
	return 0;
}