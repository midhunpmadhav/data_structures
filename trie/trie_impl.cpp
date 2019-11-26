/*
 * Author      : Midhun P
 * Description : Trie data structure implementation
 * Remarks     : 
 */

#include <map>
#include <queue>
#include <iostream>

using namespace std;

class trie_node
{
private:
    map<char, trie_node *> children;
    bool isWord;

public:
    void setIsWord(bool inp)
    {
        isWord = inp;
    }
    bool getIsWord()
    {
        return isWord;
    }
    void print_level_order()
    {
        trie_node *curr = this;
        queue<trie_node *> q;

        q.push(curr);
        cout << endl
             << "Level order: " << endl;
        while (!q.empty())
        {
            trie_node *tmp = q.front();
            q.pop();

            if (tmp->children.size())
            {
                for (auto i = tmp->children.begin(); i != tmp->children.end(); ++i)
                {
                    cout << i->first << ", ";
                    q.push(i->second);
                }
                cout << endl;
            }
        }
    }
    void add_word(string word)
    {
        trie_node *curr = this;

        for (int i = 0; i < word.length(); ++i)
        {
            auto iter = curr->children.find(word[i]);
            if (iter == curr->children.end())
            {
                trie_node *tmp = new trie_node();

                if (i == (word.length() - 1))
                    tmp->setIsWord(true);
                else
                    tmp->setIsWord(false);
                curr->children.insert(pair<char, trie_node *>(word[i], tmp));
                curr = tmp;
            }
            else
                curr = iter->second;
        }
    }

    bool find_word(string word)
    {
        trie_node *curr = this;
        for (int i = 0; i < word.length(); ++i)
        {
            auto iter = curr->children.find(word[i]);

            if (iter == curr->children.end())
                return false;
            curr = iter->second;
        }
        return curr->getIsWord();
    }
};

int main()
{
    int choice;
    string word;

    trie_node *root = new trie_node();
    root->setIsWord(false);

    do
    {
        cout << endl
             << "Menu" << endl
             << "----" << endl
             << "1. insert " << endl
             << "2. Search" << endl
             << endl
             << "Enter your choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 2)
        {
            cout << "Enter word: ";
            getline(cin, word);
            getline(cin, word);
        }
        else if (choice != 3)
        {
            cout << endl
                 << "Invalid choice!!! Exiting..." << endl
                 << endl;
            break;
        }

        switch (choice)
        {
        case 1:
            root->add_word(word);
            break;
        case 2:
            cout << endl
                 << "Word \"" << word << (root->find_word(word) ? "\" FOUND" : "\" NOT FOUND") << " in DB" << endl;
            break;
        case 3:
            root->print_level_order();
        }

    } while (true);
}