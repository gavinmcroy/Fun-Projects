#include <iostream>
#include <vector>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


vector<int> preorder(Node *root);

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

vector<int> preorder(Node *root) {
    
}