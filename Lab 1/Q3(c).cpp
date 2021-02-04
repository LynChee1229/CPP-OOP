#include <iostream>
#include <iomanip>		// needed for 'setprecision( )'
using namespace std;

int main()
{
	const int NUM_EMPS = 5;
	int index;
	int hours[NUM_EMPS];         // Define 2 parallel arrays
	double payRate[NUM_EMPS];
	double grossPay;

	cout<<"Enter the hours worked and hourly pay rates of "<<NUM_EMPS<<" employees.\n";  
	for (index = 0; index < NUM_EMPS; index++)
	{  
		cout<<"\nHours worked by employee #"<<index+1<<"     : ";
        cin>>hours[index];
		cout<<"Hourly pay rate for employee #"<<index+1<<" : ";
        cin>>payRate[index];
	}
	
	// Display the data
	cout<<"\n\n\nHere is the gross pay for each employee:\n";
	for(index=0;index<NUM_EMPS;index++)
	{
		cout<<"\nEmployee #"<<index+1<<" : RM "<<fixed<<setprecision(2)
		<<hours[index]*payRate[index]<<endl;
	}
	return 0;
}

