#include<iostream>
#include<iomanip>
using namespace std;

class ICE_CREAM{
	private : 
		string flavour;
		int number;
		float price;
		
	public : 
		void menu();
		void setFlavour();
		void setHowMany();
		friend void display_receipt(ICE_CREAM &);
		ICE_CREAM();
};

void ICE_CREAM::menu()
{
	cout<<"\n===========================================\n"
	<<"===\t\tCHOOSE FLAVOUR\t\t===\n===========================================\n"
	<<"[1] === Strawberry Flavour   RM 3.50\n"
	<<"[2] === Chocolate Flavour    RM 2.50\n"
	<<"[3] === Vanilla Flavour      RM 1.50\n"
	<<"[4] === Durian Flavour       RM 0.50\n";
}

void ICE_CREAM::setFlavour()
{
	int choice;
	cout<<"\nChoice of flavour : ";
	cin>>choice;
	
	switch(choice){
		case 1 :	flavour = "Strawberry";
					price = 3.50;
					break;
		case 2 :	flavour = "Chocolate";
					price = 2.50;
					break;
		case 3 :	flavour = "Vanilla";
					price = 1.50;
					break;
		case 4 :	flavour = "Durian";
					price = 0.50;
					break;
		default :	flavour = "Invalid flavour";
					price = 0.00;
	}
}

void ICE_CREAM::setHowMany()
{
	cout<<"How many : ";
	cin>>number;
}

ICE_CREAM::ICE_CREAM()
{
	cout<<"BARNEY'S HOUSE OF ICE";
}

void display_receipt(ICE_CREAM &ic)
{
	cout<<"\n===========================================\n"
	<<"===\t\tPAYMENT\t\t\t===\n===========================================\n"
	<<"Flavour		: "<<ic.flavour<<endl
	<<"Total price	: RM "<<fixed<<setprecision(2)<<ic.price*ic.number;
	return ;
}

int main()
{
	ICE_CREAM IC;
	IC.menu();
	IC.setFlavour();
	IC.setHowMany();
	display_receipt(IC);
	return 0;
}
