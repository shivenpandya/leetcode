#include<bits/stdc++.h>
using namespace std;

// Construct a BST from Arr

class Node {
public:
	int val;
	Node* left;
	Node* right;

	Node(int data) {
		val = data;
		left = NULL;
		right = NULL;
	}
};

class BST {
	Node* root;

	Node* constructBstUtil(int arr[], int n, int idx){
		if(idx >= n ) return NULL;
		if(arr[idx] == -1) return NULL;

		Node* cur = new Node(arr[idx]);

		cur->left = constructBstUtil(arr, n, idx*2+1);
		cur->right = constructBstUtil(arr, n, idx*2+2);
		return cur;
	}

public:
	BST(){
		root = NULL;
	}

	Node* constructBST(int arr[], int n){
		root = constructBstUtil(arr, n, 0);
		return root;
	}

	void preorder(Node* root){
		if(root != NULL)
		{
			cout << root->val << " ";
			preorder(root->left);
			preorder(root->right);
	 	}
	 	// else{
	 	// 	cout << "null ";
	 	// }
	}
};

class Solution {
public:
    int rangeSumBST(Node* root, int low, int high) {
		if(!root) return 0;

		int sum = 0;

		if(root->val >= low && root->val <= high)
			sum = root->val;

		if(root->val < low)
			sum += rangeSumBST(root->right, low, high);
		else if(root->val > high)
			sum += rangeSumBST(root->left, low, high);
		else{
			sum += rangeSumBST(root->left, low, high);
			sum += rangeSumBST(root->right, low, high);
		}
		return sum;
    }
};

int main(){
	BST bst;

	int arr[] = {10,5,15,3,7,-1,18};
	int low = 7, high = 15;
	int n = sizeof(arr)/sizeof(arr[0]);

	Node* root = bst.constructBST(arr,n);
	//bst.preorder(root);


	Solution s;
	cout << s.rangeSumBST(root, low, high) << endl;
}

