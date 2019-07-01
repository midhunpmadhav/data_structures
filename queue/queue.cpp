/*
 * Author      : Midhun P
 * Description : Queue implementation
 * Remarks     : Build queue without STL
 */

#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
    struct node *prev;
} Node;

Node* new_node(int data) {
    Node *tmp = new Node();

    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

class Queue {
private:
    int count;
    Node *head;
    Node *tail;

public:
    Queue() {
        count = 0; 
        head = NULL;
        tail = NULL;
    }

    int size() {
        return count;
    }

    void enqueue(int data) {
        Node *tmp = new_node(data);
        if(count++) {
            tail->next = tmp;
            tmp->prev = tail;
            tail = tmp;
        } else {
            head = tail = tmp;
        }
    }

    int dequeue() {
        if(!count)
            return -1;
        int data;
        Node* tmp = head;
        head = head->next;
        if(--count)
            head->prev = NULL;    
        else
            tail = head = NULL;
        
        data = tmp->data;
        free (tmp);

        return data;
    }

    int front() {
        return head->data;
    }

    void print() {
        if(!count) {
            cout << "Queue is EMPTY!" << endl;
            return;
        } 
        Node *tmp = head;
        while(tmp) {
            cout << tmp->data << ", ";
            tmp = tmp->next;
        }
        cout << "\b\b " << endl;
    }
};

int main() {
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    cout << "After enqueues of 1, 2, 3 : ";
    q.print();
    q.dequeue();

    q.enqueue(4);
    q.enqueue(5);
    cout << "After one dequeue and queue of 4, 5 : ";
    q.print();

    q.dequeue();
    q.dequeue();
    q.dequeue();
    cout << "After 3 dequeues : ";
    q.print();
    q.dequeue();
}