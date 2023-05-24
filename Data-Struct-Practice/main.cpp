#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;
    list.insert(10);
    list.insert(10);
    list.insert(50);
    list.insert(10);
    list.insert(30);
    list.insert(40);


    list.remove(3);

    return 0;
}
