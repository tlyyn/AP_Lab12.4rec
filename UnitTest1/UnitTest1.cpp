#include <cassert>
#include <sstream>
#include <iostream>
#include "../AP_Lab12.4rec/Source.cpp"

int main() {

    // Create a new empty list and test that it's empty
    Elem* L = NULL;
    assert(L == NULL);

    // Add some elements to the list and test that they were added correctly
    insert(L, 1);
    assert(L->info == 1);
    assert(L->link == L);

    insert(L, -2);
    assert(L->info == 1);
    assert(L->link->info == -2);
    assert(L->link->link == L);

    insert(L, 3);
    insert(L, -4);
    insert(L, 5);
    insert(L, 6);

    // Print the list to a stringstream and check the output
    std::stringstream ss;
    printList(L->link, L);
    assert(ss.str() == "1 -2 3 -4 5 6 ");

    // Count the number of negative elements and test the result
    int negativeCount = countNegative(L->link, L);
    assert(negativeCount == 3);

    // Remove all elements from the list and test that it's empty again
    while (L != NULL) {
        delete(L);
    }
    assert(L == NULL);

    std::cout << "All tests passed!\n";

    return 0;
}
