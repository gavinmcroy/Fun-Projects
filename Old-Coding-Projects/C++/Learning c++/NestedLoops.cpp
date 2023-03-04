#include<iostream>
#include<vector>
using namespace std;

int main(){
    // //---Displays multiplication table for 10 seperated by space 
    // for(int i {1}; i<=10;i++){
    //     for(int j{1}; j<=10;j++){
    //         cout<<i<<" * "<<j<<" = "<<i*j<<endl;
    //     }
    //     cout<<"-----------------------------------------"<<endl;
    // }
    vector<int> data{};
    int dataAmount{};
    cout<<"Enter how much data you are entering "<<endl;
    cin>>dataAmount;
    for(int i {1}; i<=dataAmount;i++){
        int value {0};
        cout<<"Enter value "<<i<<endl;
        cin>>value;
        data.push_back(value);
    } 
    
    cout<<"\nHistogram"<<endl;
    for(auto val: data){
        for(int i {1};i<=val;i++){
            cout<<"-"; 
        }
        cout<<endl;
    }
    return 0;   
}