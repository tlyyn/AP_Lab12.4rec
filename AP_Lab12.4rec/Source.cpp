#include <iostream>

typedef int Info;
struct Elem {
    Elem* link;
    Info info;
};

void insert(Elem*& L, Info value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    if (L != NULL) {
        Elem* T = L;
        while (T->link != L)
            T = T->link;
        T->link = tmp;
    }
    else {
        L = tmp;
    }
    tmp->link = L;
}

Info remove(Elem*& L) {
    Elem* T = L;
    while (T->link != L)
        T = T->link;
    Info value = L->info;
    if (T != L) {
        Elem* tmp = L->link;
        delete L;
        L = tmp;
        T->link = L;
    }
    else {
        delete L;
        L = NULL;
    }
    return value;
}

int CountNegative(Elem* first, Elem* L, int count = 0) {
    if (L == NULL)
        return count;
    if (L->info < 0)
        count++;
    if (L->link != first)
        return CountNegative(first, L->link, count);
    else
        return count;
}

void insertAfter(Elem*& L, Info value) {
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = L->link;
    L->link = tmp;
}

int main() {
    Elem* L = NULL;
    insert(L, 1);
    insert(L, -2);
    insert(L, 3);
    insert(L, -4);
    insert(L, 5);
    int count = CountNegative(L, L);
    std::cout << "List: " << "1, -2, 3, -4, 5" << std::endl;
    std::cout << "Number of list items with negative information values: " << count << std::endl;
    return 0;
}
