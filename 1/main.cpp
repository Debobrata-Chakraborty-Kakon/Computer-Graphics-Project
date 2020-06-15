#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
# define PI           3.14159265358979323846
void night(int value);
void morning(int value);
void rain(int value);


static int time=0;
GLfloat iii=0;
GLfloat speedtrain = 0.2f;
GLfloat positiontrain = 0.0f;
GLfloat positionrain=0.0f;

GLfloat speedrain = 0.9f;
void updatetrain(int value) {
if(positiontrain > 1.0)
        positiontrain = -1.0f;
    positiontrain += speedtrain;
	glutPostRedisplay();
	glutTimerFunc(100, updatetrain, 0);
}

//----------------for moving bird---------------------
GLfloat position22 = 0.0f;
GLfloat speed22 = 0.007f;
void birdd(int value) {
    if(position22 > 1.0)
        position22 =-1.0f;
    position22 += speed22;
	glutPostRedisplay();
	glutTimerFunc(100, birdd, 0);
}

//----------------for moving cloud-----------
GLfloat position2 = 0.0f;
GLfloat speed2 = 0.004f;
void cloud(int value) {
    if(position2 > 1.0)
        position2 = -1.0f;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, cloud, 0);
}


void rain_r(int value) {
    if(positionrain > 1.0)
        positionrain =-1.0f;
    positionrain += speedrain;
	glutPostRedisplay();
	glutTimerFunc(100, rain_r, 0);
}
//-----------------for moving truck and car2----------------
GLfloat position1 = 1.0f;
GLfloat speed1 =-0.05f;
void truck(int value)
{
   if(position1 <- 1.0)
        position1 = 1.0f;

    position1 += speed1;

	glutPostRedisplay();



	glutTimerFunc(100, truck, 0);
}
//----------------------for moving red car-----------
GLfloat position11 = -1.0f;
GLfloat speed11 =0.05f;
void car(int value)
{
   if(position11 > 1.0)
        position11 = -1.0f;

    position11 += speed11;

	glutPostRedisplay();



	glutTimerFunc(100, car, 0);
}

void handleKeypress(unsigned char key, int x, int y) {

	switch (key) {

case 'm':
    glutTimerFunc(100,morning,0);
    break;

case 'n':
    glutTimerFunc(100,night,0);
    break;
case 'r':
    glutTimerFunc(100,rain,0);
    break;


glutPostRedisplay();

	}
}

void SpecialInput(int key, int x, int y)
{
switch(key)
{   glPopMatrix();

case GLUT_KEY_UP:
speedtrain = 0.3f;
break;
case GLUT_KEY_DOWN:
speedtrain = 0.0f;
break;
case GLUT_KEY_LEFT:
speedtrain = 0.09f;
break;
case GLUT_KEY_RIGHT:
speedtrain = 0.02f;
break;
}
glutPostRedisplay();
}

void sound()
{

    //PlaySound("a.wav", NULL, SND_ASYNC|SND_FILENAME);
    PlaySound("a.wav", NULL,SND_ASYNC|SND_FILENAME|SND_LOOP);

}


void rain (int value)
{
   time=2;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);


    //--------------for sky--------------------

    glColor3ub(16,16,16);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.9);
    glVertex2f(1,0.9);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();

  //-------------------------sun----------------------DC-------------------------
 int i;

    GLfloat radius022=.12f;

    GLfloat twicePi11 = 2.0f * PI;



//-----------For Cloud-----------------------DC-----------------------------------



 glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    GLfloat x07=-.8f;
    GLfloat y07=.7f;
    GLfloat radius02=.1f;
    int triangleAmount01= 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(67,66,66);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.65f;
    y07=.7f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    //glColor3ub(67,66,66);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.69f;
    y07=.8f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    //glColor3ub(225,225,225);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    //-------------------------cloud2--------------------------------------
	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
int triangleAmount = 20;
  glBegin(GL_TRIANGLE_FAN);
	  //  glColor3ub(255, 255, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount01;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 glPopMatrix();
	//-----------------------------cloud ends--------------------------

//.....---------------------------grass behind station---------------....
 glBegin(GL_POLYGON);
  glColor3ub(6,40,6 );
  glVertex2f(0.44f,0.1f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.45f,0.2f);
  glVertex2f(0.4f,0.3f);
  glVertex2f(0.35f,0.2f);
  glVertex2f(0.3f,0.275f);
  glVertex2f(0.36f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(0.94f,0.1f);
   glVertex2f(1.0f,0.275f);
   glVertex2f(0.95f,0.2f);
   glVertex2f(0.9f,0.3f);
   glVertex2f(0.85f,0.2f);
   glVertex2f(0.8f,0.275f);
   glVertex2f(0.86f,0.1f);
          glEnd();

  glBegin(GL_POLYGON);
  glColor3ub(6,40,6 );
  glVertex2f(0.64f,0.1f);
  glVertex2f(0.70f,0.275f);
  glVertex2f(0.65f,0.2f);
  glVertex2f(0.6f,0.3f);
  glVertex2f(0.55f,0.2f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.56f,0.1f);
          glEnd();
    glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(0.74f,0.1f);
   glVertex2f(0.80f,0.275f);
   glVertex2f(0.75f,0.2f);
   glVertex2f(0.7f,0.3f);
   glVertex2f(0.65f,0.2f);
   glVertex2f(0.6f,0.275f);
   glVertex2f(0.66f,0.1f);
          glEnd();
     glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(-0.74f,0.1f);
   glVertex2f(-0.80f,0.275f);
   glVertex2f(-0.75f,0.2f);
   glVertex2f(-0.7f,0.3f);
   glVertex2f(-0.65f,0.2f);
   glVertex2f(-0.6f,0.275f);
   glVertex2f(-0.66f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(-0.94f,0.1f);
   glVertex2f(-1.0f,0.275f);
   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.3f);
   glVertex2f(-0.85f,0.2f);
   glVertex2f(-0.8f,0.275f);
   glVertex2f(-0.86f,0.1f);
          glEnd();
//......................grass ends.--------------------
 //For Fence-------------------------------------------
    //Upper One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.3);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.7,0.27);
    glVertex2f(-1.0,0.27);
      glEnd();
    //Lower One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.16);
    glVertex2f(-0.7,0.16);
    glVertex2f(-0.7,0.13);
    glVertex2f(-1.0,0.13);
     glEnd();

    //First Vertical One
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.35);
    glVertex2f(-0.99,0.35);
    glVertex2f(-0.99,0.1);
    glVertex2f(-1.0,0.1);
 glEnd();
    //Second Vertical One
glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.97,0.35);
    glVertex2f(-0.95,0.35);
    glVertex2f(-0.95,0.1);
    glVertex2f(-0.97,0.1);
glEnd();

    //Third Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.93,0.35);
    glVertex2f(-0.91,0.35);
    glVertex2f(-0.91,0.1);
    glVertex2f(-0.93,0.1);
   glEnd();
    //Fourth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.89,0.35);
    glVertex2f(-0.87,0.35);
    glVertex2f(-0.87,0.1);
    glVertex2f(-0.89,0.1);
   glEnd();
    //Fifth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,0.35);
    glVertex2f(-0.83,0.35);
    glVertex2f(-0.83,0.1);
    glVertex2f(-0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.81,0.35);
    glVertex2f(-0.79,0.35);
    glVertex2f(-0.79,0.1);
    glVertex2f(-0.81,0.1);

    glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.77,0.35);
    glVertex2f(-0.75,0.35);
    glVertex2f(-0.75,0.1);
    glVertex2f(-0.77,0.1);
    glEnd();
    //Last Vertical One

    glBegin(GL_QUADS);
    glVertex2f(-0.73,0.35);
    glVertex2f(-0.71,0.35);
    glVertex2f(-0.71,0.1);
    glVertex2f(-0.73,0.1);

   glEnd();
//fence on right side.......................
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.3);
    glVertex2f(0.3,0.3);
    glVertex2f(0.3,0.27);
    glVertex2f(1.0,0.27);
         glEnd();
    //Lower One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.16);
    glVertex2f(0.3,0.16);
    glVertex2f(0.3,0.13);
    glVertex2f(1.0,0.13);
    glEnd();

    //First Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.35);
    glVertex2f(0.99,0.35);
    glVertex2f(0.99,0.1);
    glVertex2f(1.0,0.1);
    glEnd();
    //Second Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.97,0.35);
    glVertex2f(0.95,0.35);
    glVertex2f(0.95,0.1);
    glVertex2f(0.97,0.1);
    glEnd();

    //Third Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.93,0.35);
    glVertex2f(0.91,0.35);
    glVertex2f(0.91,0.1);
    glVertex2f(0.93,0.1);
    glEnd();
    //Fourth Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.89,0.35);
    glVertex2f(0.87,0.35);
    glVertex2f(0.87,0.1);
    glVertex2f(0.89,0.1);
     glEnd();
    //Fifth Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.85,0.35);
    glVertex2f(0.83,0.35);
    glVertex2f(0.83,0.1);
    glVertex2f(0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.81,0.35);
    glVertex2f(0.79,0.35);
    glVertex2f(0.79,0.1);
    glVertex2f(0.81,0.1);
     glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.77,0.35);
    glVertex2f(0.75,0.35);
    glVertex2f(0.75,0.1);
    glVertex2f(0.77,0.1);
     glEnd();
    //Last Vertical One
     glBegin(GL_QUADS);
    glVertex2f(0.73,0.35);
    glVertex2f(0.71,0.35);
    glVertex2f(0.71,0.1);
    glVertex2f(0.73,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.61,0.35);
    glVertex2f(0.59,0.35);
    glVertex2f(0.59,0.1);
    glVertex2f(0.61,0.1);
     glEnd();
 glBegin(GL_QUADS);
    glVertex2f(0.57,0.35);
    glVertex2f(0.55,0.35);
    glVertex2f(0.55,0.1);
    glVertex2f(0.57,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.53,0.35);
    glVertex2f(0.51,0.35);
    glVertex2f(0.51,0.1);
    glVertex2f(0.53,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.49,0.35);
    glVertex2f(0.47,0.35);
    glVertex2f(0.47,0.1);
    glVertex2f(0.49,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.45,0.35);
    glVertex2f(0.43,0.35);
    glVertex2f(0.43,0.1);
    glVertex2f(0.45,0.1);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.41,0.35);
    glVertex2f(0.39,0.35);
    glVertex2f(0.39,0.1);
    glVertex2f(0.41,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.37,0.35);
     glVertex2f(0.35,0.35);
     glVertex2f(0.35,0.1);
     glVertex2f(0.37,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.33,0.35);
     glVertex2f(0.31,0.35);
     glVertex2f(0.31,0.1);
     glVertex2f(0.33,0.1);
     glEnd();
//..........................fence ends.----------------------
    //For Station-------------

    //Upper Portion-----------------
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.5);
    glVertex2f(0.3,0.5);
    glVertex2f(0.4,0.4);
    glVertex2f(-0.8,0.4);
    glEnd();
//Lower Portion
    glColor3ub(176,42,15);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.4);
    glVertex2f(0.3,0.4);
    glVertex2f(0.3,0.1);
    glVertex2f(-0.7,0.1);
    glEnd();

//For Inside of Station

//Last One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.2,0.1);
    glVertex2f(0.0,0.1);

    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.1,0.4);
    glEnd();

//Middle One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.1,0.1);
    glVertex2f(-0.3,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.2,0.4);
    glEnd();

    //First One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.4,0.1);
    glVertex2f(-0.6,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.5,0.4);
    glEnd();


    //For Tree

    //Lower Portion
    glColor3ub(48,31,7);
    glBegin(GL_QUADS);
    glVertex2f(0.6,0.5);
    glVertex2f(0.7,0.5);
    glVertex2f(0.7,0.1);
    glVertex2f(0.6,0.1);
    glEnd();
    //Upper Portion


    glColor3ub(20,52,6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.5);
    glVertex2f(0.65,0.7);
    glVertex2f(0.9,0.5);

    glEnd();

    glColor3ub(20,52,6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.6);
    glVertex2f(0.65,0.8);
    glVertex2f(0.9,0.6);

    glEnd();
//-------------------------road --------------DC-------------
    glColor3ub(27,28,27);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();
//----------------------------road white line------------------------
glLineWidth(6);
 glBegin(GL_LINES);
    glColor3ub(255,255, 255);
    glVertex2f(-0.6f, -0.02f);
	glVertex2f(-0.8f, -0.02f);//
    glVertex2f(-0.3f, -0.02f);
	glVertex2f(-0.1f, -0.02f);//
	glVertex2f(0.2f, -0.02f);
	glVertex2f(0.4f, -0.02f);//
	glVertex2f(0.7f, -0.02f);
	glVertex2f(0.9f,-0.02f);//
	glEnd();
//---------- station and road  border------------DC------------------------
 glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.1);
    glVertex2f(1,0.1);
    glVertex2f(1,.12);
    glVertex2f(-1,.12);
    glEnd();
//-------------------- lower green ----------------DC------------------


    glColor3ub(22,140,6);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-1);
    glVertex2f(-1,-1);
    glEnd();
//---------- road and green border ------------------------------------
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-.22);
    glVertex2f(-1,-.22);
    glEnd();
//..-----------------------------------.grass in green border.-----------------
 glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(8, 33, 7);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(-.85f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.75f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.827f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.773f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.8f, -0.4f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.725f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.875f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(.85f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.827f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.773f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.8f, -0.4f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.725f, -0.47f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.875f, -0.47f);
	glVertex2f(0.8f, -0.5f);
    glEnd();
        glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(.65f, -0.25f);
	glVertex2f(0.60f, -0.3f);
	glVertex2f(0.55f, -0.25f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.627f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.573f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.6f, -0.2f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.525f, -0.27f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.675f, -0.27f);
	glVertex2f(0.6f, -0.3f);
    glEnd();
      glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(-.65f, -0.25f);
	glVertex2f(-0.60f, -0.3f);
	glVertex2f(-0.55f, -0.25f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.627f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.573f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.525f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.675f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
    glEnd();
//--------------------grass ends-------------------
//For truck--------------------------
 glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
//-----------1st portion-----------
glBegin(GL_POLYGON);
  glColor3ub(47,79,79);
    glVertex2f(0.53,0.2);
    glVertex2f(0.5,0.1);
    glVertex2f(0.5,0.04);
    glVertex2f(0.6,0.04);
    glVertex2f(0.6,0.2);
    glEnd();
 //-----------2nd portion-----------
  glBegin(GL_LINES);
   glColor3ub(0,0,0);
   glVertex2f(0.55,0.04);
    glVertex2f(0.8,0.04);
    glEnd();

   glBegin(GL_QUADS);
   glColor3ub(25,25,112);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.04);
    glVertex2f(0.85,0.04);
    glVertex2f(0.85,0.25);
    glEnd();
    //-----------window---------------------
    glBegin(GL_QUADS);
     glColor3ub(240,255,240);
    glVertex2f(0.53,0.186);
    glVertex2f(0.516,0.148);
       glVertex2f(0.6,0.148);
     glVertex2f(0.6,0.186);
    glEnd();

 glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(0.57,0.186);
    glVertex2f(0.57,0.148);//
    glVertex2f(0.53,0.186);
     glVertex2f(0.6,0.186);//
      glVertex2f(0.535,0.186);
    glVertex2f(0.52,0.148);//
glEnd();

 //-----------1st wheel-----------
 x07=.55f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2st wheel-----------
 x07=.8f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//----------------truck ends------------------------
   //-----------------Car 2---------------------------------
  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.7,0.13);
  glVertex2f(-0.4,0.13);
  glVertex2f(-0.33,0.04);
  glVertex2f(-0.79,0.04);
    glEnd();

  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.6,0.21);
  glVertex2f(-0.48,0.21);
  glVertex2f(-0.45,0.13);
  glVertex2f(-0.65,0.13);
glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.65,0.036);
    glVertex2f(-0.45,0.036);
    glEnd();
 //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);
    glVertex2f(-0.61,0.15);
    glEnd();

   glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.545,0.2);
    glVertex2f(-0.545,0.15);//
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);//
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.61,0.15);//
glEnd();
 //-----------1st wheel-----------
 x07=-.65f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2nd wheel-----------
 x07=-.46f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

//--------------------------------Car2 ends---------

    glPopMatrix();
//---------------------------------------------------------------------

 glPushMatrix();
    glTranslatef(position11,0.0f, 0.0f);
    //For Car
    //Beginning Part(From Left)

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.0);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.77,-0.1);
    glEnd();
    //Middle Portion 1
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.55,0.05);
    glVertex2f(-0.4,0.05);
    glVertex2f(-0.33,0.0);
    glEnd();
    //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glVertex2f(-0.31,-0.1);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.48,-0.1);
    glVertex2f(-0.48,0.035);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);

    glVertex2f(-0.31,-0.1);




    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);

    glVertex2f(-0.31,-0.1);
    glVertex2f(-0.66,-0.1);
    glEnd();
    //Middle Portion 2
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,0.0);



    glEnd();
    //Last Part
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.22,0.0);






    glEnd();

    //----------Wheels of The car--------------DC----------------------
    //First One(From Left)


    x07=-.6f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.3f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
    glPopMatrix();
//---------------------------------------------------------------------------------


// ------------------train line-------------DC------------------------------
     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.8);
    glVertex2f(1,-0.78);
    glVertex2f(-1,-.78);
    glVertex2f(-1,-.8);

    glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.6);
    glVertex2f(1,-0.58);
    glVertex2f(-1,-.58);
    glVertex2f(-1,-.6);

    glEnd();
//------------------------------------------------DC--------------------

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.8,-.78);
    glVertex2f(.75,-.78);
    glVertex2f(.75,-.58);
    glVertex2f(.8,-.58);

    glEnd();

//--------------------- middle train lines--------------DC----------
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.6,-.78);
    glVertex2f(.55,-.78);
    glVertex2f(.55,-.58);
    glVertex2f(.6,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.4,-.78);
    glVertex2f(.35,-.78);
    glVertex2f(.35,-.58);
    glVertex2f(.4,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.2,-.78);
    glVertex2f(.15,-.78);
    glVertex2f(.15,-.58);
    glVertex2f(.2,-.58);

    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.0,-.78);
    glVertex2f(-.05,-.78);
    glVertex2f(-.05,-.58);
    glVertex2f(.0,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.2,-.78);
    glVertex2f(-.25,-.78);
    glVertex2f(-.25,-.58);
    glVertex2f(-.2,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-.78);
    glVertex2f(-.45,-.78);
    glVertex2f(-.45,-.58);
    glVertex2f(-.4,-.58);

    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.6,-.78);
    glVertex2f(-.65,-.78);
    glVertex2f(-.65,-.58);
    glVertex2f(-.6,-.58);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.8,-.78);
    glVertex2f(-.85,-.78);
    glVertex2f(-.85,-.58);
    glVertex2f(-.8,-.58);

    glEnd();
//-----------------------------------------------------------------
 // ------train -------------------1st compartment ---------DC--------

    glPushMatrix();
    glTranslatef(positiontrain,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(47,107,228);
    glVertex2f(0,-.75);
    glVertex2f(.5,-.75);
    glVertex2f(.42,-.6);
    glVertex2f(.0,-.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(0,-.6);
    glVertex2f(.2,-.6);
    glVertex2f(.2,-.4);
    glVertex2f(.0,-.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.55 );
    glVertex2f(.17,-.55);
    glVertex2f(.17,-.45);
    glVertex2f(.04,-.45);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,51);
    glVertex2f(.2,-.6);
    glVertex2f(.42,-.6);
    glVertex2f(.42,-.5);
    glVertex2f(.2,-.5);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,128,255);
    glVertex2f(.28,-.5);
    glVertex2f(.35,-.5);
    glVertex2f(.35,-.4);
    glVertex2f(.28,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,200);
    glVertex2f(.37,-.4);
    glVertex2f(.37,-.37);
    glVertex2f(.26,-.37);
    glVertex2f(.26,-.4);

    glEnd();

    GLfloat x01=.1f;
    GLfloat y01=-.75f;
    GLfloat radius01=.05f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x01,y01); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x01 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y01+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x02=.35f;
    GLfloat y02=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x02,y02); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x02 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y02+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();





//------------------------------------------------------
//--------train---------------2nd compartment-----------DC---------



    glBegin(GL_QUADS);
    glColor3ub(102,0,204);
    glVertex2f(-.4,-.75);
    glVertex2f(-.05,-.75);
    glVertex2f(-.05,-.4);
    glVertex2f(-.4,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.35,-.6);
    glVertex2f(-.1,-.6);
    glVertex2f(-.1,-.45);
    glVertex2f(-.35,-.45);

    glEnd();

    GLfloat x03=-.32f;
    GLfloat y03=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x03,y03); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x03 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y03+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x04=-.12f;
    GLfloat y04=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x04,y04); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x04 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y04+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//------------------------------------------------------------------------
//---------train ---------------3rd compartment ------------------DC--------


    glBegin(GL_QUADS);
    glColor3ub(255,153,51);
    glVertex2f(-.75,-.75);
    glVertex2f(-.45,-.75);
    glVertex2f(-.45,-.4);
    glVertex2f(-.75,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.72,-.6);
    glVertex2f(-.6,-.6);
    glVertex2f(-.6,-.45);
    glVertex2f(-.72,-.45);

    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.58,-.6);
    glVertex2f(-.48,-.6);
    glVertex2f(-.48,-.45);
    glVertex2f(-.58,-.45);

    glEnd();

   GLfloat x05=-.69f;
    GLfloat y05=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x05,y05);
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x05 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y05+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x06=-.52f;
    GLfloat y06=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x06,y06); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x06 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y06+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    glPopMatrix();


    glLoadIdentity();

//--------------------------------------------------------------------------

//-------------------------rain ----------------------------
 glPushMatrix();
    glTranslatef(0.0f,-positionrain, 0.0f);

  glColor3ub(255,255,255);

    glBegin(GL_LINES);
    glVertex2f(1,.85);
    glVertex2f(1,.8);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,.85);
    glVertex2f(.9,.8);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,.85);
    glVertex2f(.8,.8);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,.85);
    glVertex2f(.7,.8);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.85);
    glVertex2f(.6,.8);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.85);
    glVertex2f(.5,.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.85);
    glVertex2f(.4,.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.85);
    glVertex2f(.3,.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.85);
    glVertex2f(.2,.8);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.85);
    glVertex2f(.1,.8);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.85);
    glVertex2f(.0,.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.85);
    glVertex2f(-.1,.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.85);
    glVertex2f(-.2,.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.85);
    glVertex2f(-.3,.8);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,.85);
    glVertex2f(-.4,.8);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,.85);
    glVertex2f(-.5,.8);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,.85);
    glVertex2f(-.6,.8);
    glEnd();



                 glBegin(GL_LINES);
    glVertex2f(-.8,.85);
    glVertex2f(-.8,.8);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,.85);
    glVertex2f(-.9,.8);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,.85);
    glVertex2f(-1,.8);
    glEnd();


    //---------------

        glBegin(GL_LINES);
    glVertex2f(1,.75);
    glVertex2f(1,.7);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,.75);
    glVertex2f(.9,.7);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,.75);
    glVertex2f(.8,.7);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,.75);
    glVertex2f(.7,.7);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.75);
    glVertex2f(.6,.7);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.75);
    glVertex2f(.5,.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.75);
    glVertex2f(.4,.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.75);
    glVertex2f(.3,.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.75);
    glVertex2f(.2,.7);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.75);
    glVertex2f(.1,.7);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.75);
    glVertex2f(.0,.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.75);
    glVertex2f(-.1,.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.75);
    glVertex2f(-.2,.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.75);
    glVertex2f(-.3,.7);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,.75);
    glVertex2f(-.4,.7);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,.75);
    glVertex2f(-.5,.7);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,.75);
    glVertex2f(-.6,.7);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,.75);
    glVertex2f(-.7,.7);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,.75);
    glVertex2f(-.8,.7);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,.75);
    glVertex2f(-.9,.7);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,.75);
    glVertex2f(-1,.7);
    glEnd();
    //---------
      glBegin(GL_LINES);
    glVertex2f(1,.65);
    glVertex2f(1,.6);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.65);
    glVertex2f(.9,.6);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.65);
    glVertex2f(.8,.6);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,.65);
    glVertex2f(.7,.6);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.65);
    glVertex2f(.6,.6);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.65);
    glVertex2f(.5,.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.65);
    glVertex2f(.4,.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.65);
    glVertex2f(.3,.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.65);
    glVertex2f(.2,.6);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.65);
    glVertex2f(.1,.6);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.65);
    glVertex2f(.0,.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.65);
    glVertex2f(-.1,.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.65);
    glVertex2f(-.2,.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.65);
    glVertex2f(-.3,.6);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.65);
    glVertex2f(-.4,.6);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.65);
    glVertex2f(-.5,.6);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,.65);
    glVertex2f(-.6,.6);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,.65);
    glVertex2f(-.7,.6);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.65);
    glVertex2f(-.8,.6);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.65);
    glVertex2f(-.9,.6);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.65);
    glVertex2f(-1,.6);
    glEnd();

    //---------------
  glBegin(GL_LINES);
    glVertex2f(1,.55);
    glVertex2f(1,.5);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.55);
    glVertex2f(.9,.5);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.55);
    glVertex2f(.8,.5);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,.55);
    glVertex2f(.7,.5);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.55);
    glVertex2f(.6,.5);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.55);
    glVertex2f(.5,.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.55);
    glVertex2f(.4,.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.55);
    glVertex2f(.3,.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.55);
    glVertex2f(.2,.5);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.55);
    glVertex2f(.1,.5);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.0,.55);
    glVertex2f(.0,.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.55);
    glVertex2f(-.1,.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.55);
    glVertex2f(-.2,.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.55);
    glVertex2f(-.3,.5);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.55);
    glVertex2f(-.4,.5);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.55);
    glVertex2f(-.5,.5);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,.55);
    glVertex2f(-.6,.5);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,.55);
    glVertex2f(-.7,.5);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.55);
    glVertex2f(-.8,.5);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.55);
    glVertex2f(-.9,.5);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.55);
    glVertex2f(-1,.5);
    glEnd();

    //---------------------------
          glBegin(GL_LINES);
    glVertex2f(1,.35);
    glVertex2f(1,.3);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.35);
    glVertex2f(.9,.3);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.35);
    glVertex2f(.8,.3);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.35);
    glVertex2f(.6,.3);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.35);
    glVertex2f(.5,.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.35);
    glVertex2f(.4,.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.35);
    glVertex2f(.3,.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.35);
    glVertex2f(.2,.3);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.35);
    glVertex2f(.1,.3);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.35);
    glVertex2f(.0,.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.35);
    glVertex2f(-.1,.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.35);
    glVertex2f(-.2,.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.35);
    glVertex2f(-.3,.3);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.35);
    glVertex2f(-.4,.3);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.35);
    glVertex2f(-.5,.3);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,.35);
    glVertex2f(-.6,.3);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,.35);
    glVertex2f(-.7,.3);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.35);
    glVertex2f(-.8,.3);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.35);
    glVertex2f(-.9,.3);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.35);
    glVertex2f(-1,.3);
    glEnd();

    //-----------------
          glBegin(GL_LINES);
    glVertex2f(1,.45);
    glVertex2f(1,.4);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.45);
    glVertex2f(.9,.4);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.45);
    glVertex2f(.8,.4);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,.45);
    glVertex2f(.7,.4);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.45);
    glVertex2f(.6,.4);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.45);
    glVertex2f(.5,.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.45);
    glVertex2f(.4,.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.45);
    glVertex2f(.3,.4);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.1,.45);
    glVertex2f(.1,.4);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.45);
    glVertex2f(.0,.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.45);
    glVertex2f(-.1,.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.45);
    glVertex2f(-.2,.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.45);
    glVertex2f(-.3,.4);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.45);
    glVertex2f(-.4,.4);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.45);
    glVertex2f(-.5,.4);
    glEnd();



glBegin(GL_LINES);
    glVertex2f(-.7,.45);
    glVertex2f(-.7,.4);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.45);
    glVertex2f(-.8,.4);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.45);
    glVertex2f(-.9,.4);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.45);
    glVertex2f(-1,.4);
    glEnd();

    //-----------------------
          glBegin(GL_LINES);
    glVertex2f(1,.25);
    glVertex2f(1,.2);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.25);
    glVertex2f(.9,.2);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.25);
    glVertex2f(.8,.2);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,.25);
    glVertex2f(.7,.2);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,.25);
    glVertex2f(.6,.2);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,.25);
    glVertex2f(.5,.2);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.25);
    glVertex2f(.4,.2);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.25);
    glVertex2f(.3,.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.25);
    glVertex2f(.2,.2);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.25);
    glVertex2f(.0,.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.25);
    glVertex2f(-.1,.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.25);
    glVertex2f(-.2,.2);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.25);
    glVertex2f(-.3,.2);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.25);
    glVertex2f(-.4,.2);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.25);
    glVertex2f(-.5,.2);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,.25);
    glVertex2f(-.6,.2);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,.25);
    glVertex2f(-.7,.2);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.25);
    glVertex2f(-.8,.2);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.25);
    glVertex2f(-.9,.2);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.25);
    glVertex2f(-1,.2);
    glEnd();
    //--------------------------------
          glBegin(GL_LINES);
    glVertex2f(1,.15);
    glVertex2f(1,.1);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,.15);
    glVertex2f(.9,.1);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,.15);
    glVertex2f(.8,.1);
    glEnd();



   glBegin(GL_LINES);
    glVertex2f(.5,.15);
    glVertex2f(.5,.1);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,.15);
    glVertex2f(.4,.1);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,.15);
    glVertex2f(.3,.1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,.15);
    glVertex2f(.2,.1);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,.15);
    glVertex2f(.1,.1);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,.15);
    glVertex2f(.0,.1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,.15);
    glVertex2f(-.1,.1);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,.15);
    glVertex2f(-.2,.1);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,.15);
    glVertex2f(-.3,.1);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,.15);
    glVertex2f(-.4,.1);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,.15);
    glVertex2f(-.5,.1);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,.15);
    glVertex2f(-.6,.1);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,.15);
    glVertex2f(-.7,.1);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,.15);
    glVertex2f(-.8,.1);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,.15);
    glVertex2f(-.9,.1);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,.15);
    glVertex2f(-1,.1);
    glEnd();
//--------------------------
            glBegin(GL_LINES);
    glVertex2f(1,0);
    glVertex2f(1,-.05);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,0);
    glVertex2f(.9,-.05);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,.0);
    glVertex2f(.8,-.05);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,0);
    glVertex2f(.7,-.05);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,0);
    glVertex2f(.6,-.05);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,0);
    glVertex2f(.5,-.05);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,0);
    glVertex2f(.4,-.05);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,0);
    glVertex2f(.3,-.05);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,0);
    glVertex2f(.2,-.05);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,0);
    glVertex2f(.1,-.05);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,0);
    glVertex2f(.0,-.05);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,0);
    glVertex2f(-.1,-.05);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,0);
    glVertex2f(-.2,-.05);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,0);
    glVertex2f(-.3,-.05);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,0);
    glVertex2f(-.4,-.05);
    glEnd();




          glBegin(GL_LINES);
    glVertex2f(-.6,.0);
    glVertex2f(-.6,-.05);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,0);
    glVertex2f(-.7,-.05);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,0);
    glVertex2f(-.8,-.05);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,0);
    glVertex2f(-.9,-.05);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,0);
    glVertex2f(-1,-.05);
    glEnd();

 //-----------


            glBegin(GL_LINES);
    glVertex2f(1,-.15);
    glVertex2f(1,-.2);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.15);
    glVertex2f(.9,-.2);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,-.15);
    glVertex2f(.8,-.2);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,-.15);
    glVertex2f(.7,-.2);
    glEnd();




   glBegin(GL_LINES);
    glVertex2f(.5,-.15);
    glVertex2f(.5,-.2);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.15);
    glVertex2f(.4,-.2);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.15);
    glVertex2f(.3,-.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.15);
    glVertex2f(.2,-.2);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.15);
    glVertex2f(.1,-.2);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.15);
    glVertex2f(.0,-.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.15);
    glVertex2f(-.1,-.2);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.15);
    glVertex2f(-.2,-.2);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,-.15);
    glVertex2f(-.4,-.2);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,-.15);
    glVertex2f(-.5,-.2);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,-.15);
    glVertex2f(-.6,-.2);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.15);
    glVertex2f(-.7,-.2);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.15);
    glVertex2f(-.8,-.2);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.15);
    glVertex2f(-.9,-.2);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.15);
    glVertex2f(-1,-.2);
    glEnd();

//----------------------------------

            glBegin(GL_LINES);
    glVertex2f(1,-.25);
    glVertex2f(1,-.3);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.25);
    glVertex2f(.9,-.3);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(.7,-.25);
    glVertex2f(.7,-.3);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.25);
    glVertex2f(.6,-.3);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.25);
    glVertex2f(.5,-.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.25);
    glVertex2f(.4,-.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.25);
    glVertex2f(.3,-.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.25);
    glVertex2f(.2,-.3);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.25);
    glVertex2f(.1,-.3);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.25);
    glVertex2f(.0,-.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.25);
    glVertex2f(-.1,-.3);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.25);
    glVertex2f(-.2,-.3);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.25);
    glVertex2f(-.3,-.3);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,-.25);
    glVertex2f(-.4,-.3);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.6,-.25);
    glVertex2f(-.6,-.3);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.25);
    glVertex2f(-.7,-.3);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.25);
    glVertex2f(-.8,-.3);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.25);
    glVertex2f(-.9,-.3);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.25);
    glVertex2f(-1,-.3);
    glEnd();
//-------------------------------------
            glBegin(GL_LINES);
    glVertex2f(1,-.35);
    glVertex2f(1,-.4);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.35);
    glVertex2f(.9,-.4);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,-.35);
    glVertex2f(.8,-.4);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,-.35);
    glVertex2f(.7,-.4);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.35);
    glVertex2f(.6,-.4);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.35);
    glVertex2f(.5,-.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.34);
    glVertex2f(.4,-.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.35);
    glVertex2f(.3,-.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.35);
    glVertex2f(.2,-.4);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.35);
    glVertex2f(.1,-.4);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.35);
    glVertex2f(.0,-.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.35);
    glVertex2f(-.1,-.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.35);
    glVertex2f(-.2,-.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.35);
    glVertex2f(-.3,-.4);
    glEnd();



          glBegin(GL_LINES);
    glVertex2f(-.6,-.35);
    glVertex2f(-.6,-.4);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.35);
    glVertex2f(-.7,-.4);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.35);
    glVertex2f(-.8,-.4);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.35);
    glVertex2f(-.9,-.4);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.35);
    glVertex2f(-1,-.4);
    glEnd();

//----------------------------------------------------
            glBegin(GL_LINES);
    glVertex2f(1,-.45);
    glVertex2f(1,-.5);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.45);
    glVertex2f(.9,-.5);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,-.45);
    glVertex2f(.8,-.5);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,-.45);
    glVertex2f(.7,-.5);
    glEnd();




   glBegin(GL_LINES);
    glVertex2f(.5,-.45);
    glVertex2f(.5,-.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.45);
    glVertex2f(.4,-.5);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.45);
    glVertex2f(.3,-.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.45);
    glVertex2f(.2,-.5);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.45);
    glVertex2f(.1,-.5);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.45);
    glVertex2f(.0,-.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.45);
    glVertex2f(-.1,-.5);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.45);
    glVertex2f(-.2,-.5);
    glEnd();



        glBegin(GL_LINES);
    glVertex2f(-.4,-.45);
    glVertex2f(-.4,-.5);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,-.45);
    glVertex2f(-.5,-.5);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,-.45);
    glVertex2f(-.6,-.5);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.45);
    glVertex2f(-.7,-.5);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.45);
    glVertex2f(-.8,-.5);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.45);
    glVertex2f(-.9,-.5);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.45);
    glVertex2f(-1,-.4);
    glEnd();
//---------------------------------------------------
            glBegin(GL_LINES);
    glVertex2f(1,-.55);
    glVertex2f(1,-.6);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.55);
    glVertex2f(.9,-.6);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,-.55);
    glVertex2f(.8,-.6);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,-.55);
    glVertex2f(.7,-.6);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.55);
    glVertex2f(.6,-.6);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.55);
    glVertex2f(.5,-.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.55);
    glVertex2f(.4,-.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.55);
    glVertex2f(.3,-.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.55);
    glVertex2f(.2,-.6);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.55);
    glVertex2f(.1,-.6);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.55);
    glVertex2f(.0,-.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.55);
    glVertex2f(-.1,-.6);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.55);
    glVertex2f(-.2,-.6);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.55);
    glVertex2f(-.3,-.6);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,-.55);
    glVertex2f(-.4,-.6);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,-.55);
    glVertex2f(-.5,-.6);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,-.55);
    glVertex2f(-.6,-.6);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.55);
    glVertex2f(-.7,-.6);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.55);
    glVertex2f(-.8,-.6);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.55);
    glVertex2f(-.9,-.6);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.55);
    glVertex2f(-1,-.6);
    glEnd();
//--------------------------------------------------
            glBegin(GL_LINES);
    glVertex2f(1,-.65);
    glVertex2f(1,-.7);
    glEnd();
        glBegin(GL_LINES);
    glVertex2f(.9,-.65);
    glVertex2f(.9,-.7);
    glEnd();
           glBegin(GL_LINES);
    glVertex2f(.8,-.65);
    glVertex2f(.8,-.7);
    glEnd();
              glBegin(GL_LINES);
    glVertex2f(.7,-.65);
    glVertex2f(.7,-.7);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.65);
    glVertex2f(.6,-.7);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.65);
    glVertex2f(.5,-.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.65);
    glVertex2f(.4,-.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.65);
    glVertex2f(.3,-.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.65);
    glVertex2f(.2,-.7);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.65);
    glVertex2f(.1,-.7);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.65);
    glVertex2f(.0,-.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.65);
    glVertex2f(-.1,-.7);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.65);
    glVertex2f(-.2,-.7);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.65);
    glVertex2f(-.3,-.7);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(-.4,-.65);
    glVertex2f(-.4,-.7);
    glEnd();

          glBegin(GL_LINES);
    glVertex2f(-.5,-.65);
    glVertex2f(-.5,-.7);
    glEnd();


          glBegin(GL_LINES);
    glVertex2f(-.6,-.65);
    glVertex2f(-.6,-.7);
    glEnd();

              glBegin(GL_LINES);
    glVertex2f(-.7,-.65);
    glVertex2f(-.7,-.7);
    glEnd();

                 glBegin(GL_LINES);
    glVertex2f(-.8,-.65);
    glVertex2f(-.8,-.7);
    glEnd();

                     glBegin(GL_LINES);
    glVertex2f(-.9,-.65);
    glVertex2f(-.9,-.7);
    glEnd();

                         glBegin(GL_LINES);
    glVertex2f(-1,-.65);
    glVertex2f(-1,-.7);
    glEnd();
 //-----------------------

       glBegin(GL_LINES);
    glVertex2f(1,-.75);
    glVertex2f(1,-.8);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,-.75);
    glVertex2f(.9,-.8);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,-.75);
    glVertex2f(.8,-.8);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,-.75);
    glVertex2f(.7,-.8);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.75);
    glVertex2f(.6,-.8);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.75);
    glVertex2f(.5,-.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.75);
    glVertex2f(.4,-.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.75);
    glVertex2f(.3,-.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.75);
    glVertex2f(.2,-.8);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.75);
    glVertex2f(.1,-.8);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.75);
    glVertex2f(.0,-.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.75);
    glVertex2f(-.1,-.8);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.2,-.75);
    glVertex2f(-.2,-.8);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.75);
    glVertex2f(-.3,-.8);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,-.75);
    glVertex2f(-.4,-.8);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,-.75);
    glVertex2f(-.5,-.8);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,-.75);
    glVertex2f(-.6,-.8);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,-.75);
    glVertex2f(-.7,-.8);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,-.75);
    glVertex2f(-.8,-.8);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,-.75);
    glVertex2f(-.9,-.8);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,-.75);
    glVertex2f(-1,-.8);
    glEnd();
    //------------------------
          glBegin(GL_LINES);
    glVertex2f(1,-.85);
    glVertex2f(1,-.9);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.9,-.85);
    glVertex2f(.9,-.9);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(.8,-.85);
    glVertex2f(.8,-.9);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(.7,-.85);
    glVertex2f(.7,-.9);
    glEnd();

                glBegin(GL_LINES);
    glVertex2f(.6,-.85);
    glVertex2f(.6,-.9);
    glEnd();


   glBegin(GL_LINES);
    glVertex2f(.5,-.85);
    glVertex2f(.5,-.9);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.4,-.85);
    glVertex2f(.4,-.9);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.3,-.85);
    glVertex2f(.3,-.9);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.2,-.85);
    glVertex2f(.2,-.9);
    glEnd();

        glBegin(GL_LINES);
    glVertex2f(.1,-.85);
    glVertex2f(.1,-.9);
    glEnd();


        glBegin(GL_LINES);
    glVertex2f(.0,-.85);
    glVertex2f(.0,-.9);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.1,-.85);
    glVertex2f(-.1,-.9);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.8,-.85);
    glVertex2f(-.8,-.9);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(-.3,-.85);
    glVertex2f(-.3,-.9);
    glEnd();

     glBegin(GL_LINES);
    glVertex2f(-.4,-.85);
    glVertex2f(-.4,-.9);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.5,-.85);
    glVertex2f(-.5,-.9);
    glEnd();


 glBegin(GL_LINES);
    glVertex2f(-.6,-.85);
    glVertex2f(-.6,-.9);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.7,-.85);
    glVertex2f(-.7,-.9);
    glEnd();

glBegin(GL_LINES);
    glVertex2f(-.8,-.85);
    glVertex2f(-.8,-.9);
    glEnd();

  glBegin(GL_LINES);
    glVertex2f(-.9,-.85);
    glVertex2f(-.9,-.9);
    glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1,-.85);
    glVertex2f(-1,-.9);
    glEnd();
 glPopMatrix();

    glFlush();  // Render now
}
void night(int value){
    time=0;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);


    //--------------for sky--------------------

    glColor3ub(16,16,16);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.9);
    glVertex2f(1,0.9);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();

  //-------------------------sun----------------------DC-------------------------
 int i;
   GLfloat x077=.85f;
   GLfloat y077=.75f;
    GLfloat radius022=.12f;
    int triangleAmount011= 20; //# of triangles used to draw circle
    GLfloat twicePi11 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(255,255,255);
    glVertex2f(x077,y077); // center of circle
    for(i = 0; i <= triangleAmount011; i++)
    {
        glVertex2f(
            x077 + (radius022* cos(i *  twicePi11 / triangleAmount011)),
            y077+ (radius022 * sin(i * twicePi11 / triangleAmount011))
        );
    }
    glEnd();


//-----------For Cloud-----------------------DC-----------------------------------



 glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    GLfloat x07=-.8f;
    GLfloat y07=.7f;
    GLfloat radius02=.1f;
    int triangleAmount01= 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(67,66,66);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.65f;
    y07=.7f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    //glColor3ub(67,66,66);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.69f;
    y07=.8f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    //glColor3ub(225,225,225);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    //-------------------------cloud2--------------------------------------
	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
int triangleAmount = 20;
  glBegin(GL_TRIANGLE_FAN);
	  //  glColor3ub(255, 255, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount01;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    //glColor3ub(255, 255, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 glPopMatrix();
	//-----------------------------cloud ends--------------------------

//.....---------------------------grass behind station---------------....
 glBegin(GL_POLYGON);
  glColor3ub(6,40,6 );
  glVertex2f(0.44f,0.1f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.45f,0.2f);
  glVertex2f(0.4f,0.3f);
  glVertex2f(0.35f,0.2f);
  glVertex2f(0.3f,0.275f);
  glVertex2f(0.36f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(0.94f,0.1f);
   glVertex2f(1.0f,0.275f);
   glVertex2f(0.95f,0.2f);
   glVertex2f(0.9f,0.3f);
   glVertex2f(0.85f,0.2f);
   glVertex2f(0.8f,0.275f);
   glVertex2f(0.86f,0.1f);
          glEnd();

  glBegin(GL_POLYGON);
  glColor3ub(6,40,6 );
  glVertex2f(0.64f,0.1f);
  glVertex2f(0.70f,0.275f);
  glVertex2f(0.65f,0.2f);
  glVertex2f(0.6f,0.3f);
  glVertex2f(0.55f,0.2f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.56f,0.1f);
          glEnd();
    glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(0.74f,0.1f);
   glVertex2f(0.80f,0.275f);
   glVertex2f(0.75f,0.2f);
   glVertex2f(0.7f,0.3f);
   glVertex2f(0.65f,0.2f);
   glVertex2f(0.6f,0.275f);
   glVertex2f(0.66f,0.1f);
          glEnd();
     glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(-0.74f,0.1f);
   glVertex2f(-0.80f,0.275f);
   glVertex2f(-0.75f,0.2f);
   glVertex2f(-0.7f,0.3f);
   glVertex2f(-0.65f,0.2f);
   glVertex2f(-0.6f,0.275f);
   glVertex2f(-0.66f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(6,40,6 );
   glVertex2f(-0.94f,0.1f);
   glVertex2f(-1.0f,0.275f);
   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.3f);
   glVertex2f(-0.85f,0.2f);
   glVertex2f(-0.8f,0.275f);
   glVertex2f(-0.86f,0.1f);
          glEnd();
//......................grass ends.--------------------
 //For Fence-------------------------------------------
    //Upper One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.3);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.7,0.27);
    glVertex2f(-1.0,0.27);
      glEnd();
    //Lower One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.16);
    glVertex2f(-0.7,0.16);
    glVertex2f(-0.7,0.13);
    glVertex2f(-1.0,0.13);
     glEnd();

    //First Vertical One
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.35);
    glVertex2f(-0.99,0.35);
    glVertex2f(-0.99,0.1);
    glVertex2f(-1.0,0.1);
 glEnd();
    //Second Vertical One
glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.97,0.35);
    glVertex2f(-0.95,0.35);
    glVertex2f(-0.95,0.1);
    glVertex2f(-0.97,0.1);
glEnd();

    //Third Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.93,0.35);
    glVertex2f(-0.91,0.35);
    glVertex2f(-0.91,0.1);
    glVertex2f(-0.93,0.1);
   glEnd();
    //Fourth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.89,0.35);
    glVertex2f(-0.87,0.35);
    glVertex2f(-0.87,0.1);
    glVertex2f(-0.89,0.1);
   glEnd();
    //Fifth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,0.35);
    glVertex2f(-0.83,0.35);
    glVertex2f(-0.83,0.1);
    glVertex2f(-0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.81,0.35);
    glVertex2f(-0.79,0.35);
    glVertex2f(-0.79,0.1);
    glVertex2f(-0.81,0.1);

    glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.77,0.35);
    glVertex2f(-0.75,0.35);
    glVertex2f(-0.75,0.1);
    glVertex2f(-0.77,0.1);
    glEnd();
    //Last Vertical One

    glBegin(GL_QUADS);
    glVertex2f(-0.73,0.35);
    glVertex2f(-0.71,0.35);
    glVertex2f(-0.71,0.1);
    glVertex2f(-0.73,0.1);

   glEnd();
//fence on right side.......................
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.3);
    glVertex2f(0.3,0.3);
    glVertex2f(0.3,0.27);
    glVertex2f(1.0,0.27);
         glEnd();
    //Lower One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.16);
    glVertex2f(0.3,0.16);
    glVertex2f(0.3,0.13);
    glVertex2f(1.0,0.13);
    glEnd();

    //First Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.35);
    glVertex2f(0.99,0.35);
    glVertex2f(0.99,0.1);
    glVertex2f(1.0,0.1);
    glEnd();
    //Second Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.97,0.35);
    glVertex2f(0.95,0.35);
    glVertex2f(0.95,0.1);
    glVertex2f(0.97,0.1);
    glEnd();

    //Third Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.93,0.35);
    glVertex2f(0.91,0.35);
    glVertex2f(0.91,0.1);
    glVertex2f(0.93,0.1);
    glEnd();
    //Fourth Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.89,0.35);
    glVertex2f(0.87,0.35);
    glVertex2f(0.87,0.1);
    glVertex2f(0.89,0.1);
     glEnd();
    //Fifth Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.85,0.35);
    glVertex2f(0.83,0.35);
    glVertex2f(0.83,0.1);
    glVertex2f(0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.81,0.35);
    glVertex2f(0.79,0.35);
    glVertex2f(0.79,0.1);
    glVertex2f(0.81,0.1);
     glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.77,0.35);
    glVertex2f(0.75,0.35);
    glVertex2f(0.75,0.1);
    glVertex2f(0.77,0.1);
     glEnd();
    //Last Vertical One
     glBegin(GL_QUADS);
    glVertex2f(0.73,0.35);
    glVertex2f(0.71,0.35);
    glVertex2f(0.71,0.1);
    glVertex2f(0.73,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.61,0.35);
    glVertex2f(0.59,0.35);
    glVertex2f(0.59,0.1);
    glVertex2f(0.61,0.1);
     glEnd();
 glBegin(GL_QUADS);
    glVertex2f(0.57,0.35);
    glVertex2f(0.55,0.35);
    glVertex2f(0.55,0.1);
    glVertex2f(0.57,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.53,0.35);
    glVertex2f(0.51,0.35);
    glVertex2f(0.51,0.1);
    glVertex2f(0.53,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.49,0.35);
    glVertex2f(0.47,0.35);
    glVertex2f(0.47,0.1);
    glVertex2f(0.49,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.45,0.35);
    glVertex2f(0.43,0.35);
    glVertex2f(0.43,0.1);
    glVertex2f(0.45,0.1);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.41,0.35);
    glVertex2f(0.39,0.35);
    glVertex2f(0.39,0.1);
    glVertex2f(0.41,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.37,0.35);
     glVertex2f(0.35,0.35);
     glVertex2f(0.35,0.1);
     glVertex2f(0.37,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.33,0.35);
     glVertex2f(0.31,0.35);
     glVertex2f(0.31,0.1);
     glVertex2f(0.33,0.1);
     glEnd();
//..........................fence ends.----------------------
    //For Station-------------

    //Upper Portion-----------------
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.5);
    glVertex2f(0.3,0.5);
    glVertex2f(0.4,0.4);
    glVertex2f(-0.8,0.4);
    glEnd();
//Lower Portion
    glColor3ub(176,42,15);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.4);
    glVertex2f(0.3,0.4);
    glVertex2f(0.3,0.1);
    glVertex2f(-0.7,0.1);
    glEnd();

//For Inside of Station

//Last One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.2,0.1);
    glVertex2f(0.0,0.1);

    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.1,0.4);
    glEnd();

//Middle One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.1,0.1);
    glVertex2f(-0.3,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.2,0.4);
    glEnd();

    //First One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.4,0.1);
    glVertex2f(-0.6,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.5,0.4);
    glEnd();


    //For Tree

    //Lower Portion
    glColor3ub(48,31,7);
    glBegin(GL_QUADS);
    glVertex2f(0.6,0.5);
    glVertex2f(0.7,0.5);
    glVertex2f(0.7,0.1);
    glVertex2f(0.6,0.1);
    glEnd();
    //Upper Portion


    glColor3ub(20,52,6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.5);
    glVertex2f(0.65,0.7);
    glVertex2f(0.9,0.5);

    glEnd();

    glColor3ub(20,52,6);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.6);
    glVertex2f(0.65,0.8);
    glVertex2f(0.9,0.6);

    glEnd();
//-------------------------road --------------DC-------------
    glColor3ub(27,28,27);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();
//----------------------------road white line------------------------
glLineWidth(6);
 glBegin(GL_LINES);
    glColor3ub(255,255, 255);
    glVertex2f(-0.6f, -0.02f);
	glVertex2f(-0.8f, -0.02f);//
    glVertex2f(-0.3f, -0.02f);
	glVertex2f(-0.1f, -0.02f);//
	glVertex2f(0.2f, -0.02f);
	glVertex2f(0.4f, -0.02f);//
	glVertex2f(0.7f, -0.02f);
	glVertex2f(0.9f,-0.02f);//
	glEnd();
//---------- station and road  border------------DC------------------------
 glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.1);
    glVertex2f(1,0.1);
    glVertex2f(1,.12);
    glVertex2f(-1,.12);
    glEnd();
//-------------------- lower green ----------------DC------------------


    glColor3ub(22,140,6);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-1);
    glVertex2f(-1,-1);
    glEnd();
//---------- road and green border ------------------------------------
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-.22);
    glVertex2f(-1,-.22);
    glEnd();
//..-----------------------------------.grass in green border.-----------------
 glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(8, 33, 7);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(-.85f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.75f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.827f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.773f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.8f, -0.4f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.725f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.875f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(.85f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.827f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.773f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.8f, -0.4f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.725f, -0.47f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.875f, -0.47f);
	glVertex2f(0.8f, -0.5f);
    glEnd();
        glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(.65f, -0.25f);
	glVertex2f(0.60f, -0.3f);
	glVertex2f(0.55f, -0.25f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.627f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.573f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.6f, -0.2f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.525f, -0.27f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.675f, -0.27f);
	glVertex2f(0.6f, -0.3f);
    glEnd();
      glLineWidth(6);
    glBegin(GL_LINES);
    //glColor3ub(0, 102, 0);
	glVertex2f(-.65f, -0.25f);
	glVertex2f(-0.60f, -0.3f);
	glVertex2f(-0.55f, -0.25f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.627f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.573f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.525f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.675f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
    glEnd();
//--------------------grass ends-------------------
//For truck--------------------------
 glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
//-----------1st portion-----------
glBegin(GL_POLYGON);
  glColor3ub(47,79,79);
    glVertex2f(0.53,0.2);
    glVertex2f(0.5,0.1);
    glVertex2f(0.5,0.04);
    glVertex2f(0.6,0.04);
    glVertex2f(0.6,0.2);
    glEnd();
 //-----------2nd portion-----------
  glBegin(GL_LINES);
   glColor3ub(0,0,0);
   glVertex2f(0.55,0.04);
    glVertex2f(0.8,0.04);
    glEnd();

   glBegin(GL_QUADS);
   glColor3ub(25,25,112);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.04);
    glVertex2f(0.85,0.04);
    glVertex2f(0.85,0.25);
    glEnd();
    //-----------window---------------------
    glBegin(GL_QUADS);
     glColor3ub(240,255,240);
    glVertex2f(0.53,0.186);
    glVertex2f(0.516,0.148);
       glVertex2f(0.6,0.148);
     glVertex2f(0.6,0.186);
    glEnd();

 glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(0.57,0.186);
    glVertex2f(0.57,0.148);//
    glVertex2f(0.53,0.186);
     glVertex2f(0.6,0.186);//
      glVertex2f(0.535,0.186);
    glVertex2f(0.52,0.148);//
glEnd();

 //-----------1st wheel-----------
 x07=.55f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2st wheel-----------
 x07=.8f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//----------------truck ends------------------------
   //-----------------Car 2---------------------------------
  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.7,0.13);
  glVertex2f(-0.4,0.13);
  glVertex2f(-0.33,0.04);
  glVertex2f(-0.79,0.04);
    glEnd();

  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.6,0.21);
  glVertex2f(-0.48,0.21);
  glVertex2f(-0.45,0.13);
  glVertex2f(-0.65,0.13);
glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.65,0.036);
    glVertex2f(-0.45,0.036);
    glEnd();
 //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);
    glVertex2f(-0.61,0.15);
    glEnd();

   glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.545,0.2);
    glVertex2f(-0.545,0.15);//
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);//
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.61,0.15);//
glEnd();
 //-----------1st wheel-----------
 x07=-.65f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2nd wheel-----------
 x07=-.46f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

//--------------------------------Car2 ends---------

    glPopMatrix();
//---------------------------------------------------------------------

 glPushMatrix();
    glTranslatef(position11,0.0f, 0.0f);
    //For Car
    //Beginning Part(From Left)

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.0);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.77,-0.1);
    glEnd();
    //Middle Portion 1
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.55,0.05);
    glVertex2f(-0.4,0.05);
    glVertex2f(-0.33,0.0);
    glEnd();
    //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glVertex2f(-0.31,-0.1);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.48,-0.1);
    glVertex2f(-0.48,0.035);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);

    glVertex2f(-0.31,-0.1);




    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);

    glVertex2f(-0.31,-0.1);
    glVertex2f(-0.66,-0.1);
    glEnd();
    //Middle Portion 2
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,0.0);



    glEnd();
    //Last Part
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.22,0.0);






    glEnd();

    //----------Wheels of The car--------------DC----------------------
    //First One(From Left)


    x07=-.6f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.3f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
    glPopMatrix();
//---------------------------------------------------------------------------------


// ------------------train line-------------DC------------------------------
     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.8);
    glVertex2f(1,-0.78);
    glVertex2f(-1,-.78);
    glVertex2f(-1,-.8);

    glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.6);
    glVertex2f(1,-0.58);
    glVertex2f(-1,-.58);
    glVertex2f(-1,-.6);

    glEnd();
//------------------------------------------------DC--------------------

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.8,-.78);
    glVertex2f(.75,-.78);
    glVertex2f(.75,-.58);
    glVertex2f(.8,-.58);

    glEnd();

//--------------------- middle train lines--------------DC----------
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.6,-.78);
    glVertex2f(.55,-.78);
    glVertex2f(.55,-.58);
    glVertex2f(.6,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.4,-.78);
    glVertex2f(.35,-.78);
    glVertex2f(.35,-.58);
    glVertex2f(.4,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.2,-.78);
    glVertex2f(.15,-.78);
    glVertex2f(.15,-.58);
    glVertex2f(.2,-.58);

    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.0,-.78);
    glVertex2f(-.05,-.78);
    glVertex2f(-.05,-.58);
    glVertex2f(.0,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.2,-.78);
    glVertex2f(-.25,-.78);
    glVertex2f(-.25,-.58);
    glVertex2f(-.2,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-.78);
    glVertex2f(-.45,-.78);
    glVertex2f(-.45,-.58);
    glVertex2f(-.4,-.58);

    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.6,-.78);
    glVertex2f(-.65,-.78);
    glVertex2f(-.65,-.58);
    glVertex2f(-.6,-.58);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.8,-.78);
    glVertex2f(-.85,-.78);
    glVertex2f(-.85,-.58);
    glVertex2f(-.8,-.58);

    glEnd();
//-----------------------------------------------------------------
 // ------train -------------------1st compartment ---------DC--------

    glPushMatrix();
    glTranslatef(positiontrain,0.0f, 0.0f);

    glBegin(GL_QUADS);
    glColor3ub(47,107,228);
    glVertex2f(0,-.75);
    glVertex2f(.5,-.75);
    glVertex2f(.42,-.6);
    glVertex2f(.0,-.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(0,-.6);
    glVertex2f(.2,-.6);
    glVertex2f(.2,-.4);
    glVertex2f(.0,-.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.55 );
    glVertex2f(.17,-.55);
    glVertex2f(.17,-.45);
    glVertex2f(.04,-.45);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,51);
    glVertex2f(.2,-.6);
    glVertex2f(.42,-.6);
    glVertex2f(.42,-.5);
    glVertex2f(.2,-.5);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,128,255);
    glVertex2f(.28,-.5);
    glVertex2f(.35,-.5);
    glVertex2f(.35,-.4);
    glVertex2f(.28,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,200);
    glVertex2f(.37,-.4);
    glVertex2f(.37,-.37);
    glVertex2f(.26,-.37);
    glVertex2f(.26,-.4);

    glEnd();

    GLfloat x01=.1f;
    GLfloat y01=-.75f;
    GLfloat radius01=.05f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x01,y01); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x01 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y01+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x02=.35f;
    GLfloat y02=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x02,y02); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x02 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y02+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();





//------------------------------------------------------
//--------train---------------2nd compartment-----------DC---------



    glBegin(GL_QUADS);
    glColor3ub(102,0,204);
    glVertex2f(-.4,-.75);
    glVertex2f(-.05,-.75);
    glVertex2f(-.05,-.4);
    glVertex2f(-.4,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.35,-.6);
    glVertex2f(-.1,-.6);
    glVertex2f(-.1,-.45);
    glVertex2f(-.35,-.45);

    glEnd();

    GLfloat x03=-.32f;
    GLfloat y03=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x03,y03); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x03 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y03+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x04=-.12f;
    GLfloat y04=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x04,y04); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x04 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y04+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//------------------------------------------------------------------------
//---------train ---------------3rd compartment ------------------DC--------


    glBegin(GL_QUADS);
    glColor3ub(255,153,51);
    glVertex2f(-.75,-.75);
    glVertex2f(-.45,-.75);
    glVertex2f(-.45,-.4);
    glVertex2f(-.75,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.72,-.6);
    glVertex2f(-.6,-.6);
    glVertex2f(-.6,-.45);
    glVertex2f(-.72,-.45);

    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.58,-.6);
    glVertex2f(-.48,-.6);
    glVertex2f(-.48,-.45);
    glVertex2f(-.58,-.45);

    glEnd();

   GLfloat x05=-.69f;
    GLfloat y05=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x05,y05);
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x05 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y05+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x06=-.52f;
    GLfloat y06=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x06,y06); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x06 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y06+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    glPopMatrix();


    glLoadIdentity();

//--------------------------------------------------------------------------
//...............bird1............................................................
glPushMatrix();
    glTranslatef(position22,0.0f, 0.0f);
GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;
      glBegin(GL_TRIANGLE_FAN);
	     glColor3ub(128, 0, 0 );
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePib / triangleAmountb)),
			    nn + (radiusmm * sin(i * twicePib / triangleAmountb))
			);}
    glEnd();
 glBegin(GL_POLYGON);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();
     glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
//..........bird2.......................................
glBegin(GL_POLYGON);
 glColor3ub(128, 0, 0 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128, 0, 0 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();
    GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(128, 0, 0 );
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePib / triangleAmountb)),
			    nnn + (radiusmmm * sin(i * twicePib / triangleAmountb))
			);
		}
glEnd();
//.......bird3...........................

glBegin(GL_POLYGON);
  glColor3ub(139, 69, 19 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();
 glBegin(GL_TRIANGLES);
   // glColor3ub(242, 242, 242 );
    glColor3ub(139, 69, 19 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);

	    glColor3ub(139, 69, 19 );
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePib / triangleAmountb)),
			    nnnn + (radiusmmm * sin(i * twicePib / triangleAmountb))
			);
		}
	glEnd();

  glPopMatrix();





    glFlush();  // Render now
}
void morning(int value){
    time=1;
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
    glClear(GL_COLOR_BUFFER_BIT);


    glColor3ub(135,206,235);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.9);
    glVertex2f(1,0.9);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();

  //-------------------------sun----------------------DC-------------------------
 int i;
   GLfloat x077=.85f;
   GLfloat y077=.75f;
    GLfloat radius022=.12f;
    int triangleAmount011= 20; //# of triangles used to draw circle
    GLfloat twicePi11 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(255,128,0);
    glVertex2f(x077,y077); // center of circle
    for(i = 0; i <= triangleAmount011; i++)
    {
        glVertex2f(
            x077 + (radius022* cos(i *  twicePi11 / triangleAmount011)),
            y077+ (radius022 * sin(i * twicePi11 / triangleAmount011))
        );
    }
    glEnd();


//-----------For Cloud-----------------------DC-----------------------------------



 glPushMatrix();
    glTranslatef(position2,0.0f, 0.0f);

    GLfloat x07=-.8f;
    GLfloat y07=.7f;
    GLfloat radius02=.1f;
    int triangleAmount01= 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(225,225,225);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.65f;
    y07=.7f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(225,225,225);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.69f;
    y07=.8f;

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(225,225,225);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    //-------------------------cloud2--------------------------------------
	GLfloat x=0.0f; GLfloat y=.86f; GLfloat radius =.05f;
int triangleAmount = 20;
  glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 255, 255);
		glVertex2f(x, y); // center of circle
		for(i = 0; i <= triangleAmount01;i++) {
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

GLfloat a=.05f; GLfloat b=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 255, 255);
		glVertex2f(a, b); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            a + (radius * cos(i *  twicePi / triangleAmount)),
			    b + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat c=-0.05f; GLfloat d=.83f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 255, 255);
		glVertex2f(c, d); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            c + (radius * cos(i *  twicePi / triangleAmount)),
			    d + (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat e=.02f; GLfloat f=.8f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 255, 255);
		glVertex2f(e, f); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            e + (radius * cos(i *  twicePi / triangleAmount)),
			    f+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();

	GLfloat g=.1f; GLfloat h=.82f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(255, 255, 255);
		glVertex2f(g, h); // center of circle
		for(i = 0; i <= triangleAmount;i++) {
			glVertex2f(
		            g + (radius * cos(i *  twicePi / triangleAmount)),
			    h+ (radius * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
	 glPopMatrix();
	//-----------------------------cloud ends--------------------------

//.....---------------------------grass behind station---------------....
 glBegin(GL_POLYGON);
  glColor3ub(0, 102, 0 );
  glVertex2f(0.44f,0.1f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.45f,0.2f);
  glVertex2f(0.4f,0.3f);
  glVertex2f(0.35f,0.2f);
  glVertex2f(0.3f,0.275f);
  glVertex2f(0.36f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(0, 102, 0 );
   glVertex2f(0.94f,0.1f);
   glVertex2f(1.0f,0.275f);
   glVertex2f(0.95f,0.2f);
   glVertex2f(0.9f,0.3f);
   glVertex2f(0.85f,0.2f);
   glVertex2f(0.8f,0.275f);
   glVertex2f(0.86f,0.1f);
          glEnd();

  glBegin(GL_POLYGON);
  glColor3ub(0, 102, 0 );
  glVertex2f(0.64f,0.1f);
  glVertex2f(0.70f,0.275f);
  glVertex2f(0.65f,0.2f);
  glVertex2f(0.6f,0.3f);
  glVertex2f(0.55f,0.2f);
  glVertex2f(0.5f,0.275f);
  glVertex2f(0.56f,0.1f);
          glEnd();
    glBegin(GL_POLYGON);
   glColor3ub(0, 102, 0 );
   glVertex2f(0.74f,0.1f);
   glVertex2f(0.80f,0.275f);
   glVertex2f(0.75f,0.2f);
   glVertex2f(0.7f,0.3f);
   glVertex2f(0.65f,0.2f);
   glVertex2f(0.6f,0.275f);
   glVertex2f(0.66f,0.1f);
          glEnd();
     glBegin(GL_POLYGON);
   glColor3ub(0, 102, 0 );
   glVertex2f(-0.74f,0.1f);
   glVertex2f(-0.80f,0.275f);
   glVertex2f(-0.75f,0.2f);
   glVertex2f(-0.7f,0.3f);
   glVertex2f(-0.65f,0.2f);
   glVertex2f(-0.6f,0.275f);
   glVertex2f(-0.66f,0.1f);
          glEnd();
   glBegin(GL_POLYGON);
   glColor3ub(0, 102, 0 );
   glVertex2f(-0.94f,0.1f);
   glVertex2f(-1.0f,0.275f);
   glVertex2f(-0.95f,0.2f);
   glVertex2f(-0.9f,0.3f);
   glVertex2f(-0.85f,0.2f);
   glVertex2f(-0.8f,0.275f);
   glVertex2f(-0.86f,0.1f);
          glEnd();
//......................grass ends.--------------------
 //For Fence-------------------------------------------
    //Upper One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.3);
    glVertex2f(-0.7,0.3);
    glVertex2f(-0.7,0.27);
    glVertex2f(-1.0,0.27);
      glEnd();
    //Lower One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.16);
    glVertex2f(-0.7,0.16);
    glVertex2f(-0.7,0.13);
    glVertex2f(-1.0,0.13);
     glEnd();

    //First Vertical One
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-1.0,0.35);
    glVertex2f(-0.99,0.35);
    glVertex2f(-0.99,0.1);
    glVertex2f(-1.0,0.1);
 glEnd();
    //Second Vertical One
glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.97,0.35);
    glVertex2f(-0.95,0.35);
    glVertex2f(-0.95,0.1);
    glVertex2f(-0.97,0.1);
glEnd();

    //Third Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.93,0.35);
    glVertex2f(-0.91,0.35);
    glVertex2f(-0.91,0.1);
    glVertex2f(-0.93,0.1);
   glEnd();
    //Fourth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.89,0.35);
    glVertex2f(-0.87,0.35);
    glVertex2f(-0.87,0.1);
    glVertex2f(-0.89,0.1);
   glEnd();
    //Fifth Vertical One

    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.85,0.35);
    glVertex2f(-0.83,0.35);
    glVertex2f(-0.83,0.1);
    glVertex2f(-0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.81,0.35);
    glVertex2f(-0.79,0.35);
    glVertex2f(-0.79,0.1);
    glVertex2f(-0.81,0.1);

    glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(-0.77,0.35);
    glVertex2f(-0.75,0.35);
    glVertex2f(-0.75,0.1);
    glVertex2f(-0.77,0.1);
    glEnd();
    //Last Vertical One

    glBegin(GL_QUADS);
    glVertex2f(-0.73,0.35);
    glVertex2f(-0.71,0.35);
    glVertex2f(-0.71,0.1);
    glVertex2f(-0.73,0.1);

   glEnd();
//fence on right side.......................
 glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.3);
    glVertex2f(0.3,0.3);
    glVertex2f(0.3,0.27);
    glVertex2f(1.0,0.27);
         glEnd();
    //Lower One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.16);
    glVertex2f(0.3,0.16);
    glVertex2f(0.3,0.13);
    glVertex2f(1.0,0.13);
    glEnd();

    //First Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(1.0,0.35);
    glVertex2f(0.99,0.35);
    glVertex2f(0.99,0.1);
    glVertex2f(1.0,0.1);
    glEnd();
    //Second Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.97,0.35);
    glVertex2f(0.95,0.35);
    glVertex2f(0.95,0.1);
    glVertex2f(0.97,0.1);
    glEnd();

    //Third Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.93,0.35);
    glVertex2f(0.91,0.35);
    glVertex2f(0.91,0.1);
    glVertex2f(0.93,0.1);
    glEnd();
    //Fourth Vertical One
   glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.89,0.35);
    glVertex2f(0.87,0.35);
    glVertex2f(0.87,0.1);
    glVertex2f(0.89,0.1);
     glEnd();
    //Fifth Vertical One
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(0.85,0.35);
    glVertex2f(0.83,0.35);
    glVertex2f(0.83,0.1);
    glVertex2f(0.85,0.1);
    glEnd();
    //Sixth Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.81,0.35);
    glVertex2f(0.79,0.35);
    glVertex2f(0.79,0.1);
    glVertex2f(0.81,0.1);
     glEnd();
    //Seventh Vertical One
    glBegin(GL_QUADS);
    glVertex2f(0.77,0.35);
    glVertex2f(0.75,0.35);
    glVertex2f(0.75,0.1);
    glVertex2f(0.77,0.1);
     glEnd();
    //Last Vertical One
     glBegin(GL_QUADS);
    glVertex2f(0.73,0.35);
    glVertex2f(0.71,0.35);
    glVertex2f(0.71,0.1);
    glVertex2f(0.73,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.61,0.35);
    glVertex2f(0.59,0.35);
    glVertex2f(0.59,0.1);
    glVertex2f(0.61,0.1);
     glEnd();
 glBegin(GL_QUADS);
    glVertex2f(0.57,0.35);
    glVertex2f(0.55,0.35);
    glVertex2f(0.55,0.1);
    glVertex2f(0.57,0.1);
     glEnd();
  glBegin(GL_QUADS);
    glVertex2f(0.53,0.35);
    glVertex2f(0.51,0.35);
    glVertex2f(0.51,0.1);
    glVertex2f(0.53,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.49,0.35);
    glVertex2f(0.47,0.35);
    glVertex2f(0.47,0.1);
    glVertex2f(0.49,0.1);
     glEnd();

 glBegin(GL_QUADS);
    glVertex2f(0.45,0.35);
    glVertex2f(0.43,0.35);
    glVertex2f(0.43,0.1);
    glVertex2f(0.45,0.1);
     glEnd();
    glBegin(GL_QUADS);
    glVertex2f(0.41,0.35);
    glVertex2f(0.39,0.35);
    glVertex2f(0.39,0.1);
    glVertex2f(0.41,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.37,0.35);
     glVertex2f(0.35,0.35);
     glVertex2f(0.35,0.1);
     glVertex2f(0.37,0.1);
     glEnd();
      glBegin(GL_QUADS);
     glVertex2f(0.33,0.35);
     glVertex2f(0.31,0.35);
     glVertex2f(0.31,0.1);
     glVertex2f(0.33,0.1);
     glEnd();
//..........................fence ends.----------------------
    //For Station-------------

    //Upper Portion-----------------
    glColor3ub(102,51,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.5);
    glVertex2f(0.3,0.5);
    glVertex2f(0.4,0.4);
    glVertex2f(-0.8,0.4);
    glEnd();
//Lower Portion
    glColor3ub(176,42,15);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.4);
    glVertex2f(0.3,0.4);
    glVertex2f(0.3,0.1);
    glVertex2f(-0.7,0.1);
    glEnd();

//For Inside of Station

//Last One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.2,0.1);
    glVertex2f(0.0,0.1);

    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0,0.3);
    glVertex2f(0.2,0.3);
    glVertex2f(0.1,0.4);
    glEnd();

//Middle One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.1,0.1);
    glVertex2f(-0.3,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.3,0.3);
    glVertex2f(-0.1,0.3);
    glVertex2f(-0.2,0.4);
    glEnd();

    //First One
    glColor3ub(245,222,179);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.4,0.1);
    glVertex2f(-0.6,0.1);
    glEnd();
    glColor3ub(245,222,179);
    glBegin(GL_TRIANGLES);
    glVertex2f(-0.6,0.3);
    glVertex2f(-0.4,0.3);
    glVertex2f(-0.5,0.4);
    glEnd();


    //For Tree

    //Lower Portion
    glColor3ub(193,154,107);
    glBegin(GL_QUADS);
    glVertex2f(0.6,0.5);
    glVertex2f(0.7,0.5);
    glVertex2f(0.7,0.1);
    glVertex2f(0.6,0.1);
    glEnd();
    //Upper Portion


    glColor3ub(0,128,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.5);
    glVertex2f(0.65,0.7);
    glVertex2f(0.9,0.5);

    glEnd();

    glColor3ub(0,128,0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.4,0.6);
    glVertex2f(0.65,0.8);
    glVertex2f(0.9,0.6);

    glEnd();
//-------------------------road --------------DC-------------
    glColor3ub(128,128,128);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,0.1);
    glVertex2f(-1,0.1);
    glEnd();
//----------------------------road white line------------------------
glLineWidth(6);
 glBegin(GL_LINES);
    glColor3ub(255,255, 255);
    glVertex2f(-0.6f, -0.02f);
	glVertex2f(-0.8f, -0.02f);//
    glVertex2f(-0.3f, -0.02f);
	glVertex2f(-0.1f, -0.02f);//
	glVertex2f(0.2f, -0.02f);
	glVertex2f(0.4f, -0.02f);//
	glVertex2f(0.7f, -0.02f);
	glVertex2f(0.9f,-0.02f);//
	glEnd();
//---------- station and road  border------------DC------------------------
 glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,0.1);
    glVertex2f(1,0.1);
    glVertex2f(1,.12);
    glVertex2f(-1,.12);
    glEnd();
//-------------------- lower green ----------------DC------------------


    glColor3ub(0,255,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-1);
    glVertex2f(-1,-1);
    glEnd();
//---------- road and green border ------------------------------------
    glColor3ub(0,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-1,-0.2);
    glVertex2f(1,-0.2);
    glVertex2f(1,-.22);
    glVertex2f(-1,-.22);
    glEnd();
//..-----------------------------------.grass in green border.-----------------
 glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.05f, -0.35f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.05f, -0.35f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.027f, -0.33f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(0.0f, -0.3f);
	glVertex2f(0.0f, -0.4f);//
	glVertex2f(-0.075f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
	glVertex2f(0.0745f, -0.37f);
	glVertex2f(-0.0f, -0.4f);//
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.85f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.75f, -0.45f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.827f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.773f, -0.43f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.8f, -0.4f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.725f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
	glVertex2f(-0.875f, -0.47f);
	glVertex2f(-0.8f, -0.5f);
    glEnd();
     glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(.85f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.75f, -0.45f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.827f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.773f, -0.43f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.8f, -0.4f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.725f, -0.47f);
	glVertex2f(0.8f, -0.5f);
	glVertex2f(0.875f, -0.47f);
	glVertex2f(0.8f, -0.5f);
    glEnd();
        glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(.65f, -0.25f);
	glVertex2f(0.60f, -0.3f);
	glVertex2f(0.55f, -0.25f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.627f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.573f, -0.23f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.6f, -0.2f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.525f, -0.27f);
	glVertex2f(0.6f, -0.3f);
	glVertex2f(0.675f, -0.27f);
	glVertex2f(0.6f, -0.3f);
    glEnd();
      glLineWidth(6);
    glBegin(GL_LINES);
    glColor3ub(0, 102, 0);
	glVertex2f(-.65f, -0.25f);
	glVertex2f(-0.60f, -0.3f);
	glVertex2f(-0.55f, -0.25f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.627f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.573f, -0.23f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.6f, -0.2f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.525f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
	glVertex2f(-0.675f, -0.27f);
	glVertex2f(-0.6f, -0.3f);
    glEnd();
//--------------------grass ends-------------------
//For truck--------------------------
 glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
//-----------1st portion-----------
glBegin(GL_POLYGON);
  glColor3ub(47,79,79);
    glVertex2f(0.53,0.2);
    glVertex2f(0.5,0.1);
    glVertex2f(0.5,0.04);
    glVertex2f(0.6,0.04);
    glVertex2f(0.6,0.2);
    glEnd();
 //-----------2nd portion-----------
  glBegin(GL_LINES);
   glColor3ub(0,0,0);
   glVertex2f(0.55,0.04);
    glVertex2f(0.8,0.04);
    glEnd();

   glBegin(GL_QUADS);
   glColor3ub(25,25,112);
    glVertex2f(0.6,0.25);
    glVertex2f(0.6,0.04);
    glVertex2f(0.85,0.04);
    glVertex2f(0.85,0.25);
    glEnd();
    //-----------window---------------------
    glBegin(GL_QUADS);
     glColor3ub(240,255,240);
    glVertex2f(0.53,0.186);
    glVertex2f(0.516,0.148);
       glVertex2f(0.6,0.148);
     glVertex2f(0.6,0.186);
    glEnd();

 glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(0.57,0.186);
    glVertex2f(0.57,0.148);//
    glVertex2f(0.53,0.186);
     glVertex2f(0.6,0.186);//
      glVertex2f(0.535,0.186);
    glVertex2f(0.52,0.148);//
glEnd();

 //-----------1st wheel-----------
 x07=.55f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2st wheel-----------
 x07=.8f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//----------------truck ends------------------------
   //-----------------Car 2---------------------------------
  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.7,0.13);
  glVertex2f(-0.4,0.13);
  glVertex2f(-0.33,0.04);
  glVertex2f(-0.79,0.04);
    glEnd();

  glBegin(GL_QUADS);
  glColor3ub(128,0,128);
  glVertex2f(-0.6,0.21);
  glVertex2f(-0.48,0.21);
  glVertex2f(-0.45,0.13);
  glVertex2f(-0.65,0.13);
glEnd();

    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(-0.65,0.036);
    glVertex2f(-0.45,0.036);
    glEnd();
 //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);
    glVertex2f(-0.61,0.15);
    glEnd();

   glBegin(GL_LINES);
   glColor3ub(0,0,0);
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.545,0.2);
    glVertex2f(-0.545,0.15);//
    glVertex2f(-0.50,0.2);
    glVertex2f(-0.48,0.15);//
    glVertex2f(-0.58,0.2);
    glVertex2f(-0.61,0.15);//
glEnd();
 //-----------1st wheel-----------
 x07=-.65f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
   //-----------2nd wheel-----------
 x07=-.46f;
    y07=.04f;
    radius02=.035f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

//--------------------------------Car2 ends---------

    glPopMatrix();
//---------------------------------------------------------------------

 glPushMatrix();
    glTranslatef(position11,0.0f, 0.0f);
    //For Car
    //Beginning Part(From Left)

    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.7,0.0);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.77,-0.1);
    glEnd();
    //Middle Portion 1
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.6,0.0);
    glVertex2f(-0.55,0.05);
    glVertex2f(-0.4,0.05);
    glVertex2f(-0.33,0.0);
    glEnd();
    //Window of car
    glColor3ub(255,255,255);
    glBegin(GL_QUADS);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glVertex2f(-0.31,-0.1);
    glEnd();

    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.48,-0.1);
    glVertex2f(-0.48,0.035);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);
    glVertex2f(-0.66,-0.1);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);

    glVertex2f(-0.31,-0.1);




    glEnd();
    glColor3ub(0,0,0);
    glBegin(GL_LINES);
    glVertex2f(-0.51,0.03);
    glVertex2f(-0.45,0.03);
    glEnd();
    glColor3ub(0,0,0);

    glBegin(GL_LINES);

    glVertex2f(-0.31,-0.1);
    glVertex2f(-0.66,-0.1);
    glEnd();
    //Middle Portion 2
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.6,-0.1);
    glVertex2f(-0.6,0.0);



    glEnd();
    //Last Part
    glColor3ub(255,0,0);
    glBegin(GL_QUADS);
    glVertex2f(-0.33,0.0);
    glVertex2f(-0.33,-0.1);
    glVertex2f(-0.15,-0.1);
    glVertex2f(-0.22,0.0);






    glEnd();

    //----------Wheels of The car--------------DC----------------------
    //First One(From Left)


    x07=-.6f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    x07=-.3f;
    y07=-.1f;
    radius02=.05f;
    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(0,0,0);
    glVertex2f(x07,y07); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x07 + (radius02* cos(i *  twicePi / triangleAmount01)),
            y07+ (radius02 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
    glPopMatrix();
//---------------------------------------------------------------------------------


// ------------------train line-------------DC------------------------------
     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.8);
    glVertex2f(1,-0.78);
    glVertex2f(-1,-.78);
    glVertex2f(-1,-.8);

    glEnd();

     glBegin(GL_QUADS);
     glColor3ub(0,0,0);
    glVertex2f(1,-0.6);
    glVertex2f(1,-0.58);
    glVertex2f(-1,-.58);
    glVertex2f(-1,-.6);

    glEnd();
//------------------------------------------------DC--------------------

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.8,-.78);
    glVertex2f(.75,-.78);
    glVertex2f(.75,-.58);
    glVertex2f(.8,-.58);

    glEnd();

//--------------------- middle train lines--------------DC----------
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.6,-.78);
    glVertex2f(.55,-.78);
    glVertex2f(.55,-.58);
    glVertex2f(.6,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.4,-.78);
    glVertex2f(.35,-.78);
    glVertex2f(.35,-.58);
    glVertex2f(.4,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.2,-.78);
    glVertex2f(.15,-.78);
    glVertex2f(.15,-.58);
    glVertex2f(.2,-.58);

    glEnd();



    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(.0,-.78);
    glVertex2f(-.05,-.78);
    glVertex2f(-.05,-.58);
    glVertex2f(.0,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.2,-.78);
    glVertex2f(-.25,-.78);
    glVertex2f(-.25,-.58);
    glVertex2f(-.2,-.58);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.4,-.78);
    glVertex2f(-.45,-.78);
    glVertex2f(-.45,-.58);
    glVertex2f(-.4,-.58);

    glEnd();

     glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.6,-.78);
    glVertex2f(-.65,-.78);
    glVertex2f(-.65,-.58);
    glVertex2f(-.6,-.58);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-.8,-.78);
    glVertex2f(-.85,-.78);
    glVertex2f(-.85,-.58);
    glVertex2f(-.8,-.58);

    glEnd();
//-----------------------------------------------------------------
 // ------train -------------------1st compartment ---------DC--------

    glPushMatrix();
    glTranslatef(positiontrain,0.0f, 0.0f);
    glBegin(GL_QUADS);
    glColor3ub(47,107,228);
    glVertex2f(0,-.75);
    glVertex2f(.5,-.75);
    glVertex2f(.42,-.6);
    glVertex2f(.0,-.6);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,128,0);
    glVertex2f(0,-.6);
    glVertex2f(.2,-.6);
    glVertex2f(.2,-.4);
    glVertex2f(.0,-.4);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(.04,-.55 );
    glVertex2f(.17,-.55);
    glVertex2f(.17,-.45);
    glVertex2f(.04,-.45);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,51);
    glVertex2f(.2,-.6);
    glVertex2f(.42,-.6);
    glVertex2f(.42,-.5);
    glVertex2f(.2,-.5);

    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0,128,255);
    glVertex2f(.28,-.5);
    glVertex2f(.35,-.5);
    glVertex2f(.35,-.4);
    glVertex2f(.28,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(0,0,200);
    glVertex2f(.37,-.4);
    glVertex2f(.37,-.37);
    glVertex2f(.26,-.37);
    glVertex2f(.26,-.4);

    glEnd();

    GLfloat x01=.1f;
    GLfloat y01=-.75f;
    GLfloat radius01=.05f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x01,y01); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x01 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y01+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x02=.35f;
    GLfloat y02=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x02,y02); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x02 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y02+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();





//------------------------------------------------------
//--------train---------------2nd compartment-----------DC---------


    glBegin(GL_QUADS);
    glColor3ub(102,0,204);
    glVertex2f(-.4,-.75);
    glVertex2f(-.05,-.75);
    glVertex2f(-.05,-.4);
    glVertex2f(-.4,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.35,-.6);
    glVertex2f(-.1,-.6);
    glVertex2f(-.1,-.45);
    glVertex2f(-.35,-.45);

    glEnd();

    GLfloat x03=-.32f;
    GLfloat y03=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x03,y03); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x03 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y03+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x04=-.12f;
    GLfloat y04=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x04,y04); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x04 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y04+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
//------------------------------------------------------------------------
//---------train ---------------3rd compartment ------------------DC--------


    glBegin(GL_QUADS);
    glColor3ub(255,153,51);
    glVertex2f(-.75,-.75);
    glVertex2f(-.45,-.75);
    glVertex2f(-.45,-.4);
    glVertex2f(-.75,-.4);

    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.72,-.6);
    glVertex2f(-.6,-.6);
    glVertex2f(-.6,-.45);
    glVertex2f(-.72,-.45);

    glEnd();

      glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    glVertex2f(-.58,-.6);
    glVertex2f(-.48,-.6);
    glVertex2f(-.48,-.45);
    glVertex2f(-.58,-.45);

    glEnd();

   GLfloat x05=-.69f;
    GLfloat y05=-.75f;
   //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x05,y05);
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x05 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y05+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();

    GLfloat x06=-.52f;
    GLfloat y06=-.75f;
 //# of triangles used to draw circle

    glBegin(GL_TRIANGLE_FAN);                             //wheel
    glColor3ub(51,25,0);
    glVertex2f(x06,y06); // center of circle
    for(i = 0; i <= triangleAmount01; i++)
    {
        glVertex2f(
            x06 + (radius01* cos(i *  twicePi / triangleAmount01)),
            y06+ (radius01 * sin(i * twicePi / triangleAmount01))
        );
    }
    glEnd();
    glPopMatrix();


    glLoadIdentity();
//--------------------------------------------------------------------------
//...............bird1............................................................
glPushMatrix();
    glTranslatef(position22,0.0f, 0.0f);
GLfloat mm=0.182f; GLfloat nn=.801f; GLfloat radiusmm =.01f;
	int triangleAmountb = 20;
	GLfloat twicePib = 2.0f * PI;
      glBegin(GL_TRIANGLE_FAN);
	     glColor3ub(128, 0, 0 );
		glVertex2f(mm, nn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mm + (radiusmm * cos(i *  twicePib / triangleAmountb)),
			    nn + (radiusmm * sin(i * twicePib / triangleAmountb))
			);}
    glEnd();
 glBegin(GL_POLYGON);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();
     glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();
    glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();
//..........bird2.......................................
glBegin(GL_POLYGON);
 glColor3ub(128, 0, 0 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128, 0, 0 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();

     glBegin(GL_TRIANGLES);
     glColor3ub(128, 0, 0 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();
    GLfloat mmm=0.062f; GLfloat nnn=.801f; GLfloat radiusmmm =.01f;

	glBegin(GL_TRIANGLE_FAN);
	    glColor3ub(128, 0, 0 );
		glVertex2f(mmm, nnn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mmm + (radiusmmm * cos(i *  twicePib / triangleAmountb)),
			    nnn + (radiusmmm * sin(i * twicePib / triangleAmountb))
			);
		}
glEnd();
//.......bird3...........................

glBegin(GL_POLYGON);
  glColor3ub(139, 69, 19 );
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(139, 69, 19 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();
 glBegin(GL_TRIANGLES);
   // glColor3ub(242, 242, 242 );
    glColor3ub(139, 69, 19 );
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

	GLfloat mmmm=-0.638f; GLfloat nnnn=.801f;

	glBegin(GL_TRIANGLE_FAN);

	    glColor3ub(139, 69, 19 );
		glVertex2f(mmmm,nnnn); // center of circle
		for(i = 0; i <= triangleAmountb;i++) {
			glVertex2f(
		            mmmm + (radiusmmm * cos(i *  twicePib / triangleAmountb)),
			    nnnn + (radiusmmm * sin(i * twicePib / triangleAmountb))
			);
		}
	glEnd();

  glPopMatrix();


    glFlush();  // Render now
}

void display() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
//SKY
if(time==0)
{
    night(0);
}
if(time==1)
{
    morning(0);
}
if(time ==2)
{
    rain(0);
}
    glFlush();  // Render now

}
void idle()
{
    glutPostRedisplay();
}





int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(990,880);
    glutInitWindowPosition(98,30);
    glutCreateWindow("railway station");

    glutTimerFunc(100, cloud, 0);
    glutTimerFunc(100, birdd, 0);
    glutTimerFunc(100, truck, 0);
    glutTimerFunc(100, car, 0);
    glutTimerFunc(100, rain_r, 0);
    glutTimerFunc(100, updatetrain, 0);
    sound();
    glutKeyboardFunc(handleKeypress);
    glutSpecialFunc(SpecialInput);
    glutDisplayFunc(display);
    glutIdleFunc(idle);

    glutMainLoop();

    //return EXIT_SUCCESS;
}
