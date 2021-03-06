#ifndef RESHAPE
#define RESHAPE

#include <math.h>
#include "includes.h"
using namespace std;
void reshape (int w, int h)
{
	extern int WINDOW_HEIGHT;
	extern int WINDOW_WIDTH;
	extern int DRAWP;
	const GLdouble PI = 3.1415926535897932384626433832795028841971693993;
    GLdouble theta, aspectRatio;
 
   float l, r, b, t, n, f;
   l = -1.5; r = 1.5;   // l=left, r=right
   b = -1.0; t = 1.0;   // b=bottom, t=top
   n =  1.0; f = 20.0;  // n=near, f=far  
	
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
	if(DRAWP == 1)
	{
		glFrustum ( l, r, b, t, n, f);
   	
	} else if(DRAWP == 2)
	{
		aspectRatio = (r - l)/(t - b);
    	theta = atan((t/fabs(n)))*2;
    	theta = theta *(180/PI);
    	gluPerspective(theta, aspectRatio, n, f);
		
	} else if(DRAWP == 3)
	{
		glOrtho(l, r, b, t, n, f);
		
	} else if(DRAWP == 4)
	{
		/*custom input*/
	}
	glMatrixMode (GL_MODELVIEW);
}

void onPerspective(int msg)
{
    extern int DRAWP;
    switch (msg) {
        case 1:
            DRAWP = 1;
            break;
        case 2:
            DRAWP = 2;
            break;
		case 3:
			DRAWP = 3;
			break;
		case 4:
			DRAWP = 4;
			break;
	
    }
    glutPostRedisplay();
}

#endif

