/*Loads raw image files of size 256x256 and sets them as a texture*/
/*Clamp and Repeat mode for the textures is split up over 2 functions*/

#include <GL/gl.h>
#include <GL/glut.h> // Include the GLUT header file
#include <stdio.h>

GLuint loadTextureClamp(const char * fName)
{
	GLuint texture;
	int width, height;
	unsigned char* data;
	FILE* file;

	//Open file
	file = fopen(fName, "rb" );
	if(file == NULL)
	{
		printf("Error: Could not load texture %s", fName);
	}

	//Allocate space for data
	width = 256;
	height = 256;
	data = (unsigned char*)malloc(width * height * 3);

	//Read in data
	fread(data, width * height * 3, 1, file);
	fclose(file);

	//Set texture name
	glGenTextures(1, &texture);

	//Select texture
	glBindTexture(GL_TEXTURE_2D, texture);

	//Set shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//Bilinear filtering
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
	               GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Clamp
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width,
	height, GL_RGB, GL_UNSIGNED_BYTE, data);

	free(data);

	return texture;
}

GLuint loadTextureRepeat(const char * fName)
{
	GLuint texture;
	int width, height;
	unsigned char* data;
	FILE* file;

	//Open file
	file = fopen(fName, "rb" );
	if(file == NULL)
	{
		printf("Error: Could not load texture %s", fName);
	}

	//Allocate space for data
	width = 256;
	height = 256;
	data = (unsigned char*)malloc(width * height * 3);

	//Read in data
	fread(data, width * height * 3, 1, file);
	fclose(file);

	//Set texture name
	glGenTextures(1, &texture);

	//Select texture
	glBindTexture(GL_TEXTURE_2D, texture);

	//Set shading
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);

	//Bilinear filtering
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
	               GL_LINEAR_MIPMAP_NEAREST);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	//Repeat
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	gluBuild2DMipmaps(GL_TEXTURE_2D, 3, width,
	height, GL_RGB, GL_UNSIGNED_BYTE, data);

	free(data);

	return texture;
}