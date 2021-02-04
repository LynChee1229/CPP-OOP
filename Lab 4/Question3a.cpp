#include<iostream>
#include<cstring>
using namespace std;

class Increment{
	private : 
		char name[30], rating;
		float Sc_point;
	public : 
		char* set_name(){
			cout<<"Enter Name	: ";
			cin.getline(name,30);
			return name;
		}
		float set_Sc_Point(){
			cout<<"Score Point	: ";
			cin>>Sc_point;
			if(Sc_point<0 || Sc_point>4){
				cout<<"Re-enter Score Point	: ";
				cin>>Sc_point;
			}
			return Sc_point;
		}
		char set_rating(){
			if(Sc_point>=3 && Sc_point<=4)
				rating = 'A';
			else if(Sc_point>=2 && Sc_point<3)
				rating = 'B';
			else if(Sc_point>=0 && Sc_point<2)
				rating = 'F';
			return rating;
		}
};

int main()
{
	Increment M;
	char name[30], rating;	float Sc_point;
	cout<<"===================================\n"
	<<"\t   AGENT INFORMATION\n===================================\n";
	strcpy(name,M.set_name());
	Sc_point = M.set_Sc_Point();
	rating = M.set_rating();
	cout<<"\n===================================\n"
	<<"\t   INCREMENT SLIP\n===================================\n"
	<<"Name		: "<<name<<endl
	<<"Point Awarded	: "<<Sc_point<<endl
	<<"Rating		: "<<rating;
	return 0;
}
