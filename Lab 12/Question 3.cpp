#include<iostream>
using namespace std;

class Product{
	private : 
		int prodID;
	
	protected : 
		float total_price;
	
	public :
		Product(){
			total_price = 0.0;
		}
		
		int getProd_ID(){
			return prodID;
		}
		
		void input_ProdID(){
			cout<<"\nEnter product ID	: ";
			cin>>prodID;
		}
};

class CanFood: protected Product{
	private : 
		float unit_price;
		int order_unit;
		
	public :
		void get_Product(){
			input_ProdID();
			cout<<"Enter price		: RM ";
			cin>>unit_price;
			cout<<"Enter order unit	: ";
			cin>>order_unit;
		}
		
		void calculate_Total(){
			total_price = unit_price * order_unit;
		}
		
		void display_product(){
			cout<<"\nProduct ID	: "<<getProd_ID()<<endl
			<<"Total price	: RM "<<total_price<<endl;
		}
};

int main(){
	int num;
	cout<<"How many types of canned food? ";
	cin>>num;
	CanFood *tp = new CanFood[num];
	for(int i=0;i<num;i++){
		(tp+i)->get_Product();
		(*(tp+i)).calculate_Total();
	}
	for(int i=0;i<num;i++){
		tp[i].display_product();
	}
	delete []tp;
	return 0;
}
