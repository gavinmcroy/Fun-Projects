#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> dailyTemperaturesSlow(vector<int> &temperatures);

vector<int> dailyTemperatures(vector<int> &temperatures);


int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    // std::sort(temps.begin(), temps.end(), std::greater<>());
    //std::vector<int> answer = dailyTemperaturesSlow(temps);
    std::vector<int> answer = dailyTemperatures(temps);

//    for (int i = 0; i < answer.size(); i++) {
//        std::cout << answer[i] << " " << std::endl;
//    }
    return 0;
}

vector<int> dailyTemperaturesSlow(vector<int> &temperatures) {
    std::vector<int> answer;
    for (int i = 0; i < temperatures.size(); i++) {
        int counter = 1;
        bool noneGreater = true;
        for (int j = i + 1; j < temperatures.size(); j++) {
            if (temperatures[i] < temperatures[j]) {
                noneGreater = false;
                break;
            } else {
                counter++;
            }
        }
        if (noneGreater) {
            answer.push_back(0);
        } else {
            answer.push_back(counter);
        }
    }
    return answer;
}

vector<int> dailyTemperatures(vector<int> &temperatures){
    stack<int> myStack;
    vector<int> answer;
    for(int i = temperatures.size()-1; i >= 0; i--){
        myStack.push(temperatures[i]);
    }

    while(!myStack.empty()){
        std::cout<<myStack.top()<<" ";
        myStack.pop();
    }
    return answer;
}
