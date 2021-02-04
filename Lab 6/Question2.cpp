#include<iostream>
#include<iomanip>
using namespace std;

class Books{
	private : 
		string isbnNo, title, author;
		float price, discountedprice, discountperc;
	
	public :
		void set_Data();
		void calcDisountedPrice();
		void print();
		float getDiscountedPrice();
		~Books();
};

void Books::set_Data()
{
	cout<<"\nEnter ISBN		: ";
	getline(cin,isbnNo);
	cout<<"Enter Title		: ";
	getline(cin,title);
	cout<<"Enter Author's Name	: ";
	getline(cin,author);
	cout<<"Enter Price		: RM ";
	cin>>price;
	cout<<"Enter discount (%)	: ";
	cin>>discountperc;
	cin.ignore();
}

void Books::calcDisountedPrice()
{
	discountedprice = price - (price*discountperc/100);
}

void Books::print()
{
	cout<<"--------------------------------------------------------\n"
	<<"\t\t Book Details\n--------------------------------------------------------\n"
	<<"ISBN               : "<<isbnNo<<endl
	<<"Title              : "<<title<<endl
	<<"Author             : "<<author<<endl
	<<"Original Price     : RM "<<fixed<<setprecision(2)<<price<<endl
	<<"Discounted Price   : RM "<<discountedprice<<endl<<endl;
}

float Books::getDiscountedPrice()
{
	return discountedprice;
}

Books::~Books()
{
	cout<<"\n------------Thank you------------\n";
}

void func(Books &B)
{
	B.set_Data();
	B.calcDisountedPrice();
	B.print();
}

int main()
{
	float mostExps=0, booksDisc=0;
	Books B1;
	cout<<"Enter data for new incoming book this Month......\n";
	func(B1);
	Books B2[5];
	cout<<"\n\nNow we shall enter and display data for 5 special books...\n";
	for(int i=0;i<5;i++){
		func(B2[i]);
		if(B2[i].getDiscountedPrice()>mostExps)
			mostExps = B2[i].getDiscountedPrice();
		if(B2[i].getDiscountedPrice()<30)
			booksDisc++;
	}
	cout<<"\n--------------------------------------------------------\n"
	<<"The most expensive books is RM "<<mostExps<<endl
	<<"The number of books that are below RM 30 are : "<<fixed<<setprecision(0)<<booksDisc<<endl;
	
	return 0;
}
