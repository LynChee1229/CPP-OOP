#include<iostream>
using namespace std;

int main()
{     
	int x = 8, y = 2, z;
	cout << ++x << endl;			// 9 (8+1)
	cout << x << endl;				// 9
	cout << x-- << endl;			// 9 (memory store x=8)
	cout << x + y << endl;			// 10 (8+2)
	cout << x <<" "<< y << endl;	// 8  2
	cout << "x * x = "; 			// x * x =
	cout << x * x << endl;			// 64 (8*8)
	cout << y++ << endl;			// 2 (memory store y=3)
	z = x % y;						// (z = 8 % 3 = 2)
	cout << z << endl;				// 2 
	return 0;
}

