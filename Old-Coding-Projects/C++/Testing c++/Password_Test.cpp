//Pass Word Check
#include <iostream>
using namespace std;
//Paramater
//Global Variables
void welcome();
bool isNumber(string);
double add(double a, double b) {
        return (a+b);
}
main(){
        //Temporary Variable Initialization
        welcome();
        welcome();
        welcome();
        cout<<add(4,5)<<endl;


}
bool isNumber(string tmp) {
        for(int i = 0; i < tmp.length(); i++) {
                if(tmp[i]==97) {
                        return true;
                }
        }
}

void welcome(){
        string tmp;
        cout<<"Enter The Number"<<endl;
        cin>>tmp;
        if(isNumber(tmp)) {
                cout<<"Password Correct"<<endl;
        }

        else {
                cout<<"Password Incorrect"<<endl;
                cout<<"Ending..."<<endl;
        }
}
