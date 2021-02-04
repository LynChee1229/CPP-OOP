#include<iostream>
using namespace std;

class NumberGame{
	int array[5];
	
	public : 
		// ---3a---
		NumberGame(){
			// assigning, not initializing
			array[0] = 15;
			array[1] = 20;
			array[2] = 33;
			array[3] = 38;
			array[4] = 100;
		}
		
		friend void search(NumberGame, int *);
};

// ---3b---
void search(NumberGame g, int *numb)
{
	int status;
	int i=0;
	do{
		if(*numb == g.array[i]){
			status = 1;
			break;
		}
		else
			status = 0;
		
		i++;
	}while(i<5);
	if(status==1)
		cout<<*numb<<" is found ! ";
	else
		cout<<*numb<<" is NOT found ! ";
}

int main()
{
	NumberGame G;
	int num;
	cout<<"Enter a number : ";
	cin>>num;
	
	search(G, &num);
	return 0;
}
