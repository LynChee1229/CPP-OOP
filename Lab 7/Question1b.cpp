#include<iostream>
using namespace std;

class Bags{
	string brand;
	float length, width, height;
	
	public : 
		void setdata(){
			cout<<"\nEnter your bag's brand name : ";
			getline(cin,brand);
			cout<<"\nEnter value length, width and height of your bag L,W,H : ";
			cin>>length>>width>>height;
			cin.ignore();
		}
	
		void display(){
			cout<<"\nYour brand bag name is **"<<brand<<"** and the dimensions are : "
			<<length<<"L  "<<width<<"W  "<<height<<"H  "<<endl;
		}
	
		Bags(const Bags &Bi){
			brand = Bi.brand;
			length = Bi.length;
			width = Bi.width;
			height = Bi.height;
			cout<<"\nDo you have the same bag??"<<endl;
		}
	
		Bags(){
			brand = "Adidas";
			length = 35;
			width = 20;
			height = 45;
		}
	
		friend void check(Bags A,Bags B,Bags C);
};

void check(Bags A,Bags B,Bags C)
{
	if(A.height==B.height && B.height == C.height)
		cout<<"\n -- Common height for all 3 bags --";
	else
		cout<<"\n -- Not all bags have the same heights --";
}

int main()
{
	Bags B[3];
	for(int i=0;i<3;i++){
		B[i].setdata();
	}
	check(B[0],B[1],B[2]);
	return 0;
}
