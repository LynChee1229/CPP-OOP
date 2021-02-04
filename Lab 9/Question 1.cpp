#include<iostream>
using namespace std;

class ArtificialGrass{
	private : 
		int length, width, depth;
	
	public :
		void grass_data(int q, int r, int s){
			length = q;
			width = r;
			depth = s;
		}
		
		int grass_gauge(){
			return length*width*depth;
		}
		
		ArtificialGrass(){
			length = 4;
			width = 6;
			depth = 3;
		}
		
		~ArtificialGrass(){
			cout<<"\n\nDeleting the artificial grass details.";
		}
};

int main()
{
	ArtificialGrass *ptr;
	ptr = new ArtificialGrass;
	cout<<"+++++++++++++++++++++++++++++++++++++++++++++\n"
	<<"\tThe Artificial Grass Details\n+++++++++++++++++++++++++++++++++++++++++++++\n"
	<<"The Previous Batch Set Left....\n"
	<<"Available Grass Size : "<<(*ptr).grass_gauge()<<"cm [2 pieces in one set]";
	delete ptr;
	
	cout<<"\n\n=============================================\n"
	<<"\tThe Stocks Available...\n+++++++++++++++++++++++++++++++++++++++++++++";
	ArtificialGrass *p;
	p = new ArtificialGrass[3];
	for(int i=0;i<3;i++){
		(*(p+i)).grass_data(i+2,i+2,i+2);
		cout<<"\nThe Grass Size SET #"<<i+1<<"\n->> "<<(p+i)->grass_gauge()<<"cm [2 pieces in one set]\n";
	}
	delete []p;
	return 0;
}
