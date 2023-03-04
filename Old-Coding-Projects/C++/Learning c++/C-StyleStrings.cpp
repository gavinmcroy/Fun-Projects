#include<iostream>
#include<cstring>
#include<cctype>

using namespace std;

int main(){
    char firstName [20] {}; 
    char lastName [20] {};
    char fullName [50] {}; 
    char temp [50] {};
   
    // cout<<"Enter your first name"<<endl;
    // cin>>firstName;

    // cout<<"Enter your last name"<<endl;
    // cin>>lastName;

    // cout<<"Hello "<<firstName<<" your name has "<< strlen(firstName)<< " characters! "<<endl;
    // cout<<"and your last name has "<< strlen(firstName)<< " characters! "<<endl;

    // strcpy(fullName,firstName); 
    // strcat(fullName," ");
    // strcat(fullName,lastName);
    
    // cout<<"Your full name is "<<fullName<<endl;

    cout<<"Enter your full name ";
    cin.getline(fullName,50);

    cout<<"Your full name is "<<fullName<<endl;

}