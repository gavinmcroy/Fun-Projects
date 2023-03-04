#include <iostream>
#include <vector>
#include<string>
using namespace std;
vector <int> numbers (20);
vector <int> testScores {90,91,95,95,100};
vector <int> testNumbers (4,50);
int main(){
          cout<<testScores[0]<<endl;
           cout<<testScores[1]<<endl;
           cout<<testScores[2]<<endl;
           cout<<testScores[3]<<endl;
           cout<<testScores[4]<<endl;
           cout<<testScores.at(2)<<endl;

           cout<<"Enter a value"<<endl;
           cin>>testScores.at(0);
           cout<<testScores.at(0)<<endl;
           testScores.push_back(80);
           cout<<testScores.at(5)<<endl;

           cout<<testScores.at(0)<<endl;
           cout<<testScores.at(1)<<endl;
           cout<<testScores.at(2)<<endl;
           cout<<"\nEnter updated Test Scores"<<endl;
           cin>>testScores.at(0);
           cin>>testScores.at(1);
           cin>>testScores.at(2);
           cout<<"\nUpdated results are "<<endl;
           cout<<testScores.at(0)<<endl;
           cout<<testScores.at(1)<<endl;
           cout<<testScores.at(2)<<endl;

           int scoreToAdd=0;
           cin>>scoreToAdd;
           testScores.push_back(scoreToAdd);
           cout<<"Enter one more test score"<<endl;
           cin>>scoreToAdd;
           testScores.push_back(scoreToAdd);
           cout<<"/n Test scores are now "<<endl;
           cout<<testScores.at(0)<<endl;
           cout<<testScores.at(1)<<endl;
           cout<<testScores.at(2)<<endl;
           cout<<testScores.at(3)<<endl;
           cout<<testScores.at(4)<<endl;
           cout<<testScores.at(5)<<endl;
           cout<<testScores.at(6)<<endl;
           cout<<"Test scores size is now "<<testScores.size()<<endl;
         
        //---2D VECTOR
        vector <vector<int> > movieRatings {
/*reviewer 1 */ {1,2,3,4},
                {5,6,7,8},
                {9,10,11,12}
        };
        cout<<"Movie Ratings for reviewer #1"<<endl;
        cout<<movieRatings[0][0]<<endl;
        cout<<movieRatings[0][1]<<endl;
        cout<<movieRatings[0][2]<<endl;
        cout<<movieRatings[0][3]<<endl;
        cout<<"Movie Ratings for reviewer #2"<<endl;
        cout<<movieRatings[1][0]<<endl;
        cout<<movieRatings[1][1]<<endl;
        cout<<movieRatings[1][2]<<endl;
        cout<<movieRatings[1][3]<<endl;
        cout<<"Movie Ratings for reviewer #3"<<endl;
        cout<<movieRatings.at(2).at(0)<<endl;
        cout<<movieRatings.at(2).at(1)<<endl;
        cout<<movieRatings.at(2).at(2)<<endl;
        cout<<movieRatings.at(2).at(3)<<endl;





}
