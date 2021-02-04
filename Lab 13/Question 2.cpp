#include<iostream>
#include<iomanip>
using namespace std;

class Produce{
	private :
		float price, total;
		int qty;
	
	public :
		Produce(){
			price = 0;
			total = 0;
			qty = 0;
		}
		
		void set_input(float p, int q){
			price = p;
			qty = q;
			total = price*qty;
		}
		
		friend class Bill;
};

class Bill{
	private :
		float grand_total;
	
	public :
		Bill(){
			grand_total = 0;
		}
		
		void display(){
			cout<<"::The grand total of the bill is : RM "<<fixed<<setprecision(2)<<grand_total;
		}
		
		void operator+=(Produce pd){
			grand_total += pd.total;
			cout<<"Subtotal	: RM "<<pd.total<<endl;
		}
};

int main()
{
	Bill BL;
	Produce pd;
	float p;
	int q;
	char ans;
	
	do{
		cout<<"Enter price	: RM ";
		cin>>p;
		cout<<"Enter quantity	: ";
		cin>>q;
		
		pd.set_input(p,q);
		
		BL.operator+=(pd);		// BL+=pd;
		
		cout<<"\nContinue (y/n)? : ";
		cin>>ans;
		cout<<endl;
	}while(ans=='Y'||ans=='y');
	
	BL.display();
	return 0;
}
