#include<iostream>
using namespace std;

int main(){
	int subject, num;
	float total_payment=0, average_payment;
	float *Fees;
	cout<<"How many subjects you have registered : ";
	cin>>subject;
	cout<<endl;
	Fees = new float[subject];
	
	for(num=0;num<subject;num++){
		cout<<"Class "<<num+1<<" fees charge : RM ";
		cin>>Fees[num];
		total_payment = total_payment + Fees[num];
	}
	
	cout<<"\n===== SEPTEMBER 2016 PAYMENT DETAILS =====\n"
	<<"Fees charges you have entered : ";
	for(num=0;num<subject;num++){
		cout<<Fees[num]<<"(RM)... ";
	}
	
	average_payment = total_payment / subject;
	cout<<"\nTotal payment to be made : RM "<<total_payment<<endl
	<<"Minimum payment (Average of total payment) : RM "<<average_payment;
	
	return 0;
}
