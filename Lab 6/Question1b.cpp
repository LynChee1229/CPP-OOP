#include<iostream>
using namespace std;

class MasterStudent{
	string name, title;
	int status;
	
	public : 
		MasterStudent(string n, string t, int x){
			name = n ;
			title = t ;
			status = x ;
		}
		
		int getStatus(){
			return status;
		}
		
		string getName(){
			return name;
		}
		
		string getTitle(){
			return title;
		}
		
		~MasterStudent(){
			cout<<"\n\n ~End of the Details~Student~"<<name<<endl;
		}
};

int main()
{
	MasterStudent MS[5] = { MasterStudent("Johanes Kai","Working with Generation X employees: food industry",1), 
							MasterStudent("Cameron Chan","Collective Co-Creation within the Open Source Software Community",1), 
							MasterStudent("Meriam Azlan","What Makes Online Video Advertisements Go Viral?",0),
							MasterStudent("Peter Pan","A Study on Form 1 student's learning of Algebra",1), 
							MasterStudent("Dory Dory","Social media use for corporate communications",0)};
	for(int i=0;i<5;i++){
	cout<<"\n ================================="<<endl;
	cout<<"    Masters Student Details "<<i+1<<endl;
	cout<<" ================================="<<endl;
	cout<<" Name\t: "<<MS[i].getName()<<endl;
	cout<<" Title\t: "<<MS[i].getTitle()<<endl;
	cout<<" Status\t: ";
	if(MS[i].getStatus() == 1)
		cout<<"Approved"<<endl;
	else 
		cout<<"Pending"<<endl;
	}
	
	return 0;
}
