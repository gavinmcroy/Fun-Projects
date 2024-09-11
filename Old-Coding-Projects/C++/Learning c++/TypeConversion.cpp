#include<string> 
#include<vector>
#include<iostream>
using namespace std;

/*int num1=0;
int num2=0;
int num3=0; 
double average=0.0; 
int averageF();
*/
vector <double> dataPoints;
char  loopStop = 'Y';
double scoreToAdd = 0 ;
double Storage = 0 ; 
int main(){
    while (loopStop=='Y'){
        cout<<"Enter a number"<<endl;
        cin>>scoreToAdd; 
        dataPoints.push_back(scoreToAdd);
        cout<<"continue  loop? "<<endl;
        cin>>loopStop;          
    }; 
    int store = dataPoints.size(); 
    for(int i = 0; i < store; i++){
      Storage =  dataPoints.at(i)+Storage;

    }
cout<<Storage/dataPoints.size(); 
return 0;   
}

/*
int averageF(){
    cout<<"Enter 3 averages "<<endl;
    cin>>num1>>num2>>num3; 
    average = static_cast<double>(num1+num2+num3)/3; 
    cout<<average<<endl;
    return 0; 
}
*/