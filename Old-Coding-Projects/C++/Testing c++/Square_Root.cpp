//---Pefect Square and Square Root Program
#include <iostream>
using namespace std;
//---Functions
double squareroot(double);
double cuberoot(double);
void cont(char);
void menu();
//---Variable used to determine if the program will continue or will end
char choice;
//---Determines what case will be used either square root or cube root
int chose;
//---Global Variables
double sqr;
double cube;
//---Controls the first number tested to find the perfect square root
double a = 0;
int main(){
//---Controls the entire program and if the program will continue or end
        do {
                system("cls");
                menu();
                cont(choice);
                cin>>choice;
        } while(choice=='Y' || choice=='y');

}
double squareroot(double sqr){
//---Resets a back to 0
        a = 0;
        cout<<"Enter a number"<<endl;
        cin>>sqr;
//---Sets tmp equal to the value of sqr so it can reset if a result is not found first try
        double tmp=sqr;
        do {
                sqr=tmp;
                a++;
                sqr=sqr/a;
//---While sqr is not equal to what it was divided by then continue
        } while(sqr!=a);
        cout<<"The Square Root of "<<tmp<<" is "<<a<<endl;
        return(a);
}
double cuberoot(double cube){
//---Resets a back to zero
        a = 0;
        cout<<"Enter a number"<<endl;
        cin>>cube;
//---Sets tmp equal to the value of cube so it can reset if a result is not found first try
        double tmp=cube;
        do {
                cube=tmp;
                a++;
                cube=cube/a;
                cube=cube/a;
        } while(cube!=a);
        cout<<"The Cube Root of "<<tmp<<" is "<<a<<endl;
        return(a);
}
void cont(char choice){
        cout<<"Do you want to continue (y/n)"<<endl;
}
void menu(){
        //---User chooses which function they will want to use
        cout<<"1. Square Root"<<endl;
        cout<<"2. Cube Root"<<endl;
        cin>>chose;
        switch(chose) {
        case 1: squareroot(sqr);
                break;
        case 2: cuberoot(cube);
                break;
        default:
                cout<<"No answers where givin"<<endl;
        }
}
