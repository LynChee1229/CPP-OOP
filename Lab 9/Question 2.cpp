#include<iostream>
using namespace std;

class ChoreographyMarks{
	private : 
		float points, total;
	
	public : 
		ChoreographyMarks(){
			total = 30;
		}
		
		void setCgPoints(){
			cout<<"Enter Choreography Marks[max:30] : ";
			cin>>points;
		}
		
		friend class Dancer;
};

class InventiveMarks{
	private : 
		float points, total;
	
	public : 
		InventiveMarks(){
			total = 20;
		}
		
		void setInvPoints(){
			cout<<"Enter Inventive Marks[max:20]	 : ";
			cin>>points;
		}
		
		friend class Dancer;
};

class Dancer{
	private : 
		string name;
		int age;
		float finalpoints, cpoints, ipoints;
		
	public :
		void set_details(){
			cin.ignore();
			cout<<"\n\n::::::Details for Dancer::::::\n"
			<<"Enter name			 : ";
			getline(cin,name);
			cout<<"Enter age			 : ";
			cin>>age;
		}
		
		void calcFinalPoints(ChoreographyMarks CM,InventiveMarks IM){
			cpoints = (CM.points / CM.total) * 100;
			ipoints = (IM.points / IM.total) * 100;
			finalpoints = (CM.points + IM.points) / (CM.total+IM.total) *100;
		}
		
		int getAge(){
			return age;
		}
		
		string getName(){
			return name;
		}
		
		void displayScoreDetails(){
			cout<<"\n::::::Score Board::::::\n"
			<<"Choreography	: "<<cpoints<<endl
			<<"Inventive	: "<<ipoints<<endl
			<<"Final score	: "<<finalpoints<<endl
			<<"=========================================\n";
		}
};

int main()
{
	int size;
	cout<<"Enter number of dancers : ";
	cin>>size;
	
	Dancer *ptr = new Dancer[size];
	ChoreographyMarks CM;
	InventiveMarks IM;
	
	for(int i=0;i<size;i++){
		ptr[i].set_details();
		CM.setCgPoints();
		IM.setInvPoints();
		ptr[i].calcFinalPoints(CM,IM);
		
		cout<<"=========================================\n"
		<<"Dancer #"<<i+1<<"\n=========================================\n"
		<<"Name		= "<<ptr[i].getName()<<endl
		<<"Age		= "<<ptr[i].getAge()<<endl;
		ptr[i].displayScoreDetails();
	}
	delete []ptr;
	return 0;
}
