#include <GL/gl.h>
#include <GL/glut.h> // Include the GLUT header file
#include <math.h>
#include <time.h>
#include <stdio.h>

#include "texture.hpp"

struct Camera {
	double radius;
	double nX;
	double nY;
	double nZ;
	int xRotate;
	int yRotate;
};

bool xRotate = false;
bool yRotate = false;

Camera camera;

void keyPressed(unsigned char key, int x, int y)
{
	if(key == 'Z')
	{
		//Zoom in
		camera.radius += 0.1;
	}
	else if(key == 'z')
	{
		//Zoom out
		camera.radius -= 0.1;
	}
	else if(key == 'Y')
	{
		//Start rotate about y-axis
		yRotate = true;
	}
	else if(key == 'y')
	{
		//Stop rotate about y-axis
		yRotate = false;
	}
	else if(key == 'X')
	{
		//Start rotate about x-axis
		xRotate = true;
	}
	else if(key == 'x')
	{
		//Stop rotate about x-axis
		xRotate = false;
	}
}

void ground()
{
	glEnable(GL_TEXTURE_2D);
	GLuint texture = loadTextureRepeat("textures/wave-sand.raw");
	glBindTexture(GL_TEXTURE_2D, texture);

	
	//Ground
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
		glTexCoord2d(-200.0f,  200.0f); glVertex3f(-200.0f, 0.0f,  200.0f);
		glTexCoord2d( 200.0f,  200.0f); glVertex3f( 200.0f, 0.0f,  200.0f);
		glTexCoord2d( 200.0f, -200.0f); glVertex3f( 200.0f, 0.0f, -200.0f);
		glTexCoord2d(-200.0f, -200.0f); glVertex3f(-200.0f, 0.0f, -200.0f);
	glEnd();
}

//Only takes x and z as only makes sense to sit on the ocean floor
void rock(float x, float z)
{
	//Rock
	glPushMatrix();
	glTranslatef(x, 0.0f, z);
	glColor3f(0.5f, 0.35f, 0.05f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f( 0.0f, 1.0f,  0.0f);
		glVertex3f( 0.5f, 0.0f,  0.0f);
		glVertex3f( 0.7f, 0.0f,  0.2f);
		glVertex3f(-0.5f, 0.0f,  0.3f);
		glVertex3f(-0.2f, 0.0f, -0.6f);
		glVertex3f( 0.5f, 0.0f,  0.0f);
	glEnd();
	glPopMatrix();
}

void render(void)
{
	GLfloat qaPink[] = {1.0, 0.0, 1.0, 1.0};
	GLfloat qaYellow[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat qaBrown[] = {0.5, 0.35, 0.05, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat testShine[] = {60.0};

	ground();
	rock(2.0f, 2.0f);
	rock(2.0f, 4.0f);
}

void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}

void display(void)
{
	glEnable(GL_DEPTH_TEST);

	if(yRotate == true)
	{
		if(camera.yRotate == 359)
		{
			camera.yRotate = 0;
		}
		else
		{
			camera.yRotate++;
		}
	}

	if(xRotate == true)
	{
		if(camera.xRotate == 359)
		{
			camera.xRotate = 0;
		}
		else
		{
			camera.xRotate++;
		}
	}

	camera.nX = camera.radius * sin(camera.xRotate * (M_PI / 180)) * sin(camera.yRotate * (M_PI / 180)); //r * sin(theta) * sin(phi)
	camera.nY = camera.radius * cos(camera.xRotate * (M_PI / 180)); //r * cos(theta)
	camera.nZ = camera.radius * sin(camera.xRotate * (M_PI / 180)) * cos(camera.yRotate * (M_PI / 180)); //r * sin(theta) * cos(phi)

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.nX, camera.nY, camera.nZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Clear the background of our window to light blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glClear(GL_DEPTH_BUFFER_BIT);

	render();

	glutSwapBuffers();
}

void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window
	glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed
	glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes
	
	glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv); // Initialize GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); // Set up a basic display buffer (only single buffered for now)
	glutInitWindowSize (500, 500); // Set the width and height of the window
	glutInitWindowPosition (100, 100); // Set the position of the window
	glutCreateWindow ("Assignment"); // Set the title for the window

	//Init
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GLUT_RGBA);

	//Lighting
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	//Lighting intensity and colour
	GLfloat qaAmbientLight[] = {0.2, 0.2, 0.2, 1.0};
	GLfloat qaDiffuseLight[] = {0.8, 0.8, 0.8, 1.0};
	GLfloat qaSpecularLight[] = {1.0, 1.0, 1.0, 1.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, qaAmbientLight);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, qaDiffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, qaSpecularLight);

	//Light position
	GLfloat qaLightPosition[] = {1.5, 3.5, 0.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	glutDisplayFunc(display); // Tell GLUT to use the method "display" for rendering
	glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for reshaping
	glutKeyboardFunc(keyPressed); // Tell GLUT to use the method "keyPressed" for key presses

	camera.radius = 10;
	camera.nX = 10;
	camera.nY = 10;
	camera.nZ = 10;
	camera.xRotate = 45;
	camera.yRotate = 45;
	//camera.zRotate = 0;
	//camera.theta = 0;

	//glMatrixMode(GL_MODELVIEW);
	//glLoadIdentity();
	//gluLookAt(camera.nX, camera.nY, camera.nZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
	Timer(0);

	glutMainLoop(); // Enter GLUT's main loop
}
