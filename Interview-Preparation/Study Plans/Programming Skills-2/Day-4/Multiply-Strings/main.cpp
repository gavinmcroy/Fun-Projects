#include <iostream>
#include <string>

using namespace std;

string multiply(string num1, string num2);

string add(string num1, string num2);

string add(string num1, string num2);

int main() {
    string num1 = "10";
    string num2 = "20";
    std::cout << add(num1, num2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

string multiply(string num1, string num2) {
    string tmp;
    return tmp;
}

/* PRE: num1 < num2 in arithmetic sense */
string add(string num1, string num2) {
    int hangingDigit = 0;
    const int OFFSET = 48;
    int num = 0;
    for (int i = num1.size(); i >= 0; i--) {
        if(num1[i] == '0'){
            num = (int) (num1[i]);
        }else{
            num = (int) (num1[i]-OFFSET);
        }
        break;
    }
    std::cout<<num<<std::endl;
    string tmp;
    return tmp;
}