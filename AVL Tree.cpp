
#include<iostream>

using namespace std;
class avlnode
{
	public:
	int data;
	class avlnode *left;
	class avlnode *right;
}
*root;

/*class for stack for nonrecursive*/
class stack
{
	int top;
	avlnode *stack_nodes[20];
	
	public:
	stack()
	{
	top=-1;
	}
	
	void push(avlnode *);
	avlnode* pop();
	avlnode* peek(stack stk);
	
	int empty()
	{
	if(top==-1)
	return(1);
	return(0);
	}
};

void stack::push(avlnode *node)
{
	stack_nodes[++top]=node;
}

avlnode *stack::pop()
{
	return(stack_nodes[top--]);
}

class avlTree
{
	public:
	int height(avlnode *);
	int diff(avlnode *);
	avlnode *rr_rotation(avlnode *);
	avlnode *ll_rotation(avlnode *);
	avlnode *lr_rotation(avlnode *);
	avlnode *rl_rotation(avlnode *);
	avlnode* balance(avlnode *);
	avlnode* insert(avlnode *, int val);
	
	void display(avlnode *, int);
	void inorder(avlnode *);
	void preorder(avlnode *);
	void postorder(avlnode *);
	void inorder_non_rec(avlnode *);
	void preorder_non_rec(avlnode *);
	void postorder_non_rec(avlnode *);
	
	avlTree()
	{
	root = NULL;
	}
};

/*Height of AVL Tree*/
int avlTree::height(avlnode *temp)
{
	int h = 0;
	if (temp != NULL)
	{
		int l_height = height (temp->left);
		int r_height = height (temp->right);
		int max_height = max (l_height, r_height);
		h = max_height + 1;
	}
	return h;
}

/*Height Difference */
int avlTree::diff(avlnode *temp)
{
	int l_height = height (temp->left);
	int r_height = height (temp->right);
	int b_factor= l_height - r_height;
	return b_factor;
	
}

/* Right- Right Rotation*/
avlnode *avlTree::rr_rotation(avlnode *parent)
{
	avlnode *temp;
	temp = parent->right;
	parent->right = temp->left;
	temp->left = parent;
	return temp;
}

/*Left- Left Rotation*/
avlnode *avlTree::ll_rotation(avlnode *parent)
{
	avlnode *temp;
	temp = parent->left;
	parent->left = temp->right;
	temp->right = parent;
	return temp;
}

/*Left - Right Rotation*/
avlnode *avlTree::lr_rotation(avlnode *parent)
{
	avlnode *temp;
	temp = parent->left;
	parent->left = rr_rotation (temp);
	return ll_rotation (parent);
}

/*Right- Left Rotation*/
avlnode *avlTree::rl_rotation(avlnode *parent)
{
	avlnode *temp;
	temp = parent->right;
	parent->right = ll_rotation (temp);
	return rr_rotation (parent);
}

/* Balancing AVL Tree*/
avlnode *avlTree::balance(avlnode *temp)
{
	int bal_factor = diff (temp);
	
	if (bal_factor > 1)
	{
		if (diff (temp->left) > 0)
		temp = ll_rotation (temp);
		else
		temp = lr_rotation (temp);
	}
	else if (bal_factor < -1)
	{
		if (diff (temp->right) > 0)
		temp = rl_rotation (temp);
		else
		temp = rr_rotation (temp);
	}
	return temp;
}

/*Insert Element into the tree*/
avlnode *avlTree::insert(avlnode *root, int value)
{
	if (root == NULL)
	{
	root = new avlnode;
	root->data = value;
	root->left = NULL;
	root->right = NULL;
	return root;
	}
	else if (value < root->data)
	{
	root->left = insert(root->left, value);
	root = balance (root);
	}
	else if (value >= root->data)
	{
	root->right = insert(root->right, value);
	root = balance (root);
	}
	else
	cout<<"Node element already exist"<<endl;
	return root;
}

/*Display AVL Tree*/
void avlTree::display(avlnode *ptr, int level)
{
	if (ptr!=NULL)
	{
		display(ptr->right, level + 1);
		cout<<"\n";
		
		if (ptr == root)
		cout<<"Root -> ";
		
		for (int i = 0; i < level && ptr != root; i++)
		cout<<" ";
		cout<<ptr->data;
		display(ptr->left, level + 1);
	}
	cout<<"\n";
}

/* Inorder Traversal of AVL Tree*/
void avlTree::inorder(avlnode *tree)
{
	if (tree == NULL)
	return;
	inorder (tree->left);
	cout<<tree->data<<" ";
	inorder (tree->right);
}


/* Preorder Traversal of AVL Tree*/
void avlTree::preorder(avlnode *tree)
{
	if (tree == NULL)
	return;
	cout<<tree->data<<" ";
	preorder (tree->left);
	preorder (tree->right);
}

/* Postorder Traversal of AVL Tree*/
void avlTree::postorder(avlnode *tree)
{
	if (tree == NULL)
	return;
	postorder ( tree ->left );
	postorder ( tree ->right );
	cout<<tree->data<<" ";
}

/*Inorder Non Recursive*/
void avlTree::inorder_non_rec(avlnode *root)
{
	stack stk;
	avlnode *temp;
	
	if(root!=NULL)
	{
		temp=root;
		do
		{
			while(temp!=NULL)
			{
			stk.push(temp);
			temp=temp->left;
			}/*end while*/
			
			if(!stk.empty())
			{
			temp=stk.pop();
			cout<<temp->data<<" ";
			temp=temp->right;
			}/*end if*/
			else
			break;
		}while(1);
	}
	else
	cout<<" The tree is empty ";
}
/*Preorder Non Recursive*/
void avlTree::preorder_non_rec(avlnode *root)
{
	stack stk;
	avlnode *temp=root;
	stk.push(temp);
	
	while(!stk.empty())
	{
		temp=stk.pop();
		if(temp!=NULL)
		{
		cout<<temp->data<<" ";
		stk.push(temp->right);
		stk.push(temp->left);
		}
	}
}

void avlTree::postorder_non_rec(avlnode *ptr)
{
	int flag[50];
	int top_prev;
	avlnode * stkarr[50];
	int top =1;
	stkarr[++top]=NULL;
	
	do
	{
		while (ptr!=NULL)
		{
			stkarr[++top]=ptr;
			
			flag[top]=1;
			if (ptr->right !=NULL)
			{
			stkarr[++top]=ptr->right;
			flag[top]=-1;
			}
			
			ptr=ptr->left;
		}
		top_prev=top;
		ptr=stkarr[top--];
		
		while (flag[top_prev]==1)
		{
			cout<<ptr->data<<" ";
			top_prev=top;
			ptr=stkarr[top--];
		}
	}while (ptr!=NULL);
}


int main()
{
	int choice, item, e;
	avlTree avl;
	
	while (1)
	{
	cout<<"AVL Tree Implementation->"<<endl;
	cout<<"1.Insert Element into the tree"<<endl;
	cout<<"2.Display Balanced AVL Tree"<<endl;
	cout<<"3.InOrder traversal"<<endl;
	cout<<"4.PreOrder traversal"<<endl;
	cout<<"5.PostOrder traversal"<<endl;
	cout<<"6.Non Recursive Inorder traversal of AVL Tree"<<endl;
	cout<<"7.Non Recursive Preorder traversal of AVL Tree"<<endl;
	cout<<"8.Non Recursive Postorder traversal of AVL Tree"<<endl;
	cout<<"9.Exit"<<endl;
	cout<<"Enter your Choice:";
	cin>>choice;
	
	switch(choice)
	{
		case 1:
		do
		{
		cout<<"Enter value to be inserted: ";
		cin>>item;
		root = avl.insert(root, item);
		cout<<"1.ADD more \n0.Terminate"<<endl;
		cin>>e;
		}while(e==1);
		break;
		
		case 2:
		if (root == NULL)
		{
		cout<<"Tree is Empty"<<endl;
		continue;
		}
		cout<<"Balanced AVL Tree:"<<endl;
		avl.display(root, 1);
		break;
		
		case 3:
		cout<<"Inorder Traversal:"<<endl;
		avl.inorder(root);
		cout<<endl;
		break;
		
		case 4:
		cout<<"Preorder Traversal:"<<endl;
		avl.preorder(root);
		cout<<endl;
		break;
		
		case 5:
		cout<<"Postorder Traversal:"<<endl;
		avl.postorder(root);
		cout<<endl;
		break;
		
		case 6:
		cout<<"Non Rec Inorder Traversal:"<<endl;
		avl.inorder_non_rec(root);
		cout<<endl;
		break;
		
		case 7:
		cout<<"Non Rec Preorder Traversal:"<<endl;
		avl.preorder_non_rec(root);
		cout<<endl;
		break;
		
		case 8:
		cout<<"Non Rec Postorder Traversal:"<<endl;
		avl.postorder_non_rec(root);
		cout<<endl;
		break;
		
		case 9:
		exit(1);
		break;
		
		default:
		cout<<"Wrong choice"<<endl;
	}
	}
	return 0;
}
