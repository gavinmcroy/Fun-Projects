#include <iostream>
using namespace std;

void welcome();
main(){
        welcome();
}
void welcome(){
        string password;
        cout<<"Enter password"<<endl;
        cin>>password;
        for(int i = 0; i <password.length(); i++) {
                if(password[i]>=47 && password[i] <= 57) {
                        cout<<"Correct"<<endl;
                }
                else{
                        cout<<"incorrect try again"<<endl;
                }
        }
}
