#include <iostream>
using namespace std;

struct Node {
    int value;
    Node *next;
};

Node *front = nullptr;
Node *rear  = nullptr;

void enqueue(int value) {
    Node *baru = new Node{value, nullptr};

    if (rear == nullptr) {
        front = rear = baru;
    } else {
        rear->next = baru;
        rear = baru;
    }
    cout << "Enqueue " << value << endl;
}

void dequeue() {
    if (front == nullptr) {
        cout << "Queue kosong" << endl;
        return;
    }
    Node *temp = front;
    cout << "Dequeue " << temp->value << endl;

    front = front->next;
    if (front == nullptr) rear = nullptr;

    delete temp;
}

void display() {
    cout << "Isi Queue : ";
    for (Node *cur = front; cur != nullptr; cur = cur->next)
        cout << cur->value << " ";
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}