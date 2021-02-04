#include <iostream>
#include <cmath>		// needed for 'pow( )'
using namespace std;
const double PI = 3.14159;
double area(double radius); // function prototype

int main( )
{   
	double radius, area_of_circle, volume_of_sphere;
    cout<<"Enter a radius of a circle : ";
    cin>>radius;

    area_of_circle = area(radius);
    cout<<"\nRadius = "<<radius<<" inches\n\n"
	<<"Area of circle = "<<area_of_circle<<" square inches\n";
    return 0;
}

double area(double radius)
{
	double area;
	area = PI*pow(radius,2);
	return area;
}
