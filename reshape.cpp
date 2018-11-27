#ifndef RESHAPE
#define RESHAPE

#include <math.h>
#include "includes.h"

void reshape (int w, int h)
{
 
   float l, r, b, t, n, f;
   l = -1.5; r = 1.5;   // l=left, r=right
   b = -1.0; t = 1.0;   // b=bottom, t=top
   n =  2.0; f = 8.0;   // n=near, f=far  

   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   glFrustum ( l, r, b, t, n, f);
   glMatrixMode (GL_MODELVIEW);
}

#endif

