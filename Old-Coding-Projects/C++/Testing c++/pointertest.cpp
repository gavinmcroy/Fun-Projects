#include <iostream>
using namespace std;

int main(){
        double a = 3.01;
        double *p=&a; //---Pointer
        cout<<p<<endl; //---Outputs Adress
        cout<<*p<<endl; //---Converts Adress into whats in storage
        string name = "Gavin T McRoy";
        string &n_1 = name;
        cout<<n_1<<endl;
        cout<<"Adress of Name: "<<&name<<endl;
        cout<<"Adress of n_1: "<<&n_1<<endl;
}
