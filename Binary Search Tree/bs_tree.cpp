#include <iostream>
#include "conio.h"
#include <fstream>
#include <vector>
#include <iomanip>

struct Node{
	int key_value;
	double data1;
	double data2;
	Node *left;
	Node *right;
};

class BinarySearchTree{

public:
	BinarySearchTree();
	~BinarySearchTree();
	void insert(int key, double d1, double d2);
	Node *search(int key);
	void destroyBinarySearchTree();
	void preorder();
	void inorder();
	void postorder();
	friend std::ostream& BinarySearchTree::operator<<(std::ostream& stream, const Node* leaf);

private:
	void destroyBinarySearchTree(Node *leaf);
	void insert(int key, Node *leaf, double d1, double d2);
	Node *search(int key, Node *leaf);
	void preorder(Node* leaf);
	void inorder(Node* leaf);
	void postorder(Node* leaf, int indent);

	Node *root;
};

void print_vector(std::vector<int>& arr);

int main(){

	BinarySearchTree data;
	std::vector<int> keys;
	std::ifstream read_keys("keys.dat");
	std::ifstream read_data("num.dat");

	int tempkey;
	double tempr1, tempr2;

	while(!read_data.eof())
	{
		read_data >> tempkey >> tempr1 >> tempr2;
		data.insert(tempkey, tempr1, tempr2);
	}

	while(!read_keys.eof())
	{
		read_keys >> tempkey;
		keys.push_back(tempkey);
	}

	int count=0;

	for(int i=0; i<keys.size(); i++)
	{
		if(data.search(keys[i])!=NULL)
		{
			count++;
		}
	}
	std::cout << "Keys found in a BinarySearchTree: " << count << std::endl;

	return 0;
}

void print_vector(std::vector<int>& arr)
{
	for(int i=0; i<arr.size(); i++)
	{
		std::cout << arr[i] << std::endl;
	}
}

BinarySearchTree::BinarySearchTree()
{
	root=NULL;
}

BinarySearchTree::~BinarySearchTree()
{
	destroyBinarySearchTree();
}

void BinarySearchTree::destroyBinarySearchTree()
{
	destroyBinarySearchTree(root);
}

void BinarySearchTree::destroyBinarySearchTree(Node *leaf)
{
	if(leaf!=NULL)
	{
		destroyBinarySearchTree(leaf->left);
		destroyBinarySearchTree(leaf->right);
		delete leaf;
	}
}

void BinarySearchTree::insert(int key, Node *leaf, double d1, double d2)
{
	if(key < leaf->key_value)
	{
		if(leaf->left!=NULL)
			insert(key, leaf->left, d1, d2);
		else
		{
			leaf->left=new Node;
			leaf->left->key_value=key;
			leaf->left->data1=d1;
			leaf->left->data2=d2;
			leaf->left->left=NULL;
			leaf->left->right=NULL;
		}
	}
	else if(key > leaf->key_value)
	{
		if(leaf->right!=NULL)
			insert(key, leaf->right, d1, d2);
		else
		{
			leaf->right=new Node;
			leaf->right->key_value=key;
			leaf->right->data1=d1;
			leaf->right->data2=d2;
			leaf->right->left=NULL;
			leaf->right->right=NULL;
		}
	}
}

void BinarySearchTree::insert(int key, double d1, double d2)
{
	if(root!=NULL)
		insert(key, root, d1, d2);
	else
	{
		root = new Node;
		root->key_value=key;
		root->data1=d1;
		root->data2=d2;
		root->left=NULL;
		root->right=NULL;
	}
}

Node *BinarySearchTree::search(int key, Node *leaf)
{
	if(leaf!=NULL)
	{
		if(key==leaf->key_value)
			return leaf;
		if(key < leaf->key_value)
			return search(key, leaf->left);
		else
			return search(key, leaf->right);
	}
	else return NULL;
}

Node *BinarySearchTree::search(int key)
{
	return search(key, root);
}

std::ostream& operator<<(std::ostream& stream, const Node* leaf)
{
	if(leaf!=NULL)
	{
		stream << "Key value: " << leaf->key_value << std::endl;
		stream << "Data 1: " << leaf->data1 << std::endl;
		stream << "Data 2: " << leaf->data2 << std::endl;
	}
	else
		{
			stream << "Leaf is NULL." << std::endl;
		}
	return stream;
}

void BinarySearchTree::preorder(Node* leaf)
{
	if(leaf!=NULL)
	{
		std::cout << leaf;
		preorder(leaf->left);
		preorder(leaf->right);
	}

}

void BinarySearchTree::preorder()
{
	if(root!=NULL)
		preorder(root);
	else std::cout << "BinarySearchTree is empty." << std::endl;
}

void BinarySearchTree::inorder(Node *leaf)
{
	if(leaf!=NULL)
	{
		inorder(leaf->left);
		std::cout << leaf;
		inorder(leaf->right);
	}
}

void BinarySearchTree::inorder()
{
	if(root!=NULL) 
		inorder(root);
	else std::cout << "BinarySearchTree is empty." << std::endl;
}

void BinarySearchTree::postorder(Node* leaf, int indent)
{
	if(leaf!=NULL)
	{
		if(leaf->right)
			postorder(leaf->right, indent+4);
		
		if(indent)
			std::cout << std::setw(indent) << ' ';

		if(leaf->right) std::cout << " / \n" << std::setw(indent) << ' ';
		std::cout << leaf->key_value << std::endl;
		if(leaf->left)
		{
			std::cout << std::setw(indent) << ' ' << " \\\n";
			postorder(leaf->left, indent+4);
		}
	}
}

void BinarySearchTree::postorder()
{
	if(root!=NULL)
		postorder(root, 0);
	else std::cout << "BinarySearchTree is empty." << std::endl;
}