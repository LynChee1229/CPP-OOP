#include<iostream>
#include<iomanip>		// needed for 'setprecision( )'
using namespace std;

int main()
{
	float total_hour, ot_hour, regular_wage, ot_wage, total_wage;
	float regular_hour = 40, base_payrate = 18.50, ot_payrate = 24.35;
	cout<<"Please enter total hours you've worked this week : ";
	cin>>total_hour;
	
	if(total_hour>40)
		ot_hour = total_hour - regular_hour;
	else
	{
		ot_hour = 0;
		regular_hour = total_hour;
	}
	regular_wage = base_payrate * regular_hour;
	ot_wage = ot_payrate * ot_hour;
	total_wage = regular_wage + ot_wage;
	
	cout<<"\nWages for this week are RM "<<fixed<<setprecision(2)<<total_wage;
	return 0;
}
