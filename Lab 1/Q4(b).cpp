#include <iostream>
using namespace std; 
int multi(int, int);	// func prototype

int main ()  
{
	int number1, number2, ans; 
	
	// (i)
	cout<<"Please enter two integer numbers : ";
	cin>>number1>>number2;
	ans = multi(number1,number2);
	
	cout<<"\n "<<number1<<" * "<<number2<<" is "<<ans<<".";
	return 0;
}

// (ii)
int multi(int num1, int num2)
{
	int ans;
	ans = num1 * num2;
	return ans;
}

