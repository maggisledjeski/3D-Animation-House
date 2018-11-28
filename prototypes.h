#ifndef PROTOTYPES
#define PROTOTYPES

#include "structs.h"

void init(void);
void drawAxes(int );
void defineBox( struct box* );
void drawBox( struct box* );
void display(void);
void reshape (int , int );
void doNothing(int msg);
void onAxis(int msg);

#endif

