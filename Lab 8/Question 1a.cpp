#include <iostream>
using namespace std;

class geometry{
	private :
		float PI, height, radius;
	public :
		// (1)
		geometry(float hg,float rd){
			PI = 3.142;
			height = hg;
			radius = rd;
		}
		
		// (2)
		~geometry(){
			cout<<"\n\n = END OF PROGRAM = ";
		}
		
		// (3)
		friend class cylinder;
		
		// (4)
		friend class cone;
};

class cylinder{
	private :
		float vol;
	public :
		// (5)
		void calc_vol(geometry *g){
			vol = (*g).PI * (*g).radius * (*g).radius * (*g).height;
			cout<<"\nVolume of cylinder with radius "<<(*g).radius<<" and height "<<(*g).height<<" is : "<<vol;
		}
		
};

class cone{
	private :
		float vol;
	public :
		// (6)
		void calc_vol(geometry *g){
			vol = ((*g).PI * (*g).radius * (*g).radius * (*g).height)/3;
			cout<<"\nVolume of cone with radius "<<(*g).radius<<" and height "<<(*g).height<<" is : "<<vol;
		}
};

int main()
{
	float hg, rd;
	cout<<"Enter height	: ";
	cin>>hg;
	cout<<"Enter radius	: ";
	cin>>rd;
	// (7)
	geometry gmt(hg,rd);
	
	// (8)
	cylinder cyc;
	
	// (9)
	cyc.calc_vol(&gmt);
	
	// (10)
	cone cn;
	
	// (11)
	cn.calc_vol(&gmt);
	
	return 0;
}
