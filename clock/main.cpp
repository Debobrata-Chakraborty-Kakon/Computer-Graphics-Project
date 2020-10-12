#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>

# define PI           3.14159265358979323846
GLfloat ii=0;

GLfloat i2=0;
GLfloat i3=0;

void display()
{

    glClearColor(1.0f, 1.0f, 1.0f, 1.1f);
    glClear(GL_COLOR_BUFFER_BIT);

    int i;

    GLfloat x=.0f; GLfloat y=.0f; GLfloat radius =.5f;
	int triangleAmount = 20; //# of triangles used to draw circle
    GLfloat twicePi = 2.0f * PI;
	//GLfloat radius = 0.8f; //radius

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(203,206,252);
		glVertex2f(x,y); // center of circle
		for(i = 0; i <= triangleAmount;i++) {  // clock
			glVertex2f(
		            x + (radius * cos(i *  twicePi / triangleAmount)),
			    y + (radius* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    GLfloat x2=.0f; GLfloat y2=.0f; GLfloat radius2 =.02f;

        glBegin(GL_TRIANGLE_FAN);
        glColor3ub(0,0,0);
		glVertex2f(x2,y2); // center of circle
		for(i = 0; i <= triangleAmount;i++) {  // clock
			glVertex2f(
		            x2 + (radius2* cos(i *  twicePi / triangleAmount)),
			    y2 + (radius2* sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();


    GLfloat x1=.0f; GLfloat y1=.0f; GLfloat radius1 =.5f;

	int lineAmount = 100; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius


	glBegin(GL_LINE_LOOP);
	glColor3ub(0,0,0);
		for(i = 0; i <= lineAmount;i++) {                       //clock border
			glVertex2f(
			    x1 + (radius1 * cos(i *  twicePi / lineAmount)),
			    y1 + (radius1* sin(i * twicePi / lineAmount))
			);
		}
	glEnd();

    glBegin(GL_LINES);
    glVertex2f(.5,0);
    glVertex2f(.4,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.5,.015);
    glVertex2f(.4,.015);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.5,-.015);
    glVertex2f(.4,-.015);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.5,0);
    glVertex2f(-.4,0);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.5,.01);
    glVertex2f(-.4,.03);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.4,.01);
    glVertex2f(-.5,.03);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(0,.5);
    glVertex2f(0,.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.02,.5);
    glVertex2f(-.02,.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.02,.5);
    glVertex2f(.04,.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(.04,.5);
    glVertex2f(.02,.4);
    glEnd();


    glBegin(GL_LINES);
    glVertex2f(.0,-.5);
    glVertex2f(.0,-.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.04,-.5);
    glVertex2f(.0,-.4);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-.04,-.5);
    glVertex2f(-.06,-.4);
    glEnd();

    glPushMatrix();

    glRotatef(ii,0,0,-1);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0,0);
    glVertex2f(.02,0);
    glVertex2f(.02,.2);
    glVertex2f(0,.2);
    glEnd();
    glPopMatrix();
    ii+=.01;
    glLoadIdentity();

    glPushMatrix();
    glRotatef(i2,0,0,-1);
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(0,0);
    glVertex2f(.3,0);
    glVertex2f(.3,.01);
    glVertex2f(0,.02);
    glEnd();
    glPopMatrix();
    i2+=.03;
    glLoadIdentity();


    glPushMatrix();
    glRotatef(i3,0,0,-1);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0,0);
    glVertex2f(.3,.3);
    glEnd();
    glPopMatrix();
    i3+=.08;
    glFlush();


}

void Idle()
{
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);                 // Initialize GLUT
    glutCreateWindow("CLOCK"); // Create a window with the given title
    glutInitWindowSize(800, 450);   // Set the window's initial width & height
    glutDisplayFunc(display); // Register display callback handler for window re-paint
    glutIdleFunc(Idle);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}
