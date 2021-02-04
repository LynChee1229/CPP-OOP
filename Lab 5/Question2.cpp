#include<iostream>
using namespace std;

class  Achievement{
	private	: 
		string className[4];
		int score[4];
	
	public : 
		void set_data(string *classN, int *sc){
			for(int i=0;i<4;i++){
				className[i] = classN[i];
				score[i] = sc[i];
			}
		}
		
		void display_scale(){
			cout<<"\n\n     THE SUMMARY OF UPSR TRIAL EXAM RESULT"
			<<"\n================================================\n";
			
			for(int i=0;i<4;i++){
				cout<<"   "<<className[i]
				<<"\n The Class Passing Grade Achievement : "<<score[i]<<"%\n ";
				
				if(score[i]>=85 && score[i]<=100)
					cout<<" * * * * * ";
				else if(score[i]>=70 && score[i]<85)
					cout<<" * * * * ";
				else if(score[i]>=60 && score[i]<70)
					cout<<" * * * ";
				else if(score[i]>=50 && score[i]<60)
					cout<<" * * ";
				else if(score[i]<50)
					cout<<" Poor Achievement ";
					
				cout<<"\n .............................................\n";
			}
		}
};

int main()
{
	Achievement upsr;
	string classN[5];
	int sc[4];
	
	cout<<"------------------------------------------\n"
	<<"\tEnter Class Achievement\n------------------------------------------";
	for(int i=0;i<4;i++){
		cout<<"\n Enter the class name		: ";
		cin>>classN[i];
		cout<<" The class achievement (%)	: ";
		cin>>sc[i];
	}
	upsr.set_data(classN,sc);
	upsr.display_scale();
	return 0;
}
