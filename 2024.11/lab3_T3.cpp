#include<iostream>
#include<string>
#include<sstream>
#include<vector>
using namespace std;

struct Node
{
    char key;
    Node* left;
    Node* right;
    int height;
    Node(char k) : key(k), left(nullptr), right(nullptr), height(1) {}
};

class AVLTree
{
public:
    Node* root;
    AVLTree() : root(nullptr) {}

    int height(Node* node)
    {
        return node ? node->height : 0;
    }

    int getBalance(Node* node)
    {
        return node ? height(node->left) - height(node->right) : 0;
    }

    Node* rightRotate(Node* y)
    {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x)
    {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* insert(Node* node, char key)
    {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insert(node->left, key);
        else if (key > node->key) node->right = insert(node->right, key);
        else return node;

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);
        if (balance > 1 && key < node->left->key) return rightRotate(node);
        if (balance < -1 && key > node->right->key) return leftRotate(node);
        if (balance > 1 && key > node->left->key) { node->left = leftRotate(node->left); return rightRotate(node); }
        if (balance < -1 && key < node->right->key) { node->right = rightRotate(node->right); return leftRotate(node); }

        return node;
    }

    Node* deleteNode(Node* root, char key)
    {
        if (!root) return root;
        if (key < root->key) root->left = deleteNode(root->left, key);
        else if (key > root->key) root->right = deleteNode(root->right, key);
        else
        {
            if (!root->left || !root->right)
            {
                Node* temp = root->left ? root->left : root->right;
                if (!temp)
                {
                    temp = root;
                    root = nullptr;
                }
                else *root = *temp;
                delete temp;
            }
            else
            {
                Node* temp = minNode(root->right);
                root->key = temp->key;
                root->right = deleteNode(root->right, temp->key);
            }
        }
        if (!root) return root;
        root->height = max(height(root->left), height(root->right)) + 1;
        int balance = getBalance(root);
        if (balance > 1 && getBalance(root->left) >= 0) return rightRotate(root);
        if (balance < -1 && getBalance(root->right) <= 0) return leftRotate(root);
        if (balance > 1 && getBalance(root->left) < 0) { root->left = leftRotate(root->left); return rightRotate(root); }
        if (balance < -1 && getBalance(root->right) > 0) { root->right = rightRotate(root->right); return leftRotate(root); }
        return root;
    }

    Node* minNode(Node* node)
    {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }

    void postOrder(Node* node, string& result)
    {
        if (!node) return;
        postOrder(node->left, result);
        postOrder(node->right, result);
        result += node->key;
    }
};

int main()
{
    int N1, N2;
    cin >> N1;
    vector<char> insertSeq(N1);
    for (int i = 0; i < N1; ++i) cin >> insertSeq[i];

    AVLTree tree;
    for (char ch : insertSeq) tree.root = tree.insert(tree.root, ch);

    cin >> N2;
    vector<char> deleteSeq(N2);
    for (int i = 0; i < N2; ++i) cin >> deleteSeq[i];

    for (char ch : deleteSeq) tree.root = tree.deleteNode(tree.root, ch);

    string result;
    tree.postOrder(tree.root, result);
    cout << result;
    return 0;
}

