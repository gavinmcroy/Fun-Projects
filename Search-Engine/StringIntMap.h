//
// Created by Gavin Taylor Mcroy on 1/20/23.
//

#ifndef PROJECT_1_REBUILD_STRINGINTMAP_H
#define PROJECT_1_REBUILD_STRINGINTMAP_H


#include<string>

using namespace std;

class StringIntMap {
private:

    struct Node {
        string key;
        int val;
        Node *next;

        Node(string k, int v, Node *n) {
            key = k;
            val = v;
            next = n;
        }
    };

    Node **table;  // array of pointers to linked lists
    int size;      // size of table, as currently allocated
    int numElements; // number of elements stored in the table
    Node **allocateTable(int size);  // private helper function

public:
    StringIntMap();

    ~StringIntMap();

    int &operator[](string key);

    bool find(string key);

    void insert(const string& key, int val);

    void remove(const string& key);

    void print();

    int getNumElements() const;

    string *getKeys();
};


#endif //PROJECT_1_REBUILD_STRINGINTMAP_H
