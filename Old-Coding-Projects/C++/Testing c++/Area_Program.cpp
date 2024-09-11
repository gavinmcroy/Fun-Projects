#include <iostream>
#include <limits>
#include<string>
//---Use std everywhere you can
using namespace std;
//---Functions
void initMenu();
void menuDecision(int);
double areaCircle(double);
double areaSquare(double);
double areaRectangle(double,double);
double areaTriangle(double,double);
bool isValid(string);
//---Constant
const double pi = 3.141592;
int main(){
        int choice;
        char cont;
        do {
                //---Clears Previous Menu
                system("cls");
                //---Initializes Menu Function while cont = y or Y
                initMenu();
                //---While wrong character is entered clear input ignore rest of input and re run menu
                while(!(cin>>choice)) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        system("cls");
                        initMenu();
                        cout<<"Wrong Character Typed"<<endl;
                }
                //---Runs the switch determined on what # was entered
                menuDecision(choice);
                //--- Asks user if to continue ignores input while its not equal to any of the options
                do {
                        cout<<"Do you want to Continue (Y/N)"<<endl;
                        cin>>cont;
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                } while(cont!='y' && cont!= 'Y' && cont!='n' && cont!='N'); {

                }
                //---Runs in a loop while cont equals y or Y remains true
        } while(cont == 'y' || cont == 'Y'); {

        }

        return 0;
}
//---Displays menu options
void initMenu(){
        cout<<"Enter option: "<<endl;
        cout<<"1. Circle "<<endl;
        cout<<"2. Square "<<endl;
        cout<<"3. Rectangle "<<endl;
        cout<<"4. Triangle "<<endl;

}
//---Takes the input from the Menu and values while input is Valid meaning if its a int a int was entered
void menuDecision(int choice){
        double r,a,b,h;
        switch(choice) {
        case 1:
                cout<<"Enter the Radius: "<<endl;
                //---Send value to r while its valid from the isValid function which returns if its true or false if false asks to re enter answer
                do {cin>>r;} while(!isValid("Enter the Radius Again: "));
                areaCircle(r);
                break;
        case 2:
                cout<<"Enter the Side of the Square: "<<endl;
                do {cin>>a;} while(!isValid("Enter the Side Again: "));
                areaSquare(a);
                break;
        case 3:
                cout<<"Enter the Width of the rectangle"<<endl;
                do {cin>>a;} while(!isValid("Enter the Width Again: "));
                cout<<"Enter the Hieght of the rectangle"<<endl;
                do {cin>>b;} while(!isValid("Enter the Hieght Again: "));
                areaRectangle(a,b);
                break;
        case 4:
                cout<<"Enter the Base of the Triangle"<<endl;
                do {cin>>b;} while(!isValid("Enter the Base Again: "));
                cout<<"Enter the Hieght of the Triangle"<<endl;
                do {cin>>h;} while(!isValid("Enter the Hieght Again: "));
                areaTriangle(b,h);
                break;
        default:
                cout<<"No options chosen"<<endl;
                break;
        }
}
//---Gives area of Circle
double areaCircle(double r){
        double result = pi *r *r;
        cout<<"The area of the circle that radius is "<<r<<" = "<<result<<endl;
        return result;
}
//---Gives area of Square
double areaSquare(double a){
        double result = a *a;
        cout<<"The area of the square that side is "<<a<<" = "<<result<<endl;
        return result;

}
//---Gives area of Rectangle
double areaRectangle(double a, double b){
        double result = a * b;
        cout<<"The area of the rectangle that base is "<<a<<" and hieght "<<b <<" = "<<result<<endl;
        return result;
}
//---Gives area of Triangle
double areaTriangle(double b, double h){
        double result = .5 *(b*h);
        cout<<"The area of the Triangle that base is "<<b<<" and hieght "<<h <<" = "<<result<<endl;
        return result;
}
bool isValid(string error_msg){
        if(cin.rdstate()) { //---State is wrong when its not equal to 0
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                system("cls");
                initMenu();
                cout<<error_msg<<endl;
                return false;
        }
        //---if rdstate does not run meaning no failed values where entered return true
        return true;
}
