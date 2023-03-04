#include<iostream>
#include<string>
using namespace std;

int year;
int day;
int months();

int main(){
    cout<<months()<<endl;
    return 0;
}

int months(){
    int month = 0;
    cout<<"Enter a month! "<<endl;
    cin>>month;
    switch(month){
        case 1: 
        return 31;
        case 2:
        return 28;
    }

}