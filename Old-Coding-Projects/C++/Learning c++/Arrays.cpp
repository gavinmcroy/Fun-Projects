#include <iostream>
using namespace std;
int testScores [] {100,99,95,88,87};
char vowels [] {'a','e','i','o','u'};
double highTemp [] {90.1,89.8,77.5,81.6};
int main(){
        /*
              cout<<"Test score 0: "<<testScores[0]<<endl;
              cout<<"Test score 1: "<<testScores[1]<<endl;
              cout<<"Test score 2: "<<testScores[2]<<endl;
              cout<<"Test score 3: "<<testScores[3]<<endl;
              cout<<"Test score 4: "<<testScores[4]<<endl;
         */
        cout<<"Vowels: "<<vowels[0]<<endl;
        cout<<"Vowels: "<<vowels[1]<<endl; 
        cout<<"Vowels: "<<vowels[2]<<endl;
        cout<<"Vowels: "<<vowels[3]<<endl;
        cout<<"Vowels: "<<vowels[4]<<endl;
        cout<<highTemp[0]<<endl;
        highTemp[0] = 323.2;
        cout<<highTemp[0]<<endl;


        return 0;
}
