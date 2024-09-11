#include<iostream>
using namespace std;

int main(){
    //---Collumn
    for(int i = 1; i < 20; i++){
        cout<<endl;
        //---Row
        for(int r = 1; r < 20; r++){
            cout.width(5); 
            cout<<r*i; 
        }
    }
}