#ifndef GLOBALS
#define GLOBALS

// use extern here -- then we include this header in each code piece that
// // needs access to the variables.   Declare the actual variables in exactly
// // one location. In the case of constants, make a specific header where you define 
// // them and include it before main.c
//
int WINDOW_HEIGHT = 600;
int WINDOW_WIDTH = 600;
int DRAWAXIS = 0;
int DRAWP = 0;
int DRAWSIGN = 0;	
int DRAWFILL = 0;
float spinX = 0.0;
float spinY = 0.0;
float spinZ = 0.0;
float deltaSpinX = 0.0;
float deltaSpinY = 0.0;
float deltaSpinZ = 0.0;


#endif

