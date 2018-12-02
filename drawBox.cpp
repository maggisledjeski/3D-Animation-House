#ifndef DRAWBOX
#define DRAWBOX

#include "includes.h"
#include "structs.h"

void drawBox( struct box *face )
{
    int i, j;

    //glPolygonMode(GL_FRONT, GL_FILL);
    //glPolygonMode(GL_BACK, GL_FILL);

    glPushMatrix();

    for(j=0;j<7;j++)
    {

        glColor3f(face[j].color.red,
                  face[j].color.green,
                  face[j].color.blue);

        glBegin(GL_LINE_LOOP);//POLYGON);
        for (i=0;i<5;i++)
        {
            glVertex3f(face[j].point[i].x,
                       face[j].point[i].y,
                       face[j].point[i].z);
        }
        glEnd();
    }

    glColor3ub(200,10,100);
    glTranslatef(0.0,0.0,0.0);
    
    glPopMatrix();
}

#endif

