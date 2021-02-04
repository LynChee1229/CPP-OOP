#include<iostream>
using namespace std;

class Fraction{
	// -----(a)-----
	private : 
		int denom, nume;
	public :
		void setData(int num1,int num2){
			nume = num1;
			denom = num2;
		}
		int getNume(){
			return nume;
		}
		int getDenom(){
			return denom;
		}
};

int isValid(Fraction ob)
{
	int valid;
	if(ob.getDenom()==0){
		valid = 0;
		cout<<"\n  [Alert : Denominator is having value zero]"<<endl;
	}
	else if(ob.getNume()>ob.getDenom()){
		valid = 0;
		cout<<"\n  [Alert : Numerator greater than denominator]"<<endl;
	}
	else
		valid = 1;
	return valid;
}

int main()
{
	Fraction ob1[3];
	int valid;
	for(int i=0;i<3;i++){
		ob1[i].setData(i+1,2-i);
		// -----(b)-----
		cout<<"\n  Fraction "<<ob1[i].getNume()<<"/"<<ob1[i].getDenom();
		valid = isValid(ob1[i]);
		if(valid==1)
			cout<<" is valid. \n";
		else
			cout<<"  is INvalid. \n";
	}
	return 0;
}
