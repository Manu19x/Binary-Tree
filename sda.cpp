/// Matea Marian - 263 - sub1

#include <bits/stdc++.h>

using namespace std;

struct node{
int value;
node *left, *right;
};
typedef node *BinaryTree;

///a
bool isMinHeap(BinaryTree& T) {
    if (!T) return true;
    if (T->left && T->value > T->left->value) return false;
    if (T->right && T->value > T->right->value) return false;
    return isMinHeap(T->left) && isMinHeap(T->right);
}
/*

Aceasta implementare traverseaza recursiv arborele binar si verifica daca valoarea curenta a nodului este mai mare decat valoarea nodului sau copil
daca comparatia aceasta returneaza false, functia va returna false. daca toate comparatiile sunt true , functia returneaza true

*/
///b
 int biggestMinHeap(BinaryTree& T) {
    if (!T) return 0;
    int left = biggestMinHeap(T->left);
    int right = biggestMinHeap(T->right);
    if (T->left && T->value > T->left->value || T->right && T->value > T->right->value)
        return max(left, right);
    return left + right + 1;
}
/*

Această implementare folosește o abordare recursivă pentru a traversa arborele binar.
Dacă valoarea nodului curent este mai mare decât valorile copiilor acestuia, funcția returnează dimensiunea maximă a sub-arborilor din stânga și din dreapta.
Dacă valoarea nodului curent este mai mică sau egală cu valorile copiilor,
funcția returnează suma dimensiunilor sub-arborilor din stânga și din dreapta plus unu (pentru a include nodul curent).
Funcția max returnează maximum două valori.

*/
///c
int biggestMinBinaryHeap(BinaryTree& T) {
    if (!T) return 0;
    int left = biggestMinBinaryHeap(T->left);
    if (T->right) {
        int right = biggestMinBinaryHeap(T->right);
        if (T->value > T->left->value || T->value > T->right->value)
            return max(left, right);
        return (1 << (int)(log2(left + right + 1))) - 1;
    }
    if (T->value > T->left->value) return 0;
    return (1 << (int)(log2(left + 1))) - 1;
}
/*

Această implementare folosește o abordare recursivă pentru a parcurge arborele binar și verifică dacă valoarea nodului curent
este mai mare decât valorile copiilor acestuia. Dacă oricare dintre comparații returnează adevărat,
funcția returnează dimensiunea maximă a !!!sub-arborilor din stânga și din dreapta!!. Dacă ambele comparații sunt false, funcția calculează maximul
dimensiunea unui sub-arbore binar !!!min-heap!!! folosind formula (1 << (int)(log2(stânga + dreapta + 1))) - 1 pentru un arbore cu atât un copil stânga cât și unul drept sau (1 << (int) (log2(stânga + 1))) - 1
pentru un arbore cu doar un copil rămas.

*/
 ///d
bool isBoth(BinaryTree& T, int min, int max) {
    if (!T) return true;
    if (T->value < min || T->value > max) return false;
    return isBoth(T->left, min, T->value) && isBoth(T->right, T->value, max);
}
bool isBoth(BinaryTree& T) {
    return isBoth(T, INT_MIN, INT_MAX);
}
/*

Această implementare traverseaza recursiv arborele binar și verifică dacă nodul curent este
valoarea este mai mare decât valorile copiilor săi (proprietatea min-heap) și dacă valoarea nodului curent
este între valorile minime și maxime (proprietatea arborelui de căutare binar). Dacă vreuna dintre
comparațiile returnează false, funcția returnează false imediat. Dacă toate comparațiile sunt adevărate,
funcția returnează adevărat. INT_MIN și INT_MAX reprezintă
valorile minime respectiv, maxime ale unui tip int.

*/
int main() {
    // Creare arbore binar
    BinaryTree root = new node{5, nullptr, nullptr};
    root->left = new node{3, nullptr, nullptr};
    root->right = new node{7, nullptr, nullptr};
    root->left->left = new node{2, nullptr, nullptr};
    root->left->right = new node{4, nullptr, nullptr};
    root->right->left = new node{6, nullptr, nullptr};
    root->right->right = new node{8, nullptr, nullptr};

    // Verificare daca arborele este un min-heap
    bool is_min_heap = isMinHeap(root);
    cout << "Is the tree a min-heap? " << is_min_heap << endl;

    // Verificare dimensiunea celui mai mare subarbore binar min-heap
    int biggest_min_heap = biggestMinBinaryHeap(root);
    cout << "Biggest binary min-heap subtree size: " << biggest_min_heap << endl;

    // Verificare daca arborele este un arbore de cautare binar
    bool is_bst = isBoth(root);
    cout << "Is the tree a binary search tree? " << is_bst << endl;

    return 0;
}
