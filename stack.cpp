#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *top = nullptr;

void push(int value) {
    Node *baru = new Node{value, top};
    top = baru;
    cout << "Push " << value << endl;
}

void pop() {
    if (top == nullptr) {
        cout << "Stack kosong" << endl;
        return;
    }
    Node *temp = top;
    cout << "Pop " << temp->value << endl;

    top = top->next;
    delete temp;
}

void display() {
    cout << "Isi Stack : ";
    for (Node *cur = top; cur != nullptr; cur = cur->next)
        cout << cur->value << " ";
    cout << endl;
}

int main() {
    push(10);
    push(20);
    push(30);
    display();

    pop();
    display();

    return 0;
}