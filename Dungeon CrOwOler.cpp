/*
*/

#include <iostream>

std::String displayMap(){
	std::String rtn="";
	for(std::String s1[]: map){
		for(std::String s2:s1){
			rtn+=s2+" ";
		}
		rtn+="\n";
	}
	return(rtn);
}

int main(){
	std::String[][] map;
	bool playerAlive=true;
	int[] playerSpot=[0,0];
	int playerMove;
	while(playerAlive){
		std::cin<<playerMove;
	}
	return(0);
}
