/*
 * Author      : Midhun P
 * Description : Reverse a doubly linked list
 * Remarks     : 
 */

#include <iostream>

using namespace std;

struct node_stuct {
    int data;
    struct node_stuct* next;
    struct node_stuct* prev;
};

typedef struct node_stuct node;

node* new_node(int d, node* prev) {
    node* tmp = new node();

    tmp->data = d;
    tmp->prev = prev;
    tmp->next = NULL;

    return tmp;
}

void print_linked_list(node* head) {
    node* fwd = head;
    node* bwd = NULL;

    cout << "\tForward  : ";
    while(fwd) {
        cout << fwd->data << " <-> ";
        bwd = fwd;
        fwd = fwd->next;
    }
    cout << "NULL" << endl;

    cout << "\tBackward : ";
    while(bwd) {
        cout << bwd->data << " <-> ";
        bwd = bwd->prev;
    }
    cout << "NULL" << endl;
}

node* reverse_linked_list(node* tmp) {
    node* curr;
    node* prev;

    curr = tmp; 
    prev = NULL;

    while(curr) {
        curr->prev = curr->next;
        curr->next = prev;
        prev = curr;
        curr = curr->prev;
    }

    return prev;
}

node* reverse_linked_list_rec(node* head) {
    if(!head) {
        return NULL;
    }

    node* tmp = head->next;
    head->next = head->prev;
    head->prev = tmp;

    if(!head->prev)
        return head;
    else
        return reverse_linked_list_rec(head->prev);
}

int main() {
    node* head = NULL; 

    head = new_node(1, NULL);
    head->next = new_node(2, head);
    head->next->next = new_node(3, head->next);
    head->next->next->next = new_node(4, head->next->next);
    head->next->next->next->next = new_node(5, head->next->next->next);

    cout << "With out recursion:\nBefore : \n" ;
    print_linked_list(head);

    head = reverse_linked_list(head);
    cout << "After  : \n" ;
    print_linked_list(head);
    
    cout << "\nWith recursion:\nBefore : \n" ;
    print_linked_list(head);
    head = reverse_linked_list_rec(head);
    cout << "After  : \n" ;
    print_linked_list(head);

}