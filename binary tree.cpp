#include <bits/stdc++.h>
using namespace std;
int height(struct node* root);
void printGivenLevel(struct node *node,int level);
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int value)
{
	struct node *new_node = (struct node *)malloc(sizeof(struct node));
	new_node->data = value;
	new_node->left = NULL;
	new_node->right = NULL;
	return new_node;
}

void deleteTheDeepestNode(struct node* root, struct node* last_node)
{
	queue<struct node*>q;
	q.push(root);
	if(root == last_node)
	{
		free(last_node);
		return;
	}
	while(!q.empty())
	{
		struct node *temp = q.front();
		q.pop();
		if(temp->left == last_node)
			temp->left = NULL;
		if(temp->left)
			q.push(temp->left);
		if(temp->right == last_node)
			temp->right = NULL;
		if(temp->right)
			q.push(temp->right);
	}
}

void deleteNodeReplaceWithLastNode(struct node* root, int value)
{
	queue<struct node*>q;
	q.push(root);
	int v;
	struct node *temp = NULL;
	struct node* del_node = NULL;
	while(!q.empty())
	{
		temp = q.front();
		v = temp->data;
		if(value == temp->data)
			del_node = temp;
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);

	}
	if(del_node!=NULL)
	{	
		del_node->data = v;
		deleteTheDeepestNode(root,temp);
	}
}
void printLevelOrderUsingQueue(struct node* root)
{
	queue<node *>q;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp = q.front();
		cout<<temp->data<<" ";
		q.pop();
		if(temp->left != NULL)
			q.push(temp->left);
		if(temp->right != NULL)
			q.push(temp->right);

	}
}
void printLevelOrderUsingRecusrsion(struct node* root)
{
	int h = height(root);
	for(int i=1;i<=h;i++)
	{
		printGivenLevel(root, i);
	}
}

void printGivenLevel(struct node *node, int level)
{
	if(node == NULL)
		return;
	if(level == 1)
		cout<<node->data<<" ";
	printGivenLevel(node->left,level-1);
	printGivenLevel(node->right, level-1);
}


void insert(int value,struct node *root)
{
	queue<struct node*> q;
	q.push(root);
	while(!q.empty())
	{
		struct node* temp = q.front();
		q.pop();
		if(temp->left == NULL)
		{
			temp->left = newNode(value);
			break;
		}
		else
		{
			q.push(temp->left);
		}
		if(temp->right == NULL)
		{
			temp->right = newNode(value);
			break;
		}
		else
		{
			q.push(temp->right);
		}
	}
}
int height(struct node *node)
{
	if(node == NULL)
		return 0;
	
	
	int lheight = height(node->left);
	int rheight = height(node->right);
	
	if(lheight>rheight)
		return lheight+1;
	else
		return rheight+1;
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r" ,stdin);
	freopen("output.txt", "w" ,stdout);
	#endif

	struct node *root = newNode(10);
	insert(11,root);
	insert(9,root);
	insert(7,root);
	insert(12,root);
	insert(15,root);
	insert(8,root);
	// struct node *temp1;
	// struct node *temp2;
	// temp1 = root->right = newNode(12);
	// temp2 = root->left = newNode(15);
	// temp1->left = newNode(16);
	// temp1->right = newNode(17);
	// temp2->left = newNode(18);
	// temp2->right = newNode(20);

	printLevelOrderUsingQueue(root);
	cout<<endl;
	cout<<height(root)<<endl;
	// insert(69,root);
	deleteNodeReplaceWithLastNode(root,11);
	printLevelOrderUsingRecusrsion(root);
	cout<<endl;
	cout<<height(root)<<endl;

	// cout<<root->data<<endl;
	// cout<<root->left->data<<endl;
	// cout<<root->right->data<<endl;
	// cout<<temp1->left->data<<endl;
	// cout<<temp1->right->data<<endl;
	// cout<<temp2->left->data<<endl;
	// cout<<temp2->right->data<<endl;
	

	
	return 0;
}