#include<iostream>
using namespace std;
void get_a_b_c(double &a,double &b,double &c);

double bb_4ac()
{
	double a, b, c;
	get_a_b_c(a,b,c);
	return b*b-4*a*c;
}

void get_a_b_c(double &a,double &b,double &c)
{
	cout<<"\nEnter a, b and c : ";
	cin>>a>>b>>c;
}

int main()
{
	double discriminant;
	discriminant = bb_4ac();
	cout<<"\nThe disciminant is "<<discriminant<<".";
	return 0;
}
