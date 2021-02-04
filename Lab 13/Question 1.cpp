#include<iostream>
#include<iomanip>
using namespace std;

class Rice{
	float price_per_kg, total_weight;	//private
	
	public : 
		Rice(float w){
			price_per_kg = 10.0;
			total_weight = w;
		}
		
		void display_rice(){
			cout<<"----------------------------------------\n"
			<<"	Rice Details\n"
			<<fixed<<setprecision(2)
			<<"Total weight	  : "<<total_weight<<endl
			<<"Price per kg (RM) : "<<price_per_kg<<endl
			<<"Total (RM)	  : "<<total_weight * price_per_kg<<endl;
		}
};

class Product{
	private : float kg;
	
	public : 
		Rice operator+(const Product pd){
			return (kg + pd.kg);
		}
		
		void setdata(){
			cout<<"Enter product's weight (kg) : ";
			cin>>kg;
		}
};

int main(){
	Product A, B;
	A.setdata();
	B.setdata();

	Rice H = A.operator+(B);		// Rice H = A + B;
	H.display_rice();
	return 0;
}
