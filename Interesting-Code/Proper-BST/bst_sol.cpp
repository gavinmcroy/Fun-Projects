#include <iostream>
#include <cstdlib>
#include <tuple>

using namespace std;

typedef int keytype; // type of data stored in key fields in tree

struct Node {
    keytype key;
    int size;
    Node *left, *right;

    Node(keytype k) {
        key = k;
        size = 1;
        left = right = NULL;
    }
};

int get_size(Node *n) { return n == NULL ? 0 : n->size; }

void update_size(Node *n) { n->size = 1 + get_size(n->left) + get_size(n->right); }

Node *insert(Node *root, keytype k) {
    if (root == NULL) return new Node(k);
    if (k < root->key) root->left = insert(root->left, k);
    else root->right = insert(root->right, k);
    update_size(root);
    return root;
}

void print_inorder(Node *root) {
    if (root == NULL) return;
    print_inorder(root->left);
    cout << root->key << "\n";
    print_inorder(root->right);
}

Node *find(Node *root, keytype k) {
    if (root == NULL || k == root->key) return root;
    return find(k < root->key ? root->left : root->right, k);
}

Node *predfind(Node *root, keytype k) {
    if (root == NULL || k == root->key) return root;
    if (k < root->key) return predfind(root->left, k);
    Node *right_result = predfind(root->right, k);
    return right_result == NULL ? root : right_result;
}

pair<Node *, Node *> split(Node *root, keytype k) {
    pair < Node * , Node * > result = make_pair(root, root);
    if (root == NULL) return result;
    if (k < root->key) tie(result.first, root->left) = split(root->left, k);
    else tie(root->right, result.second) = split(root->right, k);
    update_size(root);
    return result;
}

Node *insert_keep_balanced(Node *root, keytype k) {
    if (root == NULL) return new Node(k);
    if (rand() % (1 + root->size) == 0) {
        Node *new_root = new Node(k);
        tie(new_root->left, new_root->right) = split(root, k);
        update_size(new_root);
        return new_root;
    }
    if (k < root->key) root->left = insert_keep_balanced(root->left, k);
    else root->right = insert_keep_balanced(root->right, k);
    update_size(root);
    return root;
}

Node *join(Node *L, Node *R) {
    if (L == NULL) return R;
    if (R == NULL) return L;
    Node *root = (rand() % (L->size + R->size) < L->size) ? L : R;
    if (root == L) L->right = join(L->right, R);
    else R->left = join(L, R->left);
    update_size(root);
    return root;
}

Node *remove(Node *root, keytype k) {
    if (root == NULL) return NULL;
    if (k == root->key) {
        Node *result = join(root->left, root->right);
        delete root;
        return result;
    }
    if (k < root->key) root->left = remove(root->left, k);
    else root->right = remove(root->right, k);
    update_size(root);
    return root;
}

int main(void) {
    // rootesting insert and print_inorder
    int A[10];

    // put 0..9 into A[0..9] in random order
    for (int i = 0; i < 10; i++) A[i] = i;
    for (int i = 9; i > 0; i--) swap(A[i], A[rand() % i]);

    // insert contents of A into a BSroot
    Node *root = NULL;
    for (int i = 0; i < 10; i++) root = insert(root, A[i] * 10);

    // print contents of BSroot (should be 0, 10, 20, ..., 90 in sorted order)
    cout << "\nTesting insert and print_inorder (should be 0,10,20,...,90)\n";
    print_inorder(root);
    cout << "Size (should be 10): " << (root ? root->size : 0) << "\n";

    // test find: Elements 0,10,...,90 should be found; 100 should not be found
    cout << "\nTesting find (should be 0,10,20,...,90 found, 100 not found)\n";
    for (int i = 0; i <= 100; i += 10)
        if (find(root, i)) cout << i << " found\n";
        else cout << i << " not found\n";

    // test predfind -- if nothing printed, that's good news
    if (predfind(root, -1)) cout << "Error: predfind(-1) returned something and should have returned NULL\n";
    if (predfind(root, 50)->key != 50) cout << "Error: predfind(50) didn't return the node with 50 as its key\n";
    for (int i = 0; i <= 90; i += 10)
        if (predfind(root, i + 3)->key != i)
            cout << "Error: predfind(" << i + 3 << ") didn't return the node with " << i << " as its key\n";

    // test split
    cout << "\nTesting split\n";
    Node *L, *R;
    tie(L, R) = split(root, 20);  // we'll talk about tie() and tuples shortly...
    // Alternatively, could say:
    // pair<Node *, Node *> result = split(root, 20);
    // Node *L = result.first, *R = result.second;

    cout << "Contents of left tree after split (should be 0..20):\n";
    print_inorder(L);
    cout << "\nSize left subtree (should be 3): " << L->size << "\n";
    cout << "Contents of right tree after split (should be 30..90):\n";
    print_inorder(R);
    cout << "\nSize right subtree (should be 7): " << R->size << "\n";

    // test join
    root = join(L, R);
    cout << "\nTesting join\n";
    cout << "Contents of re-joined tree (should be 0,10,20,...,90)\n";
    print_inorder(root);
    cout << "\nSize (should be 10): " << root->size << "\n";

    // test remove
    cout << "\nTesting remove\n";
    for (int i = 0; i < 10; i++) A[i] = i * 10;
    for (int i = 9; i > 0; i--) swap(A[i], A[rand() % i]);
    for (int i = 0; i < 10; i++) {
        root = remove(root, A[i]);
        cout << "Contents of tree after removing " << A[i] << ":\n";
        print_inorder(root);
        cout << "\nSize of tree after this removal (should be 1 less than before): " << (root ? root->size : 0) << "\n";
    }

    // test insert_keep_balanced basic functionality
    // insert contents of A into a BSroot
    for (int i = 0; i < 10; i++) root = insert_keep_balanced(root, A[i]);

    // print contents of BSroot
    cout << "\nTesting insert_keep_balanced (should be 0,10,20,..90)\n";
    print_inorder(root);
    cout << "\n" << "Size (should be 10): " << root->size << "\n";

    // test insert_keep_balanced speed
    cout << "Inserting 10 million elements in order; this should be very fast if insert_balance is working...\n";
    for (int i = 0; i < 10000000; i++) root = insert_keep_balanced(root, i + 10); // 10 million ints starting at 10
    cout << "Done\n";
    cout << "Size (should be 10000010): " << root->size << "\n\n";

    return 0;
}
