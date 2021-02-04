#include<iostream>
#include<iomanip>
using namespace std;

class Staff{
	protected : 
		string name, id;
		int age;
		float salary, nett_salary;
	
	public : 
		void setdata(){
			fflush(stdin);
			cout<<"\nEnter Name	: ";
			getline(cin,name);
			cout<<"Enter ID	: ";
			cin>>id;
			cout<<"Enter Age	: ";
			cin>>age;
			cout<<"Enter Salary	: RM ";
			cin>>salary;
		}
};

class Executive:public Staff{
	private : 
		int OT_hrs;
		float rate;
	
	public :
		void setExecutive(){
			cout<<"Enter OT hrs	: ";
			cin>>OT_hrs;
			cout<<"Enter Rate	: RM ";
			cin>>rate;
		}
		
		void cal_salary_exec(){
			nett_salary = salary + (OT_hrs * rate);
		}
		
		void display(){
			cout<<fixed<<setprecision(2)
			<<"\nName		: "<<name<<endl
			<<"ID		: "<<id<<endl
			<<"Age		: "<<age<<endl
			<<"Salary		: RM "<<salary<<endl
			<<"OT Hours	: "<<OT_hrs<<endl
			<<"OT Rate		: RM "<<rate<<endl
			<<"Nett Salary	: RM "<<nett_salary;
		}
};

class Salesperson:public Staff{
	private : 
		int units;
		float bonus;
		
	public :
		void setSalesperson(){
			cout<<"Enter Units	: ";
			cin>>units;
		}
		
		void cal_salary_sales(){
			if(units>500)
				bonus = 500;
			else if(units<=500)
				bonus = 250;
				
			nett_salary = salary + bonus;
		}
		
		void display(){
			cout<<fixed<<setprecision(2)
			<<"\nName		: "<<name<<endl
			<<"ID		: "<<id<<endl
			<<"Age		: "<<age<<endl
			<<"Salary		: RM "<<salary<<endl
			<<"Units		: "<<units<<endl
			<<"Bonus		: RM "<<bonus<<endl
			<<"Nett Salary	: RM "<<nett_salary;
		}
};

int main(){
	int choice;
	
	cout<<"Enter [1] for Executive        OR        [2] for Salesperson : ";
	cin>>choice;
	if(choice==1){
		Executive ex;
		ex.setdata();
		ex.setExecutive();
		ex.cal_salary_exec();
		ex.display();
	}
	else if(choice==2){
		Salesperson sp;
		sp.setdata();
		sp.setSalesperson();
		sp.cal_salary_sales();
		sp.display();
	}
	else
		cout<<"Invalid Selection ! ";
		
	return 0;
}
