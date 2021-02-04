#include<iostream>
#include<cctype>	// used for toupper
#include<iomanip>	// used for setprecision
using namespace std;

class TravelPackage{
	public :
		char package;
		int noAdult, noChild;
		float adultPrice, childPrice, discount, totalPrice;
};

int main()
{
	TravelPackage tp;
	do{
		cout<<"Select travel package <A,B,C> : ";
		cin>>tp.package;
		tp.package = toupper(tp.package);
		
		if(tp.package!='A' && tp.package!='B' && tp.package!='C')
			cout<<"Invalid selection.\n\n";
	}while(tp.package!='A' && tp.package!='B' && tp.package!='C');
	
	cout<<"\nEnter number of adult : ";
	cin>>tp.noAdult;
	cout<<"Enter number of children : ";
	cin>>tp.noChild;
	
	switch(tp.package)
	{
		case 'A' :	tp.adultPrice = 1000.00;
					tp.childPrice = 500.00;
					break;
		case 'B' :	tp.adultPrice = 800.00;
					tp.childPrice = 600.00;
					break;
		case 'C' :	tp.adultPrice = 500.00;
					tp.childPrice = 300.00;
					break;
	}
	tp.totalPrice = (tp.noAdult*tp.adultPrice) + (tp.noChild*tp.childPrice);
	
	if(tp.totalPrice>3000)
	{
		tp.discount = tp.totalPrice*0.20;
		tp.totalPrice = tp.totalPrice - tp.discount;
	}
	cout<<"\nTotal price : RM "<<fixed<<setprecision(2)<<tp.totalPrice;
	return 0;
}
