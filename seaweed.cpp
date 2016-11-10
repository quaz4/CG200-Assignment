#include <GL/gl.h>
#include <GL/glut.h>

#include "seaweed.hpp"

void seaweed(float x, float y, float z)
{
	int i;
	glPushMatrix();
	glTranslatef(x, y, z);
	glColor3f(0.05, 0.44, 0.05);
	for(i = 0; i < 4; i++)
	{
		seaweedPart();
	}
	glPopMatrix();
}

void seaweedPart()
{
	int i;
	for(i = 0; i < 5; i++)
	{
		glutSolidSphere(0.1, 5, 5);
		glTranslatef(0.06f, 0.1f, 0.0f);
	}

	for(i = 0; i < 5; i++)
	{
		glutSolidSphere(0.1, 5, 5);
		glTranslatef(-0.06f, 0.1f, 0.0f);
	}
}

void lowSeaweed(float x, float y, float z)
{
	glPushMatrix();
	glLoadIdentity();
	glColor3f(0.05, 0.44, 0.05);
	glRotatef(-90, 1, 0, 0);
	glTranslatef(x, y, z);
	gluCylinder(gluNewQuadric(), 0.1, 0.1, 4.0, 4, 4);
	glPopMatrix();
}