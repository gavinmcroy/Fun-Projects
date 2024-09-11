//Number Counter
#include <iostream>
using namespace std;
int number = 1;
int totalDigit;
main(){

        cout<<"Enter a Number"<<endl;
        cin>>totalDigit;
        int temp = totalDigit;

        while(totalDigit/=10) {
                number++;
        }
        cout<<temp<< " Has "<<number<<" Digits!"<<endl;
}
