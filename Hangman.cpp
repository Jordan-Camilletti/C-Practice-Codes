/*This is a simple hangman game that I'm making just to kill time*/

#include <iostream>

int main(){
  std::String[] man=[];
  std::String word;
  std::String guess;
  int tries=0;
  while(tries<8){
    std::cout<<"Guess your letter.\n";
    std::cin>>guess;
  }
  return(0);
}
