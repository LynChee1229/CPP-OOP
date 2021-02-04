#include<iostream>
#include<string>
#include<ctime>
#include<cstdlib>
using namespace std;

int main()
{    
	string location1, location2, location3;
	int i, randomNum; 
	unsigned seed = time(0);
	srand(seed);
	for(i=0;i<3;i++)
	{
	cout<<"#"<<i+1<<endl;
	cout<<"I am a fortune teller. Look into my crystal screen \n"
	<<"and enter 3 locations you will possibly make as your permanent home. \nExample \n\n"
	<<"    Miami \n    Alor Gajah \n    Sydney \n\n"
	<<"Then I will predict where your home will be in the future.\n\n";	   
	cout<<"\nEnter future home 1 :";
	getline(cin, location1);
	cout<<"Enter future home 2 :";
	getline(cin, location2);
	cout<<"Enter future home 3 :";
	getline(cin, location3);
	
	randomNum = 1 + rand() % 4;
	
	switch(randomNum)
	{
		case 1 : cout<<"\nYour home will be in "<<location1<<".\n";
				 break;
		case 2 : cout<<"\nYour home will be in "<<location2<<".\n";
				 break;
		case 3 : cout<<"\nYour home will be in "<<location3<<".\n";
				 break;
		default : cout<<"\nSorry, your home will be in any of these locations.\n";
	}
	cout<<endl<<"----------------------------------------------------------------------"<<endl;
	}
	return 0;
}

