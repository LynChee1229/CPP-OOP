#include<iostream>
#include<cctype>
using namespace std;

class Ticket{
	private : 
		int no;
		float price;
	public : 
		friend class Student;
		Ticket(){
			price = 10;
		}
		
		void setTickets(){
			cout<<"Please enter number of tickets to purchase : ";
			cin>>no;
		}
};

class Student{
	private : 
		string id, name, purchase;
		Ticket P;
	public :
		void setStudent(){
			fflush(stdin);
			cout<<"Enter ID	: ";
			getline(cin,id);
			cout<<"Enter name	: ";
			getline(cin,name);
		}
		
		void ticket_entry(){
			char choice;
			cout<<"Do you want to purchase charity tickets? [Enter Y or N] : ";
			cin>>choice;
			
			choice = toupper(choice);
			if(choice=='Y'){
				purchase = "Yes";
				P.setTickets();
			}
			else if(choice=='N'){
				cout<<"-----No tickets purchase-----\n";
			}
		}
		
		void display(){
			cout<<"\n--------------------------------\n"
			<<"\t   STUDENT DETAILS\n--------------------------------\n"
			<<"ID		: "<<id<<endl
			<<"Name		: "<<name<<endl
			<<"\n--------------------------------\n"
			<<"\tADDITIONAL DETAILS\n--------------------------------\n";
			
			if(purchase=="Yes"){
				cout<<"You've purchase "<<P.no<<" Tickets\n"
				<<"Total amount	: RM "<<P.no*P.price<<endl<<endl<<endl;
			}
			else
				cout<<"You've not purchased any tickets\n\n\n";
		}
};

int main()
{
	Student stu[3];
	for(int i=0;i<3;i++){
		stu[i].setStudent();
		stu[i].ticket_entry();
		stu[i].display();
	}
	return 0;
}
