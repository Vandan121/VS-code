#include <iostream>
#include"BinaryTree.h"

using namespace std;

int main()
{
    int z=0;
	BinaryTree b;
	Node *temp=b.create();
	cout<<"Here is the binary tree now in Inorder traversal"<<endl;
	b.display(temp);
int p,i,j;
	cout<<"Enter 1 to insert"<<endl;
	cout<<"Enter 2 to remove"<<endl;
	cout<<"Enter 3 to search"<<endl;
	cout<<"Enter 4 to display(Inorder Traversal)"<<endl;
	cout<<"Enter 5 to Find Maximum Element"<<endl;
	cout<<"Enter 6 to print Level order"<<endl;
	cout<<"Enter 7 to print number of Half Nodes"<<endl;
	cout<<"Enter 8 to get Diameter of Binary Tree"<<endl;
	cout<<"Enter 9 to get Sum of elements"<<endl;
	cout<<"Enter 10 to exit"<<endl;
	int opt;
	cin>>opt;
	while(1)
	{
		switch(opt)
		{
			case 1:
				cout<<"Enter element to insert"<<endl;
				cin>>p;
				temp=b.insert(temp,p);
				break;
			case 2:
				cout<<"Enter the element you want to delete"<<endl;
	            cin>>i;
	            temp=b.deletion(temp,i);
				break;
			case 3:
			    cout<<"Enter the element you want to search"<<endl;
             	cin>>j;
             	if(b.search(temp,j))
             	cout<<"Found"<<endl;
             	else
            	cout<<"Not found"<<endl;
				break;
			case 4:
                b.display(temp);
                break;

			case 5:
			    {
                int ans =b.findMax(temp);
                cout<<"Maximum element in tree is "<<ans<<endl;
                break;
			    }
            case 6:
                cout << "Level Order traversal of binary tree is \n";
                b.printLevelOrder(temp);
                cout<<endl;
                break;
            case 7:
                cout<<"No. of Half Nodes is "<<b.gethalfCount(temp)<<endl;
                break;
            case 8:
                cout <<"Diameter of the Binary tree is "<<b.diameter(temp)<<endl;
                break;
            case 9:
                b.Sum(temp, &z);
                cout<<"Sum of elements is "<<z<<endl;
                break;
            case 10:
                return 0;

		}
		cout<<"Enter your choice"<<endl;
		cin>>opt;
	}
	return 0;
}
