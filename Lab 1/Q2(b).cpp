#include<iostream>
using namespace std;

int main()
{
	int number, odd_num=0, even_num=0, total=0;
	int x=0;
	do{
		cout<<"Enter a number : ";
		cin>>number;
		cout<<endl;
		
		total = total + number;
		if(number%2==0)
			++even_num;
		else
			++odd_num;
		
		x++;
	}while(x<10);
	
	cout<<"There are "<<even_num<<" even numbers and "<<odd_num<<" odd numbers.\n";
	cout<<"The total of all the 10 numbers are "<<total<<".";
	return 0;
}
