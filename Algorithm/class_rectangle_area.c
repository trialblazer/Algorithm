#include<iostream>
#include<math.h>

using namespace std;

class Area
{
public:
	float edge();
	void setdata(float x1, float x2, float x3, float y1, float y2, float y3);
private:
	float a, b, c, d, e, f;
};


float Area::edge()
{
	float L1=sqrt((c-a)*(c-a)+(d-b)*(d-b));
	float L2=sqrt((c-b)*(c-b)+(f-e)*(f-e));
	float L3=sqrt((b-a)*(b-a)+(e-d)*(e-d));
	float s=(L1+L2+L3)/2;
	float area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
	return area;
}

void Area::setdata(float x1, float x2, float x3, float y1, float y2, float y3)
{
	a=x1;
	b=x2;
	c=x3;
	d=y1;
	e=y2;
	f=y3;
}

int main()
{
	Area area;
	area.setdata(0,0,2,0,3,0);
	float Area=area.edge();
	cout<<"area=   "<<Area<<endl;
	return 0;
}

