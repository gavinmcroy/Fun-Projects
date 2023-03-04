#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;



int main(){
    // vector <double> temps {87.2,77.9,80.0,72.5}; 
    // double averageTemp {0}; 
    // double runningSum {0};
    // int scores[] {10,20,30}; 

    // for(int score : scores)
    //     cout<<score<<endl;

    // for (auto temp : temps)
    //    runningSum += temp; 
    
    // for (auto c : "Gavin")
    //     cout<<c<<endl;
    
    // averageTemp = runningSum / temps.size();
    // //---IO MANIP Rounds it to 1 decimal 
    // cout<<fixed<<setprecision(1); 
    // cout<<averageTemp<<endl;
    
    // int number = 1'000'000;
    // cout<<number<<endl;

    // cout<<__cplusplus<<endl;

    // return 0 ;
    vector <int> vec {2,4,6,8}; 
    // int finalResult{0};
    // for(int i=0; i<vec.size(); i++){

    //     for(int j=1; j<vec.size();j++){
    //         cout<<vec.at(i)<<" , "<<vec.at(j)<<endl; 
    //     }
    // }
    int result{0};
    
    for (size_t i=0; i< vec.size(); ++i)
       for (size_t j=i+1; j< vec.size(); ++j) {
            result = result + vec.at(i) * vec.at(j);
            cout<<vec.at(i)<<" , "<<vec.at(j)<<endl;
       }
    cout<<result<<endl;
    return 0;

}
//  cout<<vec.at(i)<<" , "<<vec.at(j)<<endl;
// finalResult+=vec.at(i)*vec.at(j); 
// cout<<vec.at(i)<<" , "<<vec.at(j)<<endl;