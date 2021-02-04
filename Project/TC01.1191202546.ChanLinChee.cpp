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

/* Only a reasonable level of user input checking is needed.  
   Assume that a shopper or the owner will input text and numbers in good faith. */

// declare all needed header.
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

// global variable.
char test;

// class Check with 2 functions.
class Check{
	// can be access by any others function including main function.
	public : 
		// empty default constructor.
		Check(){
		}
		
		// print the output when the object of Check has been destructed.
		~Check(){
			cout<<"u";
		}
		
		// convert char array into string and return the string.
		string cvrtString(char *x, int size){
			string s="";
			for(int i=0;i<size;i++){
					s = s + x[i];
			}
			return s;
		}
		
		// remove all empty spaces in string and return the string (it is more accurate when we are comparing).
		string rmvSpace(string str){
			str.erase(remove(str.begin(),str.end(),' '),str.end());
			return str;
		}
};

// class Shopper with 5 functions. [Abstract class with 1 pure virtual function].
class Shopper{
	// can be access by inheritance/friend function but not main function.
	protected : 
		char fullName[50], userName[50], address[80], custType[20], passWord[10], course[30], depart[30];
		int custID;
		string id, fname, uname, ad, pw, cs, dpm;
	
	// can be access by any others function including main function.
	public :	
		// default constructor that automatically initialize some varibles when Shopper object has been created.
		Shopper(){
			custID = 0;
		}
		
		// print the output when the object of Shopper has been destructed.
		~Shopper(){
			cout<<"u";
		}
		
		// prompt user to insert password twice and ensure both string are equally same.
		void setPassW(){
			char p1[10], p2[10];
			int match;

			do{
				cout<<"\nEnter your password (combination of eight characters) : ";
				cin.getline(p1,10);
				cout<<"Re-enter your password : ";
				cin.getline(p2,10);
				match = strcmp(p1,p2);
				if(match!=0)
					cout<<"Both passwords are not same!\n";
			}while(match!=0);
			strcpy(passWord,p1);
			getCustID();					// call compiler to generated an ID.
			updateShopperData();			// insert shopper data into text file.
		}
		
		// scan file and generated an ID that following the sequence to user.
		void getCustID(){
			int n;
			string line, id;
			ifstream r;
			r.open("shopperData.txt");
	
			while(getline(r,line)){
				if(line=="")	continue;
				id = line.substr(0,3);
				stringstream convert(id);		// convert string to true numeric value.
				convert>>n;
			}
			custID = n+1;
			r.close();
		}
		
		// accessor function that return customer ID.
		int recustID(){
			return custID;
		}
		
		// append shopper data into text file.
		void updateShopperData(){
			int l1, l2, l3, l4, l5, l6, l7;
			char nm[50], usrnm[50], adds[80], type[20], pswd[10], cs[30], dp[30];			
			ofstream write;
			write.open("shopperData.txt",ios::app);
			
			l1 = strlen(fullName);							// insert data into text file one by one index.
			memset(nm, 0x20, sizeof(fullName)-1);
			memcpy(nm, fullName, l1);
			
			l2 = strlen(userName);
			memset(usrnm, 0x20, sizeof(userName)-1);
			memcpy(usrnm, userName, l2);
			
			l3 = strlen(address);
			memset(adds, 0x20, sizeof(address)-1);
			memcpy(adds, address, l3);
			
			l4 = strlen(custType);
			memset(type, 0x20, sizeof(custType)-1);
			memcpy(type, custType, l4);
			
			l5 = strlen(passWord);
			memset(pswd, 0x20, sizeof(passWord)-1);
			memcpy(pswd, passWord, l5);
			
			l6 = strlen(course);
			memset(cs, 0x20, sizeof(course)-1);
			memcpy(cs, course, l6);
			
			l7 = strlen(depart);
			memset(dp, 0x20, sizeof(depart)-1);
			memcpy(dp, depart, l7);
			
			write<<custID<<"|"<<nm<<"|"<<usrnm<<"|"<<adds<<"|"<<type<<"|"<<pswd<<"|"<<cs<<"|"<<dp;
			write.close();
		}
		
		// pure virtual function to ensure all derived class has display function.
		virtual void display(string,string)=0;
};

// class Customer with 2 functions (inherited publicly from Shopper).
// protected and public members in Shopper remain thier access specifier type.
class Customer:public Shopper{
	// can be access by any others function including main function.
	public : 
		// default constructor that automatically initialize some varibles when Customer object has been created.
		Customer(){
			strcpy(course,"empty");
			strcpy(depart,"empty");
		}
		
		// print the output when the object of Customer has been destructed. (Shopper will be destructed once also).
		~Customer(){
			cout<<"@mm";
		}
		
		// receive data that key in by user from main and store into certain private variables in object Customer.
		void setData(const char* fullN, const char* userN, const char* addr){
			strcpy(fullName,fullN);
			strcpy(userName,userN);
			strcpy(address,addr);
			strcpy(custType,"Normal Customer");
			setPassW();
		}
		
		// override the pure virtual function (display all necessary data).
		void display(string type,string username){
			string line;
			Check c;
			ifstream read;
			read.open("shopperData.txt");
			while(getline(read,line)){
				if(line=="")	continue;
				id = line.substr(0,3);
				fname = line.substr(4,49);
				uname = line.substr(54,49);
				ad = line.substr(104,79);
				pw = line.substr(204,8);
				
				string u = c.rmvSpace(uname);				// remove all spaces in the string.
				if(u==username){
					cout<<"User ID		: "<<id<<endl
					<<"User Type	: "<<type<<endl
					<<"Full Name	: "<<fname<<endl
					<<"Username	: "<<uname<<endl
					<<"Password	: "<<pw<<endl
					<<"Address		: "<<ad<<endl;
				}
			}
			read.close();
		}
};

// class MMUStudent with 2 functions (inherited publicly from Shopper).
// protected and public members in Shopper remain thier access specifier type.
class MMUStudent:public Shopper{
	// can be access by any others function including main function.
	public :
		// default constructor that automatically initialize some varibles when MMUStudent object has been created.
		MMUStudent(){
			strcpy(depart,"empty");
		}
		
		// print the output when the object of MMUStudent has been destructed. (Shopper will be destructed once also)
		~MMUStudent(){
			cout<<"@mm";
		}
		
		// receive data that key in by user from main and store into certain private variables in object MMUStudent.
		void setData(const char* fullN, const char* userN, const char* addr){
			strcpy(fullName,fullN);
			strcpy(userName,userN);
			strcpy(address,addr);
			strcpy(custType,"MMU Student");
			cout<<"Major Course : ";
			cin.getline(course,30);
			setPassW();
		}
		
		// override the pure virtual function (display all necessary data).
		void display(string type,string username){
			string line;
			Check c;
			ifstream read;
			read.open("shopperData.txt");
			while(getline(read,line)){
				if(line=="")	continue;
				id = line.substr(0,3);
				fname = line.substr(4,49);
				uname = line.substr(54,49);
				ad = line.substr(104,79);
				pw = line.substr(204,8);
				cs = line.substr(214,29);
				
				string u = c.rmvSpace(uname);				// remove all spaces in the string.
				if(u==username){
					cout<<"User ID		: "<<id<<endl
					<<"User Type	: "<<type<<endl
					<<"Full Name	: "<<fname<<endl
					<<"Username	: "<<uname<<endl
					<<"Password	: "<<pw<<endl
					<<"Address		: "<<ad<<endl
					<<"Major Course	: "<<cs<<endl;
				}
			}
			read.close();
		}
};

// class MMUStaff with 2 functions (inherited publicly from Shopper).
// protected and public members in Shopper remain thier access specifier type.
class MMUStaff:public Shopper{
	// can be access by any others function including main function.
	public : 
		// default constructor that automatically initialize some varibles when MMUStaff object has been created.
		MMUStaff(){
			strcpy(course,"empty");
		}
		
		// print the output when the object of MMUStaff has been destructed. (Shopper will be destructed once also)
		~MMUStaff(){
			cout<<"@mm";
		}
		
		// receive data that key in by user from main and store into certain private variables in object MMUStaff.
		void setData(const char* fullN, const char* userN, const char* addr){
			strcpy(fullName,fullN);
			strcpy(userName,userN);
			strcpy(address,addr);
			strcpy(custType,"MMU Staff");
			cout<<"Working Deparment : ";
			cin.getline(depart,30);
			setPassW();
		}
		
		// override the pure virtual function (display all necessary data).
		void display(string type,string username){
			string line;
			Check c;
			ifstream read;
			read.open("shopperData.txt");
			while(getline(read,line)){
				if(line=="")	continue;
				id = line.substr(0,3);
				fname = line.substr(4,49);
				uname = line.substr(54,49);
				ad = line.substr(104,79);
				pw = line.substr(204,8);
				dpm = line.substr(244,29);
				
				string u = c.rmvSpace(uname);				// remove all spaces in the string.
				if(u==username){
					cout<<"User ID		  : "<<id<<endl
					<<"User Type	  : "<<type<<endl
					<<"Full Name	  : "<<fname<<endl
					<<"Username	  : "<<uname<<endl
					<<"Password	  : "<<pw<<endl
					<<"Address		  : "<<ad<<endl
					<<"Working Deparment : "<<dpm<<endl;
				}
			}
			read.close();
		}
};

// class Item with 10 functions.
class Item{
	// can be access by function in class Item only. (others function and main function cannot).
	private : 
		int choice,sta;
		string line, id, type, name, company, unit, price, month, year, author, actor;
	
	// can be access by any others function including main function.
	public : 
		// default constructor that automatically initialize some varibles when Item object has been created.
		Item(){
			sta=0;
		}
		
		// print the output when the object of Item has been destructed.
		~Item(){
			cout<<"   @m";
		}
		
		// remove all empty spaces in string and return the string (it is more accurate when we are comparing).
		string rmvSpce(string str){
			str.erase(remove(str.begin(),str.end(),' '),str.end());
			return str;
		}
		
		// scan all data in file and display to the user.
		void viewItem(){
			cout<<"\n----------------------------------------------------\n"
			<<"::                      Menu                      ::\n"
			<<"----------------------------------------------------\n"
			<<"\t[1]  Magazine\n"<<"\t[2]  Book\n"<<"\t[3]  Movie\n"
			<<"\nEnter your choice : ";
			cin>>choice;
			system("cls");
			
			// prompt user to choose which type of item.
			if(choice==1){
				cout<<"\n----------------------------------------------------\n"
					<<"::                    Magazine                    ::\n"
					<<"----------------------------------------------------\n\n";		}
			else if(choice==2){
				cout<<"\n----------------------------------------------------\n"
					<<"::                      Book                      ::\n"
					<<"----------------------------------------------------\n\n";		}
			else if(choice==3){
				cout<<"\n----------------------------------------------------\n"
					<<"::                     Movie                      ::\n"
					<<"----------------------------------------------------\n\n";		}
			
			// open and read the text file called itemList.
			ifstream read;	
			read.open("itemList.txt");	
			
			// read line by line before end of the file.
			while(getline(read,line)){
				// get data and store as string.
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
				
				type = rmvSpce(type);				// remove all spaces in the string.
				stringstream convert(month);		// convert string to true numeric value.
				int m = 0;
				convert>>m;
				
				// assign the name of month by the numeric value of month.
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
					case 9 :	month = "September";
								break;
					case 10 :	month = "October";
								break;
					case 11 :	month = "November";
								break;
					case 12 :	month = "December";
								break;
				}
				
				// three conditions to display the item list.
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
			// close the text file after done using.
			read.close();
		}
		
		// receive itemID and unit as parameters, check if the itemID is available and the unit stocks is enough.
		void scanItem(int ii,int uu){
			ifstream read;
			read.open("itemList.txt");
			
			// read line by line before end of the file.
			while(getline(read,line)){
				id = line.substr(0,4);
				unit = line.substr(79,6);
				
				stringstream convert1 (id);
				stringstream convert2 (unit);
				int idd = 0;
				int unitt = 0;
				convert1>>idd;
				convert2>>unitt;
				
				// three possible results of the status.
				if(ii==idd){
					if(uu<=unitt){
						sta=0;
						break;		}
					else{
						cout<<"\n!!The stock is not enough.!!\n The available stock unit is "<<unitt<<".\n";
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
		
		// accessor function that return status. 
		int getSta(){
			return sta;
		}
		
		// scan the file and trace the item Name by using item ID (return the item ID as string).
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
		
		// scan the file and trace the item Price by using item ID (return the item Price as string).
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
		
		// scan the data in shopping cart file and display to the user. (return the status of shopping cart).
		int viewShoppingCart(){
			int n=1, c=0;
			string ln, vcid, vid, vnm, vp, vu;
			ifstream v;
			v.open("shoppingCart.txt");
			cout<<"\n---------------- Shopping Cart List ----------------";	

			while(getline(v,ln)){
				if(ln=="")	continue;
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
				c++;
			}
			if(c==0)	cout<<"\n\n Your shopping cart is emtpy!\n";
			cout<<"\n----------------------------------------------------\n";
			v.close();
			return c;
		}
		
		// scan the file and modify the specific line of item that user wish to. (return the status of cart ID).
		int modifyItem(){
			// prompt user to key in the item that wish to modify.
			int mod;
			cout<<"Which item you wish to modify in shopping cart?\n"<<"Cart ID : ";
			cin>>mod;
			
			// open and read the text file called itemList.
			string modify, x, cid, id, nm, p;
			int unitt,s=0;
			ifstream infile;
			infile.open("shoppingCart.txt");
			ofstream ofile;
			ofile.open("tempSC.txt");
			
			// read line by line before end of the file.
			while(getline(infile,modify)){
				if(modify=="")	continue;
				cid = modify.substr(0,2);
				id = modify.substr(3,4);
				nm = modify.substr(10,30);
				p = modify.substr(41,10);
				
				stringstream convert1(cid);
				int x=0;
				convert1>>x;
				stringstream convert2(id);
				int y=0;
				convert2>>y;
				
				if(x==mod){
					cout<<"\nHow many unit(s) you wish to buy for this item?\n Item unit : ";
					cin>>unitt;
					int sta=0;
					scanItem(y,unitt);
					sta = getSta();
					
					while(sta==1){
					cout<<"\nPlease re-enter an unit number : ";
					cin>>unitt;
					scanItem(y,unitt);
					sta = getSta();				}
					
					ofile<<setw(2)<<left<<cid<<"|"<<setw(6)<<id<<"|"<<setw(30)<<nm<<"|"<<setw(10)<<p<<"|"<<setw(4)<<unitt<<endl;
					s++;
				}
				else
					ofile<<modify<<endl;
			}
			// close the text file after done using.
			infile.close();
			ofile.close();
			
			// replace the old file with the 'temporary' file.
			remove("shoppingCart.txt");
			rename("tempSC.txt","shoppingCart.txt");
			return s;
		}
		
		// scan the file and remove the specific line of data that user wish to. (return the status of cart ID).
		int deleteItem(){
			// prompt user to key in the data that wish to remove.
			int did;
			cout<<"Which item you wish to remove from shopping cart?\n"<<"Cart ID : ";
			cin>>did;
			
			// open and read the text file called itemList.
			string dlt, x;
			int s=1;
			ifstream d;
			d.open("shoppingCart.txt");
			ofstream tempC;
			tempC.open("tempC.txt");
		
			// read line by line before end of the file.
			while(getline(d,dlt)){
				if(dlt=="")	continue;
				x = dlt.substr(0,2);			// get data and store as string.
				stringstream convert(x);		// convert string to true numeric value.
				int xx=0;
				convert>>xx;
				
				// if the line is not for deletion, insert into the 'temporary' file.
				if(did!=xx)
					tempC<<dlt<<endl;
				else
					s--;
			}
			cout<<"\n~Item with Cart ID ("<<did<<") has been deleted from your shopping cart~\n";
			// close the text file after done using.
			d.close();
			tempC.close();
			
			// replace the old file with the 'temporary' file.
			remove("shoppingCart.txt");
			rename("tempC.txt","shoppingCart.txt");
			return s;
		}
		
		// scan the file and calculate the total payment.
		void payment(int slsid,string cusid){
			cout<<fixed<<setprecision(2);
			cout<<"\t\tPAYMENT SECTION\n"<<"----------------------------------------------------\n";
			string pay, p, u, d, in;
			int num=0,card;
			float cartPrice=0.0, unit=0.0,price=0.0,total=0.0;
			ifstream paymt;
			paymt.open("shoppingCart.txt");
			while(getline(paymt,pay)){
				if(pay=="")	continue;
				d = pay.substr(3,4);
				in = pay.substr(10,30);
				p = pay.substr(41,10);
				u = pay.substr(52,4);
				
				stringstream convert1(p);
				convert1>>price;
				stringstream convert2(u);
				convert2>>unit;
				
				ofstream key;
				key.open("salesRecord.txt",ios::app);
				key<<endl<<left<<setw(3)<<slsid<<"|"<<setw(5)<<cusid<<"|"<<setw(5)<<d<<"|"<<setw(30)<<in<<"|"<<setw(4)<<unit<<"|"<<setw(10)<<price<<"|";
				
				num++;
				cartPrice = price*unit;
				total += cartPrice;
				cout<<":: Item "<<num<<" : RM "<<cartPrice<<endl;
				key.close();
			}
			paymt.close();
			cout<<"\n::: Total item    : "<<num<<endl
			<<"    Total Payment : RM "<<total<<endl
			<<"\nPlease enter card number to make payment [10 digits] : ";
			cin>>card;
			cin.ignore();
			system("cls");
			cout<<"\n [Thank you for your payment :D ]\n";
			cout<<"\n [Press ENTER key to proceed.] ";
			test = getchar();
			system("cls");
		}
};

// class Sales with 3 functions.
class Sales{
	// can be access by function in class Sales only. (others function and main function cannot).
	private : 
		int salesID;
	
	// can be access by any others function including main function.	
	public : 
		// default constructor that automatically initialize some varibles when Sales object has been created.
		Sales(){
			salesID = 0;
		}
		
		// print the output when the object of Item has been destructed.
		~Sales(){
			cout<<"m";
		}
		
		// scan file and generated an ID that following the sequence to user.
		int getSalesID(){
			int n;
			string line, id;
			ifstream r;
			r.open("salesRecord.txt");
	
			while(getline(r,line)){
				if(line=="")	continue;
				id = line.substr(0,3);
				stringstream convert(id);
				convert>>n;
			}
			salesID = n+1;
			r.close();
			return salesID;
		}
		
		// scan file and display the sales record to the user.
		int SalesRecord(string custidd){
			stringstream convert1(custidd);
			int cid=0, rc=0;
			convert1>>cid;
			string linee, salesid, customid, itmid, itmnm, unt,prc;
			ifstream vsr;
			vsr.open("salesRecord.txt");
						cout<<"\n----------------- Shopping Record ------------------\n"
			<<"\t\tYour user ID : "<<custidd
			<<"\n----------------------------------------------------";
			while(getline(vsr,linee)){
				if(linee=="")	continue;
				salesid = linee.substr(0,3);
				customid = linee.substr(4,5);
				itmid = linee.substr(10,5);
				itmnm = linee.substr(16,30);
				unt = linee.substr(47,4);
				prc = linee.substr(52,10);
				
				stringstream convert2(customid);
				int cid2 = 0;
				convert2>>cid2;

				if(cid==cid2){
					cout<<"\n:: Sales ID	: "<<salesid<<"\n   Item ID	: "<<itmid
					<<"\n   Item Name	: "<<itmnm<<"\n   Unit		: "<<unt<<"\n   Unit Price	: RM "<<prc<<endl;
					rc++;
				}
			}
			// if there are no record, inform the user.
			if(rc==0){
				cin.ignore();
				cout<<"\nYou have no past shopping record.\n";
				cout<<"\n [Press ENTER key to proceed.] ";
				test = getchar();
				system("cls");
			}
			vsr.close();
			return rc;
		}

		// scan the file and remove the specific line of data that user wish to.
		void deleteSalesRecord(){
			string rmid;
			int numm=0;
			cout<<"\n Enter a sales ID (all records of this ID will be removed) : ";
			cin>>rmid;
			stringstream convert1(rmid);
			int r1=0;
			convert1>>r1;
			string rm, x;
			ifstream dl;
			ofstream tempSR;
			dl.open("salesRecord.txt");
			tempSR.open("tempSR.txt");
			while(getline(dl,x)){
				if(x=="")	continue;
				rm = x.substr(0,2);
				stringstream convert2(rm);
				int r2=0;
				convert2>>r2;
				if(r2!=r1){
					tempSR<<x<<endl;		}
				else	numm ++;
			}
			system("cls");
			if(numm!=0){
				cout<<"\n [Record with Sales ID ("<<rmid<<") has been deleted from your the list]\n";
				cout<<"\n********************* UPDATED ********************** \n";
			}
			else if(numm==0)
				cout<<"\n [Your sales ID is invalid.]\n";
				
			dl.close();
			tempSR.close();
			remove("salesRecord.txt");
			rename("tempSR.txt","salesRecord.txt");
		}
		
		// trace the data between upper and lower limit
		void salesPurchase(string custidd){
			stringstream convert1(custidd);
			int cid=0, rc=0;
			convert1>>cid;
			string linee, salesid, customid, itmid, itmnm, unt, prc;
			ifstream vsr;
			vsr.open("salesRecord.txt");
			cout<<"\n----------------------------------------------------\n"
			<<"\t\tYour user ID : "<<custidd
			<<"\n----------------------------------------------------";
			
			// prompt user to enter upper and lower limit
			float upper, lower;
			cout<<"\nInsert a upper limit : RM ";
			cin>>upper;
			cout<<"Insert a lower limit : RM ";
			cin>>lower;
			
			while(upper<=lower){
				cout<<"\n Invalid range.\n";
				cout<<"\nInsert a upper limit : RM ";
				cin>>upper;
				cout<<"Insert a lower limit : RM ";
				cin>>lower;
			}
			
			system("cls");
			
			// read the data from file
			while(getline(vsr,linee)){
				if(linee=="")	continue;
				salesid = linee.substr(0,3);
				customid = linee.substr(4,5);
				itmid = linee.substr(10,5);
				itmnm = linee.substr(16,30);
				unt = linee.substr(47,4);
				prc = linee.substr(52,10);
				
				// convert string into float to compare
				stringstream convert2(customid);
				int cid2 = 0;
				convert2>>cid2;
				
				stringstream convert3(prc);
				float price=0;
				convert3>>price;			
				
				if(cid==cid2 && price<=upper && price>=lower){
						cout<<"\n-------------------------------------------------------------"<<fixed<<setprecision(2)
						    <<"\n Sales Record : Unit Price Between RM "<<lower<<" and RM "<<upper 
						    <<"\n-------------------------------------------------------------"
						<<"\n:: Sales ID	: "<<salesid<<"\n   Item ID	: "<<itmid
						<<"\n   Item Name	: "<<itmnm<<"\n   Unit		: "<<unt<<"\n   Unit Price	: RM "<<fixed<<setprecision(2)<<price<<endl;
						rc++;
				}
			}
			// if there are no record, inform the user.
			if(rc==0)
				cout<<"\n [You have no past shopping record between the unit price range.]\n";
			vsr.close();
		}
};

int main(){
	// declare all the variables.
	char ans, cont;	
	char fullN[50]={}, userN[50]={}, addr[80]={};
	int custT, id, choice, noacc, login;
	string username, password, dltline, custidd, ln, u, p, type;
	Customer cust;
	MMUStudent stud;
	MMUStaff stff;
	Check chk;
	Item *itm = new Item;			// dynamic memory allocation.
	Sales *sls = new Sales; 		// dynamic memory allocation.
	
	do{
		// display the banner.
		cout<<"====================================================\n"
		<<"\t    WELCOME TO MMU SHOPPING KIOSK\n====================================================";
	
		// prompt user to key in whether is new customer or have an account.
		cout<<"\nAre you a new customer? [Y/N] : ";
		cin>>ans;
		ans = toupper(ans);
		system("cls");
		cin.ignore();
	
		// if user is new customer, prompt user to register an new account.
		if(ans=='Y'){
			cout<<"----------------------------------------------------\n"
			<<"\t       REGISTRATION SECTION\n----------------------------------------------------\n"
			<<"[Please enter your personal information carefully.]\n\n";
		
			// prompt user to insert personal data.
			cout<<"Full Name as IC	: ";
			cin.getline(fullN,50);
			cout<<"Username	: ";
			cin.getline(userN,50);	
			cout<<"Home Address	: ";
			cin.getline(addr,80);
			cout<<"\n[1]  Normal Customer\n"
			<<"[2]  MMU Student\n"
			<<"[3]  MMU Staff\n\n"
			<<"Enter your type : ";
			cin>>custT;
			cin.ignore();
		
			// check customer type to prompt user to enter further data.
			switch(custT){
				case 1 :	cust.setData(fullN,userN,addr);
							break;
				case 2 :	stud.setData(fullN,userN,addr);
							break;
				case 3 :	stff.setData(fullN,userN,addr);
							break;								}
			system("cls");
			cout<<"\n**************** Done Registration *****************\n";
		}
		else{
			cout<<"\n****************** Welcome Back! *******************\n";			}
	
		// after registration, it is login phase. 
		// prompt user to key in username and password.
		fflush(stdin);
		cout<<"\n----------------------------------------------------\n"
		<<"\t\t     LOGIN\n----------------------------------------------------\n";
		cout<<"Enter your username	: ";
		getline(cin,username);
		cout<<"Enter your password	: ";
		getline(cin,password);
	
		// scan the shopper data file to check whether the user account is exist.
		ifstream lg;
		lg.open("shopperData.txt");
	
		// read line by line before end of the file. 
		while(getline(lg,ln)){
			if(ln=="")	continue;
		
			// get data and store as string.
			custidd = ln.substr(0,3);
			type = ln.substr(184,19);
			u = ln.substr(54,49);
			p = ln.substr(204,8);
		
			//remove all spaces in the string.
			type = chk.rmvSpace(type);
			u = chk.rmvSpace(u);
			p = chk.rmvSpace(p);
			username = chk.rmvSpace(username);
			password = chk.rmvSpace(password);
		
			// compare the user-keyin-data with the data in file.
			// there are three possible result.
			if(username==u){
				if(password==p){
					login=0;			// username and password are tally.
					break;		}
				else{
					cout<<"\nWrong Password!\n";	// username is correct, but password is wrong.
					login=2;
					break;		}					}
			else{
				login = 1;		}		// no record on his/her account.
		}
		lg.close();
	
		// terminate the program and ask user to restart the program to register a new account.
		if(login==1){
			//cin.ignore();
			cout<<"\n Invalid Username!";
			cout<<"\n Please do a registration for a new account.\n Thank You :)\n\n";
			cout<<"\n [Press ENTER key to proceed.] ";
			test = getchar();
			system("cls");					}
	}while(login==1);
		
	// prompt user to key in correct password as long as it is not tally.
	while(login==2){
		cout<<"Re-enter password : ";
		getline(cin,password);
		
		// compare the user-keyin-password with the data in file.
		ifstream chkpw;
		chkpw.open("shopperData.txt");
		string testP, np;
		while(getline(chkpw,testP)){
			if(testP=="")	continue;
			
			np = testP.substr(204,8);
			np = chk.rmvSpace(np);
			password = chk.rmvSpace(password);
			
			// assign the status according to the results of comparison.
			if(password==p){
				login=0;	
				break;		}
			else{
				login=2;		}
		}
		chkpw.close();		// close the file.
	}
	system("cls");
	cout<<"\n***************** Successful Login! ****************\n\n";
	
	// keep looping as long as user do not log out.
	do{
		// prompt user to view certain feature.
		int itemID, unit, cartID=0;
		cout<<"----------------------------------------------------\n"
		<<"\t[1]  Shopping Gallery\n"<<"\t[2]  Shooping Record\n"<<"\t[3]  Profile\n"
		<<"----------------------------------------------------\n"
		<<"Enter a command : ";
		cin>>choice;
		system("cls");
		
		// user going to shopping gallery.
		if(choice==1){
			char j;
			string itemName, itemPrice;
			do{
				itm->viewItem();
				cout<<"----------------------------------------------------\n";
				ofstream add;
				add.open("shoppingCart.txt",ios::app);
				
				cout<<"Which item you wish to add to shopping cart?\n Item ID : ";
				cin>>itemID;
				cout<<"\nHow many unit(s) you wish to add?\n Item unit : ";
				cin>>unit;
				
				int sta;
				itm->scanItem(itemID,unit);
				sta = itm->getSta();
				
				while(sta==2){
					cout<<"Item ID : ";
					cin>>itemID;
					cout<<"Item unit : ";
					cin>>unit;
					itm->scanItem(itemID,unit);
					sta = itm->getSta();				}
				
				while(sta==1){
					cout<<"\nPlease re-enter an unit number : ";
					cin>>unit;
					itm->scanItem(itemID,unit);
					sta = itm->getSta();				}
				
				cartID++;
				itemName = itm->traceName(itemID);
				itemPrice = itm->tracePrice(itemID);
				
				add<<setw(2)<<left<<cartID<<"|"<<setw(6)<<itemID<<"|"<<setw(30)<<itemName<<"|"<<setw(10)<<itemPrice<<"|"<<setw(4)<<unit<<endl;
				
				system("cls");
				cout<<"\n~~~ This item has been added into your shooping cart successfully. ~~~\n";
				cout<<"\n Do you wish to purchase more items? [Y/N] : ";
				cin>>j;
				j = toupper(j);
				add.close();
				system("cls");
			}while(j=='Y');
			
			int r;
			cout<<"\n----------------------------------------------------\n"
			<<"[1]  Modify item in shopping cart.\n"
			<<"[2]  Delete item in shopping cart.\n"
			<<"[3]  Checkout/Proceed to payment section.\n"
			<<"[4]  Left shopping gallery. (Your shopping cart record will be deleted!!)\n"
			<<"\nChoose a command : ";
			cin>>r;
			system("cls");
			
			while(r==1||r==2){
				if(r==1){
					int s, em;
					em = itm->viewShoppingCart();
					if(em!=0){
						s = itm->modifyItem();
						cin.ignore();
						system("cls");
						if(s==0)	cout<<"\n Your cart ID is invalid.\n";
						cout<<"\n********************* UPDATED ********************** \n";
						itm->viewShoppingCart();
						cout<<"\n [Press ENTER key to proceed.] ";
						test = getchar();
					}
					else{
						cin.ignore();
						cout<<"\n [Press ENTER key to proceed.] ";
						test = getchar();
						system("cls");
					}
				}
				else if(r==2){
					int s, em;
					em = itm->viewShoppingCart();
					if(em!=0){
						s = itm->deleteItem();
						cin.ignore();
						system("cls");
						if(s==1)	cout<<"\n Your cart ID is invalid.\n";
						cout<<"\n********************* UPDATED ********************** \n";
						itm->viewShoppingCart();
						cout<<"\n [Press ENTER key to proceed.] ";
						test = getchar();
					}
					else{
						cin.ignore();
						cout<<"\n [Press ENTER key to proceed.] ";
						test = getchar();
						system("cls");
					}
				}
				system("cls");
				cout<<"\n----------------------------------------------------\n"
				<<"[1]  Wish to modify another item.\n"
				<<"[2]  Wish to delete another item.\n"
				<<"[3]  Checkout/Proceed to payment section.\n"
				<<"[4]  Left shopping gallery. (Your shopping cart record will be deleted!!)\n"
				<<"\nChoose a command : ";	
				cin>>r;
				system("cls");
			}

			if(r==3){
				int slsid, cart;
				slsid = sls->getSalesID();
				cart = itm->viewShoppingCart();
				if(cart==0){
					remove("shoppingCart.txt");	
					cin.ignore();
					cout<<"\n [Your shopping is emtpy!!!]\n";
					cout<<"\n [Press ENTER key to proceed.] ";
					test = getchar();
					system("cls");					
				}
				else{
				itm->payment(slsid,custidd);
				remove("shoppingCart.txt");					
				}
			}
			else if(r==4){
				remove("shoppingCart.txt");
			}	
		}
		// user going to shopping record.
		else if(choice==2){
			int rc;
			char feature;
			rc = sls->SalesRecord(custidd);
		
			// if there are past shopping record, prompt user to decide whether wish to remove a record.
			if(rc>=1){
				char dltrc;
				cout<<"\n Do you wish to delete any shopping record? [Y/N]: ";
				cin>>dltrc;
				dltrc = toupper(dltrc);
				
				while(dltrc=='Y'){
					sls->deleteSalesRecord();
					rc = sls->SalesRecord(custidd);
					
					if(rc>=1){
						cout<<"\n Do you wish to delete more record? [Y/N]: ";
						cin>>dltrc;
						dltrc = toupper(dltrc);	
					}
					else
						dltrc = 'N';
				}
			}
			if(rc!=0){
				system("cls");
				cout<<"\n Do you wish to view the shopping record based on unit price range? [Y/N] : ";
				cin>>feature;
				feature = toupper(feature);
				system("cls");
				
				if(feature=='Y'){
				// use sales object to call function and passing variable customerID;
				sls->salesPurchase(custidd);
				cin.ignore();
				cout<<"\n [Press ENTER key to proceed.] ";
				test = getchar();
				system("cls");
				}
			}
		}
		// user going to profile page.
		else if(choice==3){
			int t;
			
			if(type=="NormalCustomer")
				t = 10;
			else if(type=="MMUStudent")
				t = 20;
			else if(type=="MMUStaff")
				t = 30;
			
			// Display user profile
			cout<<"\n----------------------------------------------------\n"
			    <<"::              Profile Information               ::\n"
			    <<"----------------------------------------------------\n";
			switch(t){
				case 10 :	cust.display(type,username);
							break;	
				case 20 :	stud.display(type,username);
							break;				
				case 30 :	stff.display(type,username);
							break;							}
			int z;
			cout<<"\t-----------------------\n"<<"\t[1]  Modify Information\n"
			<<"\t[2]  De-registration\n"<<"\t[3]  Back\n"<<"\t-----------------------\n"<<"Enter a command : ";
			cin>>z;
			system("cls");
			
			// update user profile data.
			if(z==1){
				cout<<"\n----------------------------------------------------\n"
				    <<"             Update Profile Information             "
				    <<"\n----------------------------------------------------\n";
				
				string x, unm, uunm, uad, upw, uty, ucs,udp, p1, p2;
				ifstream file;
				file.open("shopperData.txt");
				ofstream ofile;
				ofile.open("tempSD.txt");
				
				while(!file.eof()){
					getline(file,x);
					
					if(x=="")	continue;
					
					if(x==ln){
						fflush(stdin);
						cout<<"\nFull Name	: ";	getline(cin,unm);
						cout<<"Username	: ";	getline(cin,uunm);
						username = uunm;
						cout<<"Address		: ";	getline(cin,uad);
						
						do{
							cout<<"\nEnter your password (combination of eight characters) : ";
							getline(cin,p1);
							cout<<"Re-enter your password : ";
							getline(cin,p2);
							if(p1!=p2)
								cout<<"Both passwords are not same!\n";
						}while(p1!=p2);
						
						if(type=="NormalCustomer"){
							uty = "Normal Customer";
							ucs = "empty";
							udp = "empty";
						}
						else if(type=="MMUStudent"){
							uty = "MMU Student";
							cout<<"Course	: "; 	getline(cin,ucs);
							udp = "empty";
						}
						else if(type=="MMUStaff"){
							uty = "Normal Customer";
							ucs == "empty";
							cout<<"Department	: "; 	getline(cin,udp);
						}
						ofile<<left<<setw(3)<<custidd<<"|"<<setw(49)<<unm<<"|"<<setw(49)<<uunm<<"|"<<setw(79)<<uad<<"|"
						<<setw(19)<<uty<<"|"<<setw(9)<<p1<<"|"<<setw(29)<<ucs<<"|"<<setw(29)<<udp<<endl;
					}
					else
						ofile<<x<<endl;
				}
				file.close();
				ofile.close();
				remove("shopperData.txt");
				rename("tempSD.txt","shopperData.txt");
				
				system("cls");
				cout<<"\n**************** Successful Update! ****************\n\n";
				
				// display updated profile.
				cout<<"----------------------------------------------------\n"
			        <<"::          Updated Profile Information           ::\n"
			        <<"----------------------------------------------------\n";
				switch(t){
				case 10 :	cust.display(type,username);
							break;	
				case 20 :	stud.display(type,username);
							break;				
				case 30 :	stff.display(type,username);
							break;										}
				cout<<"\n\n [Press ENTER key to proceed.] ";
				test = getchar();
			}
			// de-registration the account.
			else if(z==2){
				char deac;
				cout<<"\n----------------------------------------------------\n"
				<<" Are you confirm to de-register you account?\n [Y - Yes]\n [N -  No]\n\n >>> ";
				cin>>deac;
				deac = toupper(deac);
				
				if(deac=='Y'){
					string linee;
					ifstream fin;
					fin.open("shopperData.txt");
					ofstream temp;
					temp.open("temp.txt");
				
					while(getline(fin,linee)){
						if(linee!=ln)
							temp<<linee<<endl;			}
					temp.close();
					fin.close();
					remove("shopperData.txt");
					rename("temp.txt","shopperData.txt");
					cin.ignore();
					system("cls");	
					cout<<"\n!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n"
					<<" You have successfully de-registered your account.\n"
					<<" You are required to register a new account in future visit.\n"
					<<"\n\n [Press ENTER key to proceed.] ";
					test = getchar();
					break;		// skip log out phase and direct display the end banner.
				}
			}
		}
		system("cls");
		
		// prompt user to decide back to home or log out.
		cout<<"\nDo you wish to log out? [Y/N]: ";
		cin>>cont;
		cont = toupper(cont);
		system("cls");
	
		// double confirm user if wish to log out.
		if(cont=='Y'){
			cout<<"----------------------------------------------------\n"
			<<"\t\t\tLOG OUT\n"
			<<"----------------------------------------------------\n"
			<<" Confirm log out?			   [Y - Yes]"
			<<"\n Nah, I don't decide to leave now~	   [N -  No]\n\n >>> ";
			cin>>cont;
			cont = toupper(cont);							}	

		system("cls");
	}while(cont!='Y');
	
	system("cls");
	// display footer.
	cout<<"\n=======================================================\n";
	cout<<"\n Hope you're enjoy shopping and happy with our service.\n\n Also, wish you have a nice day. ^v^\n"
	<<"\n=======================================================\n";
	delete itm;
	delete sls;
	return 0;
	// the watermark @mmu that shown by destructor.
}



