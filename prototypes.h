#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void drawAxes(int );
void defineBox( struct box* );
void drawBox( struct box* );
void display(void);
void reshape (int , int );
void menuAction(int msg);
void onAxis(int msg);
void onPerspective(int msg);
void drawSign(void);
void onSign(int msg);
void onFill(int msg);
void drawFill(void);
void keyboard(unsigned char key, int x, int y);
void createMenu(void);
#endif

