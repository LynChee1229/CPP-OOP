#include<iostream>
#include<cmath>
using namespace std;

void kineticEnergy(double &energy,double &mass,double &velocity)
{
	energy = 0.5*mass*pow(velocity,2);
}

int main()
{
	double mass, velocity, energy;
	cout<<"// Call by reference using reference arguements\n\n"
	<<"Enter an object's mass and velocity as required : \n\n";
	cout<<"Mass in kilograms : ";
	cin>>mass;
	cout<<"Velocity in meters per second : ";
	cin>>velocity;
	kineticEnergy(energy,mass,velocity);
	cout<<"\n\nThe kinetic energy of this object is "<<energy<<" joules.";
	return 0;
}
