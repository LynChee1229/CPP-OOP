#include<iostream>
using namespace std;
const int ITEM = 3;

class BeanBag{
	private : 
		string codeName;
		int Stock[ITEM];
		
	public : 
		void Lastest_BeanBagStock(){
			cout<<"--------------------------------------\n"
			<<" #Current# Ready Stocks Checking...\n--------------------------------------\n"
			<<"Code Tracing\t >>"<<codeName<<"<<\n";
			int x=0;
			for(int i=ITEM-1;i>=0;i--){
				cout<<"Group "<<++x<<" production	: "<<Stock[i]<<" item(s) are ready\n";
			}
		}
		
		void BeanBag_Details(int *arr){
			cout<<"#######################################\n"
			<<"\t     Stocks Checking\n---------------------------------------\n"
			<<"Enter Bean Bag Chair code : ";
			fflush(stdin);
			getline(cin,codeName);
			for(int i=0;i<3;i++){
				Stock[i] = *(arr+i);
			}		
		}
};

BeanBag ready;

void StockUpdate(){
	int grp;
	int *ptr = new int[3];
	
	cout<<"------------------------------------------\n"
	<<"    Ready Stock [BB789] for this Month\n------------------------------------------\n"
	<<"Update new stocks from how many group? : ";
	cin>>grp;
	
	int y=3;
	for(int i=0;i<3;i++){
		cout<<"Ready stock from group "<<y--<<": ";
		cin>>ptr[i];
	}
	ready.BeanBag_Details(ptr);
	ready.Lastest_BeanBagStock();
	delete []ptr;
}

int main(){
	BeanBag bb;
	int arr[3]={9,7,5};
	cout<<"\tCOSY Bean Bag Chair Sdn Bhd\n";
	bb.BeanBag_Details(arr);
	bb.Lastest_BeanBagStock();
	StockUpdate();
	return 0;
}
