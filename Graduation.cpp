#include <iostream>
#include <cstdlib>
#include <ctime>

class Bunny{
    private:
        std::string colors[4]={"White","Brown","Black","Spotted"};
        std::string names[10]={"Bob","Crigg","Doorknob","Oil","Slam","Skellet0n","Jew","Emo Chick","T3mmi","3l1t3 hax0r"};
    public:
        int age=1;
        bool sex=rand()%2;//1\true==female; 0\false==male
        bool rad=rand()%50==0;//0\true==rad; 1-49\false=not rad
        std::string color=colors[rand()%4];
        std::string name=names[rand()%10];
        void setAll(int num1, int num2, int num3, int num4){sex=num1;rad=(num2==0);color=colors[num3];name=names[num4];}
        void description(){std::cout<<"Sex "<<sex<<"\nRadioactive "<<rad<<"\nAge "<<age<<"\nColor "<<color<<"\nName "<<name<<"\n";}
};

int main(){
   Bunny bun1,bun2,bun3,bun4,bun5;
   srand(time(0));
   bun1.setAll(rand()%2,rand()%50,rand()%4,rand()%10);
   bun2.setAll(rand()%2,rand()%50,rand()%4,rand()%10);
   bun3.setAll(rand()%2,rand()%50,rand()%4,rand()%10);
   bun4.setAll(rand()%2,rand()%50,rand()%4,rand()%10);
   bun5.setAll(rand()%2,rand()%50,rand()%4,rand()%10);
   return 0;
}
