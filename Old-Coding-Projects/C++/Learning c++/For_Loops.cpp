//Local And Global Variables
#include <iostream>
#include<vector>
using namespace std;
int globalVariable;

int main(){
        // int nr,result =0;
        // int i = 0;

        // for(; i<3; i++) {

        //         cout<< "Enter " << (i + 1) << " Number"<<endl;
        //         cin>>nr;
        //         result +=nr;
        // }

        // cout<<result<<endl;
        // cout<<"We Added "<<i<<" Numbers! "<<endl;
        
        
//     for(int i = 10; i <=100; i+=10){
//         if(i%15==0)
//             cout<<i<<endl;
//     }

//     for(int i = 1,j=5;i<=5;i++,j++){
//             cout<<i<<" + "<<j<< " = "<<(i+j)<<endl;
//     }

        for(int i = 1; i <=100;i++){
                cout<<i<<((i%10==0)? "\n" : " ");
        }

        vector <int > num {10,20,30,40,50}; 


        for(unsigned i = 0; i < num.size();i++){
                cout<<num.at(i)<<endl;
        }
    return 0;
}
