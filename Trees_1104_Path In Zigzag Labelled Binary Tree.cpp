// 1104. Path In Zigzag Labelled Binary Tree
// In an infinite binary tree where every node has two children, the nodes are labelled in row order.

// In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.

// Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.

class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int height = log2(label);
        vector<int> res;
      
        while(label > 0 && height >= 0){
          res.push_back(label);
          // Find the dist from the min Val of given height and divide it by 2,
          // to get the distance in the level with height-1.
          int dist = (label - (1 << height))/2;
          label = ((1 << height) - 1 - dist);
          height--;
        }
        reverse(res.begin(), res.end());
      return res;
    }
};