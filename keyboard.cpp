#ifndef KEYBOARD
#define KEYBOARD

#include "includes.h"
#include "prototypes.h"
#include "constants.h"

void mouse(int button, int state, int x, int y)
{
	extern float spinX;
    extern float spinY;
    extern float spinZ;
	extern float deltaSpinX;
	extern float deltaSpinY;
	extern float deltaSpinZ;
	extern int WINDOW_HEIGHT;
	extern int WINDOW_WIDTH;
	int newy;
    int y2 = WINDOW_HEIGHT - y; 
	
	switch (button) {
        case GLUT_RIGHT_BUTTON:
            if (state == GLUT_DOWN)
            { 
                /*to find the center point of the screen*/
				int centerx = WINDOW_WIDTH/2;//HEIGHT/2;
				int centery = WINDOW_HEIGHT/2;//WIDTH/2;
				/*find the slope of the line in quadrant 4*/
				float m1 = ((centery - 0)/(centerx - 0));
				/*substitute centerx and centery for y=mx+b, to solve for b*/
				int b1 = centery - (m1 * centerx);	
				/*slope for line in quadrant 3*/
				float m2 = ((centery - 0)/(centerx - WINDOW_WIDTH));
				/*substitute centerx and centery for y=mx+b, to solve for b*/
                int b2 = centery - (m2 * centerx);
				/*quadrant 1 -- rotate about Y*/
				if((x < WINDOW_HEIGHT) && (y2 > centery) && (x < centerx))
                {
                    //cout << "Quad 1: " <<x << "   " << y2 << endl;
					deltaSpinY = deltaSpinY + 1.0;
					//cout << "spinY: " << spinY << "   " << "deltaSpinY: " << deltaSpinY << endl;
					
				}/*quadrant 2 -- rotate about X*/ 
				else if((x < WINDOW_HEIGHT) && (y2 > centery) && (x > centerx))
                {
                    //cout << "Quad 2: " << x << "   " << y2 << endl;
					deltaSpinX = deltaSpinX + 1.0;
					
				}/*quadrant 3 -- need to split into Z and X*/
				else if((x < WINDOW_HEIGHT) && (y2 < centery) && (x > centerx))
                {
                    /*now we know the equation of the line -- can compare the x and y values to see if the point is on, below, or above the line*/
					/*find y on line that corresponds to the x value from the click*/
                    newy = (m2 * x) + b2;
                    if(newy < y2) 
                    {
                        /*rotate about X*/
						//cout << "Quad 3 about X: " << x << "   " << y2 << endl;
						deltaSpinX = deltaSpinX + 1.0;
						
                    }
                    else if(newy >= y2)
                    {
                        /*rotate about Z*/
						//cout << "Quad 3 about Z: " << x << "   " << y2 << endl;
						deltaSpinZ = deltaSpinZ + 1.0;
						
                    }
                }/*quadrant 4 -- need to split into Z and Y*/ 
				else if((x < WINDOW_HEIGHT) && (y2 < centery) && (x < centerx))
                {
                    /*find y on line that corresponds to the x value from the click*/
					newy = (m1 * x) + b1;
					if(newy < y2)
					{
						/*rotate about Y*/
						//cout << "Quad 4 about Y: " << x << "   " << y2 << endl;
						deltaSpinY = deltaSpinY + 1.0;
						
					}
					else if(newy >= y2)
					{
						/*rotate about Z*/
						//cout << "Quad 4 about Z: " << x << "   " << y2 << endl;
						deltaSpinZ = deltaSpinZ + 1.0;
						
					}
                }   				
			}
			break;
		case GLUT_LEFT_BUTTON:
            if (state == GLUT_DOWN)
            {
                /*to find the center point of the screen*/
                int centerx = WINDOW_WIDTH/2;//HEIGHT/2;
                int centery = WINDOW_HEIGHT/2;//WIDTH/2;
                /*find the slope of the line in quadrant 4*/
                float m1 = ((centery - 0)/(centerx - 0));
                /*substitute centerx and centery for y=mx+b, to solve for b*/
                int b1 = centery - (m1 * centerx);
                /*slope for line in quadrant 3*/
                float m2 = ((centery - 0)/(centerx - WINDOW_WIDTH));
                /*substitute centerx and centery for y=mx+b, to solve for b*/
                int b2 = centery - (m2 * centerx);
                /*quadrant 1 -- rotate about Y*/
                if((x < WINDOW_HEIGHT) && (y2 > centery) && (x < centerx))
                {
                    deltaSpinY = deltaSpinY - 1.0;
                    
										
                }/*quadrant 2 -- rotate about X*/
                else if((x < WINDOW_HEIGHT) && (y2 > centery) && (x > centerx))
                {
                    //cout << "Quad 2: " << x << "   " << y2 << endl;
                    deltaSpinX = deltaSpinX - 1.0;
                    
                }/*quadrant 3 -- need to split into Z and X*/
				else if((x < WINDOW_HEIGHT) && (y2 < centery) && (x > centerx))
                {
                    /*now we know the equation of the line -- can compare the x and y values to see if the point is on, below, or above the line*/
                    /*find y on line that corresponds to the x value from the click*/
                    newy = (m2 * x) + b2;
                    if(newy < y2)
                    {
                        /*rotate about X*/
                        //cout << "Quad 3 about X: " << x << "   " << y2 << endl;
                        deltaSpinX = deltaSpinX - 1.0;
                        
                    }
                    else if(newy >= y2)
                    {
                        /*rotate about Z*/
                        //cout << "Quad 3 about Z: " << x << "   " << y2 << endl;
                        deltaSpinZ = deltaSpinZ - 1.0;
                        
                    }
                }/*quadrant 4 -- need to split into Z and Y*/
                else if((x < WINDOW_HEIGHT) && (y2 < centery) && (x < centerx))
                {
                    /*find y on line that corresponds to the x value from the click*/
                    newy = (m1 * x) + b1;
                    if(newy < y2)
                    {
                        /*rotate about Y*/
                        //cout << "Quad 4 about Y: " << x << "   " << y2 << endl;
                        deltaSpinY = deltaSpinY - 1.0;
                        
                    }
                    else if(newy >= y2)
                    {
                        /*rotate about Z*/
                        //cout << "Quad 4 about Z: " << x << "   " << y2 << endl;
                        deltaSpinZ = deltaSpinZ - 1.0;
                        
                    }
                }

			}
	}
}

void keyboard(unsigned char key, int x, int y)
{
	extern float spinX;
    extern float spinY;
    extern float spinZ;
    extern float deltaSpinX;
    extern float deltaSpinY;
    extern float deltaSpinZ;
	extern int DRAWAXIS;
    extern int DRAWP;
    extern int DRAWSIGN;
    extern int DRAWFILL;
	extern float zoom;

	/*exits the program if q or Q is clicked*/
	if(key == 'q' || key == 'Q') 
	{
		exit(0);
	}
	/*stops any animation on the house*/
    if(key == 's' || key == 'S')
    {
        /*stop animation*/
    	deltaSpinX = 0.0;
    	deltaSpinY = 0.0;
    	deltaSpinZ = 0.0;
		
    }
	/*return house to original state*/
    if(key == 'r')
    {
        DRAWAXIS = 0;
        DRAWP = 0;
        DRAWSIGN = 0;
        DRAWFILL = 0;
		spinX = 0.0;
        spinY = 0.0;
        spinZ = 0.0;
		deltaSpinX = 0.0;
        deltaSpinY = 0.0;
        deltaSpinZ = 0.0;		
    }
	/*return house and camera to original position*/
    if(key == 'R')
    {
        /*return the original perspective as well*/
		cout << "R" << endl;
		DRAWAXIS = 0;
        DRAWP = 0;
        DRAWSIGN = 0;
        DRAWFILL = 0;
		spinX = 0.0;
        spinY = 0.0;
        spinZ = 0.0;
        deltaSpinX = 0.0;
        deltaSpinY = 0.0;
        deltaSpinZ = 0.0;
		zoom = 4.0;
    }

}

/*how to process the special keys*/
void processSpecialKeys(int key, int x, int y) 
{
	extern float zoom;

	switch(key) {
		/*camera moves closer to the house*/
		case GLUT_KEY_PAGE_UP :
				zoom = zoom - 1.0;
				break;
		/*camera moves further away from the house*/
		case GLUT_KEY_PAGE_DOWN :
				zoom = zoom + 1.0;
				break;
	}
}
#endif
