#include <graphics.h>
int main(int argc,char const *argv[])
{
    int gd=DETECT,gm;
    initgraph(&gd,&gm,(char*)"");
    line(40,100,400,200);
    getch();
    closegraph();
    return 0;
}