#include <iostream>
#include<string>
using namespace std;

int main(){
        string name="Agnes";
        cout<<"The name is: "<<name<<" Variable Adress: "<<&name<<endl;
        /*Reference Variable*/ string &nr_6 = name;
        cout<<"The name is: "<<nr_6<<" Variable Adress: "<<&name<<endl;
        nr_6="Scott";
        cout<<"The name is: "<<name<<" Variable Adress: "<<&name<<endl;
        cout<<"The name is: "<<nr_6<<" Variable Adress: "<<&name<<endl;
        /*ref. Var. Must be initialized when created
         * ref. Var. Cannot change associates/connections
         * ref. Var. Must be same associated variable */
        string name1;
        cout<<"Enter a name"<<endl;
        cin>>name1;
        string &n_1= name1;
        cout<<n_1<<endl;
        return 0;
}
