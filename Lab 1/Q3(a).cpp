#include<iostream>
using namespace std;

int main()
{
	int a, b;
	int *p,*q;
	a = 20;
	p = &a;						// p ---> a	
	b = *p % 2 + 40;			// b = 20%2 + 40 = 0+40
	q = p;						// q = p ---> a
	cout<<"a  = "<<a<<endl;		// a = 20
	cout<<"b  = "<<b<<endl;		// b = 40
	cout<<"*p = "<<*p<<endl;	// *p = 20
	cout<<"*q = "<<*q<<endl;	// *q = 20
	return 0;
}
