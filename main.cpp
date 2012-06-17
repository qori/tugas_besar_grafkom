#include<stdlib.h>
#include<gl\OpenGL\GL\glut.h>


double w=720, h=480;

int c=-50;

float sudut=0,rx=0,ry=0,rz=0,p=-50,sx=1,sy=1,sz=1;

void Matahari(void){

glColor3f(1,1,0);

glutSolidSphere(12, 100, 15);

}

void Bumi(void){

glColor3f(0,1,0);

glTranslatef(20,0,0);

glutSolidSphere(5,80,15);

}

void renderScene() {

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

glEnable(GL_COLOR_MATERIAL);

glLoadIdentity();

glTranslatef(0,0,c);

glScalef(sx,sy,sz);

Matahari();

glPushMatrix();

glRotatef(sudut,0,1,0);

sudut-=1;

Bumi();

glRotatef(sudut,0,-1,0);

sudut-=1;

glutSwapBuffers();

glDisable(GL_COLOR_MATERIAL);

}

void rezise (int w1, int h1){

glViewport(0,0, w1, h1);

glMatrixMode(GL_PROJECTION);

glLoadIdentity();

gluPerspective(45.0,(float) w1/(float) h1, 1.0,300.0);

glMatrixMode(GL_MODELVIEW);

glLoadIdentity();

}

void Init(){

GLfloat LightPosition[] = {0.0f, 0.0f, 15.0f, 0.0f};

GLfloat LightAmbient[] = {0.0f, 1.0f, 0.0f, 1.0f};

GLfloat LightDiffuse[] = {0.7f, 0.7f, 0.7f, 1.0f};

GLfloat LightSpecular[] = {0.5f, 0.5f, 0.5f, 1.0f};

GLfloat Shine[] = { 80 };

glShadeModel(GL_SMOOTH);

glClearColor(0.0f,0.0f,0.0f,0.5f);

glClearDepth(1.0f);

glEnable(GL_DEPTH_TEST);

glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

glMaterialfv(GL_FRONT, GL_AMBIENT, LightAmbient);

glLightfv(GL_LIGHT0, GL_POSITION, LightPosition);

glEnable(GL_LIGHTING);

glEnable(GL_LIGHT0);

return;

}

void update(int value){

glutPostRedisplay();

glutTimerFunc(50,update,0);

}

void main(int argc, char **argv) {

glutInit(&argc, argv);

glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);

glutInitWindowPosition(0,0);

glutInitWindowSize(1500,800);

glutCreateWindow("ROTASI");

glutTimerFunc(100,update,0);

glutDisplayFunc(renderScene);

glutReshapeFunc(rezise);

Init();

glutMainLoop();

}