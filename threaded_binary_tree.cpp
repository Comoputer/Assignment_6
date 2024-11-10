#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int lbit;
    int rbit;
};

class tbt
{
public:
    Node *root;
    Node *head;

    tbt()
    {
        head = new Node();
        head->data = 999;
        head->left = head;
        head->right = head;
        head->lbit = 0;
        head->rbit = 1;
        root = nullptr;
    }

    void create(int d)
    {
        Node *temp = new Node();
        temp->data = d;
        temp->left = nullptr;
        temp->right = nullptr;
        temp->lbit = 0;
        temp->rbit = 0;

        if (root == nullptr)
        {
            root = temp;
            root->left = head;
            root->right = head;
            root->lbit = 1;
            root->rbit = 1;
            head->left = root;
            head->lbit = 1;
        }
        else
        {
            insert(root, temp);
        }
    }

    void insert(Node *root, Node *temp)
    {
        if (temp->data < root->data)
        {
                if (root->lbit == 1)
                { 
                    temp->left = root->left;
                    temp->right = root;
                    root->left = temp;
                    root->lbit = 0; 
                    temp->lbit = 1;    
                    temp->rbit = 1;    
                }
                else
                {
                    insert(root->left, temp);
                }
        }
            else if (temp->data > root->data)
            {
                if (root->rbit == 1)
                {
                    temp->right = root->right;
                    temp->left = root;
                    root->right = temp;
                    root->rbit=0;
                    temp->rbit = 1;
                    temp->lbit=1;
                }
                else
                {
                    insert(root->right, temp);
                }
            }
        }
    int search(int data)
    {
        Node *temp = head->left;
        while (temp != head)
        { 
            if (data == temp->data)
            {
                return 1;
            }
            else if (data < temp->data)
            {
                if (temp->lbit == 0)
                {
                    temp = temp->left;
                }
                else
                {
                    break;
                }
            }
            else if (data > temp->data)
            {
                if (temp->rbit == 0)
                {
                    temp = temp->right;
                }
                else
                {
                    break;
                }
            }
        }
        return 0; 
    }

        void inorder(){
            Node* temp=head->left;
            do{
            while(temp->lbit!=1){
                temp=temp->left;
            }
            cout<<temp->data<<" ";
            while(temp->rbit==1){
                temp=temp->right;
                if(temp==head){
                    return;
                }
                cout<<temp->data<<" ";
            }
            temp=temp->right;
            }while(temp!=head);
        }

        void preorder(){
            Node* temp=head->left;
            do{
                while(temp->lbit!=1){
                    cout<<temp->data<<" ";
                    temp=temp->left;
                }
                cout<<temp->data<<" ";
                while(temp->rbit==1){
                    temp=temp->right;
                    if(temp==head){
                        return;
                    }
                }
                temp=temp->right;
            }while(temp!=head);
        }
            void postorder()
    {
        if (root != nullptr)
        {
            postorderHelper(root);
        }
    }

    void postorderHelper(Node *node)
    {
        if (node == nullptr || node == head) 
            return;

        if (node->lbit == 0)
            postorderHelper(node->left);

        if (node->rbit == 0)
            postorderHelper(node->right);

        cout << node->data << " ";
    }
    };

    int main(){
        tbt tree;
tree.create(10);
tree.create(5);
tree.create(15);
tree.inorder();
cout<<endl;
tree.preorder();
cout<<endl;
tree.postorder();
//cout<<tree.search(5);
        return 0;
    }