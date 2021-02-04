#include<iostream>
#define SUBJECT 5
using namespace std;
char Greds(float avg);

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
	float marks[SUBJECT],avg ;
	char name[30], grade;
	cout<<"// 1D array\n\n";
	cout<<"Enter Name : ";
	cin.getline(name,30);
	for(int i=0;i<SUBJECT;i++)
	{
		cout<<"Enter Mark #"<<i+1<<"  : ";
		cin>>marks[i];
	}
	avg = Average(marks);
	grade = Greds(avg);
	cout<<"\n\nName	: "<<name<<"\nAverage	: "<<avg
	<<"\nGrade	: "<<grade;
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
