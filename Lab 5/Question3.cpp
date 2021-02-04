#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

class PreOrder{
	private : 
		string title;
		double price;
	
	public : 
		void BookSelection(){
			cout<<"\n [1] Mum's Favourite Recipes Book				Price : RM 14.00\n"
			<<" [2] Weight Watchers Everyday Favourite Recipes Book		Price : RM 12.00\n"
			<<" [3] The Skinny 5:2 Diet Family Recipes Book			Price : RM 10.90\n"
			<<" [4] Favourite Teatime Recipes Book				Price : RM 10.00\n"
			<<" [5] Favourite Traditional and Retro Recipes			Price : RM 13.00\n\n";
		}
		
		void BookPreOrder(){
			int choice;
			cout<<" Enter your choice, put your selection number : ";
			cin>>choice;
			if(choice==1){
				title = "Mum's Favourite Recipes Book";
				price = 14;
			}
			else if(choice==2){
				title = "Weight Watchers Everyday Favourite Recipes Book";
				price = 12;
			}
			else if(choice==3){
				title = "The Skinny 5:2 Diet Family Recipes Book";
				price = 10.90;
			}
			else if(choice==4){
				title = "Favourite Teatime Recipes Book";
				price = 10;
			}
			else if(choice==5){
				title = "Favourite Traditional and Retro Recipes";
				price = 13;
			}
			else{
				title = "No title";
				price = 0;
			}
		}
		
		double getPrice(){
			return price;
		}
		
		string getTitle(){
			return title;
		}
};

class Buyer{
	private : 
		string Booktitle, name;
		double payment;
		PreOrder objGoPO;
	
	public : 
		void set_data(){
			cout<<"=========================================\n"
			<<"   FAVOURITE RECIPE BOOK OF THE MONTH\n=========================================\n"
			<<" Type your name	: ";
			getline(cin,name);
			getBook();
		}
		
		void getBook(){
			objGoPO.BookSelection();
			objGoPO.BookPreOrder();
			payment = objGoPO.getPrice();
			Booktitle = objGoPO.getTitle();
		}
		
		void showDetails(){
			cout<<"\n....................................\n "
			<<name<<", your order details\n....................................\n"
			<<" Book title	: "<<Booktitle
			<<"\n Price		: RM "<<fixed<<setprecision(2)<<payment;
		}
};

int main(){
	Buyer objGoB;
	objGoB.set_data();
	objGoB.showDetails();
	return 0;
}
