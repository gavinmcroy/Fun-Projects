//
// Created by Gavin Taylor Mcroy on 9/23/2020 AD.
//
#include <iostream>
#include <string>
#include <cassert>
#include "StringIntMap.h"

using namespace std;

/* Return a hash for the string s in the range 0..table_size-1 */
int myHash(string s, int table_size) {
    unsigned int i, h = 0;
    for (i = 0; i < s.length(); i++)
        h = (h * 2917 + (unsigned int) s[i]) % table_size;
    return h;
}

/* Allocate a table of pointers to nodes, all initialized to NULL */
StringIntMap::Node **StringIntMap::allocateTable(int s) {
    Node **table = new Node *[s];
    for (int i = 0; i < s; i++)
        table[i] = NULL;
    return table;
}

StringIntMap::StringIntMap() {
    size = 4; // initial size of table
    table = allocateTable(size);
    numElements = 0;
}

StringIntMap::~StringIntMap() {
    for (int i = 0; i < size; i++) {
        while (table[i] != nullptr) {
            Node *temp = table[i];
            table[i] = table[i]->next;
            delete temp;
        }
    }
    delete[] table;
}

/* Return true if key is in the set */
bool StringIntMap::find(string key) {
    int h = myHash(key, size);
    Node *n = table[h];
    while (n != nullptr) {
        if (n->key == key) return true;
        n = n->next;
    }
    return false;
}

// return reference to associated int of a given key
int &StringIntMap::operator[](string key) {
    if (!find(key)) {
        insert(key, 0);
    }
    int h = myHash(key, size);
    Node *n = table[h];
    while (n != nullptr) {
        if (n->key == key) {
            return n->val;
        }
        n = n->next;
    }
}


/* Inserts a new key.  It is an error if key is already in the set. */
void StringIntMap::insert(const string &key, int val) {
    assert (!find(key));
    numElements++;

    if (numElements == size) {
        Node **old_table = table;
        size *= 2;
        table = allocateTable(size);

        // Transfer all elements from old_table into table
        for (int i = 0; i < size / 2; i++) {
            Node *n = old_table[i];
            while (n != nullptr) {
                int h = myHash(n->key, size);
                table[h] = new Node(n->key, n->val, table[h]);
                Node *to_delete = n;
                n = n->next;
                delete to_delete;
            }
        }

        // De-allocate old_table
        delete[] old_table;
    }

    int h = myHash(key, size);
    table[h] = new Node(key, val, table[h]);
}

/* Removes a key.  It is an error if key isn't in the set */
void StringIntMap::remove(const string &key) {
    assert (find(key));
    numElements--;

    int h = myHash(key, size);
    if (table[h]->key == key) {
        // Delete first node
        Node *to_delete = table[h];
        table[h] = table[h]->next;
        delete to_delete;
    } else {
        // Delete from rest of list
        Node *n = table[h];
        while (n->next->key != key) n = n->next;
        Node *to_delete = n->next;
        n->next = to_delete->next;
        delete to_delete;
    }
}

void StringIntMap::print() {
    for (int i = 0; i < size; i++)
        for (Node *n = table[i]; n != nullptr; n = n->next)
            cout << n->key << " " << n->val << "\n";
}

// Return an array of all keys in table
string *StringIntMap::getKeys() {
    auto *result = new string[numElements];
    int index = 0;
    for (int i = 0; i < size; i++)
        for (Node *n = table[i]; n != nullptr; n = n->next)
            result[index++] = n->key;
    return result;
}

int StringIntMap::getNumElements() const {
    return numElements;
}
