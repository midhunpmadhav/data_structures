/*
 * Author      : Midhun P
 * Description : Stack implementation
 * Remarks     : Build stack without STL
 */

#include <iostream>

using namespace std;

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* new_node(int data) {
    Node *tmp = new Node();

    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

class Stack {
private:
    int count;
    Node *top;

public:
    Stack() {
        count = 0; 
        top = NULL;
    }

    int size() {
        return count;
    }

    void push(int data) {
        Node *tmp = new_node(data);
        ++count;
        tmp->next = top;
        top = tmp;
    }

    int pop() {
        if(!count)
            return -1;

        --count;
        int data;
        Node* tmp = top;
        top = top->next;

        data = tmp->data;
        free(tmp);
        return data;
    }

    int front() {
        return top->data;
    }

    void print() {
        if(!count) {
            cout << "Stack is EMPTY!" << endl;
            return;
        } 
        Node *tmp = top;
        while(tmp) {
            cout << tmp->data << ", ";
            tmp = tmp->next;
        }
        cout << "\b\b " << endl;
        
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    cout << "After pushes of 1, 2, 3 : ";
    s.print();
    s.pop();

    s.push(4);
    s.push(5);
    cout << "After one pop and pushes of 4, 5 : ";
    s.print();

    s.pop();
    s.pop();
    s.pop();
    cout << "After 3 pops : ";
    s.print();
    s.pop();
}