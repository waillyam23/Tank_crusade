#include <iostream>
#include <cmath>

using namespace std;

 void round(float x, float y, float v, float angle)
    {
        float bullet[700][700][700][700];

	int i=0;
	
      	float vx;
      	float vy;
	
     
      while(y>=0)
	{
	  vx = cos(angle)*v;
	  vy = sin(angle)*v;

	  x += vx;
	  y += (vy-9.81);

	  v = sqrt(pow(vx,2)+pow((vy-9.81),2));
	  angle = atan2f((vy-9.81),vx);
	  bullet[i][0][0][0]=x;
	  bullet[0][i][0][0]=y;
	  bullet[0][0][i][0]=v;
	  bullet[0][0][0][i]=a;
	  
	  i=i+1;
	  
	}
	 i=0;
    }

int main()
{
  float x;
  float y;
  float v;
  float angle;
  
  std::cin>>x;
  std::cin>>y;
  std::cin>>v;
  std::cin>>angle;
  round(x,y,v,angle);


  return 0;
}
