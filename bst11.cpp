/* Beginning with an empty binary search tree, Construct binary search tree by inserting the
values in the order given. After constructing a binary tree -
i. Insert new node
ii. Find number of nodes in longest path from root
iii. Minimum data value found in the tree
iv. Change a tree so that the roles of the left and right pointers are swapped at every
node
v. Search a value */

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left, *right;
};

class BST
{
    node *root;

public:
    BST(void)
    {
        root = NULL;
    }
    void create();
    node *insert(node *temp, int x);
    void display(node *root);
    void swap(int a, int b);
    void search(int x);
    int min(struct node *node);
    int numOfNodes(struct node *node);
    void menu();
};

node *BST ::insert(node *temp, int x)
{
    if (temp == NULL)
    {
        node *temp2 = new node;
        temp2->data = x;
        temp2->right = NULL;
        temp2->left = NULL;
        temp = temp2;
        return temp;
    }
    else if (x < temp->data)
    {
        temp->left = insert(temp->left, x);
        return temp;
    }
    else
    {
        temp->right = insert(temp->right, x);
        return temp;
    }
}

void BST::create()
{
    int numele, data;
    std::cout << "Enter the number of values you want to insert: ";
    std::cin >> numele;
    std::cout << "Enter the first element (ROOT): ";
    std::cin >> data;
    root = insert(root, data);
    for (int i = 1; i < numele; i++)
    {
        std::cout << "Enter (" << i + 1 << ")th element: ";
        std::cin >> data;
        insert(root, data);
    }
}

void BST::display(node *t)
{
    if (t != NULL)
    {
        display(t->left);
        cout << t->data << "   ";
        display(t->right);
    }
}
int max(int a, int b)
{
    return (a > b) ? a : b;
}
int BST::numOfNodes(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else
    {
        
        return 1 + max(numOfNodes(node->left), numOfNodes(node->right));
    }
}

int BST::min(struct node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    else{
        while (node != NULL)
        {
            node = node->left;
        }
        return node->data;
    }
}

void BST::menu()
{
    create();
    display(root);
    cout << endl;
    /* cout << "Enter the value you want to insert" << endl;
    int inser;
    cin >> inser;
    insert(root,inser); */
    cout << "Minimum value in the tree is :" << min(root);
    cout << "Number of nodes in longest path from root in the tree is :" << numOfNodes(root);
}

int main()
{
    BST tree;
    tree.menu();
    return 0;
}