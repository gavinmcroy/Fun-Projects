#include <iostream>

using namespace std;
long int i;
long int timer=0;

for(i=0; i<=100000000; i++) {
        while(i==99999999) {
                timer++;
                cout<<timer<<endl;
                i=0;
        }
}
