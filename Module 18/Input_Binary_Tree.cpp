#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;

    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
Node *input_tree()
{
    int val;
    cin >> val;
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);

    queue<Node *> q;
    if (root)
        q.push(root);

    while (!q.empty())
    {
        // Remove
        Node *p = q.front();
        q.pop();

        // Work
        int l, r;
        cin >> l >> r;
        Node *myleft;
        Node *myright;
        if (l == -1)
            myleft = NULL;
        else
            myleft = new Node(l);

        if (r == -1)
            myright = NULL;
        else
            myright = new Node(r);

        p->left = myleft;
        p->right = myright;
        // Push Children

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}
void levelOrder(Node *root)
{
    if (root == NULL)
    {
        cout << "empty tree" << endl;
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        if (q.front() != NULL)
        {
            cout << q.front()->val << " ";
        }
        else
        {
            cout << endl;
            q.pop();
            if (!q.empty())
            {
                q.push(NULL);
            }
            continue;
        }

        if (q.front()->left != NULL)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right != NULL)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }
}
int main()
{
    Node *root = input_tree();
    levelOrder(root);
    return 0;
}