/*This is a program I built mostly for myself
It keeps track of your wage, your hours worked, and the dates worked*/

#include <iostream>
#include <fstream>
#include <vector>

#include <algorithm>
#include <iterator>

using namespace std;

int hrTMnt(int hour){//Hours to minutes
	int mins=0;
	mins+=((hour/100)*60);
	mins+=(hour%100);
	return(mins);
}

float mntTHr(int min){//Minutes to hours
	return(min/60.0*100);
}

void display_vector(const vector<int> &v){//Test function used to display vectors
    std::copy(v.begin(), v.end(),
        std::ostream_iterator<int>(std::cout, " "));
}

int main(){
	ifstream flsIn;
	ofstream flsOut;
	vector<int> hours,timeAmounts,dates;//Hours-start and end times, timeamounts-time spent in minutes, dates-date of the hours
	int wage=0,fileNum,h=0,total=0,removeMinutes;
	int choice=0,startH,endH,inputYear,inputMonth,inputDay;
	
	flsIn.open("Hours.txt");
	flsIn>>wage;
	while(flsIn>>fileNum){//Getting hours from text file
		hours.push_back(fileNum);
		if(h%2==1){
			total+=(hrTMnt(hours[h])-hrTMnt(hours[h-1]));
			timeAmounts.push_back(hrTMnt(hours[h])-hrTMnt(hours[h-1]));
		}
		h+=1;
	}
	flsIn.close();
	
	flsIn.open("Dates.txt");
	while(flsIn>>fileNum){//Getting dates from text file
		dates.push_back(fileNum);
	}
	flsIn.close();
	
	display_vector(dates);
	
	while(choice!=5){
		cout<<"\n(1)Check info\n(2)Change Wage\n(3)Add Hours\n(4)Remove Hours\n(5)Save and Exit\n";
		cin>>choice;
		if(choice==1){//Displaying info
			cout<<"Wage: $"<<(wage/100)<<"."<<(wage%100)<<"\n";
			cout<<"Total Hours: "<<(total/60.0)<<"\n";
			cout<<"Total Amount Owed: $"<<(((total/60.0)*wage)/100)<<"\n";
			cout<<"Start	Stop	Hours	Date"<<"\n";
			cout<<"_____________________________"<<"\n";
			for(int n=0;n<hours.size();n+=2){
				cout<<hours[n]<<"	"<<hours[n+1]<<"	"<<timeAmounts[n/2]/60.0<<"	";
				cout<<dates[(n/2)*3]<<"-"<<dates[(n/2)*3+1]<<"-"<<dates[(n/2)*3+2]<<"\n";
			}
			
		}else if(choice==2){//Entering new wage
			cout<<"Enter new wage w/o the decimal spot.\n";
			cin>>wage;
			
		}else if(choice==3){//Entering new hours
			cout<<"Enter starting hour.\n";
			cin>>startH;
			cout<<"Enter ending hour.\n";
			cin>>endH;
			cout<<"Enter the year.\n";
			cin>>inputYear;
			cout<<"Enter the month.\n";
			cin>>inputMonth;
			cout<<"Enter the day.\n";
			cin>>inputDay;
			hours.push_back(startH);
			hours.push_back(endH);
			dates.push_back(inputYear);
			dates.push_back(inputMonth);
			dates.push_back(inputDay);
			//TODO: Fix bug where hours entered and then display w/o saved to file breaks program
			
		}else if(choice==4){//Removing hours
			cout<<"Enter the amount of minutes to remove.\n";
			cin>>removeMinutes;
			while(removeMinutes>0){
				if(removeMinutes>hrTMnt(timeAmounts[0])){
					removeMinutes-=hrTMnt(timeAmounts[0]);
					timeAmounts[0]=0;
					dates[0]=0;
					dates[1]=0;
					dates[2]=0;
				}else{
					timeAmounts[0]=mntTHr(hrTMnt(timeAmounts[0])-removeMinutes);
				}
				if(timeAmounts[0]<=0){//Remove time amount
					//TODO: Fill this in
					for(int n=1;n<sizeof(timeAmounts);n++){
						timeAmounts[n-1]=timeAmounts[n];
					}
				}
			}
		}else if(choice!=5){
			cout<<"\n(1)Check info\n(2)Change Wage\n(3)Add Hours\n(4)Remove Hours\n(5)Exit\n";
		   	cin>>choice;
		}
	}
	flsOut.open("Hours.txt");
	flsOut<<wage<<"\n";//Writing back to the text files
	for(int n=0;n<hours.size();n+=2){//TODO: Don't add 0s and test this
		if(timeAmounts[n/2]!=0){
			flsOut<<hours[n]<<" "<<hours[n+1]<<"\n";
		}
	}
	flsOut.close();
	flsOut.open("Dates.txt");
	for(int n=0;n<dates.size();n+=3){//TODO: Don't add 0s and test this
		if(dates[n]!=0 || dates[n+1]!=0 || dates[n+2]!=0){
			flsOut<<dates[n]<<" "<<dates[n+1]<<" "<<dates[n+2]<<"\n";
		}
	}
	flsOut.close();
	return(0);
}
