#include "BinaryTree.h"
#include<bits/stdc++.h>

using namespace std;
Node* BinaryTree::create_newinsert(int data)
{
	Node* temp=new Node();
	temp->value=data;
	temp->left=NULL;
	temp->right=NULL;
	return temp;
}
Node* BinaryTree::create_newnode()
{
	Node* temp=new Node();
	return temp;
}
Node* BinaryTree::create()
{
	Node* new_node;
	new_node=create_newnode();
	int x;
	cout<<"Enter data(-1 to stop)"<<endl;
	cin>>x;
	if(x==-1)
	return NULL;
	new_node->value=x;
	cout<<"Enter left child(-1 to stop) of "<<x<<endl;
	new_node->left=create();
	cout<<"Enter right child(-1 to stop) of "<<x<<endl;
	new_node->right=create();
	return new_node;
}
void BinaryTree::display(Node* root){
	//Inorder traversal
	if(root)
	{
		display(root->left);
		cout<<root->value<<endl;
		display(root->right);
	}
}
Node* BinaryTree::insert(Node* root, int data)
{
    if (root == NULL) {
        root = create_newinsert(data);
        return root;
    }
 //Else level order traversal
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left =create_newinsert(data);
            return root;
        }

        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = create_newinsert(data);
            return root;
        }
    }
}
void BinaryTree::deletDeepest(Node* root,Node* d_node)
{
    queue<Node*> q;
    q.push(root);

    // Do level order traversal until last node
    Node* temp;
    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp == d_node) {
            temp = NULL;
            delete (d_node);
            return;
        }
        if (temp->right) {
            if (temp->right == d_node) {
                temp->right = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->right);
        }

        if (temp->left) {
            if (temp->left == d_node) {
                temp->left = NULL;
                delete (d_node);
                return;
            }
            else
                q.push(temp->left);
        }
    }
}

Node* BinaryTree::deletion(Node* root, int key)
{
    if (root == NULL)
        return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->value == key)
            return NULL;
        else
            return root;
    }

    queue<Node*> q;
    q.push(root);

    Node* temp;
    Node* key_node = NULL;

    // Do level order traversal to find deepest
    // node(temp) and node to be deleted (key_node)
    while (!q.empty()) {
        temp = q.front();
        q.pop();

        if (temp->value == key)
            key_node = temp;

        if (temp->left)
            q.push(temp->left);

        if (temp->right)
            q.push(temp->right);
    }

    if (key_node != NULL) {
        int x = temp->value;
        deletDeepest(root, temp);
        key_node->value = x;
    }
    return root;
}
bool BinaryTree::search(Node* root,int data)
{
   if (root== NULL)
        return false;
 //Inorder traversal
   bool res1 = search(root->left, data);
    if(res1) return true;
    if (root->value ==data)
        return true;
    bool res2 = search(root->right,data);
     return res2;
}
int BinaryTree :: findMax(Node *root)
{

    // Base case
    if (root == NULL)
    {

        return NULL;
    }
    // Return maximum of 3 values:
    // 1) Root's data 2) Max in Left Subtree
    // 3) Max in right subtree
    int res = root->value;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return res;
}
/* Print nodes at a current level */
void BinaryTree:: printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->value << " ";
    else if (level > 1)
    {
        printCurrentLevel(root->left, level-1);
        printCurrentLevel(root->right, level-1);
    }
}
/* Function to print level
order traversal a tree*/
void BinaryTree:: printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = h; i >=1; i--)
        printCurrentLevel(root, i);
}
int BinaryTree :: height(Node* node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);

        /* use the larger one */
        if (lheight > rheight)
        {
            return(lheight + 1);
        }
        else {
          return(rheight + 1);
        }
    }
}
 int BinaryTree :: gethalfCount(struct Node* node)
{
    // If tree is empty
    if (!node)
        return 0;

    int count = 0; // Initialize count of half nodes

    // Do level order traversal starting from root
    queue<Node *> q;
    q.push(node);
    while (!q.empty())
    {
        struct Node *temp = q.front();
        q.pop();

        if (!temp->left && temp->right ||
            temp->left && !temp->right)
            count++;

        if (temp->left != NULL)
            q.push(temp->left);
        if (temp->right != NULL)
            q.push(temp->right);
    }
    return count;
}

int BinaryTree:: diameter(Node *z)
{
    if (z == NULL)
    {
        return 0;
    }
    int left = height(z->left);
    int right = height(z->right);
    int dia_r, dia_l, dia_root;
    dia_root = left + right + 1;
    dia_l = diameter(z->left);
    dia_r = diameter(z->right);
    if (dia_root >= dia_l && dia_root >= dia_r)
    {
        return dia_root;
    }
    else if (dia_l >= dia_r)
    {
        return dia_l;
    }
    else if (dia_l <= dia_r)
    {
        return dia_r;
    }
}
void BinaryTree::Sum(Node *z, int *sum)
{
    if (z == NULL)
    {
        return;
    }
    Sum(z->left, sum);
    *sum = *sum + z->value;
    Sum(z->right, sum);
}


