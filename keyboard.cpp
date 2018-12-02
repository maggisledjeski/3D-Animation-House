#ifndef KEYBOARD
#define KEYBOARD

#include "includes.h"
#include "prototypes.h"
#include "constants.h"

using namespace std;

void keyboard(unsigned char key, int x, int y)
{
	/*exits the program if q or Q is clicked*/
	if(key == 'q' || key == 'Q') 
	{
		exit(0);
	}
	/*stops any animation on the house*/
    if(key == 's' || key == 'S')
    {
        /*stop animation*/
		glutIdleFunc(display);
    }
	/*return house to original state*/
    if(key == 'r')
    {
        /*return house*/
    }
	/*camera moves closer to the house*/
    if(key == GLUT_KEY_PAGE_UP)
    {
        /*the pageup key is 33*/
		cout << "key code" << endl;
    }
	/*camera moves further away from the house*/
	if(key == '4' || key == '3')
    {
        /*page down key is 34*/
    }
	/*return house and camera to original position*/
    if(key == 'R')
    {
        /*return the original perspective as well*/
    }




}

#endif
