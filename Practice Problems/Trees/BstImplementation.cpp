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

class BinarySearchTree
{
    Node *root = NULL;
    queue<Node*> q;
    public:
    void insert(int val)
    {
        Node* newNode=new Node;
        newNode->data=val;
        if(!root)
        {
            root=newNode;

        }
        else
        {
            Node* temp=root;
            Node* prev=NULL;
            while (temp)
            {
                prev=temp;
                if (val>temp->data)
                {
                    temp=temp->right;
                }
                else if(val<temp->data)
                {
                    temp=temp->left;
                }
                
            }
            if (val>prev->data)
            {
                prev->right=newNode;
            }
            else if (val<prev->data)
            {
                prev->left=newNode;
                
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
    void search(int val)
    {
        Node* temp=root;
        bool flag=false;
        while (temp)
        {
            if (val>temp->data)
            {
                temp=temp->right;
            }
            else if (val<temp->data)
            {
                temp=temp->left;
            }
            else
            {
                cout<<"Value Found in Binary Search Tree"<<endl;
                return;
            }
        }
        cout<<"Value not Found in Binary Search Tree"<<endl;

        
    }
    void del(int val)
    {
        Node* temp=root;
        Node* prev=root;
        while (temp->data!=val)
        {
            prev=temp;
            if (val>temp->data)
            {
                temp=temp->right;
            }
            else
            {
                temp=temp->left;
            }           
        }
        if (!temp->left&&!temp->right )
        {
            if (prev->right==temp)
            {
                prev->right=NULL;
            }
            else
            {
                prev->left=NULL;
            }
            free(temp);
        }
        else if (!temp->left)
        {
            if (prev->right==temp)
            {
                prev->right=temp->right;
            }
            else
            {
                prev->left=temp->right;
            }
            
            
        }
        else if (!temp->right)
        {
            if (prev->right=temp)
            {
                prev->right=temp->left;
            }
            else
            {
                prev->left=temp->left;
            }
        }
        else
        {
            Node* temp2=temp;
            Node* prev2=temp;
            temp2=temp2->left;
            while (temp2->right)
            {
                prev2=temp2;
                temp2=temp2->right;
            }
            temp->data=temp2->data;
            if (prev2->right==temp2)
            {
                prev2->right=NULL;
            }
            else if (prev2->left==temp2)
            {
                prev2->left=NULL;
            }
            
            
        }
    }
};
int main()
{
    BinarySearchTree bt;
    int infi=true;
    while(infi)
    {
        cout<<"Press 1 to insert a value in Binary Search Tree\n";
        cout<<"Press 2 for Pre Order Traversal\n";
        cout<<"Press 3 for Post Order Traversal\n";
        cout<<"Press 4 for In Order Traversal\n";
        cout<<"Press 5 for Level Order Traversal\n";
        cout<<"Press 6 search a value in Binary Search Tree\n";
        cout<<"Press 7 to delete a value in Binary Search Tree\n";
        cout<<"Press 8 to Exit\n";
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
            bt.search(v);
            break;
        case 7:
            int valu;
            cout<<"Enter the value to be deleted\n";
            cin>>valu;
            bt.del(valu);
            break;
        
        case 8:
            infi=false;
            break;
        }


    }
    
    return 0;
}