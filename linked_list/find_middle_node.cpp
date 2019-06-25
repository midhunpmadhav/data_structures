/*
 * Author      : Midhun P
 * Description : Find middle of a singly linked list
 * Remarks     : Complexity should be O(n), without count.
 */

#include <iostream>

using namespace std;

typedef struct node_stuct
{
    int data;
    struct node_stuct *next;
} node;

node *new_node(int d)
{
    node *tmp = new node();

    tmp->data = d;
    tmp->next = NULL;

    return tmp;
}

void print_linked_list(node *head)
{
    node *h = head;

    while (h)
    {
        cout << h->data << " -> ";
        h = h->next;
    }
    cout << "NULL" << endl;
}

int find_middle(node *head)
{
    node *slow, *fast;

    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main()
{
    node *head = NULL;
    node *tmp;

    head = tmp = new_node(1);

    for (int i = 2; i <= 7; ++i)
    {
        tmp->next = new_node(i);
        tmp = tmp->next;
    }

    print_linked_list(head);

    cout << "Middle point is " << find_middle(head) << endl;
}
