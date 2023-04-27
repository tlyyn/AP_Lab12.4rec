#include <iostream>

struct Elem {
    Elem* link;
    int info;
};

void insert(Elem*& L, int value) {
    Elem* tmp = new Elem{ NULL, value };
    if (L == NULL) {
        L = tmp;
        L->link = L;
    }
    else {
        Elem* p = L;
        while (p->link != L) p = p->link;
        p->link = tmp;
        tmp->link = L;
    }
}

int remove(Elem*& L) {
    if (L == NULL) return 0;
    int value = L->info;
    Elem* toDelete = L;
    if (L->link == L) {
        L = NULL;
    }
    else {
        Elem* p = L;
        while (p->link != L) p = p->link;
        p->link = L->link;
        L = L->link;
    }
    delete toDelete;
    return value;
}


void printList(Elem* L, Elem* end) {
    if (L == NULL) return;
    std::cout << L->info << " ";
    if (L->link != end)
        printList(L->link, end);
}

int countNegative(Elem* L, Elem* end) {
    if (L == NULL) return 0;
    if (L == end) return (L->info < 0);
    return (L->info < 0) + countNegative(L->link, end);
}

int main() {
    Elem* L = NULL;

    insert(L, -1);
    insert(L, 2);
    insert(L, -3);
    insert(L, 4);
    insert(L, -5);
    insert(L, 6);

    std::cout << "List: ";
    printList(L->link, L);

    int negativeCount = countNegative(L->link, L);

    std::cout << "\nNumber of negative elements: " << negativeCount << std::endl;

    while (L != NULL)
        remove(L);

    return 0;
}