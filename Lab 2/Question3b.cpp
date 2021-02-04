#include<iostream>
#include<iomanip>
using namespace std;

struct Rental{
	char name[20];
	float rent;
	int month;
};

float report(struct Rental R[])
{
	int total=0;
	cout<<"\n-------------------------------------------------\n"
	<<"-\t  AMOUNT DUE MORE THAN $1000.00\t\t-"
	<<"\n-------------------------------------------------\n";
	for(int i=0;i<3;i++)
	{
		if(R[i].rent*R[i].month>1000)
		{
			cout<<"Tenant name    : "<<R[i].name<<endl;
			cout<<"Monthly rental : $"<<fixed<<setprecision(2)<<R[i].rent<<endl;
			cout<<"Unpaid months  : "<<R[i].month<<endl;
			cout<<"Unpaid amount  : $"<<R[i].rent*R[i].month<<endl<<endl;
			total = total + (R[i].rent*R[i].month);
		}
	}
	return total;
}

int main()
{
	Rental R[3] = {{"ALI",300,4},{"Johnson",250,1},{"David",790,2}};
	float total;
	total = report(R);
	cout<<"Total rental to be collected : $ "<<total;
	return 0;
}
