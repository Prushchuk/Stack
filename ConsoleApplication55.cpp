#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class Stack {
private:
    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    void push(int val) {
        Node* newNode = new Node(val);
        if (top == nullptr) {
            top = newNode;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    int pop() {
        if (top == nullptr) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        int poppedValue = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        size--;
        return poppedValue;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getSize() {
        return size;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Size: " << stack.getSize() << endl;
    cout << "Element stack:" << endl;

    while (!stack.isEmpty()) {
        cout << stack.pop() << endl;
    }

    cout << "Size stack before delete: " << stack.getSize() << endl;
}