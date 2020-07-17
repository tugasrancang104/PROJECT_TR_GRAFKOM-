#include <windows.h>
#ifdef APPLE
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>

void init(void);
void tampil(void);
void keyboard (unsigned char, int, int);
void ukuran (int, int);

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
    glEnable(GL_DEPTH_TEST);
    is_depth=1;
    glMatrixMode(GL_MODELVIEW);
    glPointSize(7.0);
    glLineWidth(6.0f);
}
void tampil(void)
{
    if (is_depth)
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    else
        glClear(GL_COLOR_BUFFER_BIT);

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
    glColor3f(1,0,0);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -10.0, 57.0); //kanan bawah
    glVertex3f(24.0, -10.0, -67.0); //kanan atas
    glVertex3f(24.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(24.0, -10.0, 57.0); //kanan bawah
    glVertex3f(11.0, -10.0, 57.0); //kanan atas
    glVertex3f(11.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(24.0, -25.0, -67.0); //kiri bawah
    glVertex3f(24.0, -10.0, -67.0); //kanan bawah
    glVertex3f(11.0, -10.0, -67.0); //kanan atas
    glVertex3f(11.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(24.0, -25.0, 57.0); //kiri bawah
    glVertex3f(11.0, -25.0, 57.0); //kanan bawah
    glVertex3f(11.0, -25.0, -67.0); //kanan atas
    glVertex3f(24.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(24.0, -10.0, 57.0); //kiri bawah
    glVertex3f(11.0, -10.0, 57.0); //kanan bawah
    glVertex3f(11.0, -10.0, -67.0); //kanan atas
    glVertex3f(24.0, -10.0, -67.0); //kiri atas
    glEnd();

    ///bangku kiri

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(-59.0, -10.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -10.0, -67.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(-59.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -25.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -25.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-46.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan atas
    glVertex3f(-46.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-59.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-59.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(-46.0, -25.0, 57.0); //kiri bawah
    glVertex3f(-46.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-59.0, -10.0, 57.0); //kanan atas
    glVertex3f(-59.0, -25.0, 57.0); //kiri atas
    glEnd();

     //bangku blkng
     glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(-46.0, -25.0, -67.0); //kiri bawah
    glVertex3f(-46.0, -10.0, -67.0); //kanan bawah
    glVertex3f(-59.0, -10.0, -67.0); //kanan atas
    glVertex3f(-59.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///bangku depan

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(10.0, -25.0, 47.0); //kiri bawah
    glVertex3f(10.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan atas
    glVertex3f(-45.0, -25.0, 47.0); //kiri atas
    glEnd();

    ///bangku blkng
     glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(10.0, -25.0, 57.0); //kiri bawah
    glVertex3f(10.0, -10.0, 57.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(10.0, -10.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(10.0, -10.0, 57.0); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,0,0);
    glVertex3f(-45.0, -25.0, 47.0); //kiri bawah
    glVertex3f(-45.0, -10.0, 47.0); //kanan bawah
    glVertex3f(-45.0, -10.0, 57.0); //kanan atas
    glVertex3f(-45.0, -25.0, 57.0); //kiri atas
    glEnd();

    ///bangku belakang

    // bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,0,0.5);
    glVertex3f(-45.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -10.0, -57.0); //kanan bawah
    glVertex3f(10.0, -10.0, -57.0); //kanan atas
    glVertex3f(10.0, -25.0, -57.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(10.0, -25.0, -67.0); //kiri bawah
    glVertex3f(10.0, -10.0, -67.0); //kanan bawah
    glVertex3f(-45.0, -10.0, -67.0); //kanan atas
    glVertex3f(-45.0, -25.0, -67.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
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
    glColor3f(1,0,0.5);
    glVertex3f(10.0, -25.0, -57.0); //kiri bawah
    glVertex3f(-45.0, -25.0, -57.0); //kanan bawah
    glVertex3f(-45.0, -25.0, -67.0); //kanan atas
    glVertex3f(10.0, -25.0, -67.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,0.5,0);
    glVertex3f(24.0, -25.0, -77.2); //kiri bawah
    glVertex3f(24.0, -4.0, -77.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,0,1);
    glVertex3f(-59.0, -25.0, -67.2); //kiri bawah
    glVertex3f(-59.0, -4.0, -67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,1,0);
    glVertex3f(24.0, -25.0, 67.2); //kiri bawah
    glVertex3f(24.0, -4.0, 67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

     //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-59.0, -25.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -4.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(24.0, -25.0, 57.2); //kiri bawah
    glVertex3f(24.0, -4.0, 57.2); //kanan bawah
    glVertex3f(24.0, -4.0, 67.2); //kanan atas
    glVertex3f(24.0, -25.0, 67.2); //kiri atas
    glEnd();

    ///bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(24.0, -25.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -25.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -25.0, 67.2); //kanan atas
    glVertex3f(24.0, -25.0, 67.2); //kiri atas
    glEnd();

     ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(24.0, -4.0, 57.2); //kiri bawah
    glVertex3f(-59.0, -4.0, 57.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(24.0, -4.0, 67.2); //kiri atas
    glEnd();

    ///bangku kiri 2

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(-59.2, -4.0, 67.2); //kiri bawah
    glVertex3f(-70.2, -4.0, 67.2); //kanan bawah
    glVertex3f(-70.2, -4.0, -77.2); //kanan atas
    glVertex3f(-59.2, -4.0, -77.2); //kiri atas
    glEnd();

     ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
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
    glColor3f(0,1,0.7);
    glVertex3f(-70.2, -25.0, 67.2); //kiri bawah
    glVertex3f(-70.2, -4.0, 67.2); //kanan bawah
    glVertex3f(-70.2, -4.0, -77.2); //kanan atas
    glVertex3f(-70.2, -25.0, -77.2); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-70.0, -25.0, -77.2); //kiri bawah
    glVertex3f(-70.0, -4.0, -77.2); //kanan bawah
    glVertex3f(-59.0, -4.0, -77.2); //kanan atas
    glVertex3f(-59.0, -25.0, -77.2); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-70.0, -25.0, 67.2); //kiri bawah
    glVertex3f(-70.0, -4.0, 67.2); //kanan bawah
    glVertex3f(-59.0, -4.0, 67.2); //kanan atas
    glVertex3f(-59.0, -25.0, 67.2); //kiri atas
    glEnd();

    ///bangku kanan 2

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex3f(24.2, -25.0, 67.0); //kiri bawah
    glVertex3f(24.2, -4.0, 67.0); //kanan bawah
    glVertex3f(24.2, -4.0, -77.0); //kanan atas
    glVertex3f(24.2, -25.0, -77.0); //kiri atas
    glEnd();

     ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0.5,0);
    glVertex3f(35.2, -25.0, 67.0); //kiri bawah
    glVertex3f(35.2, -4.0, 67.0); //kanan bawah
    glVertex3f(35.2, -4.0, -77.0); //kanan atas
    glVertex3f(35.2, -25.0, -77.0); //kiri atas
    glEnd();

     //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(35.2, -25.0, 67.0); //kiri bawah
    glVertex3f(35.2, -4.0, 67.0); //kanan bawah
    glVertex3f(24.2, -4.0, 67.0); //kanan atas
    glVertex3f(24.2, -25.0, 67.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(35.2, -25.0, -77.0); //kiri bawah
    glVertex3f(35.2, -4.0, -77.0); //kanan bawah
    glVertex3f(24.2, -4.0, -77.0); //kanan atas
    glVertex3f(24.2, -25.0, -77.0); //kiri atas
    glEnd();

    ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(24.2, -25.0, 67.2); //kiri bawah
    glVertex3f(35.2, -25.0, 67.2); //kanan bawah
    glVertex3f(35.2, -25.0, -77.2); //kanan atas
    glVertex3f(24.2, -25.0, -77.2); //kiri atas
    glEnd();

    ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(24.2, -4.0, 67.2); //kiri bawah
    glVertex3f(35.2, -4.0, 67.2); //kanan bawah
    glVertex3f(35.2, -4.0, -77.2); //kanan atas
    glVertex3f(24.2, -4.0, -77.2); //kiri atas
    glEnd();

    ///bangku kanan 3

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex3f(35.4, -25.0, 77.0); //kiri bawah
    glVertex3f(35.4, 4.0, 77.0); //kanan bawah
    glVertex3f(35.4, 4.0, -87.0); //kanan atas
    glVertex3f(35.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(45.4, -25.0, 77.0); //kiri bawah
    glVertex3f(45.4, 4.0, 77.0); //kanan bawah
    glVertex3f(45.4, 4.0, -87.0); //kanan atas
    glVertex3f(45.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(35.4, 4.0, 77.2); //kiri bawah
    glVertex3f(45.4, 4.0, 77.2); //kanan bawah
    glVertex3f(45.4, 4.0, -87.2); //kanan atas
    glVertex3f(35.4, 4.0, -87.2); //kiri atas
    glEnd();

     ///bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(35.4, -25.0, 77.2); //kiri bawah
    glVertex3f(45.4, -25.0, 77.2); //kanan bawah
    glVertex3f(45.4, -25.0, -87.2); //kanan atas
    glVertex3f(35.4, -25.0, -87.2); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(45.4, -25.0, 77.0); //kiri bawah
    glVertex3f(45.4, 4.0, 77.0); //kanan bawah
    glVertex3f(35.4, 4.0, 77.0); //kanan atas
    glVertex3f(35.4, -25.0, 77.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(45.4, -25.0, -87.0); //kiri bawah
    glVertex3f(45.4, 4.0, -87.0); //kanan bawah
    glVertex3f(35.4, 4.0, -87.0); //kanan atas
    glVertex3f(35.4, -25.0, -87.0); //kiri atas
    glEnd();

    ///bangku kiri 3
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-70.4, 4.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, 4.0, -87.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-70.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, -25.0, 77.4); //kanan bawah
    glVertex3f(-80.4, -25.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-80.4, -25.0, -87.4); //kiri bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan bawah
    glVertex3f(-70.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0.5,0,0);
    glVertex3f(-80.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-70.4, 4.0, 77.4); //kanan atas
    glVertex3f(-70.4, -25.0, 77.4); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
    glVertex3f(-70.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-70.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-70.4, 4.0, -87.4); //kanan atas
    glVertex3f(-70.4, -25.0, -87.4); //kiri atas
    glEnd();

    ///bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(-80.4, -25.0, 77.4); //kiri bawah
    glVertex3f(-80.4, 4.0, 77.4); //kanan bawah
    glVertex3f(-80.4, 4.0, -87.4); //kanan atas
    glVertex3f(-80.4, -25.0, -87.4); //kiri atas
    glEnd();

    ///bangku depan 3
    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,1,0.5);
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
    glColor3f(1,0,0.5);
    glVertex3f(-70.0, -25.0, 67.4); //kiri bawah
    glVertex3f(-70.0, 4.0, 67.4); //kanan bawah
    glVertex3f(-70.0, 4.0, 77.4); //kanan atas
    glVertex3f(-70.0, -25.0, 77.4); //kiri atas
    glEnd();

    ///bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(35.0, -25.0, 67.4); //kiri bawah
    glVertex3f(35.0, 4.0, 67.4); //kanan bawah
    glVertex3f(35.0, 4.0, 77.4); //kanan atas
    glVertex3f(35.0, -25.0, 77.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(35.0, -25.0, 67.4); //kiri bawah
    glVertex3f(-70.0, -25.0, 67.4); //kanan bawah
    glVertex3f(-70.0, -25.0, 77.4); //kanan atas
    glVertex3f(35.0, -25.0, 77.4); //kiri atas
    glEnd();

     //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
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
    glColor3f(0,1,0.5);
    glVertex3f(35.0, -25.0, -87.4); //kiri bawah
    glVertex3f(35.0, 4.0, -87.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(-70.0, -25.0, -87.4); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(35.0, 4.0, -77.4); //kiri bawah
    glVertex3f(-70.0, 4.0, -77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(35.0, 4.0, -87.4); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(35.0, -25.0, -77.4); //kiri bawah
    glVertex3f(-70.0, -25.0, -77.4); //kanan bawah
    glVertex3f(-70.0, -25.0, -87.4); //kanan atas
    glVertex3f(35.0, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
    glVertex3f(-70.0, -25.0, -77.4); //kiri bawah
    glVertex3f(-70.0, 4.0, -77.4); //kanan bawah
    glVertex3f(-70.0, 4.0, -87.4); //kanan atas
    glVertex3f(-70.0, -25.0, -87.4); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,0,0.5);
    glVertex3f(55.0, -25.0, -98.0); //kiri bawah
    glVertex3f(55.0, 12.0, -98.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(-90.0, -25.0, -98.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(55.0, -25.0, -88.0); //kiri bawah
    glVertex3f(5.0, 12.0, -88.0); //kanan bawah
    glVertex3f(55.0, 12.0, -98.0); //kanan atas
    glVertex3f(55.0, -25.0, -98.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-90.0, -25.0, -88.0); //kiri bawah
    glVertex3f(-90.0, 12.0, -88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(-90.0, -25.0, -98.0); //kiri atas
    glEnd();

     //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(5.0, -25.0, -88.0); //kiri bawah
    glVertex3f(-90.0, -25.0, -88.0); //kanan bawah
    glVertex3f(-90.0, -25.0, -98.0); //kanan atas
    glVertex3f(55.0, -25.0, -98.0); //kiri atas
    glEnd();

     //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, 12.0, -88.0); //kiri bawah
    glVertex3f(-90.0, 12.0, -88.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -98.0); //kanan atas
    glVertex3f(55.0, 12.0, -98.0); //kiri atas
    glEnd();

    ///bangku depan 4
    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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
    glColor3f(1,1,0);
    glVertex3f(55.0, 12.0, 78.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 78.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 88.0); //kanan atas
    glVertex3f(55.0, 12.0, 88.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, -25.0, 78.0); //kiri bawah
    glVertex3f(-90.0, -25.0, 78.0); //kanan bawah
    glVertex3f(-90.0, -25.0, 88.0); //kanan atas
    glVertex3f(55.0, -25.0, 88.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-90.0, -25.0, 78.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 78.0); //kanan bawah
    glVertex3f(-90.0, 12.0, 88.0); //kanan atas
    glVertex3f(-90.0, -25.0, 88.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(55.0, -25.0, 78.0); //kiri bawah
    glVertex3f(55.0, 12.0, 78.0); //kanan bawah
    glVertex3f(55.0, 12.0, 88.0); //kanan atas
    glVertex3f(55.0, -25.0, 88.0); //kiri atas
    glEnd();

    ///bangku kiri 4
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-80.5, 12.0, 77.0); //kiri bawah
    glVertex3f(-90.0, 12.0, 77.0); //kanan bawah
    glVertex3f(-90.0, 12.0, -87.0); //kanan atas
    glVertex3f(-80.5, 12.0, -87.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-80.5, -25.0, 77.0); //kiri bawah
    glVertex3f(-90.0, -25.0, 77.0); //kanan bawah
    glVertex3f(-90.0, -25.0, -87.0); //kanan atas
    glVertex3f(-80.5, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(-80.5, -25.0, 77.0); //kiri bawah
    glVertex3f(-80.5, 12.0, 77.0); //kanan bawah
    glVertex3f(-80.5, 12.0, -87.0); //kanan atas
    glVertex3f(-80.5, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,0.5);
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

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex3f(55.0, -25.0, 77.0); //kiri bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(55.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,1);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(46.0, 12.0, 77.0); //kanan bawah
    glVertex3f(46.0, 12.0, -87.0); //kanan atas
    glVertex3f(46.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(46.0, -25.0, -87.0); //kiri bawah
    glVertex3f(46.0, 12.0, -87.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(55.0, -25.0, -87.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(46.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan atas
    glVertex3f(55.0, -25.0, 77.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(46.0, -25.0, 77.0); //kiri bawah
    glVertex3f(55.0, -25.0, 77.0); //kanan bawah
    glVertex3f(55.0, -25.0, -87.0); //kanan atas
    glVertex3f(46.0, -25.0, -87.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(46.0, 12.0, 77.0); //kiri bawah
    glVertex3f(55.0, 12.0, 77.0); //kanan bawah
    glVertex3f(55.0, 12.0, -87.0); //kanan atas
    glVertex3f(46.0, 12.0, -87.0); //kiri atas
    glEnd();

    ///bangku kanan 5
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(65.0, -25.0, 97.0); //kiri bawah
    glVertex3f(65.0, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(55.4, 18.0, 97.0); //kanan bawah
    glVertex3f(55.4, 18.0, -107.0); //kanan atas
    glVertex3f(55.4, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.4, 18.0, 97.0); //kiri bawah
    glVertex3f(65.0, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.4, 18.0, -107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(65.0, -25.0, 97.0); //kanan bawah
    glVertex3f(65.0, -25.0, -107.0); //kanan atas
    glVertex3f(55.4, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku bkng
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(55.4, -25.0, 97.0); //kiri bawah
    glVertex3f(55.4, 18.0, 97.0); //kanan bawah
    glVertex3f(65.0, 18.0, 97.0); //kanan atas
    glVertex3f(65.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(55.4, -25.0, -107.0); //kiri bawah
    glVertex3f(55.4, 18.0, -107.0); //kanan bawah
    glVertex3f(65.0, 18.0, -107.0); //kanan atas
    glVertex3f(65.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku kiri 5
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-90.5, 18.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.5, 18.0, -107.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-100.0, -25.0, 97.0); //kanan bawah
    glVertex3f(-100.0, -25.0, -107.0); //kanan atas
    glVertex3f(-90.5, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-90.5, -25.0, -107.0); //kiri bawah
    glVertex3f(-90.5, 18.0, -107.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan atas
    glVertex3f(-100.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,1,1);
    glVertex3f(-90.5, -25.0, 97.0); //kiri bawah
    glVertex3f(-90.5, 18.0, 97.0); //kanan bawah
    glVertex3f(-90.5, 18.0, -107.0); //kanan atas
    glVertex3f(-90.5, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-100.0, -25.0, 97.0); //kiri bawah
    glVertex3f(-100.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-100.0, 18.0, -107.0); //kanan atas
    glVertex3f(-100.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku depan 5
    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(55.0, -25.0, 97.0); //kiri bawah
    glVertex3f(55.0, 18.0, 97.0); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan atas
    glVertex3f(-90.0, -25.0, 88.4); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-90.0, -25.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(-90.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(55.0, 18.0, 88.4); //kanan bawah
    glVertex3f(55.0, 18.0, 97.0); //kanan atas
    glVertex3f(55.0, -25.0, 97.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, -25.0, 88.4); //kiri bawah
    glVertex3f(-90.0, -25.0, 88.4); //kanan bawah
    glVertex3f(-90.0, -25.0, 97.0); //kanan atas
    glVertex3f(55.0, -25.0, 97.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, 18.0, 88.4); //kiri bawah
    glVertex3f(-90.0, 18.0, 88.4); //kanan bawah
    glVertex3f(-90.0, 18.0, 97.0); //kanan atas
    glVertex3f(55.0, 18.0, 97.0); //kiri atas
    glEnd();

    ///bangku belakang 5
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(55.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan atas
    glVertex3f(-90.0, -25.0, -98.4); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(55.0, -25.0, -107.0); //kiri bawah
    glVertex3f(55.0, 18.0, -107.0); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, 18.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.0, 18.0, -107.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(-90.0, -25.0, -98.4); //kanan bawah
    glVertex3f(-90.0, -25.0, -107.0); //kanan atas
    glVertex3f(55.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(55.0, -25.0, -98.4); //kiri bawah
    glVertex3f(55.0, 18.0, -98.4); //kanan bawah
    glVertex3f(55.0, 18.0, -107.0); //kanan atas
    glVertex3f(55.0, -25.0, -107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-90.0, -25.0, -98.4); //kiri bawah
    glVertex3f(-90.0, 18.0, -98.4); //kanan bawah
    glVertex3f(-90.0, 18.0, -107.0); //kanan atas
    glVertex3f(-90.0, -25.0, -107.0); //kiri atas
    glEnd();

    ///bangku belakang 6
    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,0,0);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 24.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 24.0, -107.4); //kanan atas
    glVertex3f(-100.0, -25.0, -107.4); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(65.0, -25.0, -117.0); //kiri bawah
    glVertex3f(65.0, 24.0, -117.0); //kanan bawah
    glVertex3f(-100.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-100.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, 24.0, -107.4); //kanan bawah
    glVertex3f(-100.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(65.0, 24.0, -107.4); //kanan bawah
    glVertex3f(65.0, 24.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bawah bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(65.0, -25.0, -107.4); //kiri bawah
    glVertex3f(-100.0, -25.0, -107.4); //kanan bawah
    glVertex3f(-100.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.0, -25.0, -117.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
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
    glColor3f(1,0,1);
    glVertex3f(65.0, -25.0, 107.0); //kiri bawah
    glVertex3f(65.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(65.0, 24.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(65.0, 24.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, -25.0, 97.4); //kanan bawah
    glVertex3f(-100.0, -25.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(65.0, -25.0, 97.4); //kiri bawah
    glVertex3f(65.0, 24.0, 97.4); //kanan bawah
    glVertex3f(65.0, 24.0, 107.0); //kanan atas
    glVertex3f(65.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-100.0, -25.0, 97.4); //kiri bawah
    glVertex3f(-100.0, 24.0, 97.4); //kanan bawah
    glVertex3f(-100.0, 24.0, 107.0); //kanan atas
    glVertex3f(-100.0, -25.0, 107.0); //kiri atas
    glEnd();

    ///bangku kiri 6
    //atas bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-100.5, 24.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-100.5, 24.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, -25.0, 107.0); //kanan bawah
    glVertex3f(-110.0, -25.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 24.0, 107.0); //kanan bawah
    glVertex3f(-100.5, 24.0, -117.0); //kanan atas
    glVertex3f(-100.5, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-110.0, -25.0, 107.0); //kiri bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku depan
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-100.5, -25.0, 107.0); //kiri bawah
    glVertex3f(-100.5, 24.0, 107.0); //kanan bawah
    glVertex3f(-110.0, 24.0, 107.0); //kanan atas
    glVertex3f(-110.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(-100.5, -25.0, -117.0); //kiri bawah
    glVertex3f(-100.5, 24.0, -117.0); //kanan bawah
    glVertex3f(-110.0, 24.0, -117.0); //kanan atas
    glVertex3f(-110.0, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku kanan 6
    //bangku kiri
    glBegin(GL_QUADS);
    glColor3f(0,1,0);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 24.0, 107.0); //kanan bawah
    glVertex3f(65.4, 24.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku kanan
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(75.0, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku blkng
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(65.4, -25.0, -117.0); //kiri bawah
    glVertex3f(65.4, 24.0, -117.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(75.0, -25.0, -117.0); //kiri atas
    glEnd();

    //bangku dpn
    glBegin(GL_QUADS);
    glColor3f(1,0,1);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(65.4, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan atas
    glVertex3f(75.0, -25.0, 107.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(65.4, 24.0, 107.0); //kiri bawah
    glVertex3f(75.0, 24.0, 107.0); //kanan bawah
    glVertex3f(75.0, 24.0, -117.0); //kanan atas
    glVertex3f(65.4, 24.0, -117.0); //kiri atas
    glEnd();

    //bwh bangku
    glBegin(GL_QUADS);
    glColor3f(1,1,0);
    glVertex3f(65.4, -25.0, 107.0); //kiri bawah
    glVertex3f(75.0, -25.0, 107.0); //kanan bawah
    glVertex3f(75.0, -25.0, -117.0); //kanan atas
    glVertex3f(65.4, -25.0, -117.0); //kiri atas
    glEnd();

    ///bangku biru

    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 60.9);
    glVertex3f(28.0, 10.0, 60.9);
    glVertex3f(28.0, -4.0, 60.9);
    glVertex3f(32.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 37.9);
    glVertex3f(28.0, 10.0, 37.9);
    glVertex3f(28.0, -4.0, 37.9);
    glVertex3f(32.0, -4.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 37.9);
    glVertex3f(32.0, 10.0, 60.9);
    glVertex3f(32.0, -4.0, 60.9);
    glVertex3f(32.0, -4.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(28.0, 10.0, 37.9);
    glVertex3f(28.0, 10.0, 60.9);
    glVertex3f(28.0, -4.0, 60.9);
    glVertex3f(28.0, -4.0, 37.9);
    glEnd();


    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 2.9);
    glVertex3f(28.0, 10.0, 2.9);
    glVertex3f(28.0, -4.0, 2.9);
    glVertex3f(32.0, -4.0, 2.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 27.9);
    glVertex3f(28.0, 10.0, 27.9);
    glVertex3f(28.0, -4.0, 27.9);
    glVertex3f(32.0, -4.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, 27.9);
    glVertex3f(32.0, 10.0, 2.9);
    glVertex3f(32.0, -4.0, 2.9);
    glVertex3f(32.0, -4.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(28.0, 10.0, 27.9);
    glVertex3f(28.0, 10.0, 2.9);
    glVertex3f(28.0, -4.0, 2.9);
    glVertex3f(28.0, -4.0, 27.9);
    glEnd();


    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -32.9);
    glVertex3f(28.0, 10.0, -32.9);
    glVertex3f(28.0, -4.0, -32.9);
    glVertex3f(32.0, -4.0, -32.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -7.9);
    glVertex3f(28.0, 10.0, -7.9);
    glVertex3f(28.0, -4.0, -7.9);
    glVertex3f(32.0, -4.0, -7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -7.9);
    glVertex3f(32.0, 10.0, -32.9);
    glVertex3f(32.0, -4.0, -32.9);
    glVertex3f(32.0, -4.0, -7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(28.0, 10.0, -7.9);
    glVertex3f(28.0, 10.0, -32.9);
    glVertex3f(28.0, -4.0, -32.9);
    glVertex3f(28.0, -4.0, -7.9);
    glEnd();

//bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -72.9);
    glVertex3f(28.0, 10.0, -72.9);
    glVertex3f(28.0, -4.0, -72.9);
    glVertex3f(32.0, -4.0, -72.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -47.9);
    glVertex3f(28.0, 10.0, -47.9);
    glVertex3f(28.0, -4.0, -47.9);
    glVertex3f(32.0, -4.0, -47.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(32.0, 10.0, -47.9);
    glVertex3f(32.0, 10.0, -72.9);
    glVertex3f(32.0, -4.0, -72.9);
    glVertex3f(32.0, -4.0, -47.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(28.0, 10.0, -47.9);
    glVertex3f(28.0, 10.0, -72.9);
    glVertex3f(28.0, -4.0, -72.9);
    glVertex3f(28.0, -4.0, -47.9);
    glEnd();




    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -72.9);
    glVertex3f(-63.0, 10.0, -72.9);
    glVertex3f(-63.0, -4.0, -72.9);
    glVertex3f(-67.0, -4.0, -72.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -47.9);
    glVertex3f(-63.0, 10.0, -47.9);
    glVertex3f(-63.0, -4.0, -47.9);
    glVertex3f(-67.0, -4.0, -47.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -47.9);
    glVertex3f(-67.0, 10.0, -72.9);
    glVertex3f(-67.0, -4.0, -72.9);
    glVertex3f(-67.0, -4.0, -47.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-63.0, 10.0, -47.9);
    glVertex3f(-63.0, 10.0, -72.9);
    glVertex3f(-63.0, -4.0, -72.9);
    glVertex3f(-63.0, -4.0, -47.9);
    glEnd();


    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, 60.9);
    glVertex3f(-63.0, 10.0, 60.9);
    glVertex3f(-63.0, -4.0, 60.9);
    glVertex3f(-67.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, 37.9);
    glVertex3f(-63.0, 10.0, 37.9);
    glVertex3f(-63.0, -4.0, 37.9);
    glVertex3f(-67.0, -4.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, 37.9);
    glVertex3f(-67.0, 10.0, 60.9);
    glVertex3f(-67.0, -4.0, 60.9);
    glVertex3f(-67.0, -4.0, 37.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-63.0, 10.0, 37.9);
    glVertex3f(-63.0, 10.0, 60.9);
    glVertex3f(-63.0, -4.0, 60.9);
    glVertex3f(-63.0, -4.0, 37.9);
    glEnd();


    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, 2.9);
    glVertex3f(-63.0, 10.0, 2.9);
    glVertex3f(-63.0, -4.0, 2.9);
    glVertex3f(-67.0, -4.0, 2.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, 27.9);
    glVertex3f(-63.0, 10.0, 27.9);
    glVertex3f(-63.0, -4.0, 27.9);
    glVertex3f(-67.0, -4.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0,10.0, 27.9);
    glVertex3f(-67.0, 10.0, 2.9);
    glVertex3f(-67.0, -4.0, 2.9);
    glVertex3f(-67.0, -4.0, 27.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-63.0, 10.0, 27.9);
    glVertex3f(-63.0, 10.0, 2.9);
    glVertex3f(-63.0, -4.0, 2.9);
    glVertex3f(-63.0, -4.0, 27.9);
    glEnd();


    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -32.9);
    glVertex3f(-63.0, 10.0, -32.9);
    glVertex3f(-63.0, -4.0, -32.9);
    glVertex3f(-67.0, -4.0, -32.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -7.9);
    glVertex3f(-63.0, 10.0, -7.9);
    glVertex3f(-63.0, -4.0, -7.9);
    glVertex3f(-67.0, -4.0, -7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-67.0, 10.0, -7.9);
    glVertex3f(-67.0, 10.0, -32.9);
    glVertex3f(-67.0, -4.0, -32.9);
    glVertex3f(-67.0, -4.0, -7.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-63.0, 10.0, -7.9);
    glVertex3f(-63.0, 10.0, -32.9);
    glVertex3f(-63.0, -4.0, -32.9);
    glVertex3f(-63.0, -4.0, -7.9);
    glEnd();

    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, -75.9);
    glVertex3f(-53.0, 10.0, -75.9);
    glVertex3f(-53.0, -4.0, -75.9);
    glVertex3f(-37.0, -4.0, -75.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, -69.9);
    glVertex3f(-53.0, 10.0, -69.9);
    glVertex3f(-53.0, -4.0, -69.9);
    glVertex3f(-37.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, -69.9);
    glVertex3f(-37.0, 10.0, -75.9);
    glVertex3f(-37.0, -4.0, -75.9);
    glVertex3f(-37.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-53.0, 10.0, -69.9);
    glVertex3f(-53.0, 10.0, -75.9);
    glVertex3f(-53.0, -4.0, -75.9);
    glVertex3f(-53.0, -4.0, -69.9);
    glEnd();

    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, -75.9);
    glVertex3f(-29.0, 10.0, -75.9);
    glVertex3f(-29.0, -4.0, -75.9);
    glVertex3f(-13.0, -4.0, -75.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, -69.9);
    glVertex3f(-29.0, 10.0, -69.9);
    glVertex3f(-29.0, -4.0, -69.9);
    glVertex3f(-13.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, -69.9);
    glVertex3f(-13.0, 10.0, -75.9);
    glVertex3f(-13.0, -4.0, -75.9);
    glVertex3f(-13.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-29.0, 10.0, -69.9);
    glVertex3f(-29.0, 10.0, -75.9);
    glVertex3f(-29.0, -4.0, -75.9);
    glVertex3f(-29.0, -4.0, -69.9);
    glEnd();


     //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, -75.9);
    glVertex3f(-6.0, 10.0, -75.9);
    glVertex3f(-6.0, -4.0, -75.9);
    glVertex3f(11.0, -4.0, -75.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, -69.9);
    glVertex3f(-6.0, 10.0, -69.9);
    glVertex3f(-6.0, -4.0, -69.9);
    glVertex3f(11.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, -69.9);
    glVertex3f(11.0, 10.0, -75.9);
    glVertex3f(11.0, -4.0, -75.9);
    glVertex3f(11.0, -4.0, -69.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-6.0, 10.0, -69.9);
    glVertex3f(-6.0, 10.0, -75.9);
    glVertex3f(-6.0, -4.0, -75.9);
    glVertex3f(-6.0, -4.0, -69.9);
    glEnd();


//bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, 65.9);
    glVertex3f(-6.0, 10.0, 65.9);
    glVertex3f(-6.0, -4.0, 65.9);
    glVertex3f(11.0, -4.0, 65.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, 60.9);
    glVertex3f(-6.0, 10.0, 60.9);
    glVertex3f(-6.0, -4.0, 60.9);
    glVertex3f(11.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(11.0, 10.0, 60.9);
    glVertex3f(11.0, 10.0, 65.9);
    glVertex3f(11.0, -4.0, 65.9);
    glVertex3f(11.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-6.0, 10.0, 60.9);
    glVertex3f(-6.0, 10.0, 65.9);
    glVertex3f(-6.0, -4.0, 65.9);
    glVertex3f(-6.0, -4.0, 60.9);
    glEnd();

//kursi biru
    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, 65.9);
    glVertex3f(-53.0, 10.0, 65.9);
    glVertex3f(-53.0, -4.0, 65.9);
    glVertex3f(-37.0, -4.0, 65.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, 60.9);
    glVertex3f(-53.0, 10.0, 60.9);
    glVertex3f(-53.0, -4.0, 60.9);
    glVertex3f(-37.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-37.0, 10.0, 60.9);
    glVertex3f(-37.0, 10.0, 65.9);
    glVertex3f(-37.0, -4.0, 65.9);
    glVertex3f(-37.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-53.0, 10.0, 60.9);
    glVertex3f(-53.0, 10.0, 65.9);
    glVertex3f(-53.0, -4.0, 65.9);
    glVertex3f(-53.0, -4.0, 60.9);
    glEnd();

    //bangku biru

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, 65.9);
    glVertex3f(-29.0, 10.0, 65.9);
    glVertex3f(-29.0, -4.0, 65.9);
    glVertex3f(-13.0, -4.0, 65.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, 60.9);
    glVertex3f(-29.0, 10.0, 60.9);
    glVertex3f(-29.0, -4.0, 60.9);
    glVertex3f(-13.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-13.0, 10.0, 60.9);
    glVertex3f(-13.0, 10.0, 65.9);
    glVertex3f(-13.0, -4.0, 65.9);
    glVertex3f(-13.0, -4.0, 60.9);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0,0,1);
    glVertex3f(-29.0, 10.0, 60.9);
    glVertex3f(-29.0, 10.0, 65.9);
    glVertex3f(-29.0, -4.0, 65.9);
    glVertex3f(-29.0, -4.0, 60.9);
    glEnd();


     ///garis tengah lapangan (erits)
   glBegin(GL_LINES);
   glColor3f(1,1,1);
    glVertex3f(-42.5, -19.0, 0.0);
      glVertex3f(9.5, -19.0, 0.0);
   glEnd();

///sisi atas kotak tengah lapangan (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(-34, -19.0, 29.0);
    glVertex3f(3, -19.0, 29.0);
   glEnd();


    ///sisi atas kotak tengah lapangan (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(-43, -19.0, -55.0);
    glVertex3f(23, -19.0, -55.0);
   glEnd();

   ///sisi bawah kotak tengah lapangan (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(-43, -19.0, 45.0);
    glVertex3f(23, -19.0, 45.0);
   glEnd();


    ///sisi kanan kotak tengah lapangan (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(-42,-19.0, 45.0);
    glVertex3f(-42, -19.0, -55.0);
   glEnd();

   ///sisi kanan kotak tengah lapangan (erits)
       glBegin(GL_LINES);
       glColor3f(1,1,1);
    glVertex3f(-34,-19.0, 44.3);
    glVertex3f(-34, -19.0, 29.0);
   glEnd();

   ///sisi kiri kotak tengah lapangan (erits)
        glBegin(GL_LINES);
        glColor3f(1,1,1);
    glVertex3f(9,-19.0, 45.0);
    glVertex3f(9, -19.0, -55.0);
   glEnd();

///sisi kiri kotak tengah lapangan (erits)
        glBegin(GL_LINES);
        glColor3f(1,1,1);
    glVertex3f(2.2,-19.0, 44.3);
    glVertex3f(2.2, -19.0, 29.0);
   glEnd();


/// sisi bawah kotak tengah lapangan (erits)
      glBegin(GL_LINES);
    glVertex3f(-35, -19.0, -38.0);
    glVertex3f(2.5, -19.0, -38.0);
   glEnd();

    ///sisi atas kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-25, -19.0, -45.0);
    glVertex3f(-4.5, -19.0, -45.0);
   glEnd();


   ///sisi atas kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-25, -19.0, 35.0);
    glVertex3f(-4.5, -19.0, 35.0);
   glEnd();

    ///sisi kanan kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-5,-19.0, -45.0);
    glVertex3f(-5, -19.0, -55.0);
   glEnd();

   ///sisi kanan kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-5,-19.0, 35.0);
    glVertex3f(-5, -19.0,45.0);
   glEnd();



   ///sisi kanan kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-35,-19.0, -55.0);
    glVertex3f(-35, -19.0, -38.0);
   glEnd();

   ///sisi kiri kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(2.5,-19.0, -55.0);
    glVertex3f(2.5, -19.0, -38.0);
   glEnd();

   ///sisi kiri kotak tengah lapangan (erits)
       glBegin(GL_LINES);
    glVertex3f(-24.5,-19.0, 35.0);
    glVertex3f(-24.5, -19.0,45.0);
   glEnd();


   ///sisi kiri kotak tengah lapangan (erits)
        glBegin(GL_LINES);
    glVertex3f(-25,-19.0, -45.0);
    glVertex3f(-25, -19.0, -55.0);
   glEnd();



 glutSwapBuffers();
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
    glutMainLoop();
    return 0;
}
