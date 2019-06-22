/*
 * Author      : Midhun P
 * Description : Print nodes of a binary tree in vertical order.
 * Remarks     : Print nodes in the order of 
 *               horizondal distance.
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

    // Function to print vertical order of a tree
    static void vertical_order(Node *root)
    {
        queue<Node *> q;
        map<int, vector<int>> m;

        if (!root)
            return;

        root->hd = 0;
        q.push(root);

        while (!q.empty())
        {
            Node *tmp;

            tmp = q.front();
            q.pop();

            if (m.find(tmp->hd) != m.end())
                m[tmp->hd].push_back(tmp->data);
            else
                m[tmp->hd] = vector<int>(1, tmp->data);

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

        for (map<int, vector<int>>::iterator map_i = m.begin(); map_i != m.end(); ++map_i)
            for (vector<int>::iterator vector_i = map_i->second.begin(); vector_i != map_i->second.end(); ++vector_i)
                cout << *vector_i << " ";

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

    cout << "Vertical order of binary tree is : ";
    Node::vertical_order(root);

    return 0;
}
