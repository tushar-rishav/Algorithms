/*
	Implementation of Preorder, Inorder, Postorder traversals in a Tree
*/

#include <bits/stdc++.h>
using namespace std;

struct node{
	int data;
	int key;
	struct node* left;
	struct node* right;
};

class Tree{
	private:
		node* root;
		int node_count = 0;
	public:
		void insert(node**, int);
		node** get_root();
		void update_root(node** ptr);
		void preorder(node**);
		void inorder(node**);
		void postorder(node**);
		int search(node**, int);

};

node** Tree::get_root()
{
	return &(this->root);
}
void Tree::update_root(node** ptr)
{
	this->root = *ptr;
}
void Tree::insert(node** head, int item)
{
	if(*head){
		if((*head)->data > item)
			this->insert(&(*head)->left, item);
		else
			this->insert(&(*head)->right, item);
	}
	else{
		*head = new node;	// create a new node to insert the value
		(*head)->data = item;
		(*head)->left = NULL;
		(*head)->right = NULL;
		this->node_count++;
		(*head)->key = this->node_count;
		printf("Node inserted with value : %d\n", item);
	}

}
int Tree::search(node** head, int key)
{
	if(!*(head))
		return -1;
	if(key == (*head)->data)
		return (*head)->key;
	else if(key > (*head)->data)
		return (this->search(&((*head)->right),key));
	else
		return (this->search(&((*head)->left), key));

}
void Tree::preorder(node** head)
{
	if(*head){
		cout<< (*head)->data<<" ";
		this->preorder(&((*head)->left));
		this->preorder(&((*head)->right));
	}
}

void Tree::inorder(node** head)
{
	if(*head){
		this->inorder(&((*head)->left));
		cout<< (*head)->data<<" ";
		this->inorder(&((*head)->right));
	}
}

void Tree::postorder(node** head)
{
	if(*head){
		this->postorder(&((*head)->right));
		this->postorder(&((*head)->left));
		cout<< (*head)->data<<" ";
	}
}

int main()
{  
	node* head = NULL;
	Tree tree;
	
	tree.insert(&head, 10);
	tree.insert(&head, 4);
	tree.insert(&head, 20);
	tree.insert(&head, 30);
	tree.insert(&head, 8);
	tree.insert(&head, 23);
	tree.insert(&head, 1);
	tree.insert(&head, 21);
	tree.update_root(&head);
	tree.preorder(tree.get_root());
	cout<<"\tPreorder"<<endl;
	tree.inorder(tree.get_root());
	cout<<"\tInorder"<<endl;
	tree.postorder(tree.get_root());
	cout<<"\tPostorder"<<endl;
	cout<<"Enter an item to search\t";
	int n;
	cin>>n;
	int pos = tree.search(tree.get_root(),n);
	if(pos!=-1)
		cout<<"\nFound at position "<<pos<<endl;
	else
		cout<<"\nNot Found\n";
	return 0;
}