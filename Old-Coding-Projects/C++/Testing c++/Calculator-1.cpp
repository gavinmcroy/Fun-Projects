#include <iostream>
#include<stdlib.h>
using namespace std;
main()
{
  //short int a=10,b= 15,c=20;
//int= 4 bytes of memory 2 Billion to -2 Billion
//short in = 2 bytes of memory 32768 to 32767
//short int a;
//float Allocates 4 bytes of memory up to 38 zeros
//double allocates 8 bytes of memory up to 308 zeros
//String is used to write with characters
//Boolean True of False Stores only True or False
//Unsigned short int= 0 to 65667;
//You can Add unsigned to any of the functions str, int, float;
//Constant = const unchangable value
//cin = console input
/*float d=10.1212;
//Simple Arithmetic Program
    cout<<"a : " << a << " Address: "<< &a<<endl;
    cout<<"b : " << b << " Address: "<< &b<<endl;
    cout<<"c : " << c << " Address: "<< &c<<endl;
    cout<<"d : " << d << " Address: "<< &d<<endl;

   int t= a + b + c;

    cout<<t<<endl;

    char t4;

    t4='a';

    cout<<t4<<endl;
    string r= "My name is Big Gav. ";
    string w= "Big win";
    string CombinedStrings= r+w;
    cout<<CombinedStrings<<endl;


    bool tat =0;
    cout<<tat<<endl;


    //Unsigned short int= 0 to 65667;
    //You can Add unsigned to any of the functions str, int, float;
    unsigned short int Alpha = 65000;
    cout<<Alpha<<endl;

    //Constant
    const string GAMENAME= "Conqueror Of C++" ;
    cout<<GAMENAME;




//& ampersand
//& ampersand

//Name and Last Name Program

#include <iostream>
using namespace std;

main()
{
string name, surname, man;

cout<<"Enter Your Name:  ";
cin>>name;

cout<<"Enter your Last Name: ";
cin>>surname;

cout<<"Welcome "+name+" "+surname;
}

//Operator Program;

    int a =11;
    int b =4;

    cout<<a+b<<endl; //Addition Operation
    cout<<a-b<<endl; //Subtraction Operator
    cout<<a*b<<endl; //Multiplication Operator
    cout<<a/b<<endl;//Division Operator
    cout<<a%b<<endl;//Remainder Operation- Left overs after division of two integers

    //incrementation - Increase by 1
    //decrementation - Decrease by 1

    int c=1;
    c+=1; //Same as c = c + 1 -=,*=,/=,%=
    cout<<c ;

//Post incrementation
//Pre  incrementation
//Post decrementation
//Pre  decrementation
//cout<<--d<<endl; = d - 1
//cout<<++d<<endl; = d + 1


    int d = 1;
    cout<<++d<<endl;
    cout<<d;

//Relational operators

    int a = 10;
    int b = 5 ;
    cout << (a == b) << endl; // a is equal to b
    cout << (a != b) << endl;  // a is not Equal to b
    cout << (a > b) << endl; // a is greater than b
    cout << (a < b) << endl; // a is less than b
    cout << (a >= b) << endl; // a is greater than or equal to b
    cout << (a <= b) << endl; // a is less than or equal to b


Logical Operators
    And Conjunction

     (7 > 5) && (5 != 10) True ONLY if BOTH are TRUE! True + False = False

    cout<< (4 > 5 && 5 != 10)<<endl;

    // ! (0) Result will be 1
    // ! (1) Result will be 0

    //OR  Disjunction | |  True ONLY if ONE is TRUE! True + False = True

    //cout<<!(4 < 5 || 5 == 10)<<endl;

    // True + False = True ONLY for OR Disjunction

    //BitWise Operators

    // 1 0 1 0 = 1 * 2 ^3 + 0 * 2^2 + 1 * 2^1 + 0 * 2^0 = 10
    // 1 1 1 0 = 1 * 2 ^ 3 + 1 * 2^2 + 1 * 2^1 + 0 * 2^0 = 14
    // 1 0 1 1 1 0 = 1 *2^5 + 0 * 2^4 + 1 * 2^3 + 1 * 2^2 + 1 *2^1 + 0 * 2^0 = 32+8+4+2 = 46
    // 1 0 1 1 0 = 1 * 2 ^4 + 1 *2^2 + 1 *2^1 = 22

Bitwise AND Operator  &
Bitwise OR Operator  |
Bitwise NOT  ~
Bitwise XOR  ^ (Exclusive OR)
0 0 = 0
1 0 = 1
0 1 = 1
1 1 = 0
Bitwise Left Shift <<
Bitwise Right Shift >>

BIT WISE OR OPERATOR: cout<<(10|2)<<endl;
1 0 1 0
0 0 1 0
--------
1 0 1 0

BITWISE AND OPERATOR: cout<<(10&2)<<endl;
1 0 1 0
0 0 1 0
--------
0 0 1 0

BITWISE XOR OPERATOR: cout<<(10^2)<<endl;
1 0 1 0
0 0 1 0
--------
1 0 0 0

--BITWISE NOT OPERATOR:  cout<<(~10)<<endl;
1 0 1 0
--------
0 1 0 1

BITWISE LEFT SHIFT OPERATOR: cout<<(10<<1)<<endl;

0 0 0 0 1 0 1 0
----------------
0 0 0 1 0 1 0 0

10 *2^1 = 10<<1 = 20
10 *2^2 = 10<<2 = 40
10 *2^3 = 10<<3 = 80

BITWISE RIGHT SHIFT OPERATOR: cout<<(10>>1)

0 0 0 0 1 0 1 0
----------------
0 0 0 0 0 1 0 1

10 / 2^1 = 10>>1 = 5



//Conditional Statements


 int A, B;
 cout<< "Enter A: "<<endl;
 cin>>A;

 cout<<"Enter B: " <<endl;
 cin>>B;

 if(A>B)
    cout<< A << " > " << B <<endl;
    else if(A<B)
        cout<< B <<" > " << A <<endl;
    else if(A==B)
        cout<< A << " = " << B <<endl;


//Grade Checker

 int grade;
 string clas;

 cout<<"Enter Grade: ";
 cin>>grade ;

 cout<<"Enter Class: ";
 cin>>clas;

 if(grade>=90)
    cout<<"You Passed "<<clas<<"!";
 else
    cout<<clas<<" Class was not passed ";

//Grade Checker v2

    int a;
    cout<<"What is your Grade: ";
     cin>>a;
     if (a>=90)
        cout<<"You Made a A! ";
     else if(a<=89 && a>=80)
        cout<<"You made a B!" ;
     else if (a<=79 && a>=70)
        cout<<"You made a C :( ";
     else if (a<=69 && a>=60)
        cout<<"You Made a D rofl: " ;
    else if (a<=59)
        cout<<"You Failed Highschool Nerd";

*/

//Switch Function
    /*
    int x;
    cout<<"Enter Value: ";
    cin>>x;

//Letters have Numbers associated with them example a = 97 so case a will be executed and the rest will not
    char x=97 ;
    switch(x)
    {
    case 'a':
        cout<<"This is the place for the instructions to be executed when switch value is equal to 0 ";
    break;

    case 25:
        cout<<"This is the place for the instructions to be executed when switch value is equal to 25 ";
    break;

    case 50:
        cout<<"This is the place for the instructions to be executed when switch value is equal to 50";
    break;

    default:
        cout<<"This is the place for the instructions that will be executed when value of switched variable is not equal to any case";
    }


//Conditional Operators Executed if conditions are true
    int a,b;
    cout<<"What is the value of A: ";
    cin>>a;
    cout<<"What is the Value of B: ";
    cin>>b;

    cout<<((a>b ? a : b)+10)<<endl;

//Calculator Practice

float var1,var2;

char choice;
system("cls");
start:
cout<<"What is the Value for Variable #1: "<<endl ;
cin>>var1;
cout<<"What is the Value for Variable #2: " <<endl;
cin>>var2;

cout<<"What do you want to do? (Add, Subtract, Multiply, Divide)"<<endl;
cout<<"+ -Add "<<endl;
cout<<"- -Subtract "<<endl;
cout<<"* -Multiply "<<endl;
cout<<"/ -Divide "<<endl;
cin>>choice;
system("cls");
switch(choice)
    {

    case'+':
        cout<<var1<<" + "<< var2 <<" = "<< var1+var2<<endl;
        break;
    case '-':
        cout<<var1<<" - "<< var2 <<" = "<< var1-var2<<endl;;
        break;
    case '*':
        cout<<var1<<" * "<< var2 <<" = "<< var1*var2<<endl;
        break;
    case'/':
        if(var2==0)
            cout<<"Cannot Divide by 0"<<endl;
            else if (var2!=0 )
        cout<<var1<<" / "<< var2 <<" = "<< var1/var2<<endl;
        break;
    default:
        cout<<"Enter a Valid Function"<<endl;

}
    char decision2;
cout<<"Do You want to Continue Program? (Y/N)"<<endl;
    cin>> decision2;
    if(decision2=='y' || decision2=='Y')
    goto start;
        else(decision2=='n' || decision2=='N');


//---1d Arrays

int arr[3]; //Type name[Number Of Elements]

    arr[0] = 10;
    arr[1] = 30;
    arr[2] = 20;
    //arr[3]=40 Does not exist

cout<<"Array [0] = " <<"Adress: "<<&arr[0] << " "<<arr[0]<<endl;
cout<<"Array [1] = " <<"Adress: "<<&arr[1]<< " "<<arr[1]<<endl;
cout<<"Array [2] = " <<"Adress: "<<&arr[2]<<" "<<arr[2]<<endl;

//---2D Arrays
int biArray[3][4] = {25};

    cout<<&biArray[0][2]<<endl;
    cout<<&biArray[1][1]<<endl;
    cout<<&biArray[2][0]<<endl;

//---For Statements
//--- for(Variable; condition ; + or - )

for (int i = 0; i<5; i++ ){
 cout<<"IT WORKS"<<endl;

}

int arr[1000];


   for (int i=0; i<1000; i++){
        arr[i]=i;
   }
      for (int i=0; i<1000; i++){
    cout<<arr[i]<<endl;
}

//---While Loops
const int arr = 10;

int i =0;

int array[arr];

while(i<arr){
    array[i]=10*i;
    cout<<array[i]<<endl;
    i++;


}
//---Excersise On While Loops (Integer Counter)
int NumberOfDigits = 1;
int nr;
int temp;
cout<<"Enter A Number "<<endl;
cin>>nr;
temp=nr;
    while(nr/=10)
    {
    NumberOfDigits++;
    }
    cout<<"The Number "<<temp<<" Has "<<NumberOfDigits<<" Digits."<<endl;
//--Simple Column Program
int columns,rows;
char answer;
Start:
system("cls");
cout<<"Enter How Many Rows For the Table: "<<endl;
cin>>columns;
cout<<"Enter How Many Columns For The Table: "<<endl;
cin>>rows;
system("cls");

    for(int i=1; i<=columns; i++)
    {
        for(int j=1; j<=rows; j++)
        {
            cout.width(4);
            cout<<i * j<<" ";

        }
        cout<<endl;
    }

cout<<"Continue?"<<endl;
cin>>answer;

    if(answer=='y' || answer=='Y')
    {
        goto Start;
    }
    else if (!'y'|| !'Y')
    {
        cout<<"closing";
    }



    for(int i=1; i<=15; i++){ //Amount of Rows
        if(i==5)
            continue; //EVERYTHING AFTER STATEMENT IS TRUE CODE AFTER CONTINUE WILL NOT RUN! BUT CODE WILL CONTINUE
            //break; //EVERYTHING AFTER  BREAK IF STATEMENT IS TRUE WILL NOT EXECUTE AND WILL LEAVE ACTUAL LOOP
        for(int j=1; j<=15; j++) //Amount Of Columns
        {
            cout.width(4);
            cout<<i * j<<" ";

        }
        cout<<endl;




    }
*/
}



