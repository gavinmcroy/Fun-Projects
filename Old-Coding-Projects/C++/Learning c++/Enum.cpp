//---Simple Week Counter
#include <iostream>
#include <cstdlib>
#include <limits>
#include <ctime>
#include<string>
using namespace std;
string name;
int i;
/*
   enum deathword {death1,death2,death3,death4,death5,death6};

   string getdeath(deathword);
 */
enum dayofWeek {M = 0,T,W,TH,F,SA,SU};
string getDay(dayofWeek);
int main(){
        srand((unsigned)time(0));
        int p1 = rand()%7;
        cout<<"Enter a name "<<endl;
        cin>>name;
        cout<<name<<" "<<getDay(dayofWeek(p1))<<endl;
        return 0;
}

string getDay(dayofWeek(p1)){

        switch(p1) {
        case M:
                return "was brutally stabbed to death in the mist of night";
        case T:
                return "was ran over";
        case W:
                return "was stomped to death";
        case TH:
                return "was clawed to death";
        case F:
                return "was butchered";
        case SA:
                return "Fell off a cliff";
        case SU:
                return "was crushed";
        default:
                return "Mistype";
        }
        return 0;
}



/*int main(){
        cout<<"Enter day of week "<<endl;
        cin>>i;
        cout<<getdeath(deathword(i))<<endl;
        return 0;
   }
   string getdeath(deathword){
 */
