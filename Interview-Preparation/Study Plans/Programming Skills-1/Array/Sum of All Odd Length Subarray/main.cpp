#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// print data in reverse order
void print_reverse(std::string data)
{
    for (int i = data.length() - 1; i >= 0; i--)
    {
        std::cout << data[i];
    }
}

// read in file and print contents
void read_file(std::string file_name)
{
    std::ifstream file;
    file.open(file_name);
    std::string line;
    while (getline(file, line))
    {
        std::cout << line << std::endl;
    }
    file.close();
}

// find the average of a vector of numbers
double average(std::vector<double> numbers)
{
    double sum = 0;
    for (int i = 0; i < numbers.size(); i++)
    {
        sum += numbers[i];
    }
    return sum / numbers.size();
}

// add up all values in a vector
int sum_vector(std::vector<int> data)
{
    int sum = 0;
    for (int i = 0; i < data.size(); i++)
    {
        sum += data[i];
    }
    return sum;
}


int main() {
    return 0;
}

