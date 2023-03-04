#include<iostream>
#include<string>
using namespace std;

int main(){
    (2>1) ? cout<<"Hello world! "<<endl : cout<<"false?"<<endl;
    
    int num1,num2;
    cout<<"Enter two integers seperated by a space ";
    cin>>num1>>num2;
    if(num1!=num2){
        //---if num1 is greater than num2 then num1 one is the largest else num2 is the largest
        cout<<"Largest: "<<((num1>num2) ? num1 : num2)<<endl;
        cout<<"Smallest: "<<((num1<num2)? num1 : num2)<<endl;
    }else{
        cout<<"The numbers are the same... "<<endl;
    }

    int result = 0;
    //---Assigns 10 to result
    result = (1>0) ? 10 : 5; 
    cout<<result<<endl;
    int num;
    cout<<"Enter a number"<<endl;
    cin>>num;


    cout<<num<<" is"<<((num%2==0)?" even": " odd")<<endl;
    // if(num%2==0)
    //     cout<<num<<" is even"<<endl;
    // else
    //     cout<<num<<" is odd"<<endl;


    switch(num){
        case 1:
        {
            cout<<"Hi"<<endl;
            break;
        }
        default:
        {
        cout<<"Defaulted"<<endl;
        }
    }

    system("PAUSE");
    return 0;
}