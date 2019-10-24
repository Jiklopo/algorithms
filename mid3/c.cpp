#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* left;
	Node* right;

	Node(int data) {
		this->data = data;
		left = NULL;
		right = NULL;
	} 
};

class Tree {
public:
	Node* root;

	Tree() {
		root = NULL;
	}

	Node* add(Node* root, int data) {
		if (root == NULL) {
			return new Node(data);
		} else if (root->data > data) {
			root->left = add(root->left, data);
		} else if (root->data < data) {
			root->right = add(root->right, data);
		}
		return root;
	}

	Node* find(Node* root, int x) {
		if (root == NULL) {
			return NULL;
		} else if (root->data == x) {
			return root;
		} else if (root->data < x) {
			return find(root->right, x);
		} else {
			return find(root->left, x);
		}
	}

    int getLeafs(Node * root)  
{  
    if(root == NULL)      
        return 0;  
    if(root->left == NULL && root->right == NULL)  
        return 1;          
    else
        return getLeafs(root->left)+  
            getLeafs(root->right);  
}
};

int main()
{
    int n;
    cin >> n;
    Tree tr = Tree();
    for(int i = 0;i < n; i++)
    {
        int x;
        cin >> x;
        tr.root = tr.add(tr.root, x);
    }
    cout << tr.getLeafs(tr.root);
}