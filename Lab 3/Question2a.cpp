#include<iostream>
using namespace std;

class Cuboid{
	int length, width, height, volume; // default is private.
	public : 
		void setdata()
		{
			cout<<"\nEnter the width, length, height of a Cuboid object : ";
			cin>>width>>length>>height;
		}
		void findVolume()
		{
			volume = width*length*height;
		}
		void display()
		{
			cout<<"\n\n------Display Cuboid Data------\n";
			cout<<" Width	: "<<width<<" cm\n";
			cout<<" Length	: "<<length<<" cm\n";
			cout<<" Height	: "<<height<<" cm\n";
			cout<<" Volume	: "<<volume<<" cm^3\n";
		}
};

int main()
{
	Cuboid Q;
	Q.setdata();
	Q.findVolume();
	Q.display();
	return 0;
}
