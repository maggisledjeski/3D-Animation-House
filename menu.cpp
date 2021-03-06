#ifndef MENU
#define MENU

#include "includes.h"
#include "prototypes.h"

void createMenu()
{
    /*menu stuff goes here*/
    /*axes submenu*/
    int axis = glutCreateMenu(onAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    /*perspective submenu*/
    int perspective = glutCreateMenu(onPerspective);
    glutAddMenuEntry("glFrustum", 1);
	glutAddMenuEntry("gluPerspective", 2);
    glutAddMenuEntry("glOrtho", 3);
    glutAddMenuEntry("custom", 4);

    /*sign submenu*/
    int sign = glutCreateMenu(onSign);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    /*fill submenu*/
    int fill = glutCreateMenu(onFill);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

    /*create menu*/
    int menu = glutCreateMenu(menuAction);
    glutAddSubMenu("Perspective", perspective);
    glutAddMenuEntry("Revert to Original", 1);
    glutAddSubMenu("Fill in House", fill);
    glutAddSubMenu("Axes", axis);
    glutAddSubMenu("Sign", sign);
    glutAddMenuEntry("Exit", 0);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
}

void menuAction(int msg)
{
    extern int DRAWAXIS;
    extern int DRAWP;
    extern int DRAWSIGN;
    extern int DRAWFILL;
    extern float zoom;
	extern float spinX;
	extern float spinY;
	extern float spinZ;
	extern float deltaSpinX;
	extern float deltaSpinY;
	extern float deltaSpinZ;

	/*exits the program*/
    if(msg == 0)
    {
        exit(0);
    }
    /*reverts to original house and camera*/
    if(msg == 1)
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
		zoom = 4.0;
    }
}

void onFill(int msg)
{
    extern int DRAWFILL;
	switch (msg) {
        case 1:
            DRAWFILL = 1;
            break;
        case 2:
            DRAWFILL = 0;
            break;
    }
    glutPostRedisplay();
}

#endif
