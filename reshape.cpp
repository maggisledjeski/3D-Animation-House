#ifndef RESHAPE
#define RESHAPE

#include <math.h>
#include "includes.h"

void reshape (int w, int h)
{
	
	const GLdouble PI = 3.1415926535897932384626433832795028841971693993;
    GLdouble theta, aspectRatio;
 
   float l, r, b, t, n, f;
   l = -1.5; r = 1.5;   // l=left, r=right
   b = -1.0; t = 1.0;   // b=bottom, t=top
   n =  2.0; f = 10.0;   // n=near, f=far  

   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
//   glFrustum ( l, r, b, t, n, f);
   	aspectRatio = (r - l)/(t - b);
    theta = atan((t/fabs(n)))*2;
    theta = theta *(180/PI);
    gluPerspective(theta, aspectRatio, n, f);
	glMatrixMode (GL_MODELVIEW);
}

#endif

