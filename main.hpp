void keyPressed(unsigned char key, int x, int y);
void ground();
void rock(float x, float z);
void render(void);
void Timer(int iUnused);
void display(void);
void reshape(int width, int height);
void fog();
void displayText(float x, float y, char* text);
float distance(float x1, float y1, float z1, float x2, float y2, float z2);
void animation();

struct Camera
{
	double radius;
	double nX;
	double nY;
	double nZ;
	int xRotate;
	int yRotate;
};

struct Fish
{
	float x;
	float y;
	float z;
	int xRotate;
	int radius;
	int yRotate;
};