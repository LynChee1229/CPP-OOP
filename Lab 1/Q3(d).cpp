#include<iostream>
#include<iomanip>		// needed for 'setw( )'
using namespace std;

int main()
{ 
	int j, i;
	int array[2][3]={{21,4,12},{8,45,12}};
	for(j=0;j<2;j++)
	{
		cout<<"Row "<<j+1<<" : ";
		for(i=0;i<3;i++)
			cout<<left<<setw(5)<<array[j][i];
		cout<<endl;
	}
	return 0;
}

