#include <iostream>
#include <cstdlib>


#define MAX 400
#define MIN 30
#define LMAX 100000




int main()
{
  float y=10; //10/20
  float yint;
  int x=0;


  while(x <= LMAX)
    {
      yint= static_cast <float> (rand())/static_cast <float> (RAND_MAX/2) -1;
      if(y+yint>MAX)
	yint=-1.*yint;
      if(y+yint<MIN)
	yint=-1.*yint;
      y=y+yint;
      std::cout<<"x : "<<x<<" "<<"y : "<<y<<std::endl;
      x+=rand() % 100 + 30;
    }


  return 0;
}

