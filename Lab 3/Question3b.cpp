#include<iostream>
#include<iomanip>
#include<cstring>
using namespace std;

class Purchase{
	private : 
		char name[50], code[10];
		int qty;
		float price, total;
	
	public :
		void setdata(char n[],char c[],int q,float p);
		void calculate();
		void print();
};

// defined outside class
void Purchase::setdata(char n[],char c[],int q,float p)
{
	strcpy(name,n);
	strcpy(code,c);
	qty = q;
	price = p;
}

void Purchase::calculate()
{
	total = price*qty;
}

void Purchase::print()
{
	cout<<fixed<<setprecision(2)
	<<"\n========================\n"
	<<"\tRECEIPT\n========================\n"
	<<"Name          : "<<name<<endl
	<<"Product Code  : "<<code<<endl
	<<"Quantity      : "<<qty<<endl
	<<"Product Price : RM "<<price<<endl
	<<"Total Payment : RM "<<total<<endl;
}

int main()
{
	Purchase p;
	char pname[50], pcode[10], ans;
	int pqty;
	float pprice;	
	
	cout<<"\nYou have another customer to purchase item? [Y/N] : ";
	cin>>ans;
	if(ans!='N' && ans!='n' && ans!='Y' && ans!='y'){
		cout<<"Re-enter [Y/N] : ";
		cin>>ans;
	}
	
	while(ans!='N'&&ans!='n')
	{
	cin.ignore();
	cout<<"\n========================\n"
	<<"\tWELCOME\n========================\n"
	<<"Enter name	: ";
	cin.getline(pname,50);
	cout<<"Product code	: ";
	cin>>pcode;
	cout<<"Enter quantity	: ";
	cin>>pqty;
	cout<<"Enter price	: RM ";
	cin>>pprice;
	
	p.setdata(pname,pcode,pqty,pprice);
	p.calculate();
	p.print();
	
	cout<<"\nYou have another customer to purchase item? [Y/N] : ";
	cin>>ans;
	if(ans!='N' && ans!='n' && ans!='Y' && ans!='y'){
		cout<<"Re-enter [Y/N] : ";
		cin>>ans;
	}
	}
	return 0;
}
