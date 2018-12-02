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

}

void drawSign()
{
	/*draws the sign if the menu is clicked*/
	cout << "sign will be drawn" << endl;
}

void drawFill(struct box *face)
{
	/*draws the house filled*/
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
#endif

