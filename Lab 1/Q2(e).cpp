#include<iostream>
using namespace std;

int main()
{
	int number=0, total=0;
	cout<<"\nEnter a number : ";
	cin>>number;
	while(number!=99)
	{	
		total = total + number;
		cout<<"\nEnter a number : ";
		cin>>number;
	}
	cout<<"\n\nThe total is "<<total<<".";
	return 0;
}
