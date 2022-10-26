#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {

    }

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {

    }

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int sumOfLeftLeaves(TreeNode *root);

int maxDepth(TreeNode *root);

int sum(TreeNode * root);

int main() {
    std::cout << "Hello, World!" << std::endl;
    auto *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->right = new TreeNode(7);
    root->right->left = new TreeNode(15);
    std::cout<<maxDepth(root);
    return 0;
}

int sumOfLeftLeaves(TreeNode *root) {
    while (root != nullptr) {

    }
    return 0;
}

int maxDepth(TreeNode *root) {
    if (root == nullptr) {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right) ? left + 1 : right + 1;
}

int sum(TreeNode * root){
    if(root == nullptr){
        return 0;
    }
    int left = sum(root->left);
    int right = sum(root->right);
    return

}
