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
		drawFill();
	}
	drawBox(&faces[0]);

   glFlush();

}

void drawSign()
{
	/*draws the sign if the menu is clicked*/
	cout << "sign will be drawn" << endl;
}

void drawFill()
{
	/*draws the house filled*/
	cout << "filled house will be drawn" << endl;
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

