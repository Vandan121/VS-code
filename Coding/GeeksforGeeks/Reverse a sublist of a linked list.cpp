// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};
void printList(struct Node *head)
{
	struct Node *temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
    cout<<endl;
}

 // } Driver Code Ends
//User function Template for C++

/*Link list node 
struct Node {
	int data;
	struct Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};*/

class Solution
{
    public:
    Node* reverse(Node* head){
        Node* prev = NULL;
        //printList(head);
        while(head){
            Node* n = head->next;
            head->next = prev;
            prev = head;
            head = n;
        }
        return prev;
        //printList(prev);
    }
    Node* reverseBetween(Node* head, int m, int n)
    {
        if(!head) return head;
        Node dummy(0);
        Node* p= &dummy;
        p->next = head;
        Node* prevleft=p,*left=p,*nextright,*right=p;
        while(m--){
            left = left->next;
            if(m==1) prevleft = left;
        }
        while(n--){
            right = right->next;
        }
        nextright = right->next;
        right->next = NULL;
        Node* rev = reverse(left);
        prevleft->next = rev;
        left->next = nextright;
        return dummy.next;
    }
};

// { Driver Code Starts.

/* Function to print linked list */




// Driver program to test above functions
int main()
{
	int T;
	cin >> T;

	while (T--)
	{
		int N, m, n;
		cin >> N>>m>>n;

		Node *head = NULL;
		Node *temp = head;

		for (int i = 0; i < N; i++) {
			int data;
			cin >> data;
			if (head == NULL)
				head = temp = new Node(data);
			else
			{
				temp->next = new Node(data);
				temp = temp->next;
			}
		}

		

        Solution ob;

		Node* newhead = ob.reverseBetween(head, m, n);
		printList(newhead);

		cout << "\n";



	}
	return 0;
}
  // } Driver Code Ends