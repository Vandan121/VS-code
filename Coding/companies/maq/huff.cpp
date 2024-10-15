// // C++(STL) program for Huffman Coding with STL 
// #include <bits/stdc++.h> 
// using namespace std;  
// struct MinHeapNode { 
// 	char data; 
// 	unsigned freq; 
// 	MinHeapNode *left, *right; 
// 	MinHeapNode(char data, unsigned freq) 
// 	{ 
// 		left = right = NULL; 
// 		this->data = data; 
// 		this->freq = freq; 
// 	} 
// }; 
// struct compare { 

// 	bool operator()(MinHeapNode* l, MinHeapNode* r) 
// 	{ 
// 		return (l->freq > r->freq); 
// 	} 
// };  
// void printCodes(struct MinHeapNode* root, string str) 
// { 
// 	if (!root) 
// 		return; 
// 	if (root->data != '$') 
// 		cout << root->data << ": " << str << "\n"; 
// 	printCodes(root->left, str + "0"); 
// 	printCodes(root->right, str + "1"); 
// } 
// void HuffmanCodes(vector<char> data, vector<int> freq, int size) 
// { 
// 	struct MinHeapNode *left, *right, *top; 
// 	priority_queue<MinHeapNode*, vector<MinHeapNode*>, 
// 				compare> 
// 		minHeap; 
// 	for (int i = 0; i < size; ++i) 
// 		minHeap.push(new MinHeapNode(data[i], freq[i])); 
// 	while (minHeap.size() != 1) { 
// 		left = minHeap.top(); 
// 		minHeap.pop(); 

// 		right = minHeap.top(); 
// 		minHeap.pop(); 
// 		top = new MinHeapNode('$', 
// 							left->freq + right->freq); 

// 		top->left = left; 
// 		top->right = right; 

// 		minHeap.push(top); 
// 	} 
// 	printCodes(minHeap.top(), ""); 
// }  
// int main() 
// { 
// 	int t; cin>>t;
//     while(t--){
//         int n; cin>>n;
//         vector<int> freq(n);
//         vector<char> data(n);
//         for(int i=0;i<n;i++) cin>>data[i];
//         for(int i=0;i<n;i++) cin>>freq[i];
// 	    HuffmanCodes(data, freq, n); 
//     } 
// 	return 0; 
// } 


// C++ Program for Huffman Coding
// using Priority Queue
#include <iostream>
#include <queue>
using namespace std;

// Maximum Height of Huffman Tree.
#define MAX_SIZE 100

class HuffmanTreeNode {
public:
	char data;
	int freq;
	HuffmanTreeNode* left;
	HuffmanTreeNode* right;
	HuffmanTreeNode(char character,
					int frequency)
	{
		data = character;
		freq = frequency;
		left = right = NULL;
	}
};

class Compare {
public:
	bool operator()(HuffmanTreeNode* a,
					HuffmanTreeNode* b)
	{
		return a->freq > b->freq;
	}
};

HuffmanTreeNode* generateTree(priority_queue<HuffmanTreeNode*,vector<HuffmanTreeNode*>,Compare> pq)
{

	while (pq.size() != 1) {
		HuffmanTreeNode* left = pq.top();
		pq.pop();
		HuffmanTreeNode* right = pq.top();
		pq.pop();
		HuffmanTreeNode* node = new HuffmanTreeNode('$',left->freq + right->freq);
		node->left = left;
		node->right = right;
		pq.push(node);
	}
	return pq.top();
}
void printCodes(HuffmanTreeNode* root,
				int arr[], int top)
{

	if (root->left) {
		arr[top] = 0;
		printCodes(root->left,
				arr, top + 1);
	}
	if (root->right) {
		arr[top] = 1;
		printCodes(root->right, arr, top + 1);
	}
	if (!root->left && !root->right) {
		cout << root->data << ": ";
		for (int i = 0; i < top; i++) {
			cout << arr[i];
		}
		cout << endl;
	}
}
void HuffmanCodes(vector<char> data,
				vector<int>  freq, int size)
{
	priority_queue<HuffmanTreeNode*,
				vector<HuffmanTreeNode*>,
				Compare>
		pq;
	for (int i = 0; i < size; i++) {
		HuffmanTreeNode* newNode
			= new HuffmanTreeNode(data[i], freq[i]);
		pq.push(newNode);
	}
	HuffmanTreeNode* root = generateTree(pq);
	int arr[MAX_SIZE], top = 0;
	printCodes(root, arr, top);
}
int main()
{
	int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> freq(n);
        vector<char> data(n);
        for(int i=0;i<n;i++) cin>>data[i];
        for(int i=0;i<n;i++) cin>>freq[i];
	    HuffmanCodes(data, freq, n); 
    } 
	return 0;
}
