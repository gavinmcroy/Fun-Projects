//Mulitplication Table
//Written by Gavin T Mcroy
#include <iostream>
#include <stdlib.h>
using namespace std;
main()
{
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

}
