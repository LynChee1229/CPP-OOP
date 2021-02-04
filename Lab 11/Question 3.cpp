#include<iostream>
using namespace std;

class Participant{
	protected : 
		string name, location;
		int age;
	
	public : 
		Participant(){
			cout<<"-----------------------------------------\n"
			<<"\t   PARTICIPANT DETAILS\n-----------------------------------------\n";
		}
};

class Progress{
	protected : 
		string date[3];
		float rate[3];
		char grade;
		
	public :
		void mark_entry(){
			float total=0, avg;
			for(int i=0;i<3;i++){
				cin.ignore();
				cout<<"Enter date (dd/mm/yy)		: ";
				getline(cin,date[i]);
				cout<<"Enter rating (between 1-5)	: ";
				cin>>rate[i];
				
				while(rate[i]<1 || rate[i]>5){
					cout<<"Re-insert : ";
					cin>>rate[i];
				}
				total = total + rate[i];
			}
			avg = total/3;
			set_grade(avg);
		}
		
		void set_grade(float avg){
			if(avg>=4.00)
				grade = 'A';
			else if(avg>=3.00)
				grade = 'B';
			else
				grade = 'C';
		}
};

class Result: public Participant, public Progress {
	private : 
		string prize;
	
	public :
		void setdetails(){
			cin.ignore();
			cout<<"\nEnter Name	: ";
			getline(cin,name);
			cout<<"Enter Location	: ";
			getline(cin,location);
			cout<<"Enter Age	: ";
			cin>>age;
		}
		
		void display(){
			cout<<"Name		: "<<name<<endl
			<<"Location	: "<<location<<endl
			<<"Age		: "<<age<<endl;
			for(int i=0;i<3;i++){
				cout<<"Rating "<<i+1<<" : "<<rate[i]<<endl;
			}
			cout<<"Grade : "<<grade<<endl;
			
			if(grade=='A')
				prize = "Congrats, you can claim your Mug + RM 10 book voucher!\n\n";
			else 
				prize = "Congrats, you can claim your BPA free Water Bottle!\n\n";
			cout<<prize;
		}
		
		friend void summary(Result stud[3],int no); 
};

void summary(Result Stud[],int no){
	cout<<"====================================\n"
	<<"\t   Summary Results\n====================================\n";
	int A=0, B=0, C=0;
	for(int i=0;i<no;i++){
		if(Stud[i].grade=='A')
			++A;
		else if(Stud[i].grade=='B')
			++B;
		else if(Stud[i].grade=='C')
			++C;
	}
	cout<<"Grade A : ";
	for(int i=0;i<A;i++){
		cout<<" * ";
	}
	cout<<"\nGrade B : ";
	for(int i=0;i<B;i++){
		cout<<" * ";
	}
	cout<<"\nGrade C : ";
	for(int i=0;i<C;i++){
		cout<<" * ";
	}
}

int main(){
	int num;
	cout<<"Enter number of participants : ";
	cin>>num;
	
	Result *Stud1 = new Result[num];
	
	for(int i=0;i<num;i++){
		(Stud1+i)->setdetails();
		cout<<"-----------------------------------------\n"
		<<"\tRECITAL PROGRESS DETAILS\n-----------------------------------------\n";
		Stud1[i].mark_entry();
		cout<<"-----------------------------------------\n"
		<<"\t     RESULT SLIP\n-----------------------------------------\n";
		(*(Stud1+i)).display();
	}
	summary(Stud1,num);
	delete []Stud1;
	return 0;
}
