#ifndef DRAW_AXES
#define DRAW_AXES

#include "includes.h" 

void drawAxes(int length)
{   

	int i, len;

	/*set up character arrays for axis labels*/
	char xaxis[] = "X";
    char yaxis[] = "Y";
    char zaxis[] = "Z";
	
	/*font*/
	void *font = GLUT_STROKE_ROMAN;

	/*This provides a coordinate axis about the origin. */
   	glPointSize(1.0);
   	glBegin(GL_LINES);
    glVertex3i(0,length,0);
    glVertex3i(0,-length,0);
   	glEnd();
   	glBegin(GL_LINES);
    glVertex3i(length,0,0);
    glVertex3i(-length,0,0);
   	glEnd();
   	glBegin(GL_LINES);
    glVertex3i(0,0,length);
    glVertex3i(0,0,-length);
   	glEnd();

	/*add the lettering to the axis*/
	/*Z*/
	glPushMatrix();
    glTranslatef(-0.2, 0.2, 2.75);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(zaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, zaxis[i]);
    }
    glPopMatrix();

	/*Y*/
	glPushMatrix();
    glTranslatef(0.0, 4, -.4);
    glRotatef(90.0, 0.0, 0.0, 1.0);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(yaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, yaxis[i]);
    }
    glPopMatrix();

	/*X*/
	glPushMatrix();
    glTranslatef(4.0, 0.0, -.4);
    glRotatef(120.0, 0.0, 0.0, 1.0);
    glRotatef(70.0, 0.0, 1.0, 0.0);
    glScalef(0.002,0.002,0.002);
    len = (int) strlen(xaxis);
    for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, xaxis[i]);
    }
    glPopMatrix();

}

void onAxis(int msg)
{
    extern int DRAWAXIS;
	switch (msg) {
        case 1:
            DRAWAXIS = 1;
            break;
        case 2:
            DRAWAXIS = 0;
            break;
    }
    glutPostRedisplay();
}

#endif

