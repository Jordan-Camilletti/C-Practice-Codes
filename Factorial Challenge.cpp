/*Here's a challenge that's a bit more mathematical in nature.
Write a program that determines the number of trailing zeros at the end of X! (X factorial), where X is an arbitrary number.
For instance, 5! is 120, so it has one trailing zero. (How can you handle extremely values, such as 100!?) 
The input format should be that the program asks the user to enter a number, minus the !. */

#include <iostream>
using namespace std;

int main(){
	int x;
	int tot=1;
	int divisa=1;
	int divisaCount=0;
	cout<<"Enter your number.\n";
	cin>>x;
	for(int n=x;n>0;n--){
		tot=tot*n;
	}
	while(true){
		if(tot%divisa!=0){
			break;
		}
		divisa=divisa*10;
		divisaCount++;
	}
	cout<<x<<"! equals "<<tot<<", which has "<<divisaCount-1<<" zero(s) trailing it.";
	return 0;
}
