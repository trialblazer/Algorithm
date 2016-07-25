#include<iostream>
#include<math.h>

using namespace std;

float edge(float a, float b, float c, float d);
float f(float a, float b, float c);

int main()
{
	float x1, x2, x3, y1, y2, y3;
	cin>>x1>>x2>>x3;
	cin>>y1>>y2>>y3;
	float L1=edge(x1, y1, x2, y2);
	float L2=edge(x2, y2, x3, y3);
	float L3=edge(x3, y3, x1, y1);
	cout<<"Area="<<f(L1, L2, L3)<<endl;
	return 0;
}

float edge(float a, float b, float c, float d)
{
	float l=(c-a)*(c-a)+(d-b)*(d-b);
	return sqrt(l);
}

float f(float a, float b, float c)
{
	float s=(a+b+c)/2;
	float area=sqrt(s*(s-a)*(s-b)*(s-c));
	return area;
}





