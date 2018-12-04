#ifndef DISPLAY
#define DISPLAY

#include <stdio.h>
#include "includes.h"
#include "structs.h"
//#include "globals.h"
#include "prototypes.h"

void display(void)
{
	extern int DRAWAXIS;
	extern int DRAWSIGN;
	extern int DRAWFILL;
   struct box faces[7];
	extern float spinX, spinY, spinZ;   


   float *M;
   int i, j;
   

   defineBox(&faces[0]);

   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 1.0, 1.0);

   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();             /* clear the matrix */

	gluLookAt (4.0, 4.0, 4.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

   /* Draw a coordinate axis */
	glEnable(GL_DEPTH_TEST);
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glRotatef(spinX, 1.0, 0.0, 0.0);
	glRotatef(spinY, 0.0, 1.0, 0.0);
	glRotatef(spinZ, 0.0, 0.0, 1.0);
   /*draw menu items*/
	if(DRAWAXIS)
	{
		 drawAxes(5);
	}
	if(DRAWSIGN)
	{
		drawSign();
	}	
   	if(DRAWFILL)
	{
		drawFill(&faces[0]);
	} else
	{
		drawBox(&faces[0]);
	}

    glFlush();
	glutSwapBuffers();
}
		
void drawSign()
{
	/*draws the sign if the menu is clicked*/
	char charString[] = "Hello World!";
	void *font = GLUT_STROKE_ROMAN;

	/*add the lettering to the sign*/
	glPushMatrix();
    glTranslatef(1.0, 1.0, 1.0);
    glRotatef(180.0, 0.0, 0.0, 1.0);
    glRotatef(45.0, 1.0, 0.0, 0.0);
	glScalef(0.002,0.002,0.002);
    int len = (int) strlen(charString);
    int i;
	for (i = 0; i < len; i++) {
        glutStrokeCharacter(font, charString[i]);
    }
    glPopMatrix();

}

void drawFill(struct box *face)
{
	/*draws the house filled*/
	extern float spinX;
    extern float spinY;
    extern float spinZ;
    	
	int i, j;

    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();

    for(j=0;j<7;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_POLYGON);
        for (i=0;i<5;i++)
        {
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
        }
        glEnd();
    }

    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,0.0);

    glPopMatrix();

}

void onSign(int msg)
{
	extern int DRAWSIGN;
	switch (msg) {
        case 1:
            DRAWSIGN = 1;
            break;
        case 2:
            DRAWSIGN = 0;
            break;
    }
    glutPostRedisplay();
}

void spinDisplay(void)
{
	extern float spinX;
	extern float spinY;
	extern float spinZ;
	extern float deltaSpinX;
	extern float deltaSpinY;
	extern float deltaSpinZ;

	spinX = spinX + deltaSpinX;
	if(spinX > 360.0)
	{
		spinX = spinX - 360.0;
	}
	spinY = spinY + deltaSpinY;
    if(spinY > 360.0)
    {
        spinY = spinY - 360.0;
    }
	spinZ = spinZ + deltaSpinZ;
    if(spinZ > 360.0)
    {
        spinZ = spinZ - 360.0;
    }

	glutPostRedisplay();
}

#endif

