/*This is a simple hangman game that I'm making just to kill time*/

#include <iostream>

std::string changeWord(std::string wrd, char c){
	std::string newWrd=wrd;
	for(int n=0;n<wrd.length();n++){
		if(wrd.split("")[n]==c){
			
		}
	}
	return(newWrd);
}

int main(){
	std::string man[]={   "O",
					"\n/","|","\\",
					  "\n/","\\"};
	std::string word;
	std::string guess;
	int tries=0;
	while(tries<8){
	   	std::cout<<"Guess your letter.\n";
		std::cin>>guess;
	}
	return(0);
}
