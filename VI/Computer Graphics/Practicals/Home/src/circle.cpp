#include <iostream>
#include <graphics.h>

using namespace std;

int main(int argc, char const *argv[])
{
    int gm, gd = DETECT;
    char data[] = "C:\\MinGW\\lib\\libbgi.a";
    initgraph(&gd, &gm, data);
    cleardevice();
    setcolor(4);
    circle(100,120,50);
    // floodfill(90, 130, 10);
    cin.ignore();
    closegraph();
    return 0;
}
