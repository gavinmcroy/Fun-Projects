//---Factorial Program!
#include <iostream>
using namespace std;
double factorial(double);
double a;
char choice;
double factorial (double a){
        double tmp;
        cout<<"Enter the Number and you will get the Facotorial"<<endl;
        cin>>a;
        tmp = a;
        do {
                tmp = tmp-1;
                a = a * tmp;
        } while(tmp>1);
        return a;
}
int main(){
        do {
                system("cls");
                cout<<factorial(a)<<endl;
                cout<<"Do you want to continue?(y/n) "<<endl;
                cin>>choice;
        } while(choice=='y' || choice=='Y');

}
