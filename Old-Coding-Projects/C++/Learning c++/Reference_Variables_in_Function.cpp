//---Reference Variables in Action
#include <iostream>
using namespace std;

int swap(int &,int &);
int main(){
        int a = 10;
        int b = 20;
//---int c equals the return value from the function
        int c = swap(a,b);
        cout<<a<<endl;
        cout<<b<<endl;
        cout<<c<<endl;
        return 0;
}
int swap(int &x,int &y){
        int t;
        t=x; //t =10
        x=y; //x=20
        y=t; //y= 10
        return x;
}
