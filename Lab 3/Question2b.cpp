#include<iostream>
using namespace std;

class Cuboid{
	int length, width, height, volume; // default is private.
	public : 
		void setdata(){
			cout<<"\nEnter the width, length, height of a Cuboid object : ";
			cin>>width>>length>>height;
		}
		void findVolume(){
			volume = width*length*height;
		}
		// accessor functions
		int getWidth(){
			return width;
		}
		int getLength(){
			return length;
		}
		int getHeight(){
			return height;
		}
		int getVolume(){
			return volume;
		}
};

int main()
{
	Cuboid Q;
	Q.setdata();
	Q.findVolume();
	cout<<"\n\n------Display Cuboid Data------\n";
	cout<<" Width	: "<<Q.getWidth()<<" cm\n";
	cout<<" Length	: "<<Q.getLength()<<" cm\n";
	cout<<" Height	: "<<Q.getHeight()<<" cm\n";
	cout<<" Volume	: "<<Q.getVolume()<<" cm^3\n";
	return 0;
}
