/**********************************/
/*    Qori Nurqolbi - 10108424    */
/* Idham Herawan Putra - 10108450 */
/*      Nur Mufmin - 10108447     */
/*     Vian Arwanda - 10108467    */
/**********************************/

#include <cstdlib>
#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <gl\GL.h>
#include <gl\GLU.h>
#include <gl\OpenGL\GL\glut.h>

#define checkImageWidth 164 
#define checkImageHeight 164
#define phi 3.1415926535

using namespace std;

int w=900, h=600, z=0;
float tahun = 0, hari = 0;
float pitch = 0, rot = 90.0;
float jarakX = 0, jarakY = 0, jarakZ = 10.0;
float xlook = 0.0, ylook = 0.0, zlook = 0.0;
float xup = 0.0, yup = 0.0, zup= 0.0;
int lastx = 0, lasty = 0;

// Lighting values
static float ambientLight0[] = { 0.5f, 0.5f, 0.5f, 1.0f };
static float ambientLight1[] = { 0.1f, 0.1f, 0.1f, 1.0f };
static float diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
static float specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static float specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };

static float lightPos[] = { 0.0f, 0.0f, 0.0f, 1.0f };
static float emissionSun[] = { 3.0f, 0.0f, 0.0f, 0.0f};
static float nullv[] = { 0.0f, 0.0f, 0.0f, 1.0f};

void fungsiKeyboard();
void merkurius(void);
void venus(void);
void bumi(void);
void mars(void);
void jupiter(void);
void saturnus(void);
void uranus(void);
void neptunus(void);
void pluto(void);

void init(void)
{
     glClearColor(0.0,0.0,0.0,0.0);   
     glDepthFunc(GL_LEQUAL);
     glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective(45.0,(GLdouble) w/(GLdouble) h, 1.0,300.0);
     glMatrixMode(GL_MODELVIEW);
     glShadeModel(GL_SMOOTH); //mengaktifkan shade model
     glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void enable(void)
{
     glEnable(GL_DEPTH_TEST);
     glEnable(GL_LIGHTING); // mengaktifkan fungsi pencahayaan
     glEnable(GL_LIGHT0); // mengaktifkan sumber cahaya
     glEnable(GL_COLOR_MATERIAL);
     glEnable(GL_NORMALIZE);
     glDisable(GL_CULL_FACE);
}

void Rotate(void)
{
	hari += 2;
	if(hari > 360)
		hari = hari - 360;
	tahun += .1;
	if(tahun > 360)
		tahun = tahun - 360;
	glutPostRedisplay();
}

void garisOrbit(float rad, float inc)
{
	glPushMatrix();

	float y = 0.0;
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POINTS);
	for(float sudut = 0; sudut <= 360; sudut+=inc)
	{
		float x = rad*sin((sudut)*phi/180);
		float z = rad*cos((sudut)*phi/180);
		glVertex3f(x, y, z);
	}
	glEnd();

	glPopMatrix();
}

void merkurius(void)
{
     glPushMatrix();
     garisOrbit(5.5, 1);
     
     glRotatef(tahun*9, 0.0, 1.0, 0.0); // rotasi planet
     glTranslatef(5.5, 0.0, 0.0);
	 
	 glutSolidSphere(0.4, 10, 8); //gambar planet merkurius
	 glPopMatrix();
}

void venus(void)
{
     glPushMatrix();
     garisOrbit(8.5,1);
     
     glRotatef(tahun*8, 0.0, 1.0, 0.0); 
     glTranslatef(8.5, 0.0, 0.0);
	 
	 glutSolidSphere(0.3, 20, 16); 
	 glPopMatrix();
}

void bumi(void)
{  
     garisOrbit(10.5,1);
     
     glRotatef(tahun*7, 0.0, 1.0, 0.0); 
	 glTranslatef(10.5, 0.0, 0.0);
	 glColor3f(0.0, 0.0, 1.0);
	 glutSolidSphere(0.37, 20, 16); 		 
 	 
	 glRotatef(hari*6, 0.0, 1.0, 0.0); //rotasi bulan
	 glTranslatef(0.80, 0.0, 0.0);
	 glColor3f(0.5, 0.5, 0.5);
	 glutSolidSphere(0.15, 5, 4); //gambar bulan
	
}

void mars(void)
{
     glPushMatrix();
     garisOrbit(16.5,0.3);
     
     glRotatef(tahun*5, 0.0, 1.0, 0.0); 
	 glTranslatef(16.5, 0.0, 0.0);
	
	 glutSolidSphere(0.7, 20, 16); 
	 glPopMatrix();    
}

void jupiter(void)
{
     glPushMatrix();
     garisOrbit(20.5, 0.5);
     
     glRotatef(tahun*4, 0.0, 1.0, 0.0); 
	 glTranslatef(20.5, 0.0, 0.0);

	 glutSolidSphere(0.6, 20, 16); 
	 glPopMatrix();
}

void saturnus(void)
{
     glPushMatrix();
     garisOrbit(26.5, 0.7);
     
     glRotatef(tahun*4, 0.0, 1.0, 0.0); 
     glTranslatef(26.5, 0.0, 0.0);

     glutSolidSphere(0.6, 20, 16); 
     glPopMatrix();   
}

void uranus(void)
{
     glPushMatrix();
     garisOrbit(30.5, 0.9);
     
     glRotatef(tahun*3, 0.0, 1.0, 0.0);
     glTranslatef(30.5, 0.0, 0.0); 

     glutSolidSphere(0.6, 20, 16); 
     glPopMatrix(); 
}

void neptunus(void)
{
     glPushMatrix();
     garisOrbit(36.5, 0.95);
     
     glRotatef(tahun*2, 0.0, 1.0, 0.0);
     glTranslatef(36.5, 0.0, 0.0); 

     glutSolidSphere(0.6, 20, 16); 
     glPopMatrix(); 
}

void pluto(void)
{
     glPushMatrix();
     garisOrbit(41.5,0.990);
     
     glRotatef(tahun, 0.0, 1.0, 0.0);
     glTranslatef(41.5, 0.0, 0.0); 

     glutSolidSphere(0.6, 20, 16); 
     glPopMatrix(); 
}

void displayObjek(void)
{
    init();
    enable();
	Rotate();
	fungsiKeyboard();
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//set the viewing transformation
	gluLookAt(jarakX, jarakY, jarakZ,  xlook, ylook, zlook,  xup, yup, zup);

	glPushMatrix(); //save state
	glTranslatef(0.0, 0.0, -5.0); //translate out to sun

	//set specular reflectivity with low shine
	glColor4f(1.0, 0.8, 0.0, 1.0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
	glMateriali(GL_FRONT, GL_SHININESS, 3);
	glMaterialfv(GL_FRONT, GL_EMISSION, emissionSun); //make sun glow

	glLightfv(GL_LIGHT1, GL_POSITION, lightPos); //move light 1 under sun
	glutSolidSphere(3, 40, 32); //matahari

	//save lighting
	glPushAttrib(GL_LIGHTING_BIT);
	glDisable(GL_LIGHT0);
	glEnable(GL_LIGHT1); //turn on the sun

	glMaterialfv(GL_FRONT, GL_SPECULAR, nullv);
	glMaterialfv(GL_FRONT, GL_EMISSION, nullv);

	merkurius();
	venus();
	glPushMatrix();
	bumi();
	glPopMatrix();
	mars();
	jupiter();
	saturnus();
	uranus();
	neptunus();
	pluto();

	glPopAttrib();
	glPopMatrix(); //restore state

	glutSwapBuffers();
}

void SetupLighting(void)
{
	// Setup and enable light0
	glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight0);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT0, GL_SPECULAR, specular);

	// Setup light1
	glLightfv(GL_LIGHT1, GL_AMBIENT, ambientLight1);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, diffuseLight);
	glLightfv(GL_LIGHT1, GL_SPECULAR, specular);

	// Set Material properties to follow glColor values
	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

}

void SetupRC(void)
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	SetupLighting();

	glClearColor(0.0, 0.0, 0.0, 0.0);

	glShadeModel(GL_SMOOTH);
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
  
	gluPerspective(40.0, (GLfloat)w/(GLfloat)h, 1.0, 400.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void fungsiKeyboard(void)
{
	if(GetAsyncKeyState(VK_LEFT))
	{
		jarakX += (cos((rot+90)*phi/180))/2;
		jarakZ += -(sin((rot+90)*phi/180))/2;
	}

	if(GetAsyncKeyState(VK_RIGHT))
	{
		jarakX += (cos((rot-90)*phi/180))/2;
		jarakZ += -(sin((rot-90)*phi/180))/2;
	}

	if(GetAsyncKeyState(VK_UP))
	{
		jarakX += (cos(rot*phi/180)* cos(pitch*phi/180))/2;
		jarakZ += -(sin(rot*phi/180) * cos(pitch*phi/180))/2;
		jarakY += sin(pitch*phi/180);
	}

	if(GetAsyncKeyState(VK_DOWN))
	{
		jarakX -= (cos(rot*phi/180)* cos(pitch*phi/180))/2;
		jarakZ -= -(sin(rot*phi/180) * cos(pitch*phi/180))/2;
		jarakY -= sin(pitch*phi/180);
	}

	xlook = jarakX + (cos(rot*phi/180) * cos(pitch*phi/180));
	zlook = jarakZ - (sin(rot*phi/180) * cos(pitch*phi/180));
	ylook = jarakY + sin(pitch*phi/180);

	xup = cos(rot*phi/180) * cos((pitch+90)*phi/180);
	zup = -sin(rot*phi/180) * cos((pitch+90)*phi/180);
	yup = sin((pitch+90)*phi/180);

	glutPostRedisplay();
}

void PassiveMouse(int x, int y)
{
	if( (lastx - x) >50 || (lastx - x) <-50 ||
		(lasty - y) >50 || (lasty - y) <-50 )
	{
		lastx = x;
		lasty = y;
	}

	rot += ((lastx - x)/2);
	lastx = x;

	if(rot>360)
		rot-=360;
	if(rot<0)
		rot+=360;

	pitch += ((lasty - y))/2;
	lasty = y;

	if(pitch > 90)
		pitch = 90.0;
	if(pitch<-90)
		pitch = -90.0;

	glutPostRedisplay();
}

int main(void)
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(900, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Tata surya");
	SetupRC();
	glutDisplayFunc(displayObjek);
	glutReshapeFunc(Reshape);
	glutPassiveMotionFunc(PassiveMouse);

	glutMainLoop();
}
