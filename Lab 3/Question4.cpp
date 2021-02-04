#include<iostream>
#include<string>
using namespace std;
const int SIZE = 8;

class Stationery_Inventory{
	private : 
		string codeName;
		int warehouse[SIZE];
	
	public :
		void display_reverse()
		{
			int x=1;
			cout<<"-------------------------------"
			<<"\n\tThe Inventory Info\n-------------------------------"
			<<"\n Stationery Code  : "<<codeName;
			for(int i=SIZE-1;i>=0;i--){
				cout<<"\n Warehouse "<<x++<<"	  : "<<warehouse[i];	}
		}
		
		void set_data(int *arr)
		{
			cout<<"######################################\n"
			<<"\t   Item Entry\n--------------------------------------\n"
			<<" Enter Stationery Code : ";
			cin>>codeName;
			for(int i=0;i<SIZE;i++){
				warehouse[i] = arr[i];	}		// warehouse[i] = *(arr+i);
		}
}hold;

void process(void)
{
	int stocks[SIZE];
	cout<<"\n--------------------------------------"
	<<"\n     Colourful Book Holder Stock\n--------------------------------------\n"
	<<"Enter the stocks for "<<SIZE<<" warehouse : \n";
	for(int i=0;i<SIZE;i++){
		cin>>stocks[i];		}
	hold.set_data(stocks);
	hold.display_reverse();
}

int main()
{
	Stationery_Inventory obj;
	int array[SIZE]= { 5, 10, 15, 22, 20, 25, 30, 35};
	cout<<"\t   SMART Stationery Shop\n";
	obj.set_data(array);		// obj.set_data(&array[0]);
	obj.display_reverse();
	process();
	return 0;
}
