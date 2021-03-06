//This is just a text-only baseball game
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int* hitSingle(int base[]){
	base[0]+=1;
    while(base[0]>=2||base[1]>=2||base[2]>=2){
    	if(base[0]>=2){
        	base[0]=1;
            base[1]+=1;
        }
        if(base[1]>=2){
            base[1]=1;
            base[2]+=1;
        }
        if(base[2]>=2){
            base[2]=1;
            base[3]+=1;
        }
    }
    return base;
}
int* hitDouble(int base[]){
    base[1]+=1;
    if(base[0]==1){
        base[0]=0;
        base[2]+=1;
    }
    while(base[0]>=2||base[1]>=2||base[2]>=2){
        if(base[0]>=2){
            base[0]=1;
            base[2]+=1;
        }
        if(base[1]>=2){
            base[1]=1;
            base[3]+=1;
        }
        if(base[2]>=2){
            base[2]=1;
            base[3]+=1;
        }
    }
    return base;
}
int* hitTriple(int base[]){
    base[2]+=1;
    if(base[0]==1){
        base[0]=0;
        base[3]+=1;
    }
    if(base[1]==1){
        base[1]=0;
        base[3]+=1;
    }
    while(base[0]>=2||base[1]>=2||base[2]>=2){
        if(base[0]>=2){
            base[0]=1;
            base[3]+=1;
        }
        if(base[1]>=2){
            base[1]=1;
            base[3]+=1;
        }
        if(base[2]>=2){
            base[2]=1;
            base[3]+=1;
        }
    }
    return base;
}
int* hitHomeRun(int base[]){
    base[3]+=base[0]+base[1]+base[2]+1;
    base[0]=0;
    base[1]=0;
    base[2]=0;
    return base;
}

int main(){
    int b[4]={0,0,0,0};//b[3]==home
    string inn[9]={"1st","2nd","3rd","4th","5th","6th","7th","8th","9th"};
    int *bases;
    int myScore=0;
    int enemyScore=0;
    int outs=0;
    int hit=rand()%100;//50-100=out, 50-30=single, 30-15=double, 15-5=triple, 5-0=home run
    srand(time(NULL));
    for(int inning=0;inning<9;inning++){
        b[0]=0;
        b[1]=0;
        b[2]=0;
        b[3]=0;
        outs=0;
        cout<<"Top of the "<<inn[inning]<<"\n";
        while(outs!=3){
        	hit=rand()%100;
           	if(hit>=50){
            	outs+=1;
                cout<<"You struck out.\n";
            }else if(hit>=30){
                bases=hitSingle(b);
                cout<<"You got a single.\n";
            }else if(hit>=15){
                bases=hitDouble(b);
                cout<<"You got a double.\n";
			}else if(hit>=5){
                bases=hitTriple(b);
                cout<<"You got a triple.\n";
            }else if(hit>=0){
                bases=hitHomeRun(b);
                cout<<"You got a home run.\n";
            }
        }
        myScore+=bases[3];
        cout<<"\nBottom of the "<<inn[inning]<<"\n";
        outs=0;
        while(outs!=3){
            hit=rand()%100;
            if(hit>=50){
                outs+=1;
                cout<<"Opposing team stuck out.\n";
            }else if(hit>=30){
                bases=hitSingle(b);
                cout<<"Opposing team got a single.\n";
            }else if(hit>=15){
                bases=hitDouble(b);
                cout<<"Opposing team got a double.\n";
            }else if(hit>=5){
                bases=hitTriple(b); 
                cout<<"Opposing team got a triple.\n";
            }else if(hit>=0){
                bases=hitHomeRun(b);
                cout<<"Opposing team got a home run.\n";
            }
        }
        enemyScore+=bases[3]; 
    	cout<<"Scorer is "<<myScore<<" for you and "<<enemyScore<<" for the opposing team.\n";
    	cin.ignore();
	}
    if(myScore>enemyScore){
        cout<<"You win!";
    }else if(enemyScore>myScore){
        cout<<"You lose!";
    }else{
      	cout<<"It's a tie!";
    }
    return 0;
}
