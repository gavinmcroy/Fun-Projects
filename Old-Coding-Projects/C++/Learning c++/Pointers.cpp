#include <iostream>
using namespace std;
//---Pointers are ordinary Variables that can store Adresses of variables
int main(){
        int var = 5;
        int a =20;
        cout<<*&var<<endl;

        int*p=&var; //---Asterisk is used to INFORM about that this variable is a pointer so it is a variable that can point to the adress of another variable

        cout<<*p<<endl; //---This asterisk here is used to retrieve(get) the value from indicated(pointed) area in our memory(Adress)

        //var = 60;
        p=&a;
        *p=60;
        cout<<var<<endl;
        cout<<*p<<endl;
        cout<<a<<endl;

        int * const p_const = &a; //---This is a pointer that has to be initialized when definded, because it cannot change after defining the thing it is pointing too
        const int *p_2 = &a; //---This pointer cannot change the value that it is under the adress it is pointing too
        const int *const p_3 = &a; //---This is a pointer that cannot change the value that is under adress its pointing too and also it cant change the adress

        int ordinary_var = 10;
        int *ordinary_pointer = &ordinary_var;

        cout<<"Ordinary var: "<<ordinary_var<<endl; //---Integer value
        cout<<"&Ordinary var: "<<&ordinary_var<<endl;
        cout<<"ordinary_pointer: "<<ordinary_pointer<<endl; //---Adress
        cout<<"*ordinary_pointer: "<<*ordinary_pointer<<endl;//---Integer from pointed place (ordinary_var)
        cout<<"&ordinary_pointer: "<<&ordinary_pointer<<endl;//---Adress of pointer itself


        int ** p_pointing_to_adress_of_pointer = &ordinary_pointer;
        cout<<"p_pointing_to_adress_of_pointer: "<<p_pointing_to_adress_of_pointer <<endl;

        return 0;
}
