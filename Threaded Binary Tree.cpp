/*
Name: Shantanu Hemantrao Chaudhari
Batch : B1
Practical 2: 
Write a program in C++ to implement the following
operations on Threaded Binary Tree : create, recursive inorder traversal, recursive preorder traversal, recursive postorder traversal, non recursive
inorder traversal, non recursive preorder traversal, non recursive postorder traversal

*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int val;
    Node *left, *right;
    bool lthread, rthread;

    Node(int data)
	{
        this->val = data;
        this->lthread = true;
        this->rthread = true;
    }
};

Node* insert(Node *root, int data)
{
    Node *ptr = root, *parent = NULL;
    while(ptr)
	{
        if(ptr->val==data)
		{
            cout<<"Duplicate keys are not allowed\n";
            return root;
        }

        parent = ptr;
        if(data < parent->val)
		{
            if(ptr->lthread) 
			break;
            ptr = ptr->left;
        }
		else
		{
            if(ptr->rthread) 
			break;
            ptr = ptr->right;
        }
    }

    Node *temp = new Node(data);
    if(!parent)
	{
        root = temp;
        root->left = NULL;
        root->right = NULL;
    }
	else if(data < parent->val)
	{
        temp->left = parent->left;
        temp->right = parent;
        parent->lthread = false;
        parent->left = temp;
    }
	else
	{
        temp->right = parent->right;
        temp->left = parent;
        parent->rthread = false;
        parent->right = temp;
    }

    return root;
}

bool search(Node* parent, int data)
{
    if(!parent) 
	return false;

    if(parent->val == data) 
	return true;

    if(!parent->lthread && data < parent->val) 
	return search(parent->left, data);
    
	if(!parent->rthread && data > parent->val) 
	return search(parent->right, data);

    return false;
}

void recursive_preorder(Node *parent)
{
    if(!parent) 
	return;

    cout<<parent->val<<" ";
    if(!parent->lthread) 
	recursive_preorder(parent->left);
	
    if(!parent->rthread) 
	recursive_preorder(parent->right);
}

void recursive_inorder(Node *parent)
{
    if(!parent) 
	return;

    if(!parent->lthread) 
	recursive_inorder(parent->left);
    cout<<parent->val<<" ";
    
	if(!parent->rthread) 
	recursive_inorder(parent->right);
}

void recursive_postorder(Node* parent)
{
    if(!parent) 
	return;

    if(!parent->lthread) 
	recursive_postorder(parent->left);
	
    if(!parent->rthread) 
	recursive_postorder(parent->right);
    cout<<parent->val<<" ";
}

Node* inorderSuccessor(Node *ptr)
{
    if(ptr->rthread) 
	return ptr->right;

    ptr = ptr->right;
    while(!ptr->lthread) ptr = ptr->left;
    return ptr;
}

void non_recursive_preorder(Node *root)
{
    if(!root)
	{
        cout<<"Tree is empty\n";
        return;
    }

    Node *ptr = root;
    while(ptr)
	{
        cout<<ptr->val<<" ";
        if(!ptr->lthread) 
		ptr = ptr->left;
		
        else if(!ptr->rthread) 
		ptr = ptr->right;
        else
		{
            while(ptr && ptr->rthread) ptr = ptr->right;
            if(ptr) ptr = ptr->right;
        }
    }
}

void non_recursive_inorder(Node* root)
{
    if(!root) cout<<"Tree is empty\n";

    Node* ptr = root;
    while(!ptr->lthread) ptr = ptr->left;
    while(ptr)
	{
        cout<<ptr->val<<" ";
        ptr = inorderSuccessor(ptr);
    }
}

int main()
{
    Node *root = NULL;
    int choice, data, n;

    do{
        cout<<"\n\t1. Insert Nodes\n\t2. Recursive Traversals\n\t3. Non Recursive Traversals\n\t4. Search a value\n\t0. Exit\nEnter your choice: ";
        cin>>choice;
        switch(choice)
		{
            case 1:
                cout<<"\nNumber of nodes to insert: ";
                cin>>n;
                for(int i=1; i<=n; i++)
				{
                    cout<<"Enter data for node number "<<i<<": ";
                    cin>>data;
                    root = insert(root, data);
                }
                break;

            case 2:
                cout<<"\nRecursive Traversals\n";
                
				cout<<"Preorder: ";
                recursive_preorder(root);
                cout<<"\nInorder: ";
                recursive_inorder(root);
                cout<<"\nPostorder: ";
                recursive_postorder(root);
                break;

            case 3:
                cout<<"\nNon Recursive Traversals\n";
                
				cout<<"Preorder: ";
                non_recursive_preorder(root);
                cout<<"\nInorder: ";
                non_recursive_inorder(root);
                break;

            case 4:
                cout<<"Enter data to be searched: ";
                cin>>data;
                
				if(search(root, data))
				{
                    cout<<data<<" found in the Tree.";
                }
				else
				{
                    cout<<data<<" NOT found in the Tree.";
                }
                break;

            case 0: 
				break;

            default:
                cout<<"Invalid choice. Please try again!!";
        }
    }while(choice!=0);
}

/*
OUTPUT

   1. Insert Nodes
        2. Recursive Traversals
        3. Non Recursive Traversals
        4. Search a value
        0. Exit
Enter your choice: 1

Number of nodes to insert: 3
Enter data for node number 1: 3
Enter data for node number 2: 5
Enter data for node number 3: 4

        1. Insert Nodes
        2. Recursive Traversals
        3. Non Recursive Traversals
        4. Search a value
        0. Exit
Enter your choice: 2

Recursive Traversals
Preorder: 3 5 4
Inorder: 3 4 5
Postorder: 4 5 3
    
		1. Insert Nodes
        2. Recursive Traversals
        3. Non Recursive Traversals
        4. Search a value
        0. Exit
Enter your choice: 3

Non Recursive Traversals
Preorder: 3 5 4
Inorder: 3 4 5
        
		1. Insert Nodes
        2. Recursive Traversals
        3. Non Recursive Traversals
        4. Search a value
        0. Exit
Enter your choice: 4
Enter data to be searched: 4
4 found in the Tree.
        1. Insert Nodes
        2. Recursive Traversals
        3. Non Recursive Traversals
        4. Search a value
        0. Exit

*/
