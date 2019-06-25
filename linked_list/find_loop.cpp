/*
 * Author      : Midhun P
 * Description : Find loop in a singly linked list.
 * Remarks     : Complexity should be O(n).
 *               Floyd’s Cycle finding algorithm
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

void print_linked_list(node *head, int max = 20)
{
    int count = 0;
    node *iter = head;

    while (iter)
    {
        cout << iter->data << " -> ";
        iter = iter->next;

        if (++count >= max)
            break;
    }

    if (count != max)
        cout << "NULL" << endl;
    else
        cout << "..." << endl;
}

void find_loop(node *head)
{
    node *slow_ptr, *fast_ptr;

    if (!head || !head->next)
        cout << "Head / head->next is NULL\n";

    slow_ptr = head->next;
    fast_ptr = head->next->next;

    while (slow_ptr != fast_ptr && fast_ptr && fast_ptr->next)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    if (slow_ptr == fast_ptr && fast_ptr)
    {
        // Now we found the loop. Check for the starting point.
        // As per Floyd’s Cycle finding algorithm.
        // (m + n*x + k) = 2*(m + n*y + k)
        fast_ptr = head;
        while (slow_ptr->next != fast_ptr->next)
        {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next;
        }
        cout << "Found loop at " << slow_ptr->data;
    }
    else
        cout << "Unable to find loop";
    cout << endl;
}

int main()
{
    node *head = NULL;
    node *tmp;
    node *node_5;

    head = tmp = new_node(1);

    for (int i = 2; i <= 10; ++i)
    {
        tmp->next = new_node(i);
        tmp = tmp->next;

        if (i == 5)
            node_5 = tmp;
    }

    // create a loop at node with value 5. i.e, 10 -> 5
    tmp->next = node_5;

    print_linked_list(head);
    find_loop(head);
}