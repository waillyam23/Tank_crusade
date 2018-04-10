#include <iostream>
#include <cstdlib>
#include <time.h>

#define MAX 800-30
#define MIN 800-500

struct coord{
int x;
int y;
};

int main()
{
    coord t[10];
    t[0].x=0;
    t[0].y=800-30;
    int yint;
    for(int i=1; i<10; i++)
    {
        yint = rand()%(MAX-MIN) - (MAX-MIN)/2;
        std::cout << yint << " ";
        if(t[i].y+yint>MAX)
            yint=-1.*yint;
        if(t[i].y+yint<MIN)
            yint=-1.*yint;
        t[i].y=t[i].y+yint;
        t[i].x=t[i].x+rand() % 200+ 50;
    }
}
