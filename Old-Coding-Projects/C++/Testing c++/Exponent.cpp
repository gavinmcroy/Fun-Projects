//Square Root
#include <iostream>
using namespace std;
double exponent(double,int);
int tmpb,tmpe;
int main(){
        cout<<exponent(tmpb,tmpe)<<endl;
}
double exponent(double b, int e){
        cout<<"Enter the Base: "<<endl;
        cin>>b;
        cout<<"Enter the Exponent: "<<endl;
        cin>>e;
        double tmp = b;
        while(e>1) {
                e=e-1;
                b=b*tmp;
        }
        return b;
}
/*  cout<<var1 <<"^2 "<<"= "<<var1*var1<<endl;
   goto Ending;
   break;
 */
