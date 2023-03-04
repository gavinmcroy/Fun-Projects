#include<iostream>
using namespace std;

// int main(){
// int userInput;
// cout<<"Enter a letter"<<endl;
// cin>>userInput;
// switch(userInput){
//     case 1:{
//         int x;
//         cout<<"Wow...Alright"<<endl;
//         cout<<"Enter something else"<<endl;
//         cin>>x;
//         if(x>=10){
//             cout<<"this i didnt know! "<<endl;
//         }
//         break;
//     }
//     case 2:{
//         cout<<"Hello! "<<endl;
//         break;
//     }
    
// }
//     return 0;
// }
int main(){
    enum Direction{
        left,right,up,down
    };
    Direction heading = left;
    Direction b = down; 
    cout<<b<<endl;
    return 0;
}