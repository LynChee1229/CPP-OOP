#include<iostream>
#include<cstring>
using namespace std;

class Trivia{
	private : 
		string name, country, game_name;
		int age;
		float score[3];
		char status[20];
		
	public :
		void setParticipant(){
			cin.ignore();
			cout<<"\nEnter Name	 : ";
			getline(cin,name);
			cout<<"Enter Country	 : ";
			getline(cin,country);
			cout<<"Enter Age	 : ";
			cin>>age;
			cin.ignore();
			cout<<"Enter Game Name	 : ";
			getline(cin,game_name);
		}
		
		// a. void score_Gained() function
		void score_Gained( ){
			for(int i=0;i<3;i++){
				cout<<"   Enter Score "<<i+1<<" : ";
				cin>>score[i];
			}
		}
		
    	// b. void average_Val() function
    	void average_Val( ){
    		double total=0, average;
    		for(int i=0;i<3;i++){
    			total = total + score[i];
			}
			average = total/3;
			set_status(average);
		}
    	
    	void set_status(double avg){
    		if(avg>=80 && avg<=100)
    			strcpy(status,"Excellent");
    		else if(avg>=60 && avg<=80)
    			strcpy(status,"Great");
    		else if(avg>=50 && avg<=60)
    			strcpy(status,"Keep Trying");
    		else
    			strcpy(status,"Loser");
		}
		
		// c. void display_result() function
		void display_result( ){
			cout<<"-------------------------\n"
			<<"      RESULT SCORED\n-------------------------\n"
			<<"Name      : "<<name<<endl
			<<"Country   : "<<country<<endl
			<<"Age       : "<<age<<endl
			<<"Game Name : "<<game_name<<endl;
			for(int i=0;i<3;i++){
				cout<<"  Score "<<i+1<<" : "<<score[i]<<endl;
			}
			cout<<"  Status  : "<<status<<endl<<endl;
		}
};

int main()
{
	// d. Write the codes based on the requirements as stated below
	int warrior;
	Trivia TV, *TV1;
	cout<<"How many warrior? ";
	cin>>warrior;
	TV1 = &TV;
	for(int x=0;x<warrior;x++){
		TV1->setParticipant();			// when call func by pointer, use ' -> '
		// (*TV1).setParticipant();		// or using this method.
		TV1->score_Gained();
		TV1->average_Val();	
		TV1->display_result();
	}
	return 0;
}
