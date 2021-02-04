/**********|**********|**********|
Program: TC01.1191202546.ChanLinChee.cpp
Course: Object Oriented Programming
Year: 2010/11 Trimester 1
Name: Chan Lin Chee
ID: 1191202546
Lecture Section: TC01
Tutorial Section: TT01
Email: 1191202546@student.mmu.edu.my [michellechan7219@gmail.com]
Phone: 016-3577219
**********|**********|**********/

#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<cmath>
#include<cctype>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;

class Item{
	private : 
		int choice,sta;
		string line, id, type, name, company, unit, price, month, year, author, actor;
	
	public : 
		Item(){
		}
		
		~Item(){
		}
		
		string rmvSpce(string str){
			str.erase(remove(str.begin(),str.end(),' '),str.end());
			return str;
		}
		
		void viewItem(){
			cout<<"----------------------- Menu -----------------------\n"
			<<"\t[1]  Magazine\n"<<"\t[2]  Book\n"<<"\t[3]  Movie\n"
			<<"\nEnter your choice : ";
			cin>>choice;
			
			if(choice==1){
				cout<<"\n--------------------- Magazine ---------------------\n";
			}
			else if(choice==2){
				cout<<"\n----------------------- Book -----------------------\n";
			}
			else if(choice==3){
				cout<<"\n---------------------- Movie -----------------------\n";
			}
	
			ifstream read;
			read.open("itemList.txt");
	
			while(getline(read,line)){
				id = line.substr(0,4);
				type = line.substr(6,10);
				name = line.substr(17,30);
				company = line.substr(48,30);
				unit = line.substr(79,6);
				price = line.substr(86,10);
				month = line.substr(97,3);
				year = line.substr(101,5);
				author = line.substr(107,20);
				actor = line.substr(128,20);
				
				type = rmvSpce(type);
				stringstream convert(month);
				int m = 0;
				convert>>m;
				
				switch(m){
					case 1 :	month = "January";
								break;
					case 2 :	month = "February";
								break;
					case 3 :	month = "March";
								break;
					case 4 :	month = "April";
								break;
					case 5 :	month = "May";
								break;
					case 6 :	month = "June";
								break;
					case 7 :	month = "July";
								break;
					case 8 :	month = "August";
								break;
					case 9 :	month = "Septembet";
								break;
					case 10 :	month = "October";
								break;
					case 11 :	month = "November";
								break;
					case 12 :	month = "December";
								break;
				}
				
				if(choice==1 && type=="Magazine"){
					cout<<":: Item ID			: "<<id<<endl
					<<"   Item Name			: "<<name<<endl
					<<"   Publisher/Compnany Name	: "<<company<<endl
					<<"   Item Price			: "<<price<<endl
					<<"   Available Stock Unit		: "<<unit<<endl
					<<"   Publish Details		: "<<month<<" in year "<<year<<endl<<endl;
				}
				else if(choice==2 && type=="Book"){
					cout<<":: Item ID			: "<<id<<endl
					<<"   Item Name			: "<<name<<endl
					<<"   Publisher/Compnany Name	: "<<company<<endl
					<<"   Item Price			: "<<price<<endl
					<<"   Available Stock Unit		: "<<unit<<endl
					<<"   Author			: "<<author<<endl<<endl;
				}
				else if(choice==3 && type=="Movie"){
					cout<<":: Item ID			: "<<id<<endl
					<<"   Item Name			: "<<name<<endl
					<<"   Publisher/Compnany Name	: "<<company<<endl
					<<"   Item Price			: "<<price<<endl
					<<"   Available Stock Unit		: "<<unit<<endl
					<<"   Main Actor/Actress		: "<<actor<<endl<<endl;
				}

			}
			read.close();
		}
		
		void scanItem(int ii,int uu){
			ifstream read;
			read.open("itemList.txt");
	
			while(getline(read,line)){
				id = line.substr(0,4);
				unit = line.substr(79,6);
				
				stringstream convert1 (id);
				stringstream convert2 (unit);
				int idd = 0;
				int unitt = 0;
				convert1>>idd;
				convert2>>unitt;

				if(ii==idd){
					if(uu<=unitt){
						sta=0;
						break;		}
					else{
						cout<<"\n!!The stock is not enough.!!";
						sta=1;
						break;		}
				}
				else
					sta=2;
			}
			if(sta==2)
				cout<<"\nInvalid Item ID. Please retry.\n\n";
			read.close();
		}
		
		int getSta(){
			return sta;
		}
		
		string traceName(int itemID){
			ifstream tn;
			tn.open("itemList.txt");
			string line, i, name;
			
			while(getline(tn,line)){
				i = line.substr(0,4);
				stringstream convert(i);
				int id = 0;
				convert>>id;
				
				if(itemID==id){
					name = line.substr(17,30);		}
			}
			tn.close();
			return name;
		}
		
		string tracePrice(int itemID){
			ifstream tp;
			tp.open("itemList.txt");
			string line, i, price;
			
			while(getline(tp,line)){
				i = line.substr(0,4);
				stringstream convert(i);
				int id = 0;
				convert>>id;
				
				if(itemID==id){
					price = line.substr(86,10);		}
			}
			tp.close();
			return price;
		}
		
		void viewShoppingCart(){
			int n=1;
			string ln, vcid, vid, vnm, vp, vu;
			ifstream v;
			v.open("shoppingCart.txt");
			cout<<"\n---------------- Shopping Cart List ----------------";	
			
			while(getline(v,ln)){
				vcid = ln.substr(0,2);
				vid = ln.substr(3,4);
				vnm = ln.substr(10,30);
				vp = ln.substr(41,10);
				vu = ln.substr(52,4);
				
				cout<<"\n::Item "<<n++<<endl
				<<"  Cart ID	: "<<vcid<<endl
				<<"  Item ID	: "<<vid<<endl
				<<"  Item Name	: "<<vnm<<endl
				<<"  Item Price	: RM "<<vp<<endl
				<<"  Item Units	: "<<vu<<endl;
			}
			cout<<"\n----------------------------------------------------\n";
			v.close();
		}
		
		void modifyItem(){
			
		}
		
		void deleteItem(){
			int did;
			cout<<"Which item you wish to remove from shopping cart?\n"<<"Cart ID : ";
			cin>>did;
			
			string dlt, x;
			ifstream d;
			d.open("shoppingCart.txt");
			ofstream tempC;
			tempC.open("tempC.txt");
			
			while(getline(d,dlt)){
				x = dlt.substr(0,2);
				stringstream convert(x);
				int xx=0;
				convert>>xx;
				if(did!=xx)
					tempC<<dlt<<endl;
			}
			cout<<"\n~Item with Cart ID ("<<did<<") has been deleted from your shopping cart~\n";
			d.close();
			tempC.close();
			remove("shoppingCart.txt");
			rename("tempC.txt","shoppingCart.txt");
		}
		
		void payment(){
			cout<<fixed<<setprecision(2);
			cout<<"\t\tPAYMENT SECTION\n"<<"----------------------------------------------------\n";
			string pay, p, u;
			int num=0;
			float cartPrice=0.0, unit=0.0,price=0.0,total=0.0;
			ifstream paymt;
			paymt.open("shoppingCart.txt");
			while(getline(paymt,pay)){
				p = pay.substr(41,10);
				u = pay.substr(52,4);
				
				stringstream convert1(p);
				convert1>>price;
				stringstream convert2(u);
				convert2>>unit;
				
				num++;
				cartPrice = price*unit;
				total += cartPrice;
				cout<<":: Item "<<num<<" : RM "<<cartPrice<<endl;
			}
			paymt.close();
			cout<<"\n::: Total item    : "<<num<<endl
			<<"    Total Payment : RM "<<total<<endl;
		}
};


