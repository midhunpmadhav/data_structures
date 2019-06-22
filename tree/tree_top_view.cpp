/*
 * Author      : Midhun P
 * Description : Right view of a tree
 * Remarks     : Print last node in each level
 */

#include <iostream>
#include <queue>
#include <map>

using namespace std;

class Node
{
private:
    int data;
    int hd;

public:
    Node *left;
    Node *right;

    Node(int i)
    {
        data = i;
        left = right = NULL;
    }

    // Function to print top view of a tree
    static void top_view(Node *root)
    {
        queue<Node *> q;
        map<int, int> m;

        if (!root)
            return;

        root->hd = 0;
        q.push(root);

        while (!q.empty())
        {
            Node *tmp;

            tmp = q.front();
            q.pop();

            if (!m.count(tmp->hd))
                m[tmp->hd] = tmp->data;

            if (tmp->left)
            {
                tmp->left->hd = tmp->hd - 1;
                q.push(tmp->left);
            }

            if (tmp->right)
            {
                tmp->right->hd = tmp->hd + 1;
                q.push(tmp->right);
            }
        }

        for (map<int, int>::iterator i = m.begin(); i != m.end(); ++i)
            cout << i->second << " ";
        cout << endl;
    }
};

int main()
{
    /* Create following Binary Tree  
         1  
        / \  
       2   3 
       \    \
        4    5
         \  
          6  
           \  
            7
             \
              8
    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(5);
    root->left->right->right = new Node(6);
    root->left->right->right->right = new Node(7);
    root->left->right->right->right->right = new Node(8);

    cout << "Top view of binary tree is\t: ";
    Node::top_view(root);

    return 0;
}
