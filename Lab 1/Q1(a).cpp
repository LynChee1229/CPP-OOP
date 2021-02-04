#include<iostream>
#include<iomanip>		// needed for 'setw( )'
using namespace std;

int main()
{
	cout<<"Sales Report for September 15,2010"<<endl;
	cout<<setw(10)<<"Artist"<<setw(8)<<"Title"<<setw(8)<<"Price"<<setw(12)<<"Genre"<<setw(8)<<"Disc"<<setw(8)<<"Sale"<<endl;
	cout<<setw(10)<<"Merle"<<setw(8)<<"Blue"<<setw(8)<<"12.99"<<setw(12)<<"Country"<<setw(8)<<"4%"<<setw(8)<<"12.47"<<endl;
	cout<<setw(10)<<"Richard"<<setw(8)<<"Music"<<setw(8)<<"8.49"<<setw(12)<<"Classical"<<setw(8)<<"8%"<<setw(8)<<"7.81"<<endl;
	return 0;
}
