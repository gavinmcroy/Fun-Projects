//Very Simple Calculator
#include <iostream>
using namespace std;
float storage,storage1;
char store,store1;
main(){
restart:
        cout<<"Enter a Number"<<endl;
        cin>>storage;
        cout<<"Enter another Number"<<endl;
        cin>>storage1;

        cout<<"What would you like to do?"<<endl;
        cout<<"-"<<endl;
        cout<<"*"<<endl;
        cout<<"/"<<endl;
        cout<<"+"<<endl;
        cin>>store;
        switch (store) {
        case '/':
                cout<<storage/storage1<<endl;
                break;
        case '*':
                cout<<storage*storage1<<endl;
                break;
        case '+':
                cout<<storage+storage1<<endl;
                break;
        case '-':
                cout<<storage-storage1<<endl;
                break;

        default:
                cout<<"Functioning"<<endl;
                break;
        }
        cout<<"Continue y/n"<<endl;
        cin>>store1;
        switch (store1) {
        case 'y':
                goto restart;
                break;
        case 'Y':
                goto restart;
                break;
        case 'n':
                cout<<"Ending"<<endl;
                break;
        case 'N':
                cout<<"Ending"<<endl;


        }




}
