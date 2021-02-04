#include<iostream>
#include<iomanip>
using namespace std;

class CarProduction{
	int quantity;
	string plantno;
	public : 
		void setData(string s, int q){
			plantno = s;
			quantity = q;
		}
		// b. display_graph() function
		void display_graph(void){
			int asterisk, hash;
			cout<<"====================================\n"
			<<" "<<plantno<<endl;
			
			asterisk = quantity/2;
			for(int x=0; x<asterisk;x++)
				cout<<" * ";
				
			hash = quantity%2;			// result will be 0 or 1 only.
			for(int x=0; x<hash;x++)
				cout<<" # ";			// will display when hash = 1;
			cout<<endl;
		}
};

int main()
{
	// a. declare an array named C of 4 object elements of CarProduction class
	CarProduction C[4];
	
	string s;	int qty;
	for(int i=0;i<4;i++){
		cout<<" Enter the plant no#		  	   : ";
		cin>>s;
		cout<<" Enter the amount of cars produced today   : ";
		cin>>qty;
		cout<<endl;
		C[i].setData(s,qty);
	}
	cout<<"\n     Daily Productivity Report"<<endl;
	for(int i=0;i<4;i++)
		C[i].display_graph();
	return 0;
}
