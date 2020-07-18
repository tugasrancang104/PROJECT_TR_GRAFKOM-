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
    glColor3f(1,1,1);
    glVertex3f(11.0, -25.0, 57.0); //kiri bawah
    glVertex3f(11.0, -10.0, 57.0); //kanan bawah
    glVertex3f(11.0, -10.0, -67.0); //kanan atas
    glVertex3f(11.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -10.0, 57.0); //kanan bawah
    glVertex3f(24.0, -10.0, -67.0); //kanan atas
    glVertex3f(24.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -10.0, 57.0); //kanan bawah
    glVertex3f(11.0, -10.0, 57.0); //kanan atas
    glVertex3f(11.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(24.0, -25.0, -67.0); //kiri bawah
    glVertex3f(24.0, -10.0, -67.0); //kanan bawah
    glVertex3f(11.0, -10.0, -67.0); //kanan atas
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
    glVertex3f(24.0, -10.0, 57.0); //kiri bawah
    glVertex3f(11.0, -10.0, 57.0); //kanan bawah
    glVertex3f(11.0, -10.0, -67.0); //kanan atas
    glVertex3f(24.0, -10.0, -67.0); //kiri atas
    glEnd();

    ///bangku kiri

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -10.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -10.0, -67.0); //kiri atas
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
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan atas
    glVertex3f(-46.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-59.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-59.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -10.0, 57.0); //kanan atas
    glVertex3f(-59.0, -25.0, 57.0); //kiri atas
    glEnd();

     ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, -67.0); //kiri bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan bawah
    glVertex3f(-59.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, 47.0); //kiri bawah
    glVertex3f(10.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan atas
    glVertex3f(-45.0, -25.0, 47.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, 57.0); //kiri bawah
    glVertex3f(10.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -10.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(10.0, -10.0, 57.0); //kiri atas
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
    glVertex3f(10.0, -10.0, 47.0); //kanan bawah
    glVertex3f(10.0, -10.0, 57.0); //kanan atas
    glVertex3f(10.0, -25.0, 57.0); //kiri atas
    glEnd();

     ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-45.0, -25.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku belakang

    // bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-45.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -10.0, -57.0); //kanan bawah
    glVertex3f(10.0, -10.0, -57.0); //kanan atas
    glVertex3f(10.0, -25.0, -57.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, -67.0); //kiri bawah
    glVertex3f(10.0, -10.0, -67.0); //kanan bawah
    glVertex3f(-45.0, -10.0, -67.0); //kanan atas
    glVertex3f(-45.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-45.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -10.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -10.0, -67.0); //kanan atas
    glVertex3f(-45.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(10.0, -25.0, -57.0); //kiri bawah
    glVertex3f(10.0, -10.0, -57.0); //kanan bawah
    glVertex3f(10.0, -10.0, -67.0); //kanan atas
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
    glVertex3f(10.0, -10.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -10.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -10.0, -67.0); //kanan atas
    glVertex3f(10.0, -10.0, -67.0); //kiri atas
    glEnd();

    ///bangku blkng 2
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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
    glColor3f(1,1,1);
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

    ///bangku kanan 3

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.0, -25.0, 77.0); //kiri bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(55.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
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
    glVertex3f(65.0, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(55.4, 18.0, 97.0); //kanan bawah
    glVertex3f(55.4, 18.0, -107.0); //kanan atas
    glVertex3f(55.4, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, 18.0, 97.0); //kiri bawah
    glVertex3f(65.0, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.4, 18.0, -107.0); //kiri atas
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
    glVertex3f(55.4, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, 97.0); //kanan atas
    glVertex3f(65.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.4, -25.0, -107.0); //kiri bawah
    glVertex3f(55.4, 18.0, -107.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku kiri 5
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, 18.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.5, 18.0, -107.0); //kiri atas
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
    glVertex3f(-90.5, 18.0, -107.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan atas
    glVertex3f(-100.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 18.0, 97.0); //kanan bawah
    glVertex3f(-90.5, 18.0, -107.0); //kanan atas
    glVertex3f(-90.5, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-100.0, -25.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku depan 5
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 97.0); //kiri bawah
    glVertex3f(55.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan atas
    glVertex3f(-90.0, -25.0, 88.4); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.0, -25.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 18.0, 88.4); //kanan bawah
    glVertex3f(55.0, 18.0, 97.0); //kanan atas
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
    glColor3f(0,0,0);
    glVertex3f(55.0, 18.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(55.0, 18.0, 97.0); //kiri atas
    glEnd();

    ///bangku belakang 5
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(55.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan atas
    glVertex3f(-90.0, -25.0, -98.4); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, -25.0, -107.0); //kiri bawah
    glVertex3f(55.0, 18.0, -107.0); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(55.0, 18.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.0, 18.0, -107.0); //kiri atas
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
    glVertex3f(55.0, 18.0, -98.4); //kanan bawah
    glVertex3f(55.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,0,0);
    glVertex3f(-90.0, -25.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku belakang 6
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 24.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 24.0, -107.4); //kanan atas
    glVertex3f(-100.0, -25.0, -107.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, -117.0); //kiri bawah
    glVertex3f(65.0, 24.0, -117.0); //kanan bawah
    glVertex3f(-100.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, 24.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 24.0, -107.4); //kanan bawah
    glVertex3f(65.0, 24.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, -25.0, -107.4); //kanan bawah
    glVertex3f(-100.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, 24.0, -107.4); //kiri bawah
    glVertex3f(-100.0, 24.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 24.0, -117.0); //kanan atas
    glVertex3f(65.0, 24.0, -117.0); //kiri atas
    glEnd();

    ///bangku depan 6
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(65.0, 24.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 24.0, 97.4); //kanan atas
    glVertex3f(-100.0, -25.0, 97.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, 107.0); //kiri bawah
    glVertex3f(65.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, 24.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(65.0, 24.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, -25.0, 97.4); //kanan bawah
    glVertex3f(-100.0, -25.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(65.0, 24.0, 97.4); //kanan bawah
    glVertex3f(65.0, 24.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    ///bangku kiri 6
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.5, 24.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.5, 24.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, -25.0, 107.0); //kanan bawah
    glVertex3f(-110.0, -25.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 24.0, 107.0); //kanan bawah
    glVertex3f(-100.5, 24.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.0, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan atas
    glVertex3f(-110.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-100.5, -25.0, -117.0); //kiri bawah
    glVertex3f(-100.5, 24.0, -117.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku kanan 6
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 24.0, 107.0); //kanan bawah
    glVertex3f(65.4, 24.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.4, -25.0, -117.0); //kiri bawah
    glVertex3f(65.4, 24.0, -117.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan atas
    glVertex3f(75.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.4, 24.0, 107.0); //kiri bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(65.4, 24.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, -25.0, 107.0); //kanan bawah
    glVertex3f(75.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku kanan 7
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(75.4, 32.0, 120.0); //kanan bawah
    glVertex3f(75.4, 32.0, -130.0); //kanan atas
    glVertex3f(75.4, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, 120.0); //kiri bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(85.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(85.0, -25.0, 120.0); //kanan bawah
    glVertex3f(85.0, -25.0, -130.0); //kanan atas
    glVertex3f(75.4, -25.0, -130.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.4, 32.0, 120.0); //kiri bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(75.4, 32.0, -130.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.4, -25.0, 120.0); //kiri bawah
    glVertex3f(75.4, 32.0, 120.0); //kanan bawah
    glVertex3f(85.0, 32.0, 120.0); //kanan atas
    glVertex3f(85.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.4, -25.0, -130.0); //kiri bawah
    glVertex3f(75.4, 32.0, -130.0); //kanan bawah
    glVertex3f(85.0, 32.0, -130.0); //kanan atas
    glVertex3f(85.0, -25.0, -130.0); //kiri atas
    glEnd();

    ///bangku kiri 7
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.4, 32.0, 120.0); //kiri bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.4, 32.0, -130.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-120.0, -25.0, 120.0); //kanan bawah
    glVertex3f(-120.0, -25.0, -130.0); //kanan atas
    glVertex3f(-110.4, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.4, -25.0, -130.0); //kiri bawah
    glVertex3f(-110.4, 32.0, -130.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-120.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-110.4, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan atas
    glVertex3f(-120.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.4, -25.0, 120.0); //kiri bawah
    glVertex3f(-110.4, 32.0, 120.0); //kanan bawah
    glVertex3f(-110.4, 32.0, -130.0); //kanan atas
    glVertex3f(-110.4, -25.0, -130.0); //kiri atas
    glEnd();


    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.0, -25.0, 120.0); //kiri bawah
    glVertex3f(-120.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-120.0, 32.0, -130.0); //kanan atas
    glVertex3f(-120.0, -25.0, -130.0); //kiri atas
    glEnd();

    ///bangku depan 7
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(75.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan atas
    glVertex3f(-110.0, -25.0, 108.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, 120.0); //kiri bawah
    glVertex3f(75.0, 32.0, 120.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(-110.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.0, -25.0, 108.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(-110.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(75.0, 32.0, 108.0); //kanan bawah
    glVertex3f(75.0, 32.0, 120.0); //kanan atas
    glVertex3f(75.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, 108.0); //kiri bawah
    glVertex3f(-110.0, -25.0, 108.0); //kanan bawah
    glVertex3f(-110.0, -25.0, 120.0); //kanan atas
    glVertex3f(75.0, -25.0, 120.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, 32.0, 108.0); //kiri bawah
    glVertex3f(-110.0, 32.0, 108.0); //kanan bawah
    glVertex3f(-110.0, 32.0, 120.0); //kanan atas
    glVertex3f(75.0, 32.0, 120.0); //kiri atas
    glEnd();

    ///bangku belakang 7
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(75.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan atas
    glVertex3f(-110.0, -25.0, -118.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, -130.0); //kiri bawah
    glVertex3f(75.0, 32.0, -130.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.0, -25.0, -130.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, 32.0, -118.0); //kiri bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(75.0, 32.0, -130.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(-110.0, -25.0, -118.0); //kanan bawah
    glVertex3f(-110.0, -25.0, -130.0); //kanan atas
    glVertex3f(75.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(75.0, -25.0, -118.0); //kiri bawah
    glVertex3f(75.0, 32.0, -118.0); //kanan bawah
    glVertex3f(75.0, 32.0, -130.0); //kanan atas
    glVertex3f(75.0, -25.0, -130.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-110.0, -25.0, -118.0); //kiri bawah
    glVertex3f(-110.0, 32.0, -118.0); //kanan bawah
    glVertex3f(-110.0, 32.0, -130.0); //kanan atas
    glVertex3f(-110.0, -25.0, -130.0); //kiri atas
    glEnd();

    ///bangku belakang 8
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, -131.0); //kiri bawah
    glVertex3f(85.0, 38.0, -131.0); //kanan bawah
    glVertex3f(-120.0, 38.0, -131.0); //kanan atas
    glVertex3f(-120.0, -25.0, -131.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, -140.0); //kiri bawah
    glVertex3f(85.0, 38.0, -140.0); //kanan bawah
    glVertex3f(-120.0, 38.0, -140.0); //kanan atas
    glVertex3f(-120.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.0, -25.0, -131.0); //kiri bawah
    glVertex3f(-120.0, 38.0, -131.0); //kanan bawah
    glVertex3f(-120.0, 38.0, -140.0); //kanan atas
    glVertex3f(-120.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, -131.0); //kiri bawah
    glVertex3f(85.0, 38.0, -131.0); //kanan bawah
    glVertex3f(85.0, 38.0, -140.0); //kanan atas
    glVertex3f(85.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, -131.0); //kiri bawah
    glVertex3f(-120.0, -25.0, -131.0); //kanan bawah
    glVertex3f(-120.0, -25.0, -140.0); //kanan atas
    glVertex3f(85.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, 38.0, -131.0); //kiri bawah
    glVertex3f(-120.0, 38.0, -131.0); //kanan bawah
    glVertex3f(-120.0, 38.0, -140.0); //kanan atas
    glVertex3f(85.0, 38.0, -140.0); //kiri atas
    glEnd();

    ///bangku depan 8
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, 121.0); //kiri bawah
    glVertex3f(85.0, 38.0, 121.0); //kanan bawah
    glVertex3f(-120.0, 38.0, 121.0); //kanan atas
    glVertex3f(-120.0, -25.0, 121.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, 130.0); //kiri bawah
    glVertex3f(85.0, 38.0, 130.0); //kanan bawah
    glVertex3f(-120.0, 38.0, 130.0); //kanan atas
    glVertex3f(-120.0, -25.0, 130.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, 38.0, 121.0); //kiri bawah
    glVertex3f(-120.0, 38.0, 121.0); //kanan bawah
    glVertex3f(-120.0, 38.0, 130.0); //kanan atas
    glVertex3f(85.0, 38.0, 130.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, 121.0); //kiri bawah
    glVertex3f(-120.0, -25.0, 121.0); //kanan bawah
    glVertex3f(-120.0, -25.0, 130.0); //kanan atas
    glVertex3f(85.0, -25.0, 130.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.0, -25.0, 121.0); //kiri bawah
    glVertex3f(85.0, 38.0, 121.0); //kanan bawah
    glVertex3f(85.0, 38.0, 130.0); //kanan atas
    glVertex3f(85.0, -25.0, 130.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.0, -25.0, 121.0); //kiri bawah
    glVertex3f(-120.0, 38.0, 121.0); //kanan bawah
    glVertex3f(-120.0, 38.0, 130.0); //kanan atas
    glVertex3f(-120.0, -25.0, 130.0); //kiri atas
    glEnd();

    ///bangku kiri 8
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.4, 38.0, 130.0); //kiri bawah
    glVertex3f(-130.0, 38.0, 130.0); //kanan bawah
    glVertex3f(-130.0, 38.0, -140.0); //kanan atas
    glVertex3f(-120.4, 38.0, -140.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.4, -25.0, 130.0); //kiri bawah
    glVertex3f(-130.0, -25.0, 130.0); //kanan bawah
    glVertex3f(-130.0, -25.0, -140.0); //kanan atas
    glVertex3f(-120.4, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-130.0, -25.0, 130.0); //kiri bawah
    glVertex3f(-130.0, 38.0, 130.0); //kanan bawah
    glVertex3f(-130.0, 38.0, -140.0); //kanan atas
    glVertex3f(-130.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.4, -25.0, 130.0); //kiri bawah
    glVertex3f(-120.4, 38.0, 130.0); //kanan bawah
    glVertex3f(-120.4, 38.0, -140.0); //kanan atas
    glVertex3f(-120.4, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.4, -25.0, 130.0); //kiri bawah
    glVertex3f(-120.4, 38.0, 130.0); //kanan bawah
    glVertex3f(-130.0, 38.0, 130.0); //kanan atas
    glVertex3f(-130.0, -25.0, 130.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-120.4, -25.0, -140.0); //kiri bawah
    glVertex3f(-120.4, 38.0, -140.0); //kanan bawah
    glVertex3f(-130.0, 38.0, -140.0); //kanan atas
    glVertex3f(-130.0, -25.0, -140.0); //kiri atas
    glEnd();

    ///bangku kanan 8
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.4, -25.0, 130.0); //kiri bawah
    glVertex3f(85.4, 38.0, 130.0); //kanan bawah
    glVertex3f(85.4, 38.0, -140.0); //kanan atas
    glVertex3f(85.4, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(95.0, -25.0, 130.0); //kiri bawah
    glVertex3f(95.0, 38.0, 130.0); //kanan bawah
    glVertex3f(95.0, 38.0, -140.0); //kanan atas
    glVertex3f(95.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.4, -25.0, -140.0); //kiri bawah
    glVertex3f(85.4, 38.0, -140.0); //kanan bawah
    glVertex3f(95.0, 38.0, -140.0); //kanan atas
    glVertex3f(95.0, -25.0, -140.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.4, -25.0, 130.0); //kiri bawah
    glVertex3f(85.4, 38.0, 130.0); //kanan bawah
    glVertex3f(95.0, 38.0, 130.0); //kanan atas
    glVertex3f(95.0, -25.0, 130.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.4, -25.0, 130.0); //kiri bawah
    glVertex3f(95.0, -25.0, 130.0); //kanan bawah
    glVertex3f(95.0, -25.0, -140.0); //kanan atas
    glVertex3f(85.4, -25.0, -140.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(85.4, 38.0, 130.0); //kiri bawah
    glVertex3f(95.0, 38.0, 130.0); //kanan bawah
    glVertex3f(95.0, 38.0, -140.0); //kanan atas
    glVertex3f(85.4, 38.0, -140.0); //kiri atas
    glEnd();



    ///bangkubiru

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-56,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-46,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-36,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-26,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-16,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-6,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(4,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(14,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(24,-1,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();



glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,53.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,43.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,33.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,23.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,13.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,3.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-7.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-17.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-27.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-37.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-47.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-57.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,-1,-67.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,53.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,43.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,33.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,23.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,13.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,3.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-7.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-17.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-27.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-37.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-47.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-57.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-66,-1,-67.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-56,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-46,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-36,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-26,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-16,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-6,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(4,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(14,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(24,-1,-71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

//kursi biru tingkat2

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(37,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(27,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(17,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(7,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-3,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


   glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-13,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-23,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-33,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-43,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-53,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-63,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-73,6.2,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-72.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-62.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-52.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-42.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-32.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-22.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-12.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,-2.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,8.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,18.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,28.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,38.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,48.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,58.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,6.2,68.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(20,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(10,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-10,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-20,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-30,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-40,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-50,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-60,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-70,6.2,73.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,63.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,53.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,43.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,33.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,23.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,13.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,3.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-7.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-17.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-27.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-37.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-47.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-57.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,6.2,-69.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    //bangku lantai 3

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-65,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-55,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-45,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-35,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-25,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-15,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-5,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(5,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(15,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(25,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(35,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(45,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-79.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-69.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-59.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-49.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-39.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-29.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-19.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,-9.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,1.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,11.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,21.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,31.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,41.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,51.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,61.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(20,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(10,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-10,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-20,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-30,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-40,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-50,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-60,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-70,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-80,14.5,81.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,71.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,61.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,51.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,41.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,31.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,21.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,11.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,1.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-9.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-19.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-29.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-39.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-49.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-59.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-69.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-79.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,14.5,-89.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    ///bangku biru ke 4

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-103,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-93,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-83,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-73,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-63,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-53,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-43,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-33,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-23,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-13,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-3,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(7,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(17,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(27,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(37,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(47,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(57,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(67,26.4,-112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-92.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

     glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-72.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-62.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-52.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-42.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-32.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-22.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-12.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,-2.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,8.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,18.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,28.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,38.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,48.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,58.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,68.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,78.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,88.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(69.8,26.4,98.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(59.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(49.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(39.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(29.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(19.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(9.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-1.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-11.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-21.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-31.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-41.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-51.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-61.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-71.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-81.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-91.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-101.8,26.4,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,92.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,72.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,62.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,52.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,42.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,32.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,22.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,12.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,2.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-8.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-18.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-28.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-38.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-48.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-58.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-68.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-78.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-88.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105.4,26.4,-99.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

///bangku biru ke 5

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-113,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-103,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-93,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-83,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-73,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-63,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-53,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-43,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-33,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-23,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-13,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-3,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(7,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(17,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(27,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(37,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(47,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(57,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(67,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(77,34.0,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-114.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-104.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-94.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-84.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-74.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-64.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-54.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-44.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-34.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-24.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-14.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,-4.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,6.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,16.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,26.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,36.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,46.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,56.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,66.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,76.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,86.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,96.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,106.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(81,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(71,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(61,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(51,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(41,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(31,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(21,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(11,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(1,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-9,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-19,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-29,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-39,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-49,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-59,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-69,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-79,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-89,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-99,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-109,34.0,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,106.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,96.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,86.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,76.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,66.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,56.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,46.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,36.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,26.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,16.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,6.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-4.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-14.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-24.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-34.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-44.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-54.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-64.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-74.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-84.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-94.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-104.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,34.0,-114.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

///lantaike5

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-124.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-114.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-104.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-94.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-84.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-74.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-64.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-54.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-44.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-34.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-24.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-14.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,-4.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,6.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,16.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,26.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,36.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,46.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,56.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,66.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,76.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,86.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,96.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,106.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-125,40.8,116.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-115,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-105,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-95,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-85,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-75,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-65,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-55,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-45,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-35,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-25,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-15,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-5,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(5,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(15,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(25,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(35,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(45,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(55,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(65,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(75,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(85,40.8,122.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,112.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,102.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,92.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,82.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,72.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,62.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,52.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,42.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,32.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,22.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,12.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,2.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-8.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-18.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-28.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-38.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-48.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-58.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-68.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-78.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-88.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();


glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-98.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-108.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-118.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-128.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(90,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(80,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(70,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(60,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(50,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(40,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(30,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(20,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(10,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(0,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-10,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-20,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-30,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-40,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-50,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-60,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-70,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-80,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-90,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-100,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-110,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0,0,1);
    glTranslatef(-120,40.8,-134.5);
    glScalef(1,0.5,1);
    glutSolidCube(8);
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
 glTranslatef(-15,-24.5,-1.0);
 glColor3f(1.0,1.0,1.0);
 glutWireSphere(9,20,50);
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
	int x_tengaaahh = -15, y_tengaaahh = -38.1;
	for (i =10 ; i <= jumlah_titik + 0; i++) {
		float sudut = i * (2 * Pi / jumlah_titik);
		float x = x_tengaaahh + radiusss * cos(sudut);
		float y = y_tengaaahh + radiusss * sin(sudut);
		glVertex3f(x, -18.0, y);
	}
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
