#ifndef DISPLAY
#define DISPLAY

#include <stdio.h>
#include "includes.h"
#include "structs.h"

#include "prototypes.h"

void display(void)
{

   struct box faces[6];
   
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

   drawAxes(5);
   drawBox(&faces[0]);

   glFlush();

}

#endif

