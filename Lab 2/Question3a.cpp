#include<iostream>
#define SUBJECT 5
using namespace std;
char Greds(float avg);

struct Student{
	char name[30], grade;
	float marks[5], avg;
};

float Average(float marks[])
{
	float total=0, avg;
	for(int i=0;i<SUBJECT;i++)
		total = total + marks[i];
	avg = total/SUBJECT;
	return avg;
}

int main()
{
	struct Student S1;
	cout<<"// Structure variable\n\n";
	cout<<"Enter Name : ";
	cin.getline(S1.name,30);
	for(int i=0;i<SUBJECT;i++)
	{
		cout<<"Enter Mark #"<<i+1<<"  : ";
		cin>>S1.marks[i];
	}
	S1.avg = Average(S1.marks);
	S1.grade = Greds(S1.avg);
	cout<<"\n\nName	: "<<S1.name<<"\nAverage	: "<<S1.avg
	<<"\nGrade	: "<<S1.grade;
	return 0;
}

char Greds(float avg)
{
	char grade;
	if(avg>=80)
		grade = 'A';
	else if(avg>=60)
		grade = 'B';
	else if(avg>=50)
		grade = 'C';
	else
		grade = 'F';
	return grade;
}
