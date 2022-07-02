#include <iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

void preOrder(Node *cur)
{
    if (cur != NULL)
    {
        cout << cur->data << " ";
        preOrder(cur->left);
        preOrder(cur->right);
    }
}
void inOrder(Node *cur)
{
    if (cur != NULL)
    {
        inOrder(cur->left);
        cout << cur->data << " ";
        inOrder(cur->right);
    }
}
void postOrder(Node *cur)
{
    if (cur != NULL)
    {
        postOrder(cur->left);
        postOrder(cur->right);
        cout << cur->data << " ";
    }
}

void level_order(Node* cur)
{
    if (!cur)
    {
        return;
    }
    queue<Node*> q;
    q.push(cur);
    while (!q.empty())
    {
        cout<<q.front()->data<<" ";
        if (q.front()->left)
        {
            q.push(q.front()->left);
        }
        if (q.front()->right)
        {
            q.push(q.front()->right);
        }
        q.pop();
    }   
}

class BinaryTree
{
    Node *root = NULL;
    queue<Node*> q;
public:
    
    void insert(int val)
    {
        Node* newNode= new Node;
        newNode->data=val;
        
        if (root==NULL)
        {
            root=newNode;
            q.push(newNode);

        }
        else
        {
            Node* temp=root;
            if (!q.front()->left)
            {
                q.front()->left=newNode;
                q.push(newNode);
            }
            else if(!q.front()->right)
            {
                q.front()->right=newNode;
                q.push(newNode);
                q.pop();
            }
        }
    }

    void LevelOrderTraversal()
    {
        level_order(root);
        cout<<endl;
    }
    void PostOrderTraversal()
    {
        postOrder(root);
        cout<<endl;

    }
    void PreOrderTraversal()
    {
        preOrder(root);
        cout<<endl;

    }
    void InOrderTraversal()
    {
        inOrder(root);
        cout<<endl;

    }
    
    void Search(int val)
    {
        queue<Node*> qu;
        int flag=false;
        q.push(root);
        while (!q.empty())
        {
            if(q.front()->data==val)
            {
                cout<<"Value Found in Binary Tree"<<endl;
                flag=true;
                break;
            }
            if (q.front()->left)
            {
                q.push(q.front()->left);
            }
            if (q.front()->right)
            {
                q.push(q.front()->right);
            }
            q.pop();

            
        }
        if (flag==false)
        {
            cout<<"Value not found in Binary Tree"<<endl;
        }

    }

};

int main()
{
       BinaryTree bt;
    // bt.insert(5);
    // bt.insert(4);
    // bt.insert(3);
    // bt.insert(2);
    // bt.insert(1);
    // bt.insert(6);
    // bt.insert(9);

    // bt.InOrderTraversal();
    // bt.PreOrderTraversal();
    // bt.PostOrderTraversal();
    // bt.LevelOrderTraversal();

    // bt.Search(6);
    int infi=true;
    while(infi)
    {
        cout<<"Press 1 to insert a value in Complete Binary Tree\n";
        cout<<"Press 2 for Pre Order Traversal\n";
        cout<<"Press 3 for Post Order Traversal\n";
        cout<<"Press 4 for In Order Traversal\n";
        cout<<"Press 5 for Level Order Traversal\n";
        cout<<"Press 6 search a value in Binary Tree\n";
        cout<<"Press 7 to Exit\n";
        int input;
        cin>>input;
        switch (input)
        {
        case 1:
            int value;
            cout<<"Enter the value to be inserted\n";
            cin>>value;
            bt.insert(value);
            break;
        case 2:
            bt.PreOrderTraversal();
            break;
        case 3:
            bt.PostOrderTraversal();
            break;
        case 4:
            bt.InOrderTraversal();
            break;
        case 5:
            bt.LevelOrderTraversal();
            break;
        case 6:
            int v;
            cout<<"Enter the value you want to search in Binary Tree"<<endl;
            cin>>v;
            bt.Search(v);
            break;
        
        case 7:
            infi=false;
            break;
        }


    }
    return 0;
}