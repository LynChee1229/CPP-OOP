#include<iostream>
#include<cmath>
using namespace std;

class Triangle{
	protected : 
		int a, b, c;
		
	public :
		Triangle(){
			cout<<"-----------Triangle Class----------\n";
		}
		
		void setData(int sideA,int sideB){
			a = sideA;
			b = sideB;
		}
};

class PythogorasTriangle:public Triangle{
	public : 
		PythogorasTriangle(){
			cout<<"--------Pythogoras Triangle--------\n";
		}
		
		void calcHypotenuse(){
			c = sqrt( pow(a,2) + pow(b,2) );
		}
		
		void displaySides(){
			cout<<"\n::The sides of a pythogoras triangle::\n"
			<<"a : "<<a<<endl
			<<"b : "<<b<<endl
			<<"c : "<<c<<" (also known as the Hypotenuse)"<<endl;
		}
};


int main(){
	char ans;
	
	do{
	PythogorasTriangle *ptr = new PythogorasTriangle;
	int sideA, sideB;
	
	cout<<"Enter a : ";
	cin>>sideA;
	cout<<"Enter b : ";
	cin>>sideB;
	ptr->setData(sideA,sideB);
	
	ptr->calcHypotenuse();
	(*ptr).displaySides();
	
	cout<<"\nDo you want to continue [Y/N] : ";
	cin>>ans;
	cout<<endl;
	
	delete ptr;
	
	}while(ans=='Y'||ans=='y');
	return 0;
}
