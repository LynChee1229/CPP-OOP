#include<iostream>
#include<iomanip>
using namespace std;

class Manisan{
	private : 
		int KacangHijau, JagungDurian, PulutHitam, SantanMango, Pudding, Fruits;
		float price;
	
	public : 
		void Bubur_Manisan(int kh, int jd, int ph, int sm, int pudd, int fruit){
			KacangHijau = kh;
			JagungDurian = jd;
			PulutHitam = ph;
			SantanMango = sm;
			Pudding = pudd;
			Fruits = fruit;
			ManisanOrder();
		}
		
		void ManisanOrder(){
			int total;
			total = KacangHijau + JagungDurian + PulutHitam + SantanMango + Pudding + Fruits;
			cout<<"\nPlease to be seated. Your order will be served shortly...\n\n"
			<<" Here Your Bubur/Manisan Order List\n-------------------------------------\n"
			<<" Bubur Kacang Hijau		: "<<KacangHijau<<" bowl(s)\n"
			<<" Bubur Jagung + Durian		: "<<JagungDurian<<" bowl(s)\n"
			<<" Bubur Pulut Hitam		: "<<PulutHitam<<" bowl(s)\n"
			<<" Pulut, Santan & Mango		: "<<SantanMango<<" bowl(s)\n"
			<<" Creamy Marble Pudding		: "<<Pudding<<" bowl(s)\n"
			<<" Fresh Mix Local Fruits		: "<<Fruits<<" bowl(s)\n\n"
			<<" >> Total Bowls			: "<<total;
		}
		
		void calcPrice(){
			price = (KacangHijau*2.50) + (JagungDurian*4.50) + (PulutHitam*2.50) + (SantanMango*4.50) + (Pudding*2.00) + (Fruits*2.00);
			cout<<"\n >> Thank you. Your order price is RM "<<fixed<<setprecision(2)<<price;	
		}
};

int main()
{
	Manisan BM;
	char ans;
	int kh, jd, ph, sm, pudd, fruit;
	float priceee;
	
	cout<<"-----------------------------------------------\n"
	<<"\t ++ Bubur & Manisan Stall ++\n-----------------------------------------------\n"
	<<" Looking for a yummy Bubur/Manisan? [Y/N] : ";
	cin>>ans;
	
	while(ans=='Y'||ans=='y'){
		cout<<"\n........Yummy Bubur & Manisan Selection.........\n"
		<<" [1] Bubur Kacang Hijau (bowl)		: ";
		cin>>kh;
		cout<<" [2] Bubur Jagung + Durian (bowl)	: ";
		cin>>jd;
		cout<<" [3] Bubur Pulut Hitam (bowl)		: ";
		cin>>ph;
		cout<<" [4] Pulut, Santan & Mango (bowl)	: ";
		cin>>sm;
		cout<<" [5] Creamy Marble Pudding (bowl)	: ";
		cin>>pudd;
		cout<<" [6] Fresh Mix Local Fruits (bowl)	: ";
		cin>>fruit;
		
		BM.Bubur_Manisan(kh, jd, ph, sm, pudd, fruit);
		BM.calcPrice();
		
		cout<<"\n\n Would you like to make another order? [Y/N] : ";
		cin>>ans;
	}
	return 0;
}
