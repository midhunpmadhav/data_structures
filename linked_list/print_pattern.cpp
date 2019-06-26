/*
 * Author      : Midhun P
 * Description : input : 1, 2, 3, 4, 5, 6, 7, 8, 9, 10
 *               output: 1, 10, 2, 9, 3, 8, 4, 7, 5, 6
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

node *reverse_linked_list(node *tmp)
{
    node *curr;
    node *prev;

    curr = tmp;
    prev = NULL;

    while (curr)
    {
        node *tmp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = tmp;
    }

    return prev;
}

node *make_rqrd_pattern(node *head)
{
    node *middle, *fast_ptr, *tmp;

    if (!head || !head->next)
        return head;

    middle = head->next;
    fast_ptr = head->next->next;
    tmp = head;

    // Find the middle node
    while (fast_ptr && fast_ptr->next)
    {
        tmp = middle;
        middle = middle->next;
        fast_ptr = fast_ptr->next->next;
    }

    // Break list into two.
    node *start = head;
    tmp->next = NULL;

    // Reverse the second half.
    middle = reverse_linked_list(middle);

    node *ret = tmp = start;
    start = start->next;

    // Do a merge.
    while (start && middle)
    {
        tmp->next = middle;
        tmp = tmp->next;
        middle = middle->next;

        tmp->next = start;
        tmp = tmp->next;
        start = start->next;
    }

    while (start)
    {
        tmp->next = start;
        tmp = tmp->next;
        start = start->next;
    }

    while (middle)
    {
        tmp->next = middle;
        tmp = tmp->next;
        middle = middle->next;
    }

    return ret;
}

int main()
{
    node *head = NULL;
    node *tmp;

    head = tmp = new_node(1);

    for (int i = 2; i <= 10; ++i)
    {
        tmp->next = new_node(i);
        tmp = tmp->next;
    }

    cout << "Before : ";
    print_linked_list(head);

    head = make_rqrd_pattern(head);

    cout << "After  : ";
    print_linked_list(head);
}