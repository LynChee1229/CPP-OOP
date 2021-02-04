#include<iostream>
#include<cmath>
using namespace std;

double kineticEnergy(double mass,double velocity)
{
	double energy;
	energy = 0.5*mass*pow(velocity,2);
	return energy;
}

int main()
{
	double mass, velocity, energy;
	cout<<"// Call by value\n\n"
	<<"Enter an object's mass and velocity as required : \n\n";
	cout<<"Mass in kilograms : ";
	cin>>mass;
	cout<<"Velocity in meters per second : ";
	cin>>velocity;
	energy = kineticEnergy(mass,velocity);
	cout<<"\n\nThe kinetic energy of this object is "<<energy<<" joules.";
	return 0;
}
