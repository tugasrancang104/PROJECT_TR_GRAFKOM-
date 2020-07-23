
#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
#include <math.h>
#include <stdlib.h>

const double Pi = 3.141592653589793;
void init(void);
void tampil(void);
void mouse(int button, int state, int x, int y);
void keyboard (unsigned char, int, int);
void ukuran (int, int);
void mouseMotion(int x, int y);

float xrot=0.0f;
float yrot=0.0f;
float xdiff=0.0f;
float ydiff=0.0f;
bool mouseDown=false;
int is_depth;

void ukuran(int lebar, int tinggi)
{
    if (tinggi == 0) tinggi = 1;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(50.0, lebar / tinggi, 5.0, 500.0);
    glTranslatef(0.0, -10.0, -150.0);
    glMatrixMode(GL_MODELVIEW);
}
void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
     glEnable(GL_LIGHTING);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glMatrixMode(GL_MODELVIEW);
    glPointSize(7.0);
    glLineWidth(6.0f);
}
void tampil(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    GLfloat x = 0.0; GLfloat y = 50.0; GLfloat angle_stepsize = 3.0; GLfloat height = 50.0; GLfloat radius = -90.0; GLfloat jumlah_titik = 20;

    glPushMatrix();


//lapangan lain
    glBegin(GL_QUADS);
    glColor3f(0,0.5,0);
    glVertex3f(-42.0, -19.9, 45.0); //kiri bawah
    glVertex3f(9.0, -19.9, 45.0); //kanan bawah
    glVertex3f(9.0, -19.9, 25.0); //kanan atas
    glVertex3f(-42.0, -19.9, 25.0); //kiri atas
    glEnd();

    //lapangan lain
    glBegin(GL_QUADS);
    glColor3f(0,0.5,0);
    glVertex3f(-42.0, -19.9, 15.0); //kiri bawah
    glVertex3f(9.0, -19.9, 15.0); //kanan bawah
    glVertex3f(9.0, -19.9, -15.0); //kanan atas
    glVertex3f(-42.0, -19.9, -15.0); //kiri atas
    glEnd();

    //lapangan lain
    glBegin(GL_QUADS);
    glColor3f(0,0.5,0);
    glVertex3f(-42.0, -19.9, -30.0); //kiri bawah
    glVertex3f(9.0, -19.9, -30.0); //kanan bawah
    glVertex3f(9.0, -19.9, -55.0); //kanan atas
    glVertex3f(-42.0, -19.9, -55.0); //kiri atas
    glEnd();

   //lantai atas
    glBegin(GL_QUADS);
    glColor3f(0.5,1,0);
    glVertex3f(-43.0, -20.0, 45.0); //kiri bawah
    glVertex3f(10.0, -20.0, 45.0); //kanan bawah
    glVertex3f(10.0, -20.0, -55.0); //kanan atas
    glVertex3f(-43.0, -20.0, -55.0); //kiri atas
    glEnd();

    //lantaibawah
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-43.0, -25.0, 45.0); //kiri bawah
    glVertex3f(10.0, -25.0, 45.0); //kanan bawah
    glVertex3f(10.0, -25.0, -55.0); //kanan atas
    glVertex3f(-43.0, -25.0, -55.0); //kiri atas
    glEnd();

    //lantai depan
    glBegin(GL_QUADS);
    glColor3f(1,1,0.5);
    glVertex3f(-43.0, -25.0, 45.0); //kiri bawah
    glVertex3f(-43.0, -20.0, 45.0); //kanan bawah
    glVertex3f(10.0, -20.0, 45.0); //kanan atas
    glVertex3f(10.0, -25.0, 45.0); //kiri atas
    glEnd();

    //lantai samping kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-43.0, -25.0, 45.0); //kiri bawah
    glVertex3f(-43.0, -20.0, 45.0); //kanan bawah
    glVertex3f(-43.0, -20.0, -55.0); //kanan atas
    glVertex3f(-43.0, -25.0, -55.0); //kiri atas
    glEnd();

     //lantai samping kiri
    glBegin(GL_QUADS);
    glColor3f(0.5,1,1);
    glVertex3f(10.0, -25.0, 45.0); //kiri bawah
    glVertex3f(10.0, -20.0, 45.0); //kanan bawah
    glVertex3f(10.0, -20.0, -55.0); //kanan atas
    glVertex3f(10.0, -25.0, -55.0); //kiri atas
    glEnd();

    //lantai blkng
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(-43.0, -25.0, -55.0); //kiri bawah
    glVertex3f(-43.0, -20.0, -55.0); //kanan bawah
    glVertex3f(10.0, -20.0, -55.0); //kanan atas
    glVertex3f(10.0, -25.0, -55.0); //kiri atas
    glEnd();

    ///bangku kanan

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(11.0, -25.0, 57.0); //kiri bawah
    glVertex3f(11.0, -15.0, 57.0); //kanan bawah
    glVertex3f(11.0, -15.0, -67.0); //kanan atas
    glVertex3f(11.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -15.0, 57.0); //kanan bawah
    glVertex3f(24.0, -15.0, -67.0); //kanan atas
    glVertex3f(24.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -15.0, 57.0); //kanan bawah
    glVertex3f(11.0, -15.0, 57.0); //kanan atas
    glVertex3f(11.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, -67.0); //kiri bawah
    glVertex3f(24.0, -15.0, -67.0); //kanan bawah
    glVertex3f(11.0, -15.0, -67.0); //kanan atas
    glVertex3f(11.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(11.0, -25.0, 57.0); //kanan bawah
    glVertex3f(11.0, -25.0, -67.0); //kanan atas
    glVertex3f(24.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -15.0, 57.0); //kiri bawah
    glVertex3f(11.0, -15.0, 57.0); //kanan bawah
    glVertex3f(11.0, -15.0, -67.0); //kanan atas
    glVertex3f(24.0, -15.0, -67.0); //kiri atas
    glEnd();

    ///bangku kiri

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -15.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -15.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -15.0, -67.0); //kanan atas
    glVertex3f(-59.0, -15.0, -67.0); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -25.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -25.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -15.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -15.0, -67.0); //kanan atas
    glVertex3f(-46.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-59.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-59.0, -15.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -15.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -15.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -15.0, 57.0); //kanan atas
    glVertex3f(-59.0, -25.0, 57.0); //kiri atas
    glEnd();

     ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, -67.0); //kiri bawah
    glVertex3f(-46.0, -15.0, -67.0); //kanan bawah
    glVertex3f(-59.0, -15.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10.0, -25.0, 47.0); //kiri bawah
    glVertex3f(10.0, -15.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -15.0, 47.0); //kanan atas
    glVertex3f(-45.0, -25.0, 47.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, 57.0); //kiri bawah
    glVertex3f(10.0, -15.0, 57.0); //kanan bawah
    glVertex3f(-45.0, -15.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -15.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -15.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -15.0, 57.0); //kanan atas
    glVertex3f(10.0, -15.0, 57.0); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -25.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -25.0, 57.0); //kanan atas
    glVertex3f(10.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, 47.0); //kiri bawah
    glVertex3f(10.0, -15.0, 47.0); //kanan bawah
    glVertex3f(10.0, -15.0, 57.0); //kanan atas
    glVertex3f(10.0, -25.0, 57.0); //kiri atas
    glEnd();

     ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-45.0, -25.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -15.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -15.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku belakang

    // bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-45.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -15.0, -57.0); //kanan bawah
    glVertex3f(10.0, -15.0, -57.0); //kanan atas
    glVertex3f(10.0, -25.0, -57.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, -67.0); //kiri bawah
    glVertex3f(10.0, -15.0, -67.0); //kanan bawah
    glVertex3f(-45.0, -15.0, -67.0); //kanan atas
    glVertex3f(-45.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-45.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -15.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -15.0, -67.0); //kanan atas
    glVertex3f(-45.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, -57.0); //kiri bawah
    glVertex3f(10.0, -15.0, -57.0); //kanan bawah
    glVertex3f(10.0, -15.0, -67.0); //kanan atas
    glVertex3f(10.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -25.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -25.0, -67.0); //kanan atas
    glVertex3f(10.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -15.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -15.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -15.0, -67.0); //kanan atas
    glVertex3f(10.0, -15.0, -67.0); //kiri atas
    glEnd();

    ///bangku blkng 2
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24.0, -25.0, -67.2); //kiri bawah
    glVertex3f(24.0, -4.0, -67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -67.2); //kanan atas
    glVertex3f(-59.0, -25.0, -67.2); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, -77.2); //kiri bawah
    glVertex3f(24.0, -4.0, -77.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -4.0, -67.2); //kiri bawah
    glVertex3f(-59.0, -4.0, -67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(24.0, -4.0, -77.2); //kiri atas
    glEnd();

     //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, -67.2); //kiri bawah
    glVertex3f(24.0, -4.0, -67.2); //kanan bawah
    glVertex3f(24.0, -4.0, -77.2); //kanan atas
    glVertex3f(24.0, -25.0, -77.2); //kiri atas
    glEnd();

     //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -25.0, -67.2); //kiri bawah
    glVertex3f(-59.0, -4.0, -67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, -67.2); //kiri bawah
    glVertex3f(-59.0, -25.0, -67.2); //kanan bawah
    glVertex3f(-59.0, -25.0, -77.2); //kanan atas
    glVertex3f(24.0, -25.0, -77.2); //kiri atas
    glEnd();

    ///bangku depan

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24.0, -25.0, 57.2); //kiri bawah
    glVertex3f(24.0, -4.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 57.2); //kanan atas
    glVertex3f(-59.0, -25.0, 57.2); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 67.2); //kiri bawah
    glVertex3f(24.0, -4.0, 67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

     //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -25.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -4.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.2); //kiri bawah
    glVertex3f(24.0, -4.0, 57.2); //kanan bawah
    glVertex3f(24.0, -4.0, 67.2); //kanan atas
    glVertex3f(24.0, -25.0, 67.2); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -25.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -25.0, 67.2); //kanan atas
    glVertex3f(24.0, -25.0, 67.2); //kiri atas
    glEnd();

     ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -4.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -4.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(24.0, -4.0, 67.2); //kiri atas
    glEnd();

    ///bangku kiri 2

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.2, -4.0, 67.2); //kiri bawah
    glVertex3f(-70.2, -4.0, 67.2); //kanan bawah
    glVertex3f(-70.2, -4.0, -77.2); //kanan atas
    glVertex3f(-59.2, -4.0, -77.2); //kiri atas
    glEnd();

     ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.2, -25.0, 67.2); //kiri bawah
    glVertex3f(-70.2, -25.0, 67.2); //kanan bawah
    glVertex3f(-70.2, -25.0, -77.2); //kanan atas
    glVertex3f(-59.2, -25.0, -77.2); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-59.2, -25.0, 67.2); //kiri bawah
    glVertex3f(-59.2, -4.0, 67.2); //kanan bawah
    glVertex3f(-59.2, -4.0, -77.2); //kanan atas
    glVertex3f(-59.2, -25.0, -77.2); //kiri atas
    glEnd();

     //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.2, -25.0, 67.2); //kiri bawah
    glVertex3f(-70.2, -4.0, 67.2); //kanan bawah
    glVertex3f(-70.2, -4.0, -77.2); //kanan atas
    glVertex3f(-70.2, -25.0, -77.2); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.0, -25.0, -77.2); //kiri bawah
    glVertex3f(-70.0, -4.0, -77.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.0, -25.0, 67.2); //kiri bawah
    glVertex3f(-70.0, -4.0, 67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

    ///bangku kanan 2

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(24.2, -25.0, 67.0); //kiri bawah
    glVertex3f(24.2, -4.0, 67.0); //kanan bawah
    glVertex3f(24.2, -4.0, -77.0); //kanan atas
    glVertex3f(24.2, -25.0, -77.0); //kiri atas
    glEnd();

     ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.2, -25.0, 67.0); //kiri bawah
    glVertex3f(35.2, -4.0, 67.0); //kanan bawah
    glVertex3f(35.2, -4.0, -77.0); //kanan atas
    glVertex3f(35.2, -25.0, -77.0); //kiri atas
    glEnd();

     //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.2, -25.0, 67.0); //kiri bawah
    glVertex3f(35.2, -4.0, 67.0); //kanan bawah
    glVertex3f(24.2, -4.0, 67.0); //kanan atas
    glVertex3f(24.2, -25.0, 67.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.2, -25.0, -77.0); //kiri bawah
    glVertex3f(35.2, -4.0, -77.0); //kanan bawah
    glVertex3f(24.2, -4.0, -77.0); //kanan atas
    glVertex3f(24.2, -25.0, -77.0); //kiri atas
    glEnd();

    ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.2, -25.0, 67.2); //kiri bawah
    glVertex3f(35.2, -25.0, 67.2); //kanan bawah
    glVertex3f(35.2, -25.0, -77.2); //kanan atas
    glVertex3f(24.2, -25.0, -77.2); //kiri atas
    glEnd();

    ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.2, -4.0, 67.2); //kiri bawah
    glVertex3f(35.2, -4.0, 67.2); //kanan bawah
    glVertex3f(35.2, -4.0, -77.2); //kanan atas
    glVertex3f(24.2, -4.0, -77.2); //kiri atas
    glEnd();

    ///bangku kanan 3

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(35.4, -25.0, 77.0); //kiri bawah
    glVertex3f(35.4, 4.0, 77.0); //kanan bawah
    glVertex3f(35.4, 4.0, -87.0); //kanan atas
    glVertex3f(35.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(45.4, -25.0, 77.0); //kiri bawah
    glVertex3f(45.4, 4.0, 77.0); //kanan bawah
    glVertex3f(45.4, 4.0, -87.0); //kanan atas
    glVertex3f(45.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.4, 4.0, 77.2); //kiri bawah
    glVertex3f(45.4, 4.0, 77.2); //kanan bawah
    glVertex3f(45.4, 4.0, -87.2); //kanan atas
    glVertex3f(35.4, 4.0, -87.2); //kiri atas
    glEnd();

     ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.4, -25.0, 77.2); //kiri bawah
    glVertex3f(45.4, -25.0, 77.2); //kanan bawah
    glVertex3f(45.4, -25.0, -87.2); //kanan atas
    glVertex3f(35.4, -25.0, -87.2); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(45.4, -25.0, 77.0); //kiri bawah
    glVertex3f(45.4, 4.0, 77.0); //kanan bawah
    glVertex3f(35.4, 4.0, 77.0); //kanan atas
    glVertex3f(35.4, -25.0, 77.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(45.4, -25.0, -87.0); //kiri bawah
    glVertex3f(45.4, 4.0, -87.0); //kanan bawah
    glVertex3f(35.4, 4.0, -87.0); //kanan atas
    glVertex3f(35.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///bangku kiri 3
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1.1);
    glVertex3f(-70.4, 4.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, 4.0, -87.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, -25.0, 77.4); //kanan bawah
    glVertex3f(-80.4, -25.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.4, -25.0, -87.4); //kiri bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan bawah
    glVertex3f(-70.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-70.4, 4.0, 77.4); //kanan atas
    glVertex3f(-70.4, -25.0, 77.4); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-70.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-70.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-70.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan atas
    glVertex3f(-80.4, -25.0, -87.4); //kiri atas
    glEnd();

    ///bangku depan 3
    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, 77.4); //kiri bawah
    glVertex3f(35.0, 4.0, 77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, 77.4); //kanan atas
    glVertex3f(-70.0, -25.0, 77.4); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(35.0, -25.0, 67.4); //kiri bawah
    glVertex3f(35.0, 4.0, 67.4); //kanan bawah
    glVertex3f(-70.0, 4.0, 67.4); //kanan atas
    glVertex3f(-70.0, -25.0, 67.4); //kiri atas
    glEnd();

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.0, -25.0, 67.4); //kiri bawah
    glVertex3f(-70.0, 4.0, 67.4); //kanan bawah
    glVertex3f(-70.0, 4.0, 77.4); //kanan atas
    glVertex3f(-70.0, -25.0, 77.4); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, 67.4); //kiri bawah
    glVertex3f(35.0, 4.0, 67.4); //kanan bawah
    glVertex3f(35.0, 4.0, 77.4); //kanan atas
    glVertex3f(35.0, -25.0, 77.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, 67.4); //kiri bawah
    glVertex3f(-70.0, -25.0, 67.4); //kanan bawah
    glVertex3f(-70.0, -25.0, 77.4); //kanan atas
    glVertex3f(35.0, -25.0, 77.4); //kiri atas
    glEnd();

     //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, 4.0, 67.4); //kiri bawah
    glVertex3f(-70.0, 4.0, 67.4); //kanan bawah
    glVertex3f(-70.0, 4.0, 77.4); //kanan atas
    glVertex3f(35.0, 4.0, 77.4); //kiri atas
    glEnd();

    ///bangku blkng 3
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(35.0, -25.0, -77.4); //kiri bawah
    glVertex3f(35.0, 4.0, -77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -77.4); //kanan atas
    glVertex3f(-70.0, -25.0, -77.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, -87.4); //kiri bawah
    glVertex3f(35.0, 4.0, -87.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(-70.0, -25.0, -87.4); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, 4.0, -77.4); //kiri bawah
    glVertex3f(-70.0, 4.0, -77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(35.0, 4.0, -87.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, -77.4); //kiri bawah
    glVertex3f(-70.0, -25.0, -77.4); //kanan bawah
    glVertex3f(-70.0, -25.0, -87.4); //kanan atas
    glVertex3f(35.0, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-70.0, -25.0, -77.4); //kiri bawah
    glVertex3f(-70.0, 4.0, -77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(-70.0, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(35.0, -25.0, -77.4); //kiri bawah
    glVertex3f(35.0, 4.0, -77.4); //kanan bawah
    glVertex3f(35.0, 4.0, -87.4); //kanan atas
    glVertex3f(35.0, -25.0, -87.4); //kiri atas
    glEnd();

    ///bangku belakang 4
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -88.0); //kiri bawah
    glVertex3f(55.0, 12.0, -88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -88.0); //kanan atas
    glVertex3f(-90.0, -25.0, -88.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, -98.0); //kiri bawah
    glVertex3f(55.0, 12.0, -98.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(-90.0, -25.0, -98.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, -88.0); //kiri bawah
    glVertex3f(5.0, 12.0, -88.0); //kanan bawah
    glVertex3f(55.0, 12.0, -98.0); //kanan atas
    glVertex3f(55.0, -25.0, -98.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-90.0, -25.0, -88.0); //kiri bawah
    glVertex3f(-90.0, 12.0, -88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(-90.0, -25.0, -98.0); //kiri atas
    glEnd();

     //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(5.0, -25.0, -88.0); //kiri bawah
    glVertex3f(-90.0, -25.0, -88.0); //kanan bawah
    glVertex3f(-90.0, -25.0, -98.0); //kanan atas
    glVertex3f(55.0, -25.0, -98.0); //kiri atas
    glEnd();

     //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, 12.0, -88.0); //kiri bawah
    glVertex3f(-90.0, 12.0, -88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(55.0, 12.0, -98.0); //kiri atas
    glEnd();

    ///bangku depan 4
    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, 88.0); //kiri bawah
    glVertex3f(55.0, 12.0, 88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 88.0); //kanan atas
    glVertex3f(-90.0, -25.0, 88.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 78.0); //kiri bawah
    glVertex3f(55.0, 12.0, 78.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 78.0); //kanan atas
    glVertex3f(-90.0, -25.0, 78.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, 12.0, 78.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 78.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 88.0); //kanan atas
    glVertex3f(55.0, 12.0, 88.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, 78.0); //kiri bawah
    glVertex3f(-90.0, -25.0, 78.0); //kanan bawah
    glVertex3f(-90.0, -25.0, 88.0); //kanan atas
    glVertex3f(55.0, -25.0, 88.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-90.0, -25.0, 78.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 78.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 88.0); //kanan atas
    glVertex3f(-90.0, -25.0, 88.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, 78.0); //kiri bawah
    glVertex3f(55.0, 12.0, 78.0); //kanan bawah
    glVertex3f(55.0, 12.0, 88.0); //kanan atas
    glVertex3f(55.0, -25.0, 88.0); //kiri atas
    glEnd();

    ///bangku kiri 4
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.5, 12.0, 77.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 77.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -87.0); //kanan atas
    glVertex3f(-80.5, 12.0, -87.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.5, -25.0, 77.0); //kiri bawah
    glVertex3f(-90.0, -25.0, 77.0); //kanan bawah
    glVertex3f(-90.0, -25.0, -87.0); //kanan atas
    glVertex3f(-80.5, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-80.5, -25.0, 77.0); //kiri bawah
    glVertex3f(-80.5, 12.0, 77.0); //kanan bawah
    glVertex3f(-80.5, 12.0, -87.0); //kanan atas
    glVertex3f(-80.5, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-90.0, -25.0, 77.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 77.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -87.0); //kanan atas
    glVertex3f(-90.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.5, -25.0, 77.0); //kiri bawah
    glVertex3f(-80.5, 12.0, 77.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 77.0); //kanan atas
    glVertex3f(-90.0, -25.0, 77.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-80.5, -25.0, -87.0); //kiri bawah
    glVertex3f(-80.5, 12.0, -87.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -87.0); //kanan atas
    glVertex3f(-90.0, -25.0, -87.0); //kiri atas
    glEnd();

    ///bangku kanan 4

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, 77.0); //kiri bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(55.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(46.0, 12.0, 77.0); //kanan bawah
    glVertex3f(46.0, 12.0, -87.0); //kanan atas
    glVertex3f(46.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(46.0, -25.0, -87.0); //kiri bawah
    glVertex3f(46.0, 12.0, -87.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(55.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(46.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan atas
    glVertex3f(55.0, -25.0, 77.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(55.0, -25.0, 77.0); //kanan bawah
    glVertex3f(55.0, -25.0, -87.0); //kanan atas
    glVertex3f(46.0, -25.0, -87.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(46.0, 12.0, 77.0); //kiri bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(46.0, 12.0, -87.0); //kiri atas
    glEnd();

      ///bangku kanan 5
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(65.0, -25.0, 97.0); //kiri bawah
    glVertex3f(65.0, 24.0, 97.0); //kanan bawah
    glVertex3f(65.0, 24.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(55.4, 24.0, 97.0); //kanan bawah
    glVertex3f(55.4, 24.0, -107.0); //kanan atas
    glVertex3f(55.4, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.4, 24.0, 97.0); //kiri bawah
    glVertex3f(65.0, 24.0, 97.0); //kanan bawah
    glVertex3f(65.0, 24.0, -107.0); //kanan atas
    glVertex3f(55.4, 24.0, -107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(65.0, -25.0, 97.0); //kanan bawah
    glVertex3f(65.0, -25.0, -107.0); //kanan atas
    glVertex3f(55.4, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku bkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(55.4, 24.0, 97.0); //kanan bawah
    glVertex3f(65.0, 24.0, 97.0); //kanan atas
    glVertex3f(65.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, -107.0); //kiri bawah
    glVertex3f(55.4, 24.0, -107.0); //kanan bawah
    glVertex3f(65.0, 24.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku kiri 5
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-90.5, 24.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 24.0, -107.0); //kanan atas
    glVertex3f(-90.5, 24.0, -107.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-100.0, -25.0, 97.0); //kanan bawah
    glVertex3f(-100.0, -25.0, -107.0); //kanan atas
    glVertex3f(-90.5, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, -107.0); //kiri bawah
    glVertex3f(-90.5, 24.0, -107.0); //kanan bawah
    glVertex3f(-100.0, 24.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 24.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 24.0, 97.0); //kanan atas
    glVertex3f(-100.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 24.0, 97.0); //kanan bawah
    glVertex3f(-90.5, 24.0, -107.0); //kanan atas
    glVertex3f(-90.5, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-100.0, -25.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 24.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku depan 5
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 97.0); //kiri bawah
    glVertex3f(55.0, 24.0, 97.0); //kanan bawah
    glVertex3f(-90.0, 24.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 24.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 24.0, 88.4); //kanan atas
    glVertex3f(-90.0, -25.0, 88.4); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.0, -25.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 24.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 24.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 24.0, 88.4); //kanan bawah
    glVertex3f(55.0, 24.0, 97.0); //kanan atas
    glVertex3f(55.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(-90.0, -25.0, 88.4); //kanan bawah
    glVertex3f(-90.0, -25.0, 97.0); //kanan atas
    glVertex3f(55.0, -25.0, 97.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, 24.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 24.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 24.0, 97.0); //kanan atas
    glVertex3f(55.0, 24.0, 97.0); //kiri atas
    glEnd();

    ///bangku belakang 5
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(55.0, 24.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 24.0, -98.4); //kanan atas
    glVertex3f(-90.0, -25.0, -98.4); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -107.0); //kiri bawah
    glVertex3f(55.0, 24.0, -107.0); //kanan bawah
    glVertex3f(-90.0, 24.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, 24.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 24.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 24.0, -107.0); //kanan atas
    glVertex3f(55.0, 24.0, -107.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(-90.0, -25.0, -98.4); //kanan bawah
    glVertex3f(-90.0, -25.0, -107.0); //kanan atas
    glVertex3f(55.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(55.0, 24.0, -98.4); //kanan bawah
    glVertex3f(55.0, 24.0, -107.0); //kanan atas
    glVertex3f(55.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.0, -25.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 24.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku belakang 6
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 32.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 32.0, -107.4); //kanan atas
    glVertex3f(-100.0, -25.0, -107.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, -117.0); //kiri bawah
    glVertex3f(65.0, 32.0, -117.0); //kanan bawah
    glVertex3f(-100.0, 32.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, 32.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 32.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 32.0, -107.4); //kanan bawah
    glVertex3f(65.0, 32.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, -25.0, -107.4); //kanan bawah
    glVertex3f(-100.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, 32.0, -107.4); //kiri bawah
    glVertex3f(-100.0, 32.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 32.0, -117.0); //kanan atas
    glVertex3f(65.0, 32.0, -117.0); //kiri atas
    glEnd();

    ///bangku depan 6
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(65.0, 32.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 32.0, 97.4); //kanan atas
    glVertex3f(-100.0, -25.0, 97.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, 107.0); //kiri bawah
    glVertex3f(65.0, 32.0, 107.0); //kanan bawah
    glVertex3f(-100.0, 32.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, 32.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 32.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 32.0, 107.0); //kanan atas
    glVertex3f(65.0, 32.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, -25.0, 97.4); //kanan bawah
    glVertex3f(-100.0, -25.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(65.0, 32.0, 97.4); //kanan bawah
    glVertex3f(65.0, 32.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 32.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 32.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    ///bangku kiri 6
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.5, 32.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -117.0); //kanan atas
    glVertex3f(-100.5, 32.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, -25.0, 107.0); //kanan bawah
    glVertex3f(-110.0, -25.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 32.0, 107.0); //kanan bawah
    glVertex3f(-100.5, 32.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.0, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 32.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 107.0); //kanan atas
    glVertex3f(-110.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-100.5, -25.0, -117.0); //kiri bawah
    glVertex3f(-100.5, 32.0, -117.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku kanan 6
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 32.0, 107.0); //kanan bawah
    glVertex3f(65.4, 32.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, 32.0, 107.0); //kanan bawah
    glVertex3f(75.0, 32.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.4, -25.0, -117.0); //kiri bawah
    glVertex3f(65.4, 32.0, -117.0); //kanan bawah
    glVertex3f(75.0, 32.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 32.0, 107.0); //kanan bawah
    glVertex3f(75.0, 32.0, 107.0); //kanan atas
    glVertex3f(75.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.4, 32.0, 107.0); //kiri bawah
    glVertex3f(75.0, 32.0, 107.0); //kanan bawah
    glVertex3f(75.0, 32.0, -117.0); //kanan atas
    glVertex3f(65.4, 32.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, -25.0, 107.0); //kanan bawah
    glVertex3f(75.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku kanan 7
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(75.4, 32.0, 120.0); //kanan bawah
    glVertex3f(75.4, 32.0, -130.0); //kanan atas
    glVertex3f(75.4, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(85.0, -25.0, 120.0); //kiri bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(85.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(85.0, -25.0, 120.0); //kanan bawah
    glVertex3f(85.0, -25.0, -130.0); //kanan atas
    glVertex3f(75.4, -25.0, -130.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.4, 32.0, 120.0); //kiri bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(75.4, 32.0, -130.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(75.4, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan atas
    glVertex3f(85.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.4, -25.0, -130.0); //kiri bawah
    glVertex3f(75.4, 32.0, -130.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(85.0, -25.0, -130.0); //kiri atas
    glEnd();

    ///bangku kiri 7
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.4, 32.0, 120.0); //kiri bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.4, 32.0, -130.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-120.0, -25.0, 120.0); //kanan bawah
    glVertex3f(-120.0, -25.0, -130.0); //kanan atas
    glVertex3f(-110.4, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.4, -25.0, -130.0); //kiri bawah
    glVertex3f(-110.4, 32.0, -130.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-120.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-110.4, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan atas
    glVertex3f(-120.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-110.4, 32.0, 120.0); //kanan bawah
    glVertex3f(-110.4, 32.0, -130.0); //kanan atas
    glVertex3f(-110.4, -25.0, -130.0); //kiri atas
    glEnd();


    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-120.0, -25.0, 120.0); //kiri bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-120.0, -25.0, -130.0); //kiri atas
    glEnd();

    ///bangku depan 7
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(75.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan atas
    glVertex3f(-110.0, -25.0, 108.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, 120.0); //kiri bawah
    glVertex3f(75.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(-110.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.0, -25.0, 108.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(-110.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(75.0, 32.0, 108.0); //kanan bawah
    glVertex3f(75.0, 32.0, 120.0); //kanan atas
    glVertex3f(75.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(-110.0, -25.0, 108.0); //kanan bawah
    glVertex3f(-110.0, -25.0, 120.0); //kanan atas
    glVertex3f(75.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, 32.0, 108.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(75.0, 32.0, 120.0); //kiri atas
    glEnd();

    ///bangku belakang 7
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(75.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan atas
    glVertex3f(-110.0, -25.0, -118.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, -130.0); //kiri bawah
    glVertex3f(75.0, 32.0, -130.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.0, -25.0, -130.0); //kiri atas
    glEnd();

    //atas atap
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(70.0, 32.0, -118.0); //kiri bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(7.0, 32.0, -130.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(-110.0, -25.0, -118.0); //kanan bawah
    glVertex3f(-110.0, -25.0, -130.0); //kanan atas
    glVertex3f(75.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(75.0, 32.0, -118.0); //kanan bawah
    glVertex3f(75.0, 32.0, -130.0); //kanan atas
    glVertex3f(75.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-110.0, -25.0, -118.0); //kiri bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.0, -25.0, -130.0); //kiri atas
    glEnd();


    ///atap kontol kiri
    //atap kiri
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(-120.0, 32.0, 110.0); //kiri bawah
    glVertex3f(-120.0, 50.0, 110.0); //kanan bawah
    glVertex3f(-120.0, 50.0, -120.0); //kanan atas
    glVertex3f(-120.0, 32.0, -120.0); //kiri atas
    glEnd();

    //atap kanan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-115.0, 32.0, 105.0); //kiri bawah
    glVertex3f(-115.0, 45.0, 105.0); //kanan bawah
    glVertex3f(-115.0, 45.0, -117.0); //kanan atas
    glVertex3f(-115.0, 32.0, -117.0); //kiri atas
    glEnd();

    //atas atap
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-70.0, 50.0, 110.0); //kiri bawah
    glVertex3f(-120.0, 50.0, 110.0); //kanan bawah
    glVertex3f(-120.0, 50.0, -120.0); //kanan atas
    glVertex3f(-70.0, 50.0, -120.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-105.0, 32.0, 120.0); //kiri bawah
    glVertex3f(-105.0, 50.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 50.0, 110.0); //kanan atas
    glVertex3f(-120.0, 32.0, 110.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-107.0, 32.0, 110.0); //kiri bawah
    glVertex3f(-107.0, 45.0, 110.0); //kanan bawah
    glVertex3f(-115.0, 45.0, 105.0); //kanan atas
    glVertex3f(-115.0, 32.0, 105.0); //kiri atas
    glEnd();

    //bangku dpn 2
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-103.0, 32.0, -123.0); //kiri bawah
    glVertex3f(-103.0, 45.0, -123.0); //kanan bawah
    glVertex3f(-115.0, 45.0, -117.0); //kanan atas
    glVertex3f(-115.0, 32.0, -117.0); //kiri atas
    glEnd();

    //bangku blkng 2
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-100.0, 32.0, -130.0); //kiri bawah
    glVertex3f(-100.0, 50.0, -130.0); //kanan bawah
    glVertex3f(-120.0, 50.0, -120.0); //kanan atas
    glVertex3f(-120.0, 32.0, -120.0); //kiri atas
    glEnd();


    ///atap kontol depan
    //atap dpn
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(70.0, 32.0, 110.0); //kiri bawah
    glVertex3f(70.0, 45.0, 110.0); //kanan bawah
    glVertex3f(-107.0, 45.0, 110.0); //kanan atas
    glVertex3f(-107.0, 32.0, 110.0); //kiri atas
    glEnd();

    //atap kanan dpan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(70.0, 32.0, 110.0); //kiri bawah
    glVertex3f(70.0, 45.0, 110.0); //kanan bawah
    glVertex3f(78.0, 45.0, 102.0); //kanan atas
    glVertex3f(78.0, 32.0, 102.0); //kiri atas
    glEnd();

    //atap blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(70.0, 32.0, 120.0); //kiri bawah
    glVertex3f(70.0, 50.0, 120.0); //kanan bawah
    glVertex3f(-105.0, 50.0, 120.0); //kanan atas
    glVertex3f(-105.0, 32.0, 120.0); //kiri atas
    glEnd();

    //atap kanan blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(70.0, 32.0, 120.0); //kiri bawah
    glVertex3f(70.0, 50.0, 120.0); //kanan bawah
    glVertex3f(85.0, 50.0, 110.0); //kanan atas
    glVertex3f(85.0, 32.0, 110.0); //kiri atas
    glEnd();

    //atas atap
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(70.0, 50.0, 120.0); //kiri bawah
    glVertex3f(-105.0, 50.0, 120.0); //kanan bawah
    glVertex3f(-105.0, 50.0, 70.0); //kanan atas
    glVertex3f(70.0, 50.0, 70.0); //kiri atas
    glEnd();


    ///atap kontol blkng
    //atap dpn
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(70.0, 32.0, -123.0); //kiri bawah
    glVertex3f(70.0, 45.0, -123.0); //kanan bawah
    glVertex3f(-103.0, 45.0, -123.0); //kanan atas
    glVertex3f(-103.0, 32.0, -123.0); //kiri atas
    glEnd();

    //atap blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(73.0, 32.0, -130.0); //kiri bawah
    glVertex3f(73.0, 50.0, -130.0); //kanan bawah
    glVertex3f(-100.0, 50.0, -130.0); //kanan atas
    glVertex3f(-100.0, 32.0, -130.0); //kiri atas
    glEnd();

    //atas atap
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(73.0, 50.0, -130.0); //kiri bawah
    glVertex3f(-100.0, 50.0, -130.0); //kanan bawah
    glVertex3f(-100.0, 50.0, -70.0); //kanan atas
    glVertex3f(73.0, 50.0, -70.0); //kiri atas
    glEnd();



    ///atap kontol kanan
    //atap miring depan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(78, 32.0, 102.0); //kiri bawah
    glVertex3f(78, 45.0, 102.0); //kanan bawah
    glVertex3f(78, 45.0, -110.0); //kanan atas
    glVertex3f(78, 32.0, -110.0); //kiri atas
    glEnd();

    //atap miring blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(73.0, 32.0, -130.0); //kiri bawah
    glVertex3f(73.0, 50.0, -130.0); //kanan bawah
    glVertex3f(85.0, 50.0, -115.0); //kanan atas
    glVertex3f(85.0, 32.0, -115.0); //kiri atas
    glEnd();

    //atap blkng
    glBegin(GL_QUADS);
    glColor3f(0.1,0.1,0.5);
    glVertex3f(85, 32.0, 110.0); //kiri bawah
    glVertex3f(85, 50.0, 110.0); //kanan bawah
    glVertex3f(85, 50.0, -115.0); //kanan atas
    glVertex3f(85, 32.0, -115.0); //kiri atas
    glEnd();


    //atap dpan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(70.0, 32.0, -123.0); //kiri bawah
    glVertex3f(70.0, 45.0, -123.0); //kanan bawah
    glVertex3f(78.0, 45.0, -110.0); //kanan atas
    glVertex3f(78.0, 32.0, -110.0); //kiri atas
    glEnd();

    //atas ATAP
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(30, 50.0, 110.0); //kiri bawah
    glVertex3f(85.0, 50.0, 110.0); //kanan bawah
    glVertex3f(85.0, 50.0, -115.0); //kanan atas
    glVertex3f(30, 50.0, -115.0); //kiri atas
    glEnd();




    //kursi biru
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-66,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-66,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-63,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-63,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-60,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-60,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();





    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //sebrang

        glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,43.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,38.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,33.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,28.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,23.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,18.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-67.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-68,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,-2,-72.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //sebrang 2


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,-2,-73.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,-2,-68.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


//krsilantai2



glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-66,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-66,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();



glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-63,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-63,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-60,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-60,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-57,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-54,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-51,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-48,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-45,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-42,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-39,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-30,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-27,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-24,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-21,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


   glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


   glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,5,-83.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,5,-78.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    //sebrang 1


glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-65,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-62,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-62,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-59,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-59,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-56,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-56,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-53,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-53,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-50,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-50,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-47,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-47,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-44,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-44,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-41,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-41,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-38,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-38,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-29,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-29,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-26,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-26,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-23,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-23,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-20,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-20,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-17,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-14,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-11,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-8,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-5,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();



    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(31,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,5,76.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,5,71.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //sebrang kanan kiri
    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,63.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

 glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


       glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(44,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(41,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(38,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

//sebrang kanan kiri
glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-70.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-65.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-60.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-55.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-50.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-45.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,32.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,56.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,56.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,56.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-77,5,61.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-74,5,61.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-71,5,61.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();
//lantai 3

 glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-81,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-84,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-87,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


//sebrang 1

glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,58.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,53.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,40.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,35.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,30.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,25.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,20.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,15.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,3.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-2.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-7.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-12.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-17.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-22.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-27.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-37.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-42.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-47.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-52.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-57.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(46,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(49,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(52,14,-62.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    //sebrang 2
     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


   glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-4,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-4,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-10,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-10,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-16,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-16,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-22,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-22,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-25,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-25,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-28,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-28,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-37,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-37,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-40,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-40,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-43,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-43,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-46,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-46,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-49,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-49,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-52,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-52,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-55,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-55,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-58,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-58,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-64,14,-92.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-64,14,-87.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


    //sebrang 2
     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(16,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(19,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(13,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(10,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(7,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(25,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(22,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(28,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();


   glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(4,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-4,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-4,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-7,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-10,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-10,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-13,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-16,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-16,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-19,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-22,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-22,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-25,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-25,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-28,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-28,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-37,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-37,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-40,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-40,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-43,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-43,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-46,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-46,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-49,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-49,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-52,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-52,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-55,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-55,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-58,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-58,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-61,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-64,14,85.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.1,0.1,0.5);
    glTranslatef(-64,14,80.5);
    glScalef(1,0.5,2);
    glutSolidCube(2);
    glPopMatrix();




     ///garis tengah lapangan (erits)
   glBegin(GL_LINES);
   glColor3f(1,1,1);
    glVertex3f(-42.5, -19.0, 0.0);
      glVertex3f(9.5, -19.0, 0.0);
   glEnd();


    ///Gawang1 (new erits)
    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-5,-19.0, 35.0);
    glVertex3f(-5, 1.5, 35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-5, -19.0, 45.0);
    glVertex3f(-5, 1, 35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-24.5,-19.0, 35.0);
    glVertex3f(-24.5, 1.5, 35.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-24.5, -19.0, 45.0);
    glVertex3f(-24.5, 1, 35.0);
    glEnd();


    ///pengubung sisi kiri dan kanan gawang1(new)

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-25, 1, 35.0);
   glVertex3f(-4.5, 1, 35.0);
    glEnd();


   ///sisi dalam kotak pinalti, sisi depan (erits)
    glBegin(GL_LINES);
     glColor3f(1,1,1);
    glVertex3f(-25, -19.0, 35.0);
    glVertex3f(-4.5, -19.0, 35.0);
    glEnd();

    ///sisi dalam kotak pinalti, sisi kanan (erits)
    glBegin(GL_LINES);
     glColor3f(1,1,1);
    glVertex3f(-5,-19.0, 35.0);
    glVertex3f(-5, -19.0,45.0);
    glEnd();


   ///sisi dalam kotak, sisi kiri (erits)
    glBegin(GL_LINES);
     glColor3f(1,1,1);
    glVertex3f(-24.5,-19.0, 35.0);
    glVertex3f(-24.5, -19.0,45.0);
    glEnd();

    ///sisi luar kanan kotak pinalti (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(2.2,-19.0, 44.3);
    glVertex3f(2.2, -19.0, 29.0);
    glEnd();

       ///sisi luar kiri kotak pinalti (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-34,-19.0, 44.3);
    glVertex3f(-34, -19.0, 29.0);
    glEnd();

        ///sisi atas depan kotak pinalti (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-34, -19.0, 29.0);
    glVertex3f(3, -19.0, 29.0);
    glEnd();




    ///Gawang2 (new erits)

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-25,-19.0, -45.0);
    glVertex3f(-25, 1, -45.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-25,-19.0, -55.0);
    glVertex3f(-25, 1, -45.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-5,-19.0, -45.0);
    glVertex3f(-5, 1, -45.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-5,-19.0, -55.0);
    glVertex3f(-5, 1, -45.0);
    glEnd();

    ///pengubung sisi kiri dan kanan gawang2(new)

    glBegin(GL_LINES);
    glColor3f(0,0,0);
    glVertex3f(-25.5, 1, -45);
    glVertex3f(-4.5, 1, -45);
    glEnd();


    ///sisi dalam kotak pinalti, sisi depan  (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-25, -19.0, -45.0);
    glVertex3f(-4.5, -19.0, -45.0);
    glEnd();

   ///sisi dalam kotak sisi kanan (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-25,-19.0, -45.0);
    glVertex3f(-25, -19.0, -55.0);
    glEnd();

    ///sisi dalam kotak pinalti, sisi kiri (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-5,-19.0, -45.0);
    glVertex3f(-5, -19.0, -55.0);
    glEnd();


    /// sisi depan kotak pinalti (erits)
      glBegin(GL_LINES);
      glColor3f(1,1,1);
    glVertex3f(-35, -19.0, -38.0);
    glVertex3f(2.5, -19.0, -38.0);
   glEnd();

   ///sisi luar kanan kotak pinalti (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-35,-19.0, -55.0);
    glVertex3f(-35, -19.0, -38.0);
   glEnd();


   ///sisi luar kiri kotak pinalti (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(2.5,-19.0, -55.0);
    glVertex3f(2.5, -19.0, -38.0);
   glEnd();



    ///kumpulan garis panjang sisi kiri,kanan atas bawah


    ///sisi kiri lapangan garis putih panjang (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-42,-19.0, 45.0);
    glVertex3f(-42, -19.0, -55.0);
   glEnd();

      ///sisi kanan lapangan garis putih panjang (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(9,-19.0, 45.0);
    glVertex3f(9, -19.0, -55.0);
   glEnd();

    ///garis panjang putih belakang gawang (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-43, -19.0, -55.0);
    glVertex3f(23, -19.0, -55.0);
   glEnd();

    ///garis panjang putih belakang gawang (erits)
    glBegin(GL_LINES);
    glColor3f(1,1,1);
    glVertex3f(-43, -19.0, 45.0);
    glVertex3f(23, -19.0, 45.0);
   glEnd();


///bola
    glPushMatrix();
 glTranslatef(-28,-16.5,-25.0);
 glColor3f(0.0,0.0,0.0);
 glutWireSphere(2,25,3);
 glPopMatrix();


 glPushMatrix();
 glTranslatef(-28,-16.5,-25.0);
 glColor3f(1.0,1.0,1.0);
 glutWireSphere(1.6,25,50);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(-18,-16.5,-25.0);
 glColor3f(1,0,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-18,-10.5,-25.0);
 glColor3f(1,0,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(-18,-16.5,-45.0);
 glColor3f(1,0,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-18,-10.5,-45.0);
 glColor3f(1,0,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

///orang
 glPushMatrix();
 glTranslatef(-8,-16.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-8,-10.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(6,-16.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(6,-10.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(-36,-16.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-36,-10.5,-5.0);
 glColor3f(1,0,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(-18,-16.5,15.0);
 glColor3f(1,0.5,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-18,-10.5,15.0);
 glColor3f(1,0.5,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

///orang
 glPushMatrix();
 glTranslatef(-27,-16.5,-18.0);
 glColor3f(1,0.5,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-27,-10.5,-18.0);
 glColor3f(1,0.5,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();


 ///orang
 glPushMatrix();
 glTranslatef(-30,-16.5,12.0);
 glColor3f(1,0.5,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-30,-10.5,12.0);
 glColor3f(1,0.5,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();


 ///orang
 glPushMatrix();
 glTranslatef(5,-16.5,-13.0);
 glColor3f(1,0.5,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(5,-10.5,-13.0);
 glColor3f(1,0.5,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();

 ///orang
 glPushMatrix();
 glTranslatef(-20,-16.5,28.0);
 glColor3f(1,0.5,0);
 glutWireSphere(3.0,300,500);
 glPopMatrix();

 glPushMatrix();
 glTranslatef(-20,-10.5,28.0);
 glColor3f(1,0.5,0);
 glutWireSphere(2.0,400,800);
 glPopMatrix();


 ///new 1/2 lingkaran
    int i;
   glColor3f(1, 1, 1);
	glBegin(GL_LINE_STRIP);
	int radiusss = -7, x_tengaaah = -15, y_tengaaah = 29;
	for (i = 0; i <= jumlah_titik - 10; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaaah + radiusss * cos(sudut);
		float y = y_tengaaah + radiusss * sin(sudut);
		glVertex3f(x, -18.0, y);
	}
	glEnd();
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	int x_tengaaahh = -15, y_tengaaahh = 0.1;
	for (i =10 ; i <= 360+ 0; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaaahh + radiusss * cos(sudut);
		float y = y_tengaaahh + radiusss * sin(sudut);
		glVertex3f(x, -18.0, y);
	}
	glEnd();

	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_STRIP);
	int a_tengaaahh = -15, b_tengaaahh = -38.1;
	for (i =10 ; i <= jumlah_titik+ 0; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = a_tengaaahh + radiusss * cos(sudut);
		float y = b_tengaaahh + radiusss * sin(sudut);
		glVertex3f(x, -18.0, y);
	}
	glEnd();





	//tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 39.9);
    glVertex3f(-44.0, -16.0, 39.9);
    glVertex3f(-44.0, -6.0, 39.9);
    glVertex3f(-42.0, -6.0, 39.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 37.9);
    glVertex3f(-44.0, -16.0, 37.9);
    glVertex3f(-44.0, -6.0, 37.9);
    glVertex3f(-42.0, -6.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 37.9);
    glVertex3f(-42.0, -16.0, 39.9);
    glVertex3f(-42.0, -6.0, 39.9);
    glVertex3f(-42.0, -6.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, 37.9);
    glVertex3f(-44.0, -16.0, 39.9);
    glVertex3f(-44.0, -6.0, 39.9);
    glVertex3f(-44.0, -6.0, 37.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,39.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

	//tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 29.9);
    glVertex3f(-44.0, -16.0, 29.9);
    glVertex3f(-44.0, -6.0, 29.9);
    glVertex3f(-42.0, -6.0, 29.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 27.9);
    glVertex3f(-44.0, -16.0, 27.9);
    glVertex3f(-44.0, -6.0, 27.9);
    glVertex3f(-42.0, -6.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 27.9);
    glVertex3f(-42.0, -16.0, 29.9);
    glVertex3f(-42.0, -6.0, 29.9);
    glVertex3f(-42.0, -6.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, 27.9);
    glVertex3f(-44.0, -16.0, 29.9);
    glVertex3f(-44.0, -6.0, 29.9);
    glVertex3f(-44.0, -6.0, 27.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,29.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 19.9);
    glVertex3f(-44.0, -16.0, 19.9);
    glVertex3f(-44.0, -6.0, 19.9);
    glVertex3f(-42.0, -6.0, 19.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 17.9);
    glVertex3f(-44.0, -16.0, 17.9);
    glVertex3f(-44.0, -6.0, 17.9);
    glVertex3f(-42.0, -6.0, 17.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 17.9);
    glVertex3f(-42.0, -16.0, 19.9);
    glVertex3f(-42.0, -6.0, 19.9);
    glVertex3f(-42.0, -6.0, 17.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, 17.9);
    glVertex3f(-44.0, -16.0, 19.9);
    glVertex3f(-44.0, -6.0, 19.9);
    glVertex3f(-44.0, -6.0, 17.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,19.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 9.9);
    glVertex3f(-44.0, -16.0, 9.9);
    glVertex3f(-44.0, -6.0,9.9);
    glVertex3f(-42.0, -6.0, 9.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 7.9);
    glVertex3f(-44.0, -16.0, 7.9);
    glVertex3f(-44.0, -6.0,7.9);
    glVertex3f(-42.0, -6.0, 7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, 7.9);
    glVertex3f(-42.0, -16.0, 9.9);
    glVertex3f(-42.0, -6.0, 9.9);
    glVertex3f(-42.0, -6.0, 7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, 7.9);
    glVertex3f(-44.0, -16.0, 9.9);
    glVertex3f(-44.0, -6.0, 9.9);
    glVertex3f(-44.0, -6.0, 7.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,9.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

//tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -1.9);
    glVertex3f(-44.0, -16.0, -1.9);
    glVertex3f(-44.0, -6.0, -1.9);
    glVertex3f(-42.0, -6.0, -1.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -3.9);
    glVertex3f(-44.0, -16.0, -3.9);
    glVertex3f(-44.0, -6.0, -3.9);
    glVertex3f(-42.0, -6.0, -3.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -3.9);
    glVertex3f(-42.0, -16.0, -1.9);
    glVertex3f(-42.0, -6.0, -1.9);
    glVertex3f(-42.0, -6.0, -3.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -3.9);
    glVertex3f(-44.0, -16.0, -1.9);
    glVertex3f(-44.0, -6.0, -1.9);
    glVertex3f(-44.0, -6.0, -3.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-3.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();


 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -11.9);
    glVertex3f(-44.0, -16.0, -11.9);
    glVertex3f(-44.0, -6.0, -11.9);
    glVertex3f(-42.0, -6.0, -11.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -13.9);
    glVertex3f(-44.0, -16.0, -13.9);
    glVertex3f(-44.0, -6.0, -13.9);
    glVertex3f(-42.0, -6.0, -13.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -13.9);
    glVertex3f(-42.0, -16.0, -11.9);
    glVertex3f(-42.0, -6.0, -11.9);
    glVertex3f(-42.0, -6.0, -13.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -13.9);
    glVertex3f(-44.0, -16.0, -11.9);
    glVertex3f(-44.0, -6.0, -11.9);
    glVertex3f(-44.0, -6.0, -13.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-13.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

//tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -21.9);
    glVertex3f(-44.0, -16.0, -21.9);
    glVertex3f(-44.0, -6.0, -21.9);
    glVertex3f(-42.0, -6.0, -21.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -23.9);
    glVertex3f(-44.0, -16.0, -23.9);
    glVertex3f(-44.0, -6.0, -23.9);
    glVertex3f(-42.0, -6.0, -23.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -23.9);
    glVertex3f(-42.0, -16.0, -21.9);
    glVertex3f(-42.0, -6.0, -21.9);
    glVertex3f(-42.0, -6.0, -23.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -23.9);
    glVertex3f(-44.0, -16.0, -21.9);
    glVertex3f(-44.0, -6.0, -21.9);
    glVertex3f(-44.0, -6.0, -23.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-23.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();


 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -31.9);
    glVertex3f(-44.0, -16.0, -31.9);
    glVertex3f(-44.0, -6.0, -31.9);
    glVertex3f(-42.0, -6.0, -31.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -33.9);
    glVertex3f(-44.0, -16.0, -33.9);
    glVertex3f(-44.0, -6.0, -33.9);
    glVertex3f(-42.0, -6.0, -33.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -33.9);
    glVertex3f(-42.0, -16.0, -31.9);
    glVertex3f(-42.0, -6.0, -31.9);
    glVertex3f(-42.0, -6.0, -33.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -33.9);
    glVertex3f(-44.0, -16.0, -31.9);
    glVertex3f(-44.0, -6.0, -31.9);
    glVertex3f(-44.0, -6.0, -33.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-33.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -41.9);
    glVertex3f(-44.0, -16.0, -41.9);
    glVertex3f(-44.0, -6.0, -41.9);
    glVertex3f(-42.0, -6.0, -41.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -43.9);
    glVertex3f(-44.0, -16.0, -43.9);
    glVertex3f(-44.0, -6.0, -43.9);
    glVertex3f(-42.0, -6.0, -43.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -43.9);
    glVertex3f(-42.0, -16.0, -41.9);
    glVertex3f(-42.0, -6.0, -41.9);
    glVertex3f(-42.0, -6.0, -43.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -43.9);
    glVertex3f(-44.0, -16.0, -41.9);
    glVertex3f(-44.0, -6.0, -41.9);
    glVertex3f(-44.0, -6.0, -43.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-43.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();


 //tiang

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -51.9);
    glVertex3f(-44.0, -16.0, -51.9);
    glVertex3f(-44.0, -6.0, -51.9);
    glVertex3f(-42.0, -6.0, -51.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -53.9);
    glVertex3f(-44.0, -16.0, -53.9);
    glVertex3f(-44.0, -6.0, -53.9);
    glVertex3f(-42.0, -6.0, -53.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-42.0, -16.0, -53.9);
    glVertex3f(-42.0, -16.0, -51.9);
    glVertex3f(-42.0, -6.0, -51.9);
    glVertex3f(-42.0, -6.0, -53.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.0,0.0,0.0);
    glVertex3f(-44.0, -16.0, -53.9);
    glVertex3f(-44.0, -16.0, -51.9);
    glVertex3f(-44.0, -6.0, -51.9);
    glVertex3f(-44.0, -6.0, -53.9);
    glEnd();
//lampu
    glPushMatrix();
 glTranslatef(-43,-6.5,-53.0);
 glColor3f(1,1,0);
 glutWireSphere(1.6,250,500);
 glPopMatrix();

 ///bendera

    //tiang depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-43.0, -10.0, 53.0); //kiri bawah
    glVertex3f(-43.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-46.0, 30.0, 53.0); //kanan atas
    glVertex3f(-46.0, -10.0, 53.0); //kiri atas
    glEnd();

    //tiang blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-43.0, -10.0, 56.0); //kiri bawah
    glVertex3f(-43.0, 30.0, 56.0); //kanan bawah
    glVertex3f(-46.0, 30.0, 56.0); //kanan atas
    glVertex3f(-46.0, -10.0, 56.0); //kiri atas
    glEnd();

    //tiang kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-46.0, -10.0, 53.0); //kiri bawah
    glVertex3f(-46.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-46.0, 30.0, 56.0); //kanan atas
    glVertex3f(-46.0, -10.0, 56.0); //kiri atas
    glEnd();

    //tiang kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-43.0, -10.0, 53.0); //kiri bawah
    glVertex3f(-43.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-43.0, 30.0, 56.0); //kanan atas
    glVertex3f(-43.0, -10.0, 56.0); //kiri atas
    glEnd();

    //bawah bendera 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-50.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-43.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-43.0, 30.0, 56.0); //kanan atas
    glVertex3f(-50.0, 30.0, 56.0); //kiri atas
    glEnd();

    //bawah bendera 2
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-57.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-50.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-50.0, 30.0, 56.0); //kanan atas
    glVertex3f(-57.0, 30.0, 56.0); //kiri atas
    glEnd();

    //bawah bendera 3
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-64.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-57.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-57.0, 30.0, 56.0); //kanan atas
    glVertex3f(-64.0, 30.0, 56.0); //kiri atas
    glEnd();

    //atas bendera 1
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-50.0, 40.0, 53.0); //kiri bawah
    glVertex3f(-43.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-43.0, 40.0, 56.0); //kanan atas
    glVertex3f(-50.0, 40.0, 56.0); //kiri atas
    glEnd();

    //bawah bendera 2
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-57.0, 40.0, 53.0); //kiri bawah
    glVertex3f(-50.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-50.0, 40.0, 56.0); //kanan atas
    glVertex3f(-57.0, 40.0, 56.0); //kiri atas
    glEnd();

    //bawah bendera 3
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-64.0, 40.0, 53.0); //kiri bawah
    glVertex3f(-57.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-57.0, 40.0, 56.0); //kanan atas
    glVertex3f(-64.0, 40.0, 56.0); //kiri atas
    glEnd();

    //biru blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-50.0, 30.0, 56.0); //kiri bawah
    glVertex3f(-50.0, 40.0, 56.0); //kanan bawah
    glVertex3f(-43.0, 40.0, 56.0); //kanan atas
    glVertex3f(-43.0, 30.0, 56.0); //kiri atas
    glEnd();

    //biru depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-50.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-50.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-43.0, 40.0, 53.0); //kanan atas
    glVertex3f(-43.0, 30.0, 53.0); //kiri atas
    glEnd();

    //putih blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-57.0, 30.0, 56.0); //kiri bawah
    glVertex3f(-57.0, 40.0, 56.0); //kanan bawah
    glVertex3f(-50.0, 40.0, 56.0); //kanan atas
    glVertex3f(-50.0, 30.0, 56.0); //kiri atas
    glEnd();

    //putih dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-57.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-57.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-50.0, 40.0, 53.0); //kanan atas
    glVertex3f(-50.0, 30.0, 53.0); //kiri atas
    glEnd();

    //merah blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-57.0, 30.0, 56.0); //kiri bawah
    glVertex3f(-57.0, 40.0, 56.0); //kanan bawah
    glVertex3f(-64.0, 40.0, 56.0); //kanan atas
    glVertex3f(-64.0, 30.0, 56.0); //kiri atas
    glEnd();

    //merah blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-57.0, 30.0, 53.0); //kiri bawah
    glVertex3f(-57.0, 40.0, 53.0); //kanan bawah
    glVertex3f(-64.0, 40.0, 53.0); //kanan atas
    glVertex3f(-64.0, 30.0, 53.0); //kiri atas
    glEnd();

    //biru kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-43.0, 40.0, 53.0); //kiri bawah
    glVertex3f(-43.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-43.0, 30.0, 56.0); //kanan atas
    glVertex3f(-43.0, 40.0, 56.0); //kiri atas
    glEnd();

    //merah kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-64.0, 40.0, 53.0); //kiri bawah
    glVertex3f(-64.0, 30.0, 53.0); //kanan bawah
    glVertex3f(-64.0, 30.0, 56.0); //kanan atas
    glVertex3f(-64.0, 40.0, 56.0); //kiri atas
    glEnd();





    ///tiang lampu

    //tiang depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10.0, -10.0, 53.0); //kiri bawah
    glVertex3f(10.0, 35.0, 53.0); //kanan bawah
    glVertex3f(15.0, 35.0, 53.0); //kanan atas
    glVertex3f(15.0, -10.0, 53.0); //kiri atas
    glEnd();

    //tiang blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10.0, -10.0, 57.0); //kiri bawah
    glVertex3f(10.0, 35.0, 57.0); //kanan bawah
    glVertex3f(15.0, 35.0, 57.0); //kanan atas
    glVertex3f(15.0, -10.0, 57.0); //kiri atas
    glEnd();

    //tiang kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(15.0, -10.0, 53.0); //kiri bawah
    glVertex3f(15.0, 35.0, 53.0); //kanan bawah
    glVertex3f(15.0, 35.0, 57.0); //kanan atas
    glVertex3f(15.0, -10.0, 57.0); //kiri atas
    glEnd();

    //tiang kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(10.0, -10.0, 53.0); //kiri bawah
    glVertex3f(10.0, 35.0, 53.0); //kanan bawah
    glVertex3f(10.0, 35.0, 57.0); //kanan atas
    glVertex3f(10.0, -10.0, 57.0); //kiri atas
    glEnd();

    //bawah lampu
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-5.0, 35.0, 50.0); //kiri bawah
    glVertex3f(25.0, 35.0, 50.0); //kanan bawah
    glVertex3f(25.0, 35.0, 57.0); //kanan atas
    glVertex3f(-5.0, 35.0, 57.0); //kiri atas
    glEnd();

    //atas lampu
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-5.0, 45.0, 50.0); //kiri bawah
    glVertex3f(25.0, 45.0, 50.0); //kanan bawah
    glVertex3f(25.0, 45.0, 57.0); //kanan atas
    glVertex3f(-5.0, 45.0, 57.0); //kiri atas
    glEnd();

    //lampu kiri
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-5.0, 45.0, 50.0); //kiri bawah
    glVertex3f(-5.0, 35.0, 50.0); //kanan bawah
    glVertex3f(-5.0, 35.0, 57.0); //kanan atas
    glVertex3f(-5.0, 45.0, 57.0); //kiri atas
    glEnd();

    //lampu kanan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(25.0, 45.0, 50.0); //kiri bawah
    glVertex3f(25.0, 35.0, 50.0); //kanan bawah
    glVertex3f(25.0, 35.0, 57.0); //kanan atas
    glVertex3f(25.0, 45.0, 57.0); //kiri atas
    glEnd();

    //lampu blkng
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-5.0, 35.0, 57.0); //kiri bawah
    glVertex3f(-5.0, 45.0, 57.0); //kanan bawah
    glVertex3f(25.0, 45.0, 57.0); //kanan atas
    glVertex3f(25.0, 35.0, 57.0); //kiri atas
    glEnd();

    //lampu 1
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-5.0, 43.0, 50.0); //kiri bawah
    glVertex3f(-5.0, 44.0, 50.0); //kanan bawah
    glVertex3f(25.0, 44.0, 50.0); //kanan atas
    glVertex3f(25.0, 43.0, 50.0); //kiri atas
    glEnd();

    //lampu 2
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-5.0, 40.0, 50.0); //kiri bawah
    glVertex3f(-5.0, 41.0, 50.0); //kanan bawah
    glVertex3f(25.0, 41.0, 50.0); //kanan atas
    glVertex3f(25.0, 40.0, 50.0); //kiri atas
    glEnd();

    //lampu 3
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-5.0, 37.0, 50.0); //kiri bawah
    glVertex3f(-5.0, 38.0, 50.0); //kanan bawah
    glVertex3f(25.0, 38.0, 50.0); //kanan atas
    glVertex3f(25.0, 37.0, 50.0); //kiri atas
    glEnd();

    ///lampu blkng
    //tiang depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-35.0, -10.0, -57.0); //kiri bawah
    glVertex3f(-35.0, 35.0, -57.0); //kanan bawah
    glVertex3f(-40.0, 35.0, -57.0); //kanan atas
    glVertex3f(-40.0, -10.0, -57.0); //kiri atas
    glEnd();

    //tiang depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-35.0, -10.0, -60.0); //kiri bawah
    glVertex3f(-35.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-40.0, 35.0, -60.0); //kanan atas
    glVertex3f(-40.0, -10.0, -60.0); //kiri atas
    glEnd();

    //tiang kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-40.0, -10.0, -60.0); //kiri bawah
    glVertex3f(-40.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-40.0, 35.0, -57.0); //kanan atas
    glVertex3f(-40.0, -10.0, -57.0); //kiri atas
    glEnd();

    //tiang kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-35.0, -10.0, -60.0); //kiri bawah
    glVertex3f(-35.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-35.0, 35.0, -57.0); //kanan atas
    glVertex3f(-35.0, -10.0, -57.0); //kiri atas
    glEnd();

    //bawah lampu
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-25.0, 35.0, -60.0); //kiri bawah
    glVertex3f(-50.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-50.0, 35.0, -57.0); //kanan atas
    glVertex3f(-25.0, 35.0, -57.0); //kiri atas
    glEnd();

    //atas lampu
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-25.0, 45.0, -60.0); //kiri bawah
    glVertex3f(-50.0, 45.0, -60.0); //kanan bawah
    glVertex3f(-50.0, 45.0, -57.0); //kanan atas
    glVertex3f(-25.0, 45.0, -57.0); //kiri atas
    glEnd();

    //lampu blkng
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-25.0, 35.0, -60.0); //kiri bawah
    glVertex3f(-25.0, 45.0, -60.0); //kanan bawah
    glVertex3f(-50.0, 45.0, -60.0); //kanan atas
    glVertex3f(-50.0, 35.0, -60.0); //kiri atas
    glEnd();

    //lampu kanan
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-25.0, 45.0, -60.0); //kiri bawah
    glVertex3f(-25.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-25.0, 35.0, -57.0); //kanan atas
    glVertex3f(-25.0, 45.0, -57.0); //kiri atas
    glEnd();

    //lampu kiri
    glBegin(GL_QUADS);
    glColor3f(0.75,0.75,0.75);
    glVertex3f(-50.0, 45.0, -60.0); //kiri bawah
    glVertex3f(-50.0, 35.0, -60.0); //kanan bawah
    glVertex3f(-50.0, 35.0, -57.0); //kanan atas
    glVertex3f(-50.0, 45.0, -57.0); //kiri atas
    glEnd();

    //lampu 1
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-25.0, 43.0, -57.0); //kiri bawah
    glVertex3f(-25.0, 44.0, -57.0); //kanan bawah
    glVertex3f(-50.0, 44.0, -57.0); //kanan atas
    glVertex3f(-50.0, 43.0, -57.0); //kiri atas
    glEnd();

    //lampu 2
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-25.0, 40.0, -57.0); //kiri bawah
    glVertex3f(-25.0, 41.0, -57.0); //kanan bawah
    glVertex3f(-50.0, 41.0, -57.0); //kanan atas
    glVertex3f(-50.0, 40.0, -57.0); //kiri atas
    glEnd();

    //lampu 3
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-25.0, 37.0, -57.0); //kiri bawah
    glVertex3f(-25.0, 38.0, -57.0); //kanan bawah
    glVertex3f(-50.0, 38.0, -57.0); //kanan atas
    glVertex3f(-50.0, 37.0, -57.0); //kiri atas
    glEnd();



 glutSwapBuffers();
}

void idle(){
    if(!mouseDown){
        xrot += 0.3f;
        yrot += 0.4f;
    }
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        mouseDown = true;
        xdiff = x - yrot;
        ydiff = -y + xrot;
    }
    else
    mouseDown = false;
}

void mouseMotion(int x, int y){
    if(mouseDown){
        yrot = x - xdiff;
        xrot = y + ydiff;

        glutPostRedisplay();
    }
    glLoadIdentity();
    gluLookAt(0,0,3,0,0,0,0,1,0);
    glRotatef(xrot, 1, 0, 0);
    glRotatef(yrot, 0, 1, 0);
}



void keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w' :
    case 'W' :
        glTranslated(0.0, 0.0, 3.0); ///zoom in
        break;
    case 'd' :
    case 'D' :
        glTranslated(3.0, 0.0, 0.0);/// ke kanan
        break;
    case 's' :
    case 'S' :
        glTranslated(0.0, 0.0, -3.0); ///zome out
        break;
    case 'a' :
    case 'A' :
        glTranslated(-3.0, 0.0, 0.0);/// ke kiri
        break;
    case '1' :
        glTranslated(0.0, 3.0, 0.0);/// ke atas
        break;
    case '2' :
        glTranslated(0.0, -3.0, 0.0);/// ke bawah
        break;
    case '3' :
        glRotatef(2.0, 1.0, 0.0, 0.0);///rotasi ke bawah
        break;
    case '4' :
        glRotatef(-2.0, 1.0, 0.0, 0.0); ///rotasi ke atas
        break;
    case '5' :
        glRotatef(2.0, 0.0, 1.0, 0.0); /// rotasi ke kanan
        break;
    case '6' :
        glRotatef(-2.0, 0.0, 1.0, 0.0);/// rotasi ke kiri
        break;
    case '7' :
        glRotatef(2.0, 0.0, 0.0, 1.0);///rotasi kebalikan arah jam
        break;
    case '8' :
        glRotatef(-2.0, 0.0, 0.0, 1.0);/// rotasi sesuai arah jam
        break;
    case '9' : /// objeknya transparan
        if (is_depth)
        {

            is_depth = 0;
            glDisable(GL_DEPTH_TEST);
        }
        else
        {
            is_depth = 1;
            glEnable(GL_DEPTH_TEST);
        }
    }
    tampil();
}

int main (int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(1800, 700);
    glutInitWindowPosition(10, 10);
    glutCreateWindow("lapangan");
    init();
    glutDisplayFunc(tampil);
    glutKeyboardFunc(keyboard);
    glutReshapeFunc(ukuran);

    glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
    glutIdleFunc(tampil);
	glutMainLoop();
	return 0;
}
