//Simple Calculator Program C++
//Written by Gavin T Mcroy
#include <iostream>
#include <stdlib.h>
#include<string>
//Start Functions
double exponent(double,int);
int tmpb,tmpe;
using namespace std;
int main ()
{
//Start Variables
        float var1,var2, radius,lengthT,widthT,lengthS;
        char choice,special2;
        int tmpb,tmpe;
//Constants
        float pi = 3.141592653589;
        string special;
//Clear Screen
        system("cls");
//Go to point when Y is selected
start:
//Var1 Storage
        cout<<"What is the Value for Variable #1: "<<endl;
        cin>>var1;
//Special Character Storage
        cout<<"Special Options? (yes to enable anything else to continue)"<<endl;
        cin>>special;
        if (special=="yes")
        {
                cout<<"Select one of the Following Operations: "<<endl;
                cout<<"^- Square Number "<<endl;
                cout<<"%- Percent of Number "<<endl;
                cout<<"?- Area Of Circle "<<endl;
                cout<<"/- Area of Triangle"<<endl;
                cout<<"!- Area of Square"<<endl;
                cout<<"~- Exit"<<endl;
                cin>>special2;
                switch(special2)
                {
                case '^':
                        system("cls");
                        cout<<exponent(tmpb,tmpe)<<endl;
                        goto Ending;
                        break;
                case '%':
                        system("cls");
                        cout<<var1<<" / 100 = "<<var1/100<<"%"<<endl;
                        goto Ending;
                        break;
                case '?':
                        cout<<"Enter Radius"<<endl;
                        cin>>radius;
                        system("cls");
                        cout<<radius<< " ^2 * Pi = "<<radius*radius*pi<<endl;
                        goto Ending;
                        break;
                case '/':
                        system("cls");
                        cout<<"Enter Length: "<<endl;
                        cin>>lengthT;
                        cout<<"Enter Width: "<<endl;
                        cin>>widthT;
                        cout<<lengthT<<" * "<<widthT<<" /2 "<< " = " <<lengthT*widthT/2<<endl;
                        goto Ending;
                        break;
                case '!':
                        cout<<"Enter Length: "<<endl;
                        cin>>lengthS;
                        system("cls");
                        cout<<lengthS<< " * "<<lengthS<< " = "<<lengthS*lengthS<<endl;
                        goto Ending;
                        break;

                case '~':
                        goto Variable2;
                }
        }
        else
        {
                goto Variable2;
        }

//Var2 Storage
Variable2:
        cout<<"What is the Value for Variable #2: " <<endl;
        cin>>var2;
//Operation Choice
        cout<<"What do you want to do? (Add, Subtract, Multiply, Divide)"<<endl;
        cout<<"+ -Add "<<endl;
        cout<<"- -Subtract "<<endl;
        cout<<"* -Multiply "<<endl;
        cout<<"/ -Divide "<<endl;
        cin>>choice;
//Clear Choice Screen
        system("cls");
//Operations From Choice
        switch(choice)
        {

        case '+':
                cout<<var1<<" + "<< var2 <<" = "<< var1+var2<<endl;
                break;
        case '-':
                cout<<var1<<" - "<< var2 <<" = "<< var1-var2<<endl;;
                break;
        case '*':
                cout<<var1<<" * "<< var2 <<" = "<< var1*var2<<endl;
                break;
        case '/':
                if(var2==0)
                        cout<<"Cannot Divide by 0"<<endl;
                else if (var2!=0 )
                        cout<<var1<<" / "<< var2 <<" = "<< var1/var2<<endl;
                break;
        default:
                cout<<"Enter a Valid Function"<<endl;
                break;
                goto Ending;

        }
Ending:
        char decision2;
        cout<<"Do You want to Continue Program? (Y/N)"<<endl;
        cin>> decision2;
        if(decision2=='y' || decision2=='Y')
        {
                system("cls");
                goto start;
        }
        else if (decision2=='n' || decision2=='N')
        {
                system("cls");
                cout<<"ending";
        }


}
//Exponent Function
double exponent(double b, int e){
        cout<<"Enter the Base Value: "<<endl;
        cin>>b;
        cout<<"Enter the Exponential Value: "<<endl;
        cin>>e;
        while(e>1) {
                double tmp = b;
                b = b * tmp;
                e=e-1;
        }
        return b;
}
