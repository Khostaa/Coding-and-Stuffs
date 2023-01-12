#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>

void main()
{
    int gd=DETECT,gm,x1,y1,x2,y2,lx,ly,dy,dx,pk,i;
    initgraph(&gd,&gm,(char*)"");
    printf("put the values of x1 and y1\n");
    scanf("%d %d",&x1,&x2);
    printf("put the values of x2 and y2\n");
    scanf("%d%d",&x2,&y2);
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    if(x2 > x1)
    {
        lx = 1;
        
    }
}