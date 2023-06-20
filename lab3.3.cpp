#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;
public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void enqueue(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->next = NULL;
        if (front == NULL) {
            front = temp;
        }
        else {
            rear->next = temp;
        }
        rear = temp;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }

    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        else {
            return front->data;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    cout << q.getFront() << endl;
    q.dequeue();
    q.dequeue();
    return 0;
}

