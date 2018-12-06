#ifndef MAIN
#define MAIN

#include "includes.h"
#include "structs.h"
#include "prototypes.h"
#include "globals.h"

int main(int argc, char** argv)
{
   	glutInit(&argc, argv);
   	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
   	glutInitWindowSize(WINDOW_HEIGHT, WINDOW_WIDTH); 
   	glutInitWindowPosition(100, 100);
   	glutCreateWindow(argv[0]);
   	init();
	createMenu();
   	glutMouseFunc(mouse);
	glutSpecialFunc(processSpecialKeys);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display); 
   	glutReshapeFunc(reshape);	
	glutIdleFunc(spinDisplay);
	glutMainLoop();
   	return 0;
}

#endif

