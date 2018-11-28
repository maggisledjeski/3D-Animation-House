#ifndef MAIN
#define MAIN

#include "includes.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"
#include "constants.h"


int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DEPTH | GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (WINDOW_HEIGHT, WINDOW_WIDTH); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   
/*menu stuff goes here*/
	/*axis menu*/
	int axis = glutCreateMenu(onAxis);
    glutAddMenuEntry("On", 1);
    glutAddMenuEntry("Off", 2);

	/*create menu*/
	int menu = glutCreateMenu(doNothing);
    glutAddSubMenu("Axes", axis);
    //glutAddSubMenu("Sphere", sphere);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);
	
	glutMainLoop();
   return 0;
}
void doNothing(int msg)
{
}

#endif

