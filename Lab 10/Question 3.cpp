#include<iostream>
using namespace std;

class Number{
	private : 
		int no, index, sample, numbers;
	
	public : 
		Number(){
			cout<<"\t    NUMBERS :: Let's PLAY\n===========================================\n";
		}
		
		int SmallestNumb(int numb[],int element,int size){
			index = element;
			sample = size;
			no = numb[element];
			
			for(int i=element+1;i<size;i++){
				if(no>numb[i]){
					index = i;
					no = numb[i];
				}				
			}
			return index;
		}
		
		void select_Number(int number[],int size){
			int digit, sort;
			for(int i=0;i<size-1;i++){
				digit = SmallestNumb(number,i,size);
				
				if(number[digit]<number[i]){
					sort = number[digit];
					number[digit] = number[i];
					number[i] = sort;
				}
				
				cout<<"\nThe Cycle-"<<i+1<<" sorting : ";
				for(int i=0;i<size;i++){
					cout<<number[i]<<" ";
				}
			}
		}
};

int main(){
	Number obj;
	int size;
	cout<<"How many numbers would you like to be sorted : ";
	cin>>size;
	int *numbers = new int[size];
	cout<<"The "<<size<<" numbers are : ";
	for(int i=0;i<size;i++){
		cin>>numbers[i];
	}
	obj.select_Number(numbers,size);
	cout<<"\n\nThe final list of sorted numbers is : ";
	for(int i=0;i<size;i++){
		cout<<numbers[i]<<" ";
	}
	cout<<endl;
	delete []numbers;
	return 0;
}
