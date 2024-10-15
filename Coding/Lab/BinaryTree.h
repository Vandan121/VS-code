#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>


class Node{
 public:
 int value;
 Node* left;
 Node* right;
};
class BinaryTree{
	Node *root;
	public:
		BinaryTree(){
			root=NULL;
		}
		Node* create_newnode();
		Node* create_newinsert(int);
		Node* create();
		void remove(int);
		bool search(Node* ,int);
		Node* insert(Node* ,int);
		void display(Node*);
		void deletDeepest(Node*,Node*);
		Node* deletion(Node*,int);
		int findMax(Node *root);
		void printCurrentLevel(Node* root, int level);
		void printLevelOrder(Node* root);
		int height(Node* node);
		int gethalfCount(struct Node* node);
		int diameter(Node *z);
		void Sum(Node *z, int *sum);


};
#endif // BINARYTREE_H
