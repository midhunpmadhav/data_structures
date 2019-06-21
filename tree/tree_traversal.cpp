/*
 * Author      : Midhun P
 * Description : different types of tree traversals
 * Remarks     : Preorder, inorder, postorder and level order
 */

#include<iostream>
#include<queue>

using namespace std;

class Node {
    private:
        int data;

    public:
        Node* left;
        Node* right;

        Node(int i) {
            data = i;
            left = right = NULL;
        }

        static void in_order(Node* root) {
            if(!root)
                return;

            in_order(root->left);
            cout << root->data << " ";
            in_order(root->right);
        }

        static void pre_order(Node* root) {
            if(!root)
                return;

            cout << root->data << " ";
            pre_order(root->left);
            pre_order(root->right);
        }

        static void post_order(Node* root) {
            if(!root)
                return;

            post_order(root->left);
            post_order(root->right);
            cout << root->data << " ";
        }

        static void level_order(Node* root) {
            queue<Node*> q;

            if(!root)
                return;

            q.push(root);

            while(!q.empty()) {
                Node *tmp;
                
                tmp = q.front();
                q.pop();

                cout << tmp->data << " ";

                if(tmp->left)
                    q.push(tmp->left);

                if(tmp->right)
                    q.push(tmp->right);
            }
            cout << endl;
        }
};

int main() { 
    struct Node *root = new Node(1); 

    root->left = new Node(2); 
    root->right = new Node(3); 
    root->left->left = new Node(4); 
    root->left->right = new Node(5);  
  
    cout << "\nPre order traversal of binary tree is \t: "; 
    Node::pre_order(root);
    cout << endl;
  
    cout << "In order traversal of binary tree is \t: "; 
    Node::in_order(root);
    cout << endl;
  
    cout << "Post order traversal of binary tree is \t: "; 
    Node::post_order(root);
    cout << endl;

    cout << "Level order traversal of binary tree is\t: "; 
    Node::level_order(root);
    cout << endl;
    return 0; 
} 
