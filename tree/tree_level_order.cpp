/*
 * Author      : Midhun P
 * Description : Level order traversal
 * Remarks     : Level order traversal with and without queue.
 */

#include <iostream>
#include <queue>

using namespace std;

class Node
{
private:
    int data;

public:
    Node *left;
    Node *right;

    Node(int i)
    {
        data = i;
        left = right = NULL;
    }

    // Function to do level order traversal using queue.
    static void level_order_using_queue(Node *root)
    {
        queue<Node *> q;

        if (!root)
            return;

        q.push(root);

        while (!q.empty())
        {
            Node *tmp;

            tmp = q.front();
            q.pop();

            cout << tmp->data << " ";

            if (tmp->left)
                q.push(tmp->left);

            if (tmp->right)
                q.push(tmp->right);
        }
        cout << endl;
    }

    // Function to find the height of a tree.
    static int height(Node *root)
    {
        if (!root)
            return 0;

        return 1 + max(height(root->left), height(root->right));
    }

    // Funtion to print nodes at a level.
    static void print_level(Node *root, int level)
    {
        if (!root)
            return;

        if (level == 1)
        {
            cout << root->data << " ";
        }
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }

    // Funciton to do level order traversal without queue.
    // But this will be slow.
    static void level_order(Node *root)
    {
        if (!root)
            return;

        for (int i = 1, h = height(root); i <= h; ++i)
        {
            print_level(root, i);
        }
        cout << endl;
    }
};

int main()
{
    struct Node *root = new Node(1);

    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Level order traversal of binary tree is\t\t: ";
    Node::level_order(root);

    cout << "Level order traversal (queue) of binary tree is\t: ";
    Node::level_order_using_queue(root);

    return 0;
}
