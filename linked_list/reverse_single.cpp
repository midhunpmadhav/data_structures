/*
 * Author      : Midhun P
 * Description : Reverse a singly linked list
 * Remarks     : 
 */

#include <iostream>

using namespace std;

struct node_stuct {
    int data;
    struct node_stuct* next;
};

typedef struct node_stuct node;

node* new_node(int d) {
    node* tmp = new node();

    tmp->data = d;
    tmp->next = NULL;

    return tmp;
}

void print_linked_list(node* head) {
    node* h = head;

    while(h) {
        cout << h->data << " -> ";
        h = h->next;
    }
    cout << "NULL" << endl;
}

node* reverse_linked_list(node* tmp) {
    node* curr;
    node* prev;

    curr = tmp; 
    prev = NULL;

    while(curr) {
        node* tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    return prev;
}

node* reverse_linked_list_rec(node* head) {
    node* tmp = head;
    if(!tmp || !tmp->next) {
        return tmp;
    }

    node* new_head = reverse_linked_list_rec(tmp->next);
    tmp->next->next = tmp;
    tmp->next = NULL;

    return new_head;
}

int main() {
    node* head = NULL; 

    head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);
    head->next->next->next = new_node(4);
    head->next->next->next->next = new_node(5);

    cout << "With out recursion:\nBefore : " ;
    print_linked_list(head);
    head = reverse_linked_list(head);
    cout << "After  : " ;
    print_linked_list(head);

    cout << "\nWith recursion:\nBefore : " ;
    print_linked_list(head);
    head = reverse_linked_list_rec(head);
    cout << "After  : " ;
    print_linked_list(head);
}