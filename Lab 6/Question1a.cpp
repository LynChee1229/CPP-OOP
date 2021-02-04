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
		
		MasterStudent(){
			name = "Peter" ;
			title = "A Study on the Usability Factors of Mobile Apps.";
			status = 1 ;
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
	MasterStudent MS1;
	cout<<" ================================="<<endl;
	cout<<"    Masters Student Details       "<<endl;
	cout<<" ================================="<<endl;
	cout<<" Name\t: "<<MS1.getName()<<endl;
	cout<<" Title\t: "<<MS1.getTitle()<<endl;
	cout<<" Status\t: ";
	if(MS1.getStatus() == 1)
		cout<<"Approved"<<endl;
	else 
		cout<<"Pending"<<endl;
	
	MasterStudent MS2("Alina Mahmud","Customer Satisfaction towards Green Products",0);
	cout<<"\n ================================="<<endl;
	cout<<"    Masters Student Details       "<<endl;
	cout<<" ================================="<<endl;
	cout<<" Name\t: "<<MS2.getName()<<endl;
	cout<<" Title\t: "<<MS2.getTitle()<<endl;
	cout<<" Status\t: ";
	if(MS2.getStatus() == 1)
		cout<<"Approved"<<endl;
	else 
		cout<<"Pending"<<endl;
	
	return 0;
}
