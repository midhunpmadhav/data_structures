/*
 * Author      : Midhun P
 * Description : Right view of a tree
 * Remarks     : Print last node in each level
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

    // Function to print right view of a tree
    static void right_view(Node *root)
    {
        queue<Node *> q;

        if (!root)
            return;

        q.push(root);
        q.push(NULL);

        while (!q.empty())
        {
            Node *tmp;

            tmp = q.front();
            q.pop();

            if (!tmp)
            {
                if (q.empty())
                    break;
                else
                {
                    q.push(NULL);
                    continue;
                }
            }

            // If next node is null,
            // then current node is the last node in that level.
            if (!q.front())
                cout << tmp->data << " ";

            if (tmp->left)
                q.push(tmp->left);

            if (tmp->right)
                q.push(tmp->right);
        }
        cout << endl;
    }
};

int main()
{
    /* Create following Binary Tree  
         1  
        / \  
       2   3 
        \   \
         4   5
           \  
             6  
              \  
               7
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);

    cout << "Right view of binary tree is\t: ";
    Node::right_view(root);

    return 0;
}
