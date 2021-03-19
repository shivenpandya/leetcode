// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.
// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
    	if(nums.size() == 0) return NULL;
    	TreeNode* root;
        root = util(root, nums, 0, nums.size()-1);

        return root;
    }

    TreeNode* util(vector<int> nums, int start, int end){
    	if(start > end) return NULL;

    	int mid = start + (end-start)/2;

    	TreeNode *root = new TreeNode(nums[mid]);
    	root->left = util(nums, start, mid-1);
    	root->right = util(nums, mid+1, end);

    	return root;
    }
};