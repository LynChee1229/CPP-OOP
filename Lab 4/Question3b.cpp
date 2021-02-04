#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class Strawberry{
	private : 
		string selection;
		double price;
	public : 
		void dispStrawberrySelection(){
			cout<<"\n[1] Strawberry & Nutella Crepe			Price : RM 10.00\n"
			<<"[2] Strawberry & Chocolate Crepe 		Price : RM 12.00\n"
			<<"[3] Strawberry Waffle with Custard		Price : RM 13.40\n"
			<<"[4] Strawberry Smoothie				Price : RM 10.00\n"
			<<"[5] Strawberry & Country Cream			Price : RM 13.00\n";
		}
		
		void purchase(){
			int select;
			cout<<"\nEnter your choice based on the number : \n";
			cin>>select;
			if(select==1){
				selection = "Strawberry & Nutella Crepe";
				price = 10.00;
			}
			else if(select==2){
				selection = "Strawberry & Chocolate Crepe";
				price = 12.00;
			}
			else if(select==3){
				selection = "Strawberry Waffle with Custard";
				price = 13.40;
			}
			else if(select==4){
				selection = "Strawberry Smoothie";
				price = 10.00;
			}
			else if(select==5){
				selection = "Strawberry & Country Cream";
				price = 13.00;
			}
			else{
				selection = "Not Available.";
				price = 0.00;
			}	
		}

		double getPrice(){
			return price;
		}
		
		string getSelection(){
			return selection;
		}
};

class Customer{
	private : 
		string StrawSelect, name;
		double payment;
		Strawberry st;
	public : 
		void set_data(){
			cout<<"++++++++++++++++++++++++++++++++++++++++++++\n"
			<<"\tTutti Frutti: Strawberry\n++++++++++++++++++++++++++++++++++++++++++++\n"
			<<"Your Name	: ";
			getline(cin,name);
			getOrder();
		}
		
		void getOrder(){
			st.dispStrawberrySelection();
			st.purchase();
			payment = st.getPrice();
			StrawSelect = st.getSelection();
		}
		
		void dispDetails(){
			cout<<"...................................................\n "
			<<name<<", Below is your purchase details\n"
			<<"...................................................\n"
			<<"Selection		: "<<StrawSelect<<endl
			<<"Payment to be made	: RM "<<fixed<<setprecision(2)<<payment<<endl;
		}
};

int main()
{
	Customer obj;
	obj.set_data();
	obj.dispDetails();
	return 0;
}
