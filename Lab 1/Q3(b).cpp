#include <iostream>
#include <string>        // Needed to use string objects
#include <cctype>        // Needed for the toupper function
using namespace std;

int main()
{
	char ch;
	int vowelCount = 0;
	string sentence;
    cout << "Enter any sentence. \nI will display the sentence in uppercase and count for the vowels.\n\nYour sentence : ";
	getline(cin,sentence);
	cout<<endl<<endl;
	for(int pos=0; pos<sentence.length(); pos++)
    {
    	ch = toupper(sentence[pos]);
    	if(sentence[pos]=='A'||sentence[pos]=='E'||sentence[pos]=='I'||sentence[pos]=='O'||sentence[pos]=='U'
		||sentence[pos]=='a'||sentence[pos]=='e'||sentence[pos]=='i'||sentence[pos]=='o'||sentence[pos]=='u')
    		++vowelCount;
		cout<<ch;
	}
	cout<<"\n [ This sentence has "<<vowelCount<<" vowels.]"<<endl;
    return 0;
}
