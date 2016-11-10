#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

void fish(float x, float y, float z, float rotation, float r, float g, float b)
{
	//Body
	//glPushMatrix();
	glRotatef(rotation * (M_PI / 180), 0, 1, 0);
	glColor3f(r, g, b);
	//Pos side
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f( 0.0f + x,  0.0f + y, 0.1f + z); //0 yes
		glVertex3f(-0.1f + x, -0.3f + y, 0.0f + z); //1 yes
		glVertex3f( 0.2f + x, -0.3f + y, 0.0f + z);	//2 yes
		glVertex3f( 0.9f + x, -0.1f + y, 0.0f + z); //3 yes
		glVertex3f( 0.9f + x,  0.2f + y, 0.0f + z); //4 yes
		glVertex3f( 0.2f + x,  0.3f + y, 0.0f + z); //5 yes
		glVertex3f(-0.1f + x,  0.3f + y, 0.0f + z); //6 yes
		glVertex3f(-0.3f + x,  0.0f + y, 0.0f + z); //7 yes
		glVertex3f(-0.1f + x, -0.3f + y, 0.0f + z); //1 yes
	glEnd();

	//Neg side
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f( 0.0f + x,  0.0f + y, -0.1f + z); //0 yes
		glVertex3f(-0.1f + x, -0.3f + y,  0.0f + z); //1 yes
		glVertex3f( 0.2f + x, -0.3f + y,  0.0f + z); //2 yes
		glVertex3f( 0.9f + x, -0.1f + y,  0.0f + z); //3 yes
		glVertex3f( 0.9f + x,  0.2f + y,  0.0f + z); //4 yes
		glVertex3f( 0.2f + x,  0.3f + y,  0.0f + z); //5 yes
		glVertex3f(-0.1f + x,  0.3f + y,  0.0f + z); //6 yes
		glVertex3f(-0.3f + x,  0.0f + y,  0.0f + z); //7 yes
		glVertex3f(-0.1f + x, -0.3f + y,  0.0f + z); //1 yes
	glEnd();

	//Tail
	glColor3f(1.0 - r, 1.0 - b, 1.0 - b);

	glBegin(GL_POLYGON);
		glVertex3f( 0.9f + x, -0.1f + y,  0.0f + z); //3 yes
		glVertex3f( 0.9f + x,  0.2f + y,  0.0f + z); //4 yes
		glVertex3f( 1.3f + x,  0.4f + y,  0.0f + z); //3 yes
		glVertex3f( 1.3f + x, -0.4f + y,  0.0f + z); //4 yes
	glEnd();
	//glPopMatrix();
}

void lowFish(float x, float y, float z, float rotation, float r, float g, float b)
{
	//Body
	glColor3f(r, g, b);
	//Pos side
	glBegin(GL_POLYGON);
		glVertex3f(-0.3f + x, -0.3f + y,  0.1f + z); //7 yes
		glVertex3f(-0.3f + x,  0.3f + y,  0.1f + z); //4 yes
		glVertex3f( 0.9f + x,  0.3f + y,  0.1f + z); //3 yes
		glVertex3f( 0.9f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Neg side
	glBegin(GL_POLYGON);
		glVertex3f(-0.3f + x, -0.3f + y, -0.1f + z); //7 yes
		glVertex3f(-0.3f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 0.9f + x,  0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 0.9f + x, -0.3f + y, -0.1f + z); //4 yes
	glEnd();

	//Front
	glBegin(GL_POLYGON);
		glVertex3f(-0.3f + x,  0.3f + y,  0.1f + z); //7 yes
		glVertex3f(-0.3f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f(-0.3f + x, -0.3f + y, -0.1f + z); //7 yes
		glVertex3f(-0.3f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Top
	glBegin(GL_POLYGON);
		glVertex3f(-0.3f + x,  0.3f + y,  0.1f + z); //7 yes
		glVertex3f(-0.3f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 0.9f + x,  0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 0.9f + x,  0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Bottom
	glBegin(GL_POLYGON);
		glVertex3f(-0.3f + x, -0.3f + y,  0.1f + z); //7 yes
		glVertex3f(-0.3f + x, -0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 0.9f + x, -0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 0.9f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Tail
	glColor3f(1.0 - r, 1.0 - b, 1.0 - b);

	//Pos side
	glBegin(GL_POLYGON);
		glVertex3f( 1.3f + x, -0.3f + y,  0.1f + z); //7 yes
		glVertex3f( 1.3f + x,  0.3f + y,  0.1f + z); //4 yes
		glVertex3f( 0.9f + x,  0.3f + y,  0.1f + z); //3 yes
		glVertex3f( 0.9f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Neg side
	glBegin(GL_POLYGON);
		glVertex3f( 1.3f + x, -0.3f + y, -0.1f + z); //7 yes
		glVertex3f( 1.3f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 0.9f + x,  0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 0.9f + x, -0.3f + y, -0.1f + z); //4 yes
	glEnd();

	//Top
	glBegin(GL_POLYGON);
		glVertex3f( 0.9f + x,  0.3f + y,  0.1f + z); //7 yes
		glVertex3f( 0.9f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 1.3f + x,  0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 1.3f + x,  0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Bottom
	glBegin(GL_POLYGON);
		glVertex3f( 0.9f + x, -0.3f + y,  0.1f + z); //7 yes
		glVertex3f( 0.9f + x, -0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 1.3f + x, -0.3f + y, -0.1f + z); //3 yes
		glVertex3f( 1.3f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();

	//Behind
	glBegin(GL_POLYGON);
		glVertex3f( 1.3f + x,  0.3f + y,  0.1f + z); //7 yes
		glVertex3f( 1.3f + x,  0.3f + y, -0.1f + z); //4 yes
		glVertex3f( 1.3f + x, -0.3f + y, -0.1f + z); //7 yes
		glVertex3f( 1.3f + x, -0.3f + y,  0.1f + z); //4 yes
	glEnd();
}