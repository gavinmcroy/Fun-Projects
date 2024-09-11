//---to the 99.94%
// #include<iostream>
// #include<string>
// using namespace std;

//  void daysAliveCalc();
// int yearC,monthC,dayC = 0;
// int yearB,monthB,dayB=0;
// int yearA,monthA,dayA = 0;
// int leapYear = 0;
// int currentTimeInMonth=0;
// int extraDays = 0;
// int main(){

//     cout<<"Enter current date (10 24 2018) "<<endl;
//     cin>>monthC>>dayC>>yearC;
//     cout<<"Enter your birthdate (4 3 2000) "<<endl;
//     cin>>monthB>>dayB>>yearB;

//     daysAliveCalc();
//     cout<<"ExtraDays: "<<extraDays<<endl;
//     cout<<"LeapYear: "<<leapYear<<endl;
//     cout<<yearA<<endl;
//     cout<<monthA<<endl;
//     cout<<dayA<<endl;

// }

// void daysAliveCalc() {
//     //---Gives years Alive
//     yearA = yearC - yearB;
//     //---Gives Current Month Time
//     int tmp = yearA;
//     int tmp2 = yearA;
//     currentTimeInMonth = monthC-monthB;
//     int tmp1 = currentTimeInMonth;

//     //---Gives Months Alive 
//     monthA = (yearA * 12) +monthC-monthB;
//     //---Gives days Alive 
//     while(tmp>=4){
//         tmp = tmp-4;
//         leapYear++;
//     }  
//     while(tmp2>=0){
//         tmp2--;
//         extraDays =extraDays+5;
//     }
//     while(tmp1>=0){
//         tmp1=tmp1-2;
//         extraDays++; 
//     }

//     dayA = extraDays+ leapYear + (monthA*30);

// }