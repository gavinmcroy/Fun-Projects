#include <iostream>
#include <sstream>
using namespace std;
//Menu Function
void InitMenu();
void MenuChoice();
const int pi = 3.141592;
string selection;
int main(){
        char cont;
        do {
                system("cls");
                InitMenu();
                MenuChoice();
                cout<<"Do you want to continue?(Y/N)"<<endl;
                cin>>cont;


        }  while(cont == 'Y' || cont=='y');
        return 0;
}
void InitMenu(){
        cout<<"Enter Option: "<<endl;
        cout<<"1. Circle: "<<endl;
        cout<<"2. Square: "<<endl;
        cout<<"3. Rectangle: "<<endl;
        cout<<"4. Triangle: "<<endl;
        cin>>selection;
        for(int i = 0; i<selection.length(); i++) {
                if(selection[i]>=49 && selection[i]<=52) {

                }
                else{
                        cout<<"Bad Answer"<<endl;
                }
        }
}
void MenuChoice(){
        stringstream geek(selection);
        int x = 0;
        geek >> x;
        switch(x) {
        case 1:
                double radius;
                cout<<"Enter the Radius of the Circle"<<endl;
                cin>>radius;
                cout<<"The Radius of the Circle is: "<<(radius*radius)*pi<<endl;
                break;

        case 2:
                double SquareW;
                cout<<"Enter Width of  the Square: "<<endl;
                cin>>SquareW;
                cout<<"The Area of the Square is: "<<SquareW*SquareW<<endl;
                break;
        case 3:
                double RecW,RecH;
                cout<<"Enter the  Width of the Rectangle: "<<endl;
                cin>>RecW;
                cout<<"Enter the Hieght of the Rectangle: "<<endl;
                cin>>RecH;
                cout<<"The Area of the Rectangle is: "<<RecW*RecH<<endl;
                break;
        case 4:
                double triangleH,triangleB;
                cout<<"Enter the Base of the Triangle"<<endl;
                cin>>triangleB;
                cout<<"Enter the Hieght of the Triangle"<<endl;
                cin>>triangleH;
                cout<<"The Area of the Triangle is: "<<(triangleB * triangleH)/2<<endl;
                break;
        }
}
