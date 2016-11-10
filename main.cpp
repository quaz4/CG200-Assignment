#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "main.hpp"
#include "texture.hpp"
#include "fish.hpp"
#include "seaweed.hpp"

bool xRotate = false;
bool yRotate = false;

Camera camera;
Fish fish1;
Fish fish2;
Fish fish3;

GLuint sand = NULL;

bool anim = false;
int animationSpeed = 10;

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
	else if(key == 'p')
	{
		//Enable flat shading mode
		glShadeModel(GL_FLAT);
	}
	else if(key == 'P')
	{
		//Enable smooth shading mode
		glShadeModel(GL_SMOOTH);
	}
	else if(key == 'T' or key == 't')
	{
		anim = false;
	}
	else if(key == 'C' or key == 'c')
	{
		anim = true;
	}
	else if(key == 'F' or key == 'f')
	{
		animationSpeed -= 50;
	}
	else if(key == 'S' or key == 's')
	{
		animationSpeed += 50;
	}
	else if(key == 'A' or key == 'a')
	{
		anim = true;
	}
}

void ground()
{
	glEnable(GL_TEXTURE_2D);

	if(sand == NULL)
	{
		sand = loadTextureRepeat("textures/small.raw");
		printf("Loaded texture\n");
		glBindTexture(GL_TEXTURE_2D, sand);
	}

	//Ground
	glColor3f(1.0f, 0.83f, 0.0f);
	glBegin(GL_POLYGON);
		glTexCoord2d(-9.0f,  9.0f); glVertex3f(-9.0f, 0.0f,  9.0f);
		glTexCoord2d( 9.0f,  9.0f); glVertex3f( 9.0f, 0.0f,  9.0f);
		glTexCoord2d( 9.0f, -9.0f); glVertex3f( 9.0f, 0.0f, -9.0f);
		glTexCoord2d(-9.0f, -9.0f); glVertex3f(-9.0f, 0.0f, -9.0f);
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

//Draw objects in scene
void render(void)
{
	GLfloat qaPink[] = {1.0, 0.0, 1.0, 1.0};
	GLfloat qaYellow[] = {1.0, 1.0, 0.0, 1.0};
	GLfloat qaBrown[] = {0.5, 0.35, 0.05, 1.0};
	GLfloat qaWhite[] = {1.0, 1.0, 1.0, 1.0};
	GLfloat testShine[] = {60.0};

	ground();

	//////////////////////////////////////////////////////////////////////////////////////////Seaweed
	seaweed(0.1, 0, 0.3);
	seaweed(0.3, 0, 1.3);
	seaweed(-0.6, 0, 2.3);
	seaweed(0.9, 0, 0.3);
	seaweed(1.2, 0, 1.3);
	seaweed(-1.5, 0, 2.3);
	seaweed(2.1, 0, 0.3);
	seaweed(2.4, 0, 1.3);
	seaweed(4.3, 0, 2.3);
	seaweed(5.1, 0, 0.3);
	seaweed(-2.9, 0, 1.3);
	seaweed(5.3, 0, 2.3);
	seaweed(1.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(2.3, 0, 2.3);
	seaweed(-5.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(-1.3, 0, 2.3);

	glPushMatrix();
	glTranslatef(0,0,3);
	seaweed(0.1, 0, 0.3);
	seaweed(0.3, 0, 1.3);
	seaweed(-0.6, 0, 2.3);
	seaweed(0.9, 0, 0.3);
	seaweed(1.2, 0, 1.3);
	seaweed(-1.5, 0, 2.3);
	seaweed(2.1, 0, 0.3);
	seaweed(2.4, 0, 1.3);
	seaweed(4.3, 0, 2.3);
	seaweed(5.1, 0, 0.3);
	seaweed(-2.9, 0, 1.3);
	seaweed(5.3, 0, 2.3);
	seaweed(1.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(2.3, 0, 2.3);
	seaweed(-5.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(-1.3, 0, 2.3);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,-3);
	seaweed(0.1, 0, 0.3);
	seaweed(0.3, 0, 1.3);
	seaweed(-0.6, 0, 2.3);
	seaweed(0.9, 0, 0.3);
	seaweed(1.2, 0, 1.3);
	seaweed(-1.5, 0, 2.3);
	seaweed(2.1, 0, 0.3);
	seaweed(2.4, 0, 1.3);
	seaweed(4.3, 0, 2.3);
	seaweed(5.1, 0, 0.3);
	seaweed(-2.9, 0, 1.3);
	seaweed(5.3, 0, 2.3);
	seaweed(1.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(2.3, 0, 2.3);
	seaweed(-5.1, 0, 0.3);
	seaweed(6.9, 0, 1.3);
	seaweed(-1.3, 0, 2.3);
	glPopMatrix();

	//Can
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(-1.5, 1, 0);
	gluCylinder(gluNewQuadric(), 0.3, 0.3, 0.9, 16, 16);
	glPopMatrix();

	//Ball
	glPushMatrix();
	glColor3f(0, 0, 0.8);
	glTranslatef(3.6, 0.3, -1.8);
	gluSphere(gluNewQuadric(), 0.8, 16, 16);
	glPopMatrix();

	//Rocks
	rock(1, -2);
	rock(-1, 2.3);
	rock(1, -2.2);
	rock(-2, 4);
	rock(3, 2);
	rock(4.6, 2.9);
	rock(7, -4);
	rock(-3, 7);
	rock(3, -6);
	rock(9, 2);
	rock(2.0f, 2.0f);
	rock(2.0f, 4.0f);

	//Select what quality to render object as
	//Fish1
	if(distance(camera.nX, camera.nY, camera.nZ, fish1.x, fish1.y, fish1.z) > 15)
	{
		lowFish(fish1.x, fish1.y, fish1.z, 0, 0.1, 0.9, 0.3);
	}
	else
	{
		fish(fish1.x, fish1.y, fish1.z, 0, 0.1, 0.9, 0.3);
	}

	//Fish2
	if(distance(camera.nX, camera.nY, camera.nZ, fish2.x, fish2.y, fish2.z) > 15)
	{
		lowFish(fish2.x, fish2.y, fish2.z, 0, 0.1, 0.9, 0.3);
	}
	else
	{
		glPushMatrix();
		fish(fish2.x, fish2.y, fish2.z,0, 0.1, 0.9, 0.3);
		glTranslatef(-fish2.x, -fish2.y, -fish2.z);
		glRotatef(45, 0, 0, 1);
		glTranslatef(fish2.x, fish2.y, fish2.z);
		glPopMatrix();
	}

	//Fish3
	if(distance(camera.nX, camera.nY, camera.nZ, fish3.x, fish3.y, fish3.z) > 15)
	{
		lowFish(fish3.x, fish3.y, fish3.z, 0, 0.3, 0.5, 0.3);
	}
	else
	{
		fish(fish3.x, fish3.y, fish3.z, 0, 0.7, 0.1, 0.9);
	}

                glPushMatrix();
                //glTranslatef(-2, -2, -2);
                glRotatef(45, 0, 0, 1);
                //glTranslatef(2, 2, 2);
		fish(2, 4.5, 2,0, 0.1, 0.9, 0.3);
                glPopMatrix();

}

//Render timer
void Timer(int iUnused)
{
	glutPostRedisplay();
	glutTimerFunc(50, Timer, 0);
}

//Animation timer
void Timer2(int iUnused)
{
	if(anim == true)
	{
		animation();
	}

	glutTimerFunc(animationSpeed, Timer2, 0);
}

//Displays text ontop of the viewport
void displayText(float x, float y, char* text)
{
	//Clear projection and modelview matrices
	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();

	glDisable(GL_DEPTH_TEST);

	//Set position the text is displayed at
	glRasterPos2f(x, y);

	//Set the colour of the text
	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);

	//Copy text
	char buf[300];
	sprintf(buf, text);
	char* p = buf;

	//Loop through string and print
	int len = strlen(buf);
	for(int i = 0; i < len; i++)
	{ 
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, p[i]); 
	}

	//Load old matrices
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION) ;
	glPopMatrix();
	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
}

//Moves the fish around the origin
void animation()
{
	//Update fish1 rotation
	if(fish1.yRotate == 359)
	{
		fish1.yRotate = 0;
	}
	else
	{
		fish1.yRotate++;
	}

	//Calculate changes
	fish1.x = fish1.radius * sin(fish1.xRotate * (M_PI / 180)) * sin(fish1.yRotate * (M_PI / 180)); //r * sin(theta) * sin(phi)
	fish1.y = 4;//fish1.radius * cos(fish1.xRotate * (M_PI / 180)); //r * cos(theta)
	fish1.z = fish1.radius * sin(fish1.xRotate * (M_PI / 180)) * cos(fish1.yRotate * (M_PI / 180)); //r * sin(theta) * cos(phi)

	//Update fish2 rotation
	if(fish2.yRotate == 359)
	{
		fish2.yRotate = 0;
	}
	else
	{
		fish2.yRotate++;
	}

	//Calculate changes
	fish2.x = fish2.radius * sin(fish2.xRotate * (M_PI / 180)) * sin(fish2.yRotate * (M_PI / 180)); //r * sin(theta) * sin(phi)
	fish2.y = 6;//fish1.radius * cos(fish1.xRotate * (M_PI / 180)); //r * cos(theta)
	fish2.z = fish2.radius * sin(fish2.xRotate * (M_PI / 180)) * cos(fish2.yRotate * (M_PI / 180)); //r * sin(theta) * cos(phi)

	//Update fish3 rotation
	if(fish3.yRotate == 359)
	{
		fish3.yRotate = 0;
	}
	else
	{
		fish3.yRotate++;
	}

	//Calculate changes
	fish3.x = fish3.radius * sin(fish3.xRotate * (M_PI / 180)) * sin(fish3.yRotate * (M_PI / 180)); //r * sin(theta) * sin(phi)
	fish3.y = 6;//fish1.radius * cos(fish1.xRotate * (M_PI / 180)); //r * cos(theta)
	fish3.z = fish3.radius * sin(fish3.xRotate * (M_PI / 180)) * cos(fish3.yRotate * (M_PI / 180)); //r * sin(theta) * cos(phi)

}

//Draw everything on the screen
void display(void)
{
	glEnable(GL_DEPTH_TEST);
	fog();

	//Update camera rotation
	if(yRotate == true)
	{
		if(camera.yRotate == 0)
		{
			camera.yRotate = 359;
		}
		else
		{
			camera.yRotate--;
		}
	}

	if(xRotate == true)
	{
		if(camera.xRotate == 0)
		{
			camera.xRotate = 359;
		}
		else
		{
			camera.xRotate--;
		}
	}

	//Calculate camera location
	camera.nX = camera.radius * sin(camera.xRotate * (M_PI / 180)) * sin(camera.yRotate * (M_PI / 180)); //r * sin(theta) * sin(phi)
	camera.nY = camera.radius * cos(camera.xRotate * (M_PI / 180)); //r * cos(theta)
	camera.nZ = camera.radius * sin(camera.xRotate * (M_PI / 180)) * cos(camera.yRotate * (M_PI / 180)); //r * sin(theta) * cos(phi)

	//Set camera
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(camera.nX, camera.nY, camera.nZ, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);

	glClearColor(0.7f, 0.9f, 1.0f, 1.0f); // Clear the background of our window to light blue
	glClear(GL_COLOR_BUFFER_BIT); //Clear the colour buffer (more buffers later on)
	glClear(GL_DEPTH_BUFFER_BIT);

	//Render objects and text
	render();
	displayText(-0.9, 0.9, "Z/z - zoom in/out");
	displayText(-0.9, 0.8, "Y/y - rotate Y-axis start/stop");
	displayText(-0.9, 0.7, "X/x - rotate X-axis start/stop");
	displayText(-0.9, 0.6, "S/s - slow down animation");
	displayText(-0.9, 0.5, "C/c - resume animation");
	displayText(-0.9, 0.4, "F/f - speed up animation");
	displayText(-0.9, 0.3, "T/t - pause animation");
	displayText(-0.9, 0.2, "P/p - shading smooth/flat");
	displayText(-0.9, 0.1, "A/a - start animation");

	//Set frame
	glutSwapBuffers();
}

//Update viewport when changed
void reshape(int width, int height)
{
	glViewport(0, 0, (GLsizei)width, (GLsizei)height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

//Create fog in the distance of the scene
void fog()
{
	GLfloat fogColor[4]= {0.7f, 0.9f, 1.0f, 1.0f};
	glFogi(GL_FOG_MODE, GL_LINEAR);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.35f);
	glHint(GL_FOG_HINT, GL_DONT_CARE);
	glFogf(GL_FOG_START, 10.0f);
	glFogf(GL_FOG_END, 20.0f);
	glMatrixMode(GL_MODELVIEW);
	glEnable(GL_FOG);
}

//Returns the distance between two points in 3d space
float distance(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return abs(sqrt(pow((x2 - x1) + (y2 - y1) + (z2 - z1), 2)));
}

int main(int argc, char **argv)
{
	//Init glut and glut window
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH); 
	glutInitWindowSize (500, 500);
	glutInitWindowPosition (100, 100); 
	glutCreateWindow ("Assignment");

	//Init
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GLUT_RGBA);

	//Lighting
	glLightModeli(GL_LIGHT_MODEL_LOCAL_VIEWER, GL_TRUE);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

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

	//Lighting intensity and colour
	GLfloat qaAmbientLight2[] = {0.0, 0.05, 0.05, 1.0};
	GLfloat qaDiffuseLight2[] = {0.4, 0.5, 0.5, 1.0};
	GLfloat qaSpecularLight2[] = {0.04, 0.7, 0.7, 1.0};
	glLightfv(GL_LIGHT1, GL_AMBIENT, qaAmbientLight2);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight2);
	glLightfv(GL_LIGHT1, GL_SPECULAR, qaSpecularLight2);

	//Light position
	GLfloat qaLightPosition2[] = {-1.5, 2.5, 2.0, 1.0};
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);

	//Bind functions to glut
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyPressed);

	//Shading setup
	glShadeModel(GL_SMOOTH);

	//Init camera
	camera.radius = 10;
	camera.nX = 10;
	camera.nY = 10;
	camera.nZ = 10;
	camera.xRotate = 45;
	camera.yRotate = 45;

	//Start timer to redraw frames
	Timer(0);

	//Start timer to update animation
	Timer2(0);

	//Init fish1, fish2, fish3
	fish1.x = 0;
	fish1.y = 2;
	fish1.z = 2;
	fish1.xRotate = 45;
	fish1.yRotate = 45;
	fish1.radius = 4;

	fish2.x = 2;
	fish2.y = 4;
	fish2.z = 5;
	fish2.xRotate = 45;
	fish2.yRotate = 45;
	fish2.radius = 2;

	fish3.x = 0;
	fish3.y = 2;
	fish3.z = 2;
	fish3.xRotate = 45;
	fish3.yRotate = 45;
	fish3.radius = 6;

	animationSpeed == 100;

	//Start glut
	glutMainLoop();
}
